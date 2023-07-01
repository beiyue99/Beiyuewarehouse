#include <stdio.h>
#include <unistd.h>
#include <event.h>
#include "wrap.h"
#include <string.h>

#define MAX_FD 1024

struct event* events[MAX_FD];

void cfdcb(int cfd, short event, void* arg) 
{
    char buf[1500] = "";
    struct event* ev = events[cfd];
    int n = Read(cfd, buf, sizeof(buf));
    if (n <= 0) 
    {
        if (n < 0) 
        {
            perror("Read error");
        }
        else 
        {
            printf("Client closed connection\n");
        }
        close(cfd); // 关闭客户端连接
        event_del(ev); // 删除事件
        event_free(ev); // 释放事件
        events[cfd] = NULL;
        return; // 退出回调函数
    }
    else 
    {
        printf("recive from client:%s\n", buf);
        int ret = Write(cfd, buf, n); // 假设这是一个 echo 服务器，将接收到的内容回传给客户端
        if (ret < 0)
        {
            printf("Write error: %s\n", strerror(-ret)); // 注意这里用 -ret 来获取错误码
            close(cfd); // 关闭客户端连接
            event_del(ev); // 删除事件
            event_free(ev); // 释放事件
            events[cfd] = NULL;
            return; // 退出回调函数
        }

    }
}

void lfdcb(int lfd, short event, void* arg)
{
    struct event_base* base = (struct event_base*)arg;

    // 提取新的cfd
    int cfd = Accept(lfd, NULL, NULL);
    if (cfd < 0)
    {
        perror("Accept error");
        return;
    }
    printf("cfd is %d\n", cfd);
    // 将cfd上树
    struct event* ev = event_new(base, cfd, EV_READ | EV_PERSIST, cfdcb, NULL);

    if (!ev) 
    {
        perror("Could not create event for cfd");
        close(cfd); // 关闭客户端连接
        return;
    }
    events[cfd] = ev;
    event_add(ev, NULL);
}

int main(int argc, char* argv[])
{
    // 创建套接字并绑定
    int lfd = tcp4bind(8888, NULL);
    if (lfd < 0) 
    {
        perror("tcp4bind error");
        return 1;
    }
    printf("lfd is %d", lfd);
    if (Listen(lfd, SOMAXCONN)<0)
    {
        perror("Listen error");
        return 1;
    }
    // 创建 event base 根节点
    struct event_base* base = event_base_new();
    if (!base)
    {
        perror("Could not create event base");
        close(lfd);
        return 1;
    }

    // 初始化 lfd 上树节点
    struct event* ev = event_new(base, lfd, EV_READ | EV_PERSIST, lfdcb, base);
//lfd, EV_READ | EV_PERSIST 和 base是在调用event_new时传入的参数，然后lfd和base分别会作为回调函数lfdcb的第一个参数和第三个参数。
//而回调函数的第二个参数event则会由Libevent库根据具体被触发的事件类型来设置。
    if (!ev)
    {
        perror("Could not create event for lfd");
        close(lfd);
        event_base_free(base);
        return 1;
    }

    // 上树
    event_add(ev, NULL);

    // 循环监听
    event_base_dispatch(base); // 阻塞

    // 收尾
    for (int i = 0; i < MAX_FD; i++) 
    {
        if (events[i]) 
        {
            event_free(events[i]);
            events[i] = NULL;
        }
    }
    close(lfd);
    event_base_free(base);

    return 0;
}


