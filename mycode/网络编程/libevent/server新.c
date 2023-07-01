#include <event2/event.h>
#include <event2/bufferevent.h>
#include <sys/socket.h>
#include <string.h>

void echo_read_cb(struct bufferevent* bev, void* ctx) {
    /* This callback is invoked when there is data to read on bev. */
    struct evbuffer* input = bufferevent_get_input(bev);   //��ȡ���뻺����
    struct evbuffer* output = bufferevent_get_output(bev);//��ȡ���������

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
    struct sockaddr_storage ss;  //��������socket���͵Ľṹ��
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


//Ϊʲô�����ȵ�һ�κã�  ��һ��Ϊʲôû������ȫ��events�����¼��أ�������ô�ͷŵģ�
//��Դ�����ڶ��δ���ʹ��ȫ�� events �������洢ÿ���ͻ��˵� event�������ڿͻ��˶Ͽ�����ʱ�����Է�����ҵ����ͷŶ�Ӧ�� event��
//����һ�δ��벢û�����Եĵط����洢�͹�����Щ event��������ĳЩ����������Դй©��
//
//������ĵڶ������⣬��һ�δ����У�event ���� bufferevent �д����͹���ġ��� bufferevent ���� EOF ���ߴ����ͷ�ʱ
//���� echo_event_cb �����е��� bufferevent_free����������ص� event Ҳ�ᱻ�Զ��ͷš�
//
//Ȼ������ʹ��ˣ��ڶ��δ�����ʹ��ȫ�� events ������� event �ķ�ʽ���������ŵ�ġ���ʹ���¼����������ڸ��������Ϳɿأ�
//���Ա����ڸ�������¿��ܳ��ֵ���Դй©�����⣬������������Ҫʱ�ṩ�����л event �ķ��ʣ������ڷ������ر�ʱ��Ҫ�ͷ����е� event��