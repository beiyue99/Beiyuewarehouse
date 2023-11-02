#include "wrap.h"
#include"epollweb.h"




void send_header(int cfd, int code, char* info, const  char* filetype, int length)//文件描述符，状态行，状态信息
{
	//发送状态行
	char buf[1024] = "";
	int len = 0;
	len = sprintf(buf, "HTTP/1.1 %d %s\r\n", code, info);
	//send(cfd, buf, strlen(buf));如果组包有0，那么结果不准确，所以引入len记录长度
	if (send(cfd, buf, len, 0) < 0)
	{
		perror("send header failed");
		return;
	}
	//发送消息头
	len = sprintf(buf, "Content-Type:%s\r\n", filetype);
	if (send(cfd, buf, len, 0) < 0)
	{
		perror("send header failed");
		return;
	}
	if (length > 0)
	{
		len = sprintf(buf, "Content-Length:%d\r\n", length);
		if (send(cfd, buf, len, 0) < 0)
		{
			perror("send header failed");
			return;
		}
	}
	//空行
	if (send(cfd, "\r\n", 2, 0) < 0)
	{
		perror("send header failed");
		return;
	}
}

void send_file(int cfd, char* path, struct epoll_event* ev, int epfd, int flag)
{
	int fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("open file failed");
		// 此处我们可以移除连接，因为无法发送任何内容给客户端
		epoll_ctl(epfd, EPOLL_CTL_DEL, cfd, ev);
		close(cfd);
		return;
	}
	char buf[1024] = "";
	int len = 0;
	while (1)
	{
		len = read(fd, buf, sizeof(buf));
		if (len < 0)
		{
			perror("read file failed");
			break;
		}
		else if (len == 0)
		{
			break;
		}
		else
		{
			int n = 0;
			//if (n=send(cfd, buf, len, 0) < 0)
			if ((n = send(cfd, buf, len, 0)) < 0)
			{
				perror("send file failed");
				break;
			}
			printf("len=%d\n", n);
			//在 Unix 系统中，文本文件的行通常由一个换行符 (\n) 结束
		}
	}
	close(fd);
	//关闭cfd，下树	
	if (flag == 1)
	{
		close(cfd);
		epoll_ctl(epfd, EPOLL_CTL_DEL, cfd, ev);
	}
}




void read_client_request(int epfd, struct epoll_event* ev, char* pwd_path)
{
	//读取请求(先读取一行在把其他行读取扔掉)
	char buf[1024] = "";
	char tmp[1024] = "";
	int n = Readline(ev->data.fd, buf, sizeof(buf));
	if (n <= 0)
	{
		printf("close or err\n");
		epoll_ctl(epfd, EPOLL_CTL_DEL, ev->data.fd, ev);
		close(ev->data.fd);
		return;
	}
	printf("%s\n", buf);
	int ret = 0;
	while ((ret = Readline(ev->data.fd, tmp, sizeof(tmp))) > 0);
	//printf("read ok\n");
	//解析请求
	//判断是否为get请求get请求才处理
	//得到刘览请求的文件.如过对方没有请求文件
	//不存在发送error.html
	//解析请求行GET / a.txt HTTP, / 1.1\RIN
	char method[256] = "";
	char content[256] = "";
	char protocol[256] = "";
	sscanf(buf, "%[^ ] %[^ ] %[^ \r\n]", method, content, protocol);
	//"%[^ ]"的意思是读取一串连续的非空格字符，直到遇到第一个空格为止
	printf("[%s] [%s] [%s]\n", method, content, protocol);

	if (strcasecmp(method, "get") == 0)
	{
		char* strfile = content + 1;
		decodeMsg(strfile, strfile);
		//GET HTTP/1.1\R\N
		if (*strfile == 0) // 如果没有请求文件, 默认请求当前目录
			strfile = "./";
		// 判断请求的文件在不在
		struct stat s;
		//stat函数在C语言中被用来获取关于文件的信息
		if (stat(strfile, &s) < 0)  //不存在	 
		{
			printf("file not found\n");
			//确定 error.html 文件的完整路径
			char errorFilePath[1024] = "";
			sprintf(errorFilePath, "%s/error.html", pwd_path);
			printf("Error file path: %s\n", errorFilePath);
			//先发送报头(状态行消息头空行)
			send_header(ev->data.fd, 404, "NOT FOUND", getFileType("*.html"), 0);
			//发送文件error.html 
			send_file(ev->data.fd, "error.html", ev, epfd, 1);
		}
		else
		{
			if (S_ISREG(s.st_mode))
			{
				printf("file\n");
				//先发送报头(状态行消息头空行)
				send_header(ev->data.fd, 200, "OK", getFileType(strfile), s.st_size);
				//发送文件
				send_file(ev->data.fd, strfile, ev, epfd, 1);
			}
			else if (S_ISDIR(s.st_mode))
			{
				printf("dir\n");
				//发送一个列表网页
				send_header(ev->data.fd, 200, "OK", getFileType("*.html"), 0);
				send_file(ev->data.fd, "dir_header.html", ev, epfd, 0);
				struct dirent** mylist = NULL;
				char buf[1024] = "";
				int len = 0;
				int n = scandir(strfile, &mylist, NULL, alphasort);
				for (int i = 0; i < n; i++)
				{
					//printf("%s\n", mylist[i]->d_name);
					if (mylist[i]->d_type == DT_DIR)
					{
						len = sprintf(buf, "<li><a href=%s/ >%s</a></li>", mylist[i]->d_name, mylist[i]->d_name);
					}
					else
					{
						len = sprintf(buf, "<li><a href=%s >%s</a></li>", mylist[i]->d_name, mylist[i]->d_name);
					}
					send(ev->data.fd, buf, len, 0);
					free(mylist[i]);
				}
				free(mylist);
				send_file(ev->data.fd, "dir_tail.html", ev, epfd, 1);
			}
		}
	}
}

void  epollRun()
{
	signal(SIGPIPE, SIG_IGN);
	//切换工作目录
	//获取当前目录的工作路径
	char pwd_path[256] = "";
	char* path = getenv("PWD");
	//如果程序中修改了目录，再调用 getenv("PWD")，它可能还会返回旧的工作目录（除非你的程序自己更新了 "PWD" 环境变量）。
	strcpy(pwd_path, path);
	strcat(pwd_path, "/web-http");
	chdir(pwd_path);
	//剑建套接字绑定
	int lfd = tcp4bind(PORT, NULL);
	// 监听
	Listen(lfd, 128);
	// 创建树
	int epfd = epoll_create(1);
	// lfd上树
	struct epoll_event ev, evs[1024];
	ev.data.fd = lfd;
	ev.events = EPOLLIN;
	epoll_ctl(epfd, EPOLL_CTL_ADD, lfd, &ev);
	//循环监听
	while (1)
	{
		int nready = epoll_wait(epfd, evs, 1024, -1);
		if (nready == 0)
		{
			perror("");
			break;
		}
		else
		{
			for (int i = 0; i < nready; i++)
			{
				//判断是否是Lfd
				if (evs[i].data.fd == lfd && evs[i].events & EPOLLIN)
				{
					struct sockaddr_in cliaddr;
					char ip[16] = "";
					socklen_t len = sizeof(cliaddr);
					int cfd = Accept(lfd, (struct sockaddr*)&cliaddr, &len);
					printf("new client ip=%s port=%d\n",
						inet_ntop(AF_INET, &cliaddr.sin_addr.s_addr, ip, 16),
						ntohs(cliaddr.sin_port));
					//设置cfd为非阻塞
					int flag = fcntl(cfd, F_GETFL);
					flag |= O_NONBLOCK;
					fcntl(cfd, F_SETFL, flag);
					//上树
					ev.data.fd = cfd;
					ev.events = EPOLLIN;
					epoll_ctl(epfd, EPOLL_CTL_ADD, cfd, &ev);
				}
				else if (evs[i].events & EPOLLIN)//cfd
				{
					read_client_request(epfd, &evs[i], pwd_path);
				}
			}
		}
	}
}