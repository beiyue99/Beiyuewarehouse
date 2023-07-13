#include "stdio.h"
#include "wrap.h"
#define PORT 8080
#include<sys/epoll.h>
#include<fcntl.h>
#include<sys/stat.h>
#include"serverhttp.h"
#include<ctype.h>
#include<stdlib.h>
#include<dirent.h>
#include<signal.h>
//发送消息头
void send_header(int cfd, int code, char* info,const  char* filetype,int length)//文件描述符，状态行，状态信息
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
	


//发送文件
//发送大文件
//写缓存区可能满, 写不进去, 写不进去监听EPOLLOUT, 
//将没有发送的数据保存, 等写事件触发, 写出去
//调用 send() 时没有检查它是否已经发送了所有的数据。在一些情况下，
//例如网络缓冲区已满，send() 可能会发送部分数据然后返回。
//如果 send() 只发送了部分数据，那么文件的一部分可能就丢失了。

//在 libevent 中，可以通过设置回调函数和事件来实现你的需求。
//如果 send 函数因为缓冲区已满而不能发送数据，你可以设置一个 EV_WRITE 事件，
//然后把数据保存在某个地方（比如某个缓冲区或者链表）。
//然后在可写事件的回调函数中再次尝试发送数据。
void send_file(int cfd, char* path,struct epoll_event*ev,int epfd,int flag)
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












void read_client_request(int epfd, struct epoll_event* ev,char*pwd_path)
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
			send_file(ev->data.fd, "error.html",ev,epfd,1);
		}
		else
		{
			if (S_ISREG(s.st_mode))
			{
				printf("file\n");
				//先发送报头(状态行消息头空行)
				send_header(ev->data.fd,200,"OK", getFileType(strfile),s.st_size);
                //发送文件
				send_file(ev->data.fd, strfile,ev,epfd,1);
			}
			else if (S_ISDIR(s.st_mode))
			{
				printf("dir\n");
				//发送一个列表网页
				send_header(ev->data.fd, 200, "OK", getFileType("*.html"), 0);
				send_file(ev->data.fd,"dir_header.html", ev, epfd,0);
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
					send(ev->data.fd,buf,len ,0);
					free(mylist[i]);
				}
				free(mylist);
				send_file(ev->data.fd, "dir_tail.html", ev, epfd, 1);
			}
		}
	}
}









int main(int argc, char const* argv[])
{
	signal(SIGPIPE, SIG_IGN);
	//切换工作目录
	//获取当前目录的工作路径
	char pwd_path[256] = "";
	char *path = getenv("PWD");
	//如果程序中修改了目录，再调用 getenv("PWD")，它可能还会返回旧的工作目录
	//（除非你的程序自己更新了 "PWD" 环境变量）。而如果你调用 getcwd()，它会返回正确的新工作目录 
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
	struct epoll_event ev,evs[1024];
	ev.data.fd = lfd;
	ev.events = EPOLLIN;
	epoll_ctl(epfd, EPOLL_CTL_ADD, lfd, &ev);
	//循环监听
	while (1)
	{
		int nready =  epoll_wait(epfd, evs, 1024, -1);
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
						read_client_request( epfd ,&evs[i],pwd_path);
					}
			}
		}
	}
	return 0;
}




//send_file 函数在一个循环中连续读取和发送文件内容。这里使用的是 send 系统调用，
//这是一个同步（或者说阻塞）操作。如果内核输出缓冲区已满，这个调用将会阻塞，
//直到有足够的空间来存储新的数据。然而，你的 socket 是被设置为非阻塞的，所以如果内核缓冲区满了，send 会立即返回一个错误。
//
//你的 send_file 函数没有处理这种情况，所以当 send 返回错误时，你就看到了 
//"send file failed: Resource temporarily unavailable" 的错误消息。
//
//你可以采取以下两种方式之一来解决这个问题：
//
//改为阻塞模式：你可以在发送文件内容之前把 socket 重新设置为阻塞模式，然后在发送完文件后再把它设置回非阻塞模式。
//
//正确处理非阻塞 send：你可以改进你的 send_file 函数，让它能够正确处理非阻塞 send。
//如果 send 返回一个错误并且错误是 EAGAIN 或 EWOULDBLOCK，你可以暂停发送数据，
//然后等待 socket 可写事件（EPOLLOUT）再继续发送。这种做法可能需要把未发送的数据和文件描述符存储在某处，然后在 socket 可写时再继续发送。
//
//
//
//
//这个错误是由于你的 HTTP 服务器在尝试向客户端发送数据时，出现了 "Resource temporarily unavailable" 错误。
//这通常意味着你的进程尝试进行了一个会被阻塞的系统调用，但是这个系统调用由于某种原因无法立即完成。在你的代码中，这个系统调用是 send，它用于将数据从服务器发送到客户端。
//
//这个错误通常发生在下列情况：
//
//在非阻塞模式下，如果调用 send 函数并且内核的输出缓冲区已满，那么 send 函数会返回错误，并设置错误码为 EAGAIN 或 EWOULDBLOCK。这种情况下，你应该稍后再次尝试发送数据。
//
//在阻塞模式下，如果 send 函数在完成之前被信号中断，那么 send 函数也会返回错误，并设置错误码为 EINTR。这种情况下，你可以立即再次尝试发送数据。
//
//你的服务器在发送大量数据（如文件内容）时，可能会遇到上述的第一种情况。为了解决这个问题，你可以改进你的 send_file 函数，
//让它能够正确处理非阻塞 send。具体来说，如果 send 返回一个错误并且错误是 EAGAIN 或 EWOULDBLOCK，那么你应该暂停发送数据，等待 socket 可写（EPOLLOUT）再继续发送。
//
//这个错误通常在你打印的最后一行出现，这可能是因为这是你在大量数据发送后首次遇到输出缓冲区已满的情况，也可能是因为 send 函数在发送最后一部分数据时遇到了错误。



//你的代码在发送文件时没有处理可能发生的“资源暂时不可用（EAGAIN 或 EWOULDBLOCK）”的错误情况，这是因为网络缓冲区已满。当你尝试发送一个较大的文件时，很可能会遇到这种情况。
//当 send() 函数无法立即发送所有数据时，它可能会发送部分数据并返回已发送数据的数量。你的代码没有检查这种可能性，所以当 send() 函数只发送了部分数据时，剩余的数据就会丢失。
//
//解决这个问题的方法是修改 send_file 函数，使其能够在 send() 函数只发送部分数据时正确处理。具体来说，如果 send() 函数返回的值小于你尝试发送的数据量，
//那么你需要将剩余的数据保存下来，然后在稍后再次尝试发送。
//
//此外，你需要设置 socket 为非阻塞模式，并在 epoll 中注册 EPOLLOUT 事件。这样，当 socket 可以发送更多数据时，你就可以收到一个通知。
//
//还需要注意，你的代码在读取和发送文件时使用了同一个缓冲区。这可能会导致在尝试发送剩余数据时覆盖了部分数据。
//你应该使用两个独立的缓冲区：一个用于读取文件，另一个用于存储尚未发送的数据。
//
//最后，你的代码在处理 HTTP 请求时没有正确处理分块传输编码（Chunked transfer encoding）。
//这是 HTTP / 1.1 中的一种功能，允许服务器在开始发送响应之前不需要知道响应的总长度。这对于发送大文件或生成内容需要很长时间的响应非常有用。
//你应该检查 HTTP 请求的 "Transfer-Encoding" 头部，如果它的值是 "chunked"，那么你需要使用分块传输编码来发送响应。



//如果使用 libevent，你会使用事件回调和缓冲事件（bufferevent）来读写数据，这意味着 libevent 会帮你处理网络缓冲区满的情况，
//你不需要直接处理 send() 和 recv() 系统调用。一旦你添加了数据到 libevent 的输出缓冲区，libevent 就会处理实际的发送操作，包括处理部分写入的情况。
//
//此外，libevent 支持非阻塞 IO 和水平触发（level - triggered）模式，所以你不需要手动重新尝试读写操作。
//
//然而，即使使用了 libevent，你仍然需要处理 HTTP 分块传输编码的问题。libevent 不包含 HTTP 协议的具体处理，你需要自己解析 HTTP 请求和响应，包括处理分块传输编码。