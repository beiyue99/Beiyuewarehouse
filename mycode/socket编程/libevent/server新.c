#include <event2/event.h>
#include <event2/bufferevent.h>
#include <sys/socket.h>
#include <string.h>

void echo_read_cb(struct bufferevent* bev, void* ctx) {
    /* This callback is invoked when there is data to read on bev. */
    struct evbuffer* input = bufferevent_get_input(bev);   //获取输入缓冲区
    struct evbuffer* output = bufferevent_get_output(bev);//获取输出缓冲区

    /* Copy all the data from the input buffer to the output buffer. */
    evbuffer_add_buffer(output, input);
}

void echo_event_cb(struct bufferevent* bev, short events, void* ctx) {
    if (events & BEV_EVENT_ERROR)
        perror("Error from bufferevent");
    if (events & (BEV_EVENT_EOF | BEV_EVENT_ERROR)) {
        bufferevent_free(bev);
    }
}

void accept_conn_cb(evutil_socket_t listener, short event, void* arg) {
    struct event_base* base = arg;
    struct sockaddr_storage ss;  //储存任意socket类型的结构体
    socklen_t slen = sizeof(ss);
    int fd = accept(listener, (struct sockaddr*)&ss, &slen);
    if (fd < 0) {
        perror("accept");
    }
    else
    {
        struct bufferevent* bev = bufferevent_socket_new(base, fd, BEV_OPT_CLOSE_ON_FREE);
        bufferevent_setcb(bev, echo_read_cb, NULL, echo_event_cb, NULL);
        bufferevent_enable(bev, EV_READ | EV_WRITE);
    }
}

int main(int argc, char** argv) {
    struct event_base* base;
    base = event_base_new();
    if (!base) {
        puts("Couldn't open event base");
        return 1;
    }
    evutil_socket_t listener;
    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = htonl(0);
    sin.sin_port = htons(8888);
    listener = socket(AF_INET, SOCK_STREAM, 0);
    bind(listener, (struct sockaddr*)&sin, sizeof(sin));
    listen(listener, 16);




    struct event* listener_event;
    listener_event = event_new(base, listener, EV_READ | EV_PERSIST, accept_conn_cb, base);
    event_add(listener_event, NULL);

    event_base_dispatch(base);

    return 0;
}


//为什么质量比第一段好？  第一段为什么没有引入全局events储存事件呢？他是怎么释放的？
//资源管理：第二段代码使用全局 events 数组来存储每个客户端的 event，这样在客户端断开连接时，可以方便地找到和释放对应的 event。
//而第一段代码并没有明显的地方来存储和管理这些 event，可能在某些情况下造成资源泄漏。
//
//至于你的第二个问题，第一段代码中，event 是在 bufferevent 中创建和管理的。当 bufferevent 由于 EOF 或者错误被释放时
//（在 echo_event_cb 函数中调用 bufferevent_free），与其相关的 event 也会被自动释放。
//
//然而，即使如此，第二段代码中使用全局 events 数组管理 event 的方式还是有其优点的。它使得事件的生命周期更加清晰和可控，
//可以避免在复杂情况下可能出现的资源泄漏。另外，它还可以在需要时提供对所有活动 event 的访问，比如在服务器关闭时需要释放所有的 event。