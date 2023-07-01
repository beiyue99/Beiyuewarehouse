#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#define _EVENT_SIZE_ 1024
// server
int main(int argc, const char* argv[])
{
    // 创建监听的套接字
    int lfd = socket(AF_INET, SOCK_STREAM, 0);
    if (lfd == -1)
    {
        perror("socket error");
        exit(1);
    }

    // 绑定
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(9999);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);  

    // 设置端口复用
    int opt = 1;
    setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // 绑定端口
    int ret = bind(lfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if (ret == -1)
    {
        perror("bind error");
        exit(1);
    }

    // 监听
    ret = listen(lfd, 64);
    if (ret == -1)
    {
        perror("listen error");
        exit(1);
    }

    // 创建一个epoll模型
    int epfd = epoll_create(100);
    if (epfd == -1)
    {
        perror("epoll_create");
        exit(0);
    }

    // 往epoll实例中添加需要检测的节点, 现在只有监听的文件描述符
    struct epoll_event ev;
    ev.events = EPOLLIN;  
    // 在 epoll 模型中指定要监视的文件描述符的事件。在这种情况下，它表示当文件描述符中有可读数据时，触发 epoll 事件
    ev.data.fd = lfd;
    ret = epoll_ctl(epfd, EPOLL_CTL_ADD, lfd, &ev);
    if (ret == -1)
    {
        perror("epoll_ctl");
        exit(0);
    }

    struct epoll_event evs[_EVENT_SIZE_];
    int size = sizeof(evs) / sizeof(struct epoll_event);
    // 持续检测
    while (1)
    {
        // 调用一次, 检测一次
        int num = epoll_wait(epfd, evs, size, -1);
        for (int i = 0; i < num; ++i)
        {
            // 取出当前的文件描述符
            int curfd = evs[i].data.fd;
            // 判断这个文件描述符是不是用于监听的
            if (curfd == lfd)
            {
                // 建立新的连接
                int cfd = accept(curfd, NULL, NULL);
                ev.events = EPOLLIN;     //加上EPOLLET  表示边缘触发  然后需要设置非阻塞属性
                ev.data.fd = cfd;
                ret = epoll_ctl(epfd, EPOLL_CTL_ADD, cfd, &ev);
                if (ret == -1)
                {
                    perror("epoll_ctl-accept");
                    exit(0);
                }
            }
            else
            {
                // 处理通信的文件描述符
                // 接收数据
                char buf[1024];
                memset(buf, 0, sizeof(buf));
                int len = recv(curfd, buf, sizeof(buf), 0);
                if (len == 0)
                {
                    printf("The client has disconnected!\n");
                    // 将这个文件描述符从epoll模型中删除
                    epoll_ctl(epfd, EPOLL_CTL_DEL, curfd, NULL);
                    close(curfd);
                }
                else if (len > 0)
                {
                    //STDOUT_FILENO: 将数据直接写入标准输出就是将数据输出到终端（通常是命令行界面）
                    // write(STDOUT_FILENO,buf,1en);   发送到当前终端，代替下面这行代码
                    printf("client say: %s\n", buf);
          /*        如果 buf 的最后一个字符不是空字符(\0)，则在使用 printf 函数输出时可能会导致乱码或意外的结果。
                    使用 write 函数直接输出 buf 的内容，不依赖字符串的结尾空字符。因此，即使最后一个字符不是空字符，
                    也不会出现乱码，write 函数会按照指定的长度输出。
                    printf 函数是通过寻找字符串的结尾空字符(\0) 来确定字符串的结束位置的。如果 buf 的最后一个字符不是空字符，
                    则 printf 函数会继续读取内存中的其他数据，直到遇到第一个空字符为止，这可能导致乱码或意外的输出结果。
                    为了避免出现乱码或意外结果，确保 buf 是以空字符结尾的字符串或者明确指定要输出的字节数。*/

                    send(curfd, buf, len, 0);
                    //如果一次读五个，一次读不完的情况下，会打印乱码，以下是解决方案
                    // send(fd, buf, strlen(buf) + 1, 0);
                    //strlen(buf) + 1 的值通常用于确保完整发送包括字符串结尾的空字符（'\0'）。
                    //如果要发送的数据不是以空字符结尾的字符串，而只是普通的字节数据，则不需要在第三个参数中加一，直接使用数据的长度即可。
                }
                else
                {
                    perror("recv");
                    exit(0);
                }
            }
        }
    }

    return 0;
}


