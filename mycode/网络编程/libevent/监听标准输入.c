#include <event2/event.h>
#include <unistd.h>

void cb_func(evutil_socket_t fd, short what, void* arg)
{
    char buf[1024];
    while (fgets(buf, sizeof(buf), stdin) != NULL) {
        // �����ȡ��������
        printf("read from stdin : %s\n", buf);
    }
    //ע��������ȥ��whileѭ������ôû�д����׼��������ݣ���һֱѭ����ӡ�ڶ���printf���
    //����ѭ����fgets���������ˣ������ӡ�ڶ���printfѭ����������read��������������Ϊ������

    const char* data = arg;
    printf("Got an event on socket %d:%s%s%s%s [%s]\n",
        (int)fd,
        (what & EV_TIMEOUT) ? " timeout" : "", //��� what �е� EV_TIMEOUT λ�����ã���ô what & EV_TIMEOUT �Ľ���Ͳ�Ϊ0
        (what & EV_READ) ? " read" : "",
        (what & EV_WRITE) ? " write" : "",
        (what & EV_SIGNAL) ? " signal" : "",
        data);
}

int main()
{
    struct event_base* base = event_base_new();


    /* �������ڼ������ļ��������Ǳ�׼���� */
    evutil_socket_t fd = STDIN_FILENO;
    //�ڲ�ͬ��ƽ̨��ϵͳ�ϣ�evutil_socket_t���ܱ�ʾ��ͬ�����͡�
    //��һЩϵͳ�ϣ���������һ���������ͣ���Unixϵͳ�е��ļ�����������
    //����һЩϵͳ�ϣ���������һ��ָ��������ͣ���Windows�е�SOCKET���ͣ���
    //ʹ��evutil_socket_t����ֱ��ʹ��ƽ̨�ض������ͣ�����ʹ�ô�������п���ֲ�ԡ�
/* �������ڼ������¼������ǣ��ɶ��¼��������ǳ־��¼� */
    short what = EV_READ | EV_PERSIST;

    /* ����һ���ص����� */
    event_callback_fn cb = cb_func;

    /* ����һ���µ��¼� */
    struct event* ev = event_new(base, fd, what, cb, "User Argument");

    /* ����¼����¼�ѭ�� */
    event_add(ev, NULL);

    /* ��ʼ�¼�ѭ�� */
    event_base_dispatch(base);

    /* ���� */
    event_free(ev);
    event_base_free(base);

    return 0;
}
