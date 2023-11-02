#include "wrap.h"



void perr_exit(const char* s)
{
	perror(s);
	exit(1);
}



int Accept(int fd, struct sockaddr* sa, socklen_t* salenptr)
{
	int n;
again:
	if ((n = accept(fd, sa, salenptr))	< 0) 
	{
		if ((errno == ECONNABORTED) || (errno == EINTR))
			goto again;
		else
			perr_exit("accept error");
	}
	return n;
}



const char* getFileType(const char* name)
{
	// a.jpg a.mp4 a.html
	// 自右向左查找‘.’字符, 如不存在返回NULL
	const char* dot = strrchr(name, '.');
	if (dot == NULL)
		return "text/plain; charset=utf-8";	// 纯文本
	if (strcmp(dot, ".html") == 0 || strcmp(dot, ".htm") == 0)
		return "text/html; charset=utf-8";
	if (strcmp(dot, ".jpg") == 0 || strcmp(dot, ".jpeg") == 0)
		return "image/jpeg";
	if (strcmp(dot, ".gif") == 0)
		return "image/gif";
	if (strcmp(dot, ".png") == 0)
		return "image/png";
	if (strcmp(dot, ".css") == 0)
		return "text/css";
	if (strcmp(dot, ".au") == 0)
		return "audio/basic";
	if (strcmp(dot, ".wav") == 0)
		return "audio/wav";
	if (strcmp(dot, ".avi") == 0)
		return "video/x-msvideo";
	if (strcmp(dot, ".mov") == 0 || strcmp(dot, ".qt") == 0)
		return "video/quicktime";
	if (strcmp(dot, ".mpeg") == 0 || strcmp(dot, ".mpe") == 0)
		return "video/mpeg";
	if (strcmp(dot, ".vrml") == 0 || strcmp(dot, ".wrl") == 0)
		return "model/vrml";
	if (strcmp(dot, ".midi") == 0 || strcmp(dot, ".mid") == 0)
		return "audio/midi";
	if (strcmp(dot, ".mp3") == 0)
		return "audio/mpeg";
	if (strcmp(dot, ".ogg") == 0)
		return "application/ogg";
	if (strcmp(dot, ".pac") == 0)
		return "application/x-ns-proxy-autoconfig";

	return "text/plain; charset=utf-8";
}



void decodeMsg(char* to, char* from)
{
	for (; *from != '\0'; ++to, ++from)
	{
		if (from[0] == '%' && isxdigit(from[1]) && isxdigit(from[2]))
		{
			*to = hexit(from[1]) * 16 + hexit(from[2]);

			from += 2;
		}
		else
		{
			*to = *from;
		}
	}
	*to = '\0';
}


int hexit(char c)
{
	if (c >= '0' && c <= '9')
		return c - '0';
	if (c >= 'a' && c <= 'f')
		return c - 'a' + 10;
	if (c >= 'A' && c <= 'F')
		return c - 'A' + 10;
	return 0;
}



int tcp4bind(short port, const char* IP)
{
	struct sockaddr_in serv_addr;
	int lfd = Socket(AF_INET, SOCK_STREAM, 0);
	// 设置端口复用
	int opt = 1;
	setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	memset(&serv_addr, 0, sizeof(serv_addr));
	if (IP == NULL)
	{
		//如果这样使用0.0.0.0,任意ip将可以连接
		serv_addr.sin_addr.s_addr = INADDR_ANY;
	}
	else 
	{
		if (inet_pton(AF_INET, IP, &serv_addr.sin_addr.s_addr) <= 0) 
			//使用inet_pton函数将IP参数的字符串形式转换为网络字节序的IPv4地址，并将结果存储在s_addr成员变量中
		{
			perror(IP);//转换失败
			exit(1);
		}
	}
	serv_addr.sin_port = htons(port);
	//将传入的port参数由主机字节序转换为网络字节序，并将结果存储在sin_port成员变量中。	
	serv_addr.sin_addr.s_addr = INADDR_ANY;


	if (bind(lfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	return lfd;
}

int Listen(int fd, int backlog)
{
	int n;
	if ((n = listen(fd, backlog))< 0)
		perr_exit("listen error");
	return n;
}


int Socket(int family, int type, int protocol)
{
	int n;
	if ((n = socket(family, type, protocol))< 0)
		perr_exit("socket error");
	return n;
}






/*这个函数在读取时可能会被中断（比如因为接收到了一个信号），所以它使用了goto语句在被中断时重新尝试读取。
虽然在许多情况下使用goto是不推荐的，但在处理错误和中断的时候，使用goto可以使代码更加清晰*/ 
ssize_t my_read(int fd, char* ptr)
{
	static int read_cnt;
	static char* read_ptr;
	static char read_buf[100];
	if (read_cnt <= 0)
	{
	again:
		if ((read_cnt = read(fd, read_buf, sizeof(read_buf)))< 0) 
		{
			if (errno == EINTR)

	/*			errno是一个全局变量，用于在C和C++中报告错误。当你调用一些可能会失败的函数（比如read）时，
				如果发生错误，这些函数通常会设置errno的值来指示具体的错误类型。
				EINTR是errno的一个可能值，代表了“Interrupted system call”（被中断的系统调用）。
				当你的程序正在执行一个系统调用（比如read）时，如果接收到一个可以被捕获的信号，
				那么系统调用可能会被中断，而不是正常完成。当这种情况发生时，系统调用会返回 - 1，并且设置errno为EINTR。*/
			goto again;
			return -1;
		}
		else if (read_cnt == 0)
			return 0;
		read_ptr = read_buf;
	}
	read_cnt--;
	*ptr = *read_ptr++;
	return 1;
}
//从文件描述符fd中读取一行数据，直到遇到换行符\n或读取到的字符数达到maxlen为止。
//这个函数会将读取到的数据存储到vptr指向的内存空间中，并在结束时添加一个空字符作为结束标志。
ssize_t Readline(int fd, void* vptr, size_t maxlen)
{
	ssize_t n, rc;
	char c, * ptr;
	ptr = vptr;
	for (n = 1; n < maxlen; n++) 
	{
		if ((rc = my_read(fd, &c))== 1) 
		{
			*ptr++ = c;
			if (c == '\n')
			break;
		}
		else if (rc == 0) 
		{
			*ptr = 0;
			return n - 1;
		}
		else
			return -1;
	}
	*ptr = 0;
	return n;
}