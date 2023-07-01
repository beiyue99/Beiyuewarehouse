
//evutil_socket_t ���������Ϊ - 1 ͨ����ʾ�㲻��������¼����κ��ض����ļ�����������Unix - likeϵͳ��
//���׽��֣���Windows����������һЩ����£������ֻ���ĳ�ʱ�����źţ������Ǿ���Ķ� / д�¼���
//
//�ٸ����ӣ������������һ����ʱ�¼�������ܻ�������
//�¼�ev�����κ��ļ����������׽��ֹ��������evutil_socket_t������Ϊ - 1��
//����¼��Ļص�����cb_func����ÿ��1��ʱ�����á�

#include <event2/event.h>
#include <sys/time.h>

void cb_func(evutil_socket_t fd, short what, void* arg) {
    printf("cb_func is call back!\n");
}

int main() {
    struct event_base* base = event_base_new();

    struct event* ev = event_new(base, -1, EV_PERSIST, cb_func, NULL);

    struct timeval one_sec = {1, 0};    
    //evutil_timerclear(&one_sec);  //���Ϊ0

    if (event_add(ev, &one_sec) != 0)
    {
        puts("Couldn't add event");
        return 1;
    }
    event_base_dispatch(base);

    event_free(ev);
    event_base_free(base);
    return 0;
}

//struct timeval {
//    long    tv_sec;
//    long    tv_usec;
//};