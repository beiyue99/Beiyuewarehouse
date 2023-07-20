#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "wrap.h"
#include <event.h>
#include <event2/listener.h>
#include <dirent.h>

#define _WORK_DIR_ "%s/webpath"
#define _DIR_PREFIX_FILE_ "html/dir_header.html"
#define _DIR_TAIL_FILE_ "html/dir_tail.html"
void decodeMsg(char* to, char* from);
const char* getFileType(const char* name);



int  copy_header(struct bufferevent* bev, int op, char* msg, const char* filetype, long filesize)
{
	char buf[4096] = { 0 };
	sprintf(buf, "HTTP/1.1 %d %s\r\n", op, msg);
	snprintf(buf, sizeof(buf), "%sContent-Type: %s\r\n", buf, filetype);

	if (filesize >= 0) {
		snprintf(buf, sizeof(buf), "%sContent-Length: %ld\r\n", buf, filesize);

	}
	strcat(buf, "\r\n");
	bufferevent_write(bev, buf, strlen(buf));
	return 0;
}

int copy_file(struct bufferevent* bev, const char* strFile)
{
	int fd = open(strFile, O_RDONLY);
	char buf[1024] = { 0 };
	int ret;
	while ((ret = read(fd, buf, sizeof(buf))) > 0)
	{
		bufferevent_write(bev, buf, ret);
	}
	close(fd);
	return 0;
}

int send_dir(struct bufferevent* bev, const char* strPath)
{
	copy_file(bev, _DIR_PREFIX_FILE_);
	DIR* dir = opendir(strPath);
	if (dir == NULL)
	{
		perror("opendir error");
		return -1;
	}
	char bufline[1024] = { 0 };
	struct dirent* dirent = NULL;
	while ((dirent = readdir(dir)))
	{
		struct stat sb;
		char filepath[256];
		snprintf(filepath, sizeof(filepath) - 1, "%s/%s", strPath, dirent->d_name);

		stat(filepath, &sb);
		if (dirent->d_type == DT_DIR)
		{
			// 目录文件，特殊处理
			// 格式：<li><a href='dirname/'>dirname</a>    size</li>
			memset(bufline, 0x00, sizeof(bufline));
			sprintf(bufline, "<li><a href='%s/'>%32s</a>    %ld</li>", dirent->d_name, dirent->d_name, sb.st_size);
			bufferevent_write(bev, bufline, strlen(bufline));
		}
		else if (dirent->d_type == DT_REG)
		{
			// 普通文件，直接显示列表即可
			memset(bufline, 0x00, sizeof(bufline));
			sprintf(bufline, "<li><a href='%s'>%32s</a>    %ld</li>", dirent->d_name, dirent->d_name, sb.st_size);
			bufferevent_write(bev, bufline, strlen(bufline));
		}
	}
	closedir(dir);
	copy_file(bev, _DIR_TAIL_FILE_);
	return 0;
}

int http_request(struct bufferevent* bev, char* path)
{
	decodeMsg(path, path); // 将中文问题转码成 UTF-8 格式的字符串
	char* strPath = path;
	if (strcmp(strPath, "/") == 0 || strcmp(strPath, "/.") == 0)
	{
		strPath = "./";
	}
	else
	{
		strPath = path + 1;
		struct stat sb;
		if (stat(strPath, &sb) < 0)
		{
			// 不存在，返回 404 页面
			copy_header(bev, 404, "NOT FOUND", getFileType("error.html"), -1);
			copy_file(bev, "error.html");
			return -1;
		}
		if (S_ISDIR(sb.st_mode))
		{
			// 处理目录
			copy_header(bev, 200, "OK", getFileType("ww.html"), sb.st_size);
			send_dir(bev, strPath);
		}
		else if (S_ISREG(sb.st_mode))
		{
			// 处理文件
			// 写头部
			copy_header(bev, 200, "OK", getFileType(strPath), sb.st_size);
			// 写文件内容
			copy_file(bev, strPath);
		}
		return 0;
	}
	return 0;
}

void read_cb(struct bufferevent* bev, void* ctx)
{
	char buf[256];
	char method[10], path[256], protocol[10];
	int ret = bufferevent_read(bev, buf, sizeof(buf));
	if (ret > 0)
	{
		sscanf(buf, "%[^ ] %[^ ] %[^ \r\n]", method, path, protocol);
		if (strcasecmp(method, "GET") == 0)
		{
			// 处理客户端的请求
			char bufline[256];
			write(STDOUT_FILENO, buf, ret);

			// 确保数据读完
			while ((ret = bufferevent_read(bev, bufline, sizeof(bufline))) > 0)
			{
				write(STDOUT_FILENO, bufline, ret);
			}

			http_request(bev, path); // 处理请求
		}
	}
}

void bevent_cb(struct bufferevent* bev, short what, void* ctx)
{
	if (what & BEV_EVENT_EOF) // 客户端关闭
	{
		printf("client closed\n");
		bufferevent_free(bev);
	}
	else if (what & BEV_EVENT_ERROR)
	{
		printf("error: client closed\n");
		bufferevent_free(bev);
	}
	else if (what & BEV_EVENT_CONNECTED) // 连接成功
	{
		printf("client connected\n");
	}
}

void listen_cb(struct evconnlistener* listener, evutil_socket_t fd, struct sockaddr* addr, int socklen, void* arg)
{
	printf("new\n");
	// 定义与客户端通信的 bufferevent
	struct event_base* base = (struct event_base*)arg;
	struct bufferevent* bev = bufferevent_socket_new(base, fd, BEV_OPT_CLOSE_ON_FREE);
	bufferevent_setcb(bev, read_cb, NULL, bevent_cb, base); // 设置回调函数
	bufferevent_enable(bev, EV_READ | EV_WRITE); // 启用读和写
}

int main(int argc, char* argv[])
{
	char workdir[256] = { 0 };
	if (getcwd(workdir, sizeof(workdir)) == NULL)
	{
		perror("getcwd");
		return -1;
	}
	printf("%s\n", workdir);
	chdir(workdir);

	struct event_base* base = event_base_new(); // 创建根节点

	struct sockaddr_in serv;
	memset(&serv, 0, sizeof(serv));
	serv.sin_family = AF_INET;
	serv.sin_port = htons(9999);
	serv.sin_addr.s_addr = htonl(INADDR_ANY);
	struct evconnlistener* listener = evconnlistener_new_bind(
		base,
		listen_cb,
		base,
		LEV_OPT_CLOSE_ON_FREE | LEV_OPT_REUSEABLE,
		-1,
		(struct sockaddr*)&serv,
		sizeof(serv)
	);

	event_base_dispatch(base); // 进入事件循环

	event_base_free(base); // 释放根节点
	evconnlistener_free(listener); // 释放链接监听器

	return 0;
}