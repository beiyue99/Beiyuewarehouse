#include <event2/event.h>
#include <unistd.h>

void cb_func(evutil_socket_t fd, short what, void* arg)
{
    char buf[1024];
   /* while (fgets(buf, sizeof(buf), stdin) != NULL) {
        // 处理读取到的数据
        printf("read from stdin : %s\n", buf);
    }*/
    fgets( buf, sizeof(buf), stdin);
    printf("read from stdin : %s\n", buf);
    //如果标准输入(stdin)没有数据，fgets() 函数会阻塞，直到有数据可供读取或者用户关闭了输入
    //注意这里，如果去掉while循环，那么没有处理标准输入的数据，会一直循环打印第二个printf语句
    //加上循环后，fgets函数阻塞了，不会打印第二个printf循环。除非用read函数，并且设置为非阻塞

    const char* data = arg;
    printf("Got an event on socket %d:%s%s%s%s [%s]\n",
        (int)fd,
        (what & EV_TIMEOUT) ? " timeout" : "", //如果 what 中的 EV_TIMEOUT 位被设置，那么 what & EV_TIMEOUT 的结果就不为0
        (what & EV_READ) ? " read" : "",
        (what & EV_WRITE) ? " write" : "",
        (what & EV_SIGNAL) ? " signal" : "",
        data);
}

int main()
{
    struct event_base* base = event_base_new();


    evutil_socket_t fd = STDIN_FILENO;
    //在不同的平台和系统上，evutil_socket_t可能表示不同的类型。
    //在一些系统上，它可能是一个整数类型（如Unix系统中的文件描述符），
    //而在一些系统上，它可能是一个指针或句柄类型（如Windows中的SOCKET类型）。
    //使用evutil_socket_t代替直接使用平台特定的类型，可以使得代码更具有可移植性。
/* 我们正在监听的事件类型是：可读事件，并且是持久事件 */
    short what = EV_READ | EV_PERSIST;

    /* 设置一个回调函数 */
    event_callback_fn cb = cb_func;

    /* 创建一个新的事件 */
    struct event* ev = event_new(base, fd, what, cb, "User Argument");

    /* 添加事件到事件循环 */
    event_add(ev, NULL);

    /* 开始事件循环 */
    event_base_dispatch(base);

    /* 清理 */
    event_free(ev);
    event_base_free(base);

    return 0;
}
