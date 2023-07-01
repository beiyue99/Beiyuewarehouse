

struct event_base*  event_base_new(void);
����������һ���µ�event_base��




struct event* event_new(struct event_base* base, evutil_socket_t fd, short what, event_callback_fn cb, void* arg);


evutil_socket_t fd : ��Ҫ�������ļ��������������Ϊ�˲������� - 1����ʾ���¼��������κ��ļ�������
short what : �¼����ͣ����������µ�һ�����߶����ʹ�� | �����������ϣ�
EV_READ�������ɶ��¼�����
EV_WRITE��������д�¼�����
EV_PERSIST���־��¼����¼��������Զ�ɾ������
EV_ET����Ե����ģʽ����
EV_TIMEOUT����ʱ���¼�����
EV_SIGNAL���ź��¼�����
event_callback_fn cb : �¼��ص����������¼�����ʱ���˺����������á�
void* arg : �û����������ݸ��ص�������
��������᷵��һ���´������¼��������ʹ�� event_add() ������ӵ��¼�ѭ����:
int event_add(struct event* ev, const struct timeval* timeout);

const struct timeval* timeout : ����һ����ѡ�ĳ�ʱ��������������ΪNULL������ṩ��һ��timeval�ṹ�壬
��ô�¼�����û�м��������µȴ���ô����ʱ�䣬Ȼ��ͳ�ʱ���������ΪNULL����ô�¼����ȴ�ֱ�������





int event_base_dispatch(struct event_base* base);


�����������ȴ��¼�������һ�����¼����������� socket �ɶ�����д�����߶�ʱ����ʱ�ȣ���
���ͻ������Ӧ�Ļص���������������¼��������е��¼����������
event_base_dispatch() �������ٴ��������ȴ��µ��¼������ѭ����һֱ������
ֱ��û�и���Ļ�¼�������ֱ������ event_base_loopbreak() �� event_base_loopexit() ������


��������ɹ�����������е��¼�ѭ������ô���� 0��
���û���κ���ע����¼�����ô���� 1��
�����Ϊĳ�ִ��󣨱����ṩ��һ����Ч�� event_base�������ܿ�ʼ�¼�ѭ������ô���� - 1��
����¼�ѭ���� event_base_loopbreak() ��ϣ���ô���� - 1��
����¼�ѭ���� event_base_loopexit() ���õĳ�ʱ��������ô���� 0��



















�ȴ��¼����� - ѭ���ȴ�event_loop
Libevent�ڵػ����֮����Ҫ�ȴ��¼��Ĳ�����Ҳ���ǵȴ���Ҫ�ȴ����¼��ļ����ô�������˳�������epoll��˵��
������Ҫ�Լ�����ѭ��������libevent��Ҳ�������ṩ��api�ӿڣ�����where(1)�Ĺ���.�������£�



int event_base_loop(struct event_base* base, int flags);
flags��ȡֵ��
#define EVLOOP_ONCE	0x01    ֻ����һ�Σ�����¼�û�б������������ȴ�
#define EVLOOP_NONBLOCK	0x02    ��������ʽ����¼��Ƿ񱻴����������¼�������񣬶�����������



����������Ƕ�����libevent�������ṩ������һ��api��
int event_base_dispatch(struct event_base* base);
���øú������൱��û�����ñ�־λ��event_base_loop�����򽫻�һֱ���У�ֱ��û����Ҫ�����¼��ˣ����߱�����ѭ����api��ֹ��



int event_base_loopexit(struct event_base* base, const struct timeval* tv);
�˺������ڰ����¼�ѭ����һ��ʱ����˳��������ͨ���趨struct timeval* tvָ����ʱ���������¼�ѭ����ʱ�˳�����������õ�ʱ����0��
��ô�¼�ѭ�����ڴ����굱ǰ���л�¼��������˳�������ζ���¼�ѭ�������ڴ����굱ǰ���л�¼��󣬲��ٵȴ����¼��ĳ��֣������˳���



int event_base_loopbreak(struct event_base* base);
�˺������������ж��¼�ѭ���������Ƿ��л�¼�δ����һ�����ô˺������¼�ѭ�����ڵ�ǰ������¼���ɺ�����ֹͣ��
��ʹ������������¼��ڵȴ����������ǰû���¼��ڴ����¼�ѭ��������������




��libevent�У���������ò�ͬ���͵��¼������������ݲ�ͬ���¼�������������ͬ�Ļص���������Щ�¼����Ͱ�����

EV_TIMEOUT : ��ʱ�¼���������������¼����ͣ��¼�����������ָ����ʱ��󱻴�����

EV_READ : ���¼������ļ���������ͨ����һ���׽��֣�׼���ö�ȡ����ʱ���¼��������ᱻ������

EV_WRITE : д�¼������ļ���������ͨ����һ���׽��֣�׼����д������ʱ���¼��������ᱻ������

EV_SIGNAL : �ź��¼����������յ�һ���ض���ϵͳ�ź�ʱ���¼��������ᱻ������

EV_PERSIST : �����Դ�����ͨ����һ���¼��������ڱ�������ͻᱻ�Զ��Ƴ���������������������־��
�¼�����������ÿ�α������󱣳ֻ״̬��ֱ����ȷ�ر��Ƴ���

EV_ET : ��Ե����������һ�ָ��߼����¼�����ģʽ����ĳЩ����£��������ṩ��Ĭ�ϵ�ˮƽ����ģʽ���ߵ����ܡ�
�ڱ�Ե����ģʽ�£�ֻ���ļ���������״̬�����ı�ʱ���¼��������Żᱻ��������������ģʽ��Ҫ�����ӵı�̼�����
��Ϊ�����ȷ����ÿ���¼�������������ʱ�����������еĿ������ݡ�

��Щ�����ͨ��λ��������������������һ���¼��������Ķ������ԡ�
���磬�����ʹ��EV_READ | EV_PERSIST������һ���־õĶ��¼���������������ÿ���ļ�������׼���ö�ȡ����ʱ��������






�� / д�¼�����: ʹ��bufferevent�����Զ������ / д�¼���ʹ�ÿ����������ֶ������ײ��socket read / write��c

���� / ������� : bufferevent�ڲ��ṩ������ / �����������ʹ�����ݵĶ�ȡ��д����ӷ��㡣

ˮλ�߹��� : bufferevent�������ö� / д��ˮλ�ߣ�ˮλ�������� / ��������������ݵĴ�С���ƣ����ڴﵽ�����ĳһ�ض�ˮλ��ʱ���Դ����ص�������

���ӽ��� / ������ : bufferevent���������ڼ������ӽ������߳���ʱ���¼������ṩ��Ӧ�Ļص�����






struct bufferevent* bufferevent_socket_new(struct event_base* base, evutil_socket_t fd, enum bufferevent_options options);

base���¼��Ļ����ṹ����������ṹ������ĳ���ʼʱ�����ģ�ͨ�����������߳��д����ġ�

fd��һ���׽������������������Ϊ - 1��libevent ������Ҫ��ʱ�򴴽�һ���µ��׽��֡�

options������һ����־���������Խ������¼���ѡ�BEV_OPT_CLOSE_ON_FREE��BEV_OPT_DEFER_CALLBACKS��BEV_OPT_UNLOCK_CALLBACKS��
���У�BEV_OPT_CLOSE_ON_FREE ��ʾ�� bufferevent ���ͷ�ʱ�ر���ײ���׽��֣�
BEV_OPT_DEFER_CALLBACKS ��ʾ�ӳٻص���ִ�У�BEV_OPT_UNLOCK_CALLBACKS ��ʾ��ִ�лص�ʱ������ bufferevent��






void bufferevent_setcb(struct bufferevent* bufev,
    bufferevent_data_cb readcb,
    bufferevent_data_cb writecb,
    bufferevent_event_cb eventcb,
    void* cbarg);


readcb�����Ƕ�ȡ�����Ļص���������bufferevent�����뻺�����е����������ȡ��������ﵽ��ˮλ�ߣ�ʱ������ص������ᱻ���á�

writecb������д������Ļص���������bufferevent������������е���������д������������ڵ�ˮλ�ߣ�ʱ������ص������ᱻ���á�

eventcb������һЩ�����¼��Ļص���������������ӶϿ�����ʱ�ȡ�

cbarg�������û�����Ĳ����������ڵ��������Ļص�����ʱ��Ϊ�������롣





void bufferevent_setwatermark(struct bufferevent* bufev,
    short events,
    size_t lowmark,
    size_t highmark);


bufev������Ҫ����ˮλ�ߵ�bufferevent��

events����ʾҪ���������¼���ˮλ�ߣ�ȡֵ������EV_READ��EV_WRITE��Ҳ�������߶����ã�EV_READ | EV_WRITE����

lowmark����ʾ��ˮλ�ߵĴ�С�������� / ��������������������ڻ�������ֵʱ���� / д�ص������ᱻ������

highmark����ʾ��ˮλ�ߵĴ�С�����ڶ������������뻺�������������������ֵʱ���Ͳ��ٶ�ȡ��������ݣ�����д������
ֻ�е������������������С�����ֵʱ���Żᴥ��д�ص�����������㽫highmark����Ϊ0����ô�ͱ�ʾ��ˮλ�������޵ġ�



















struct event_base* base;
base = event_base_new();
struct bufferevent* bev;

// ����һ���µ�bufferevent
bev = bufferevent_socket_new(base, -1, BEV_OPT_CLOSE_ON_FREE);

// ���ûص�����
bufferevent_setcb(bev, read_callback, write_callback, event_callback, NULL);

// ����ˮλ��
bufferevent_setwatermark(bev, EV_READ, 0, MAX_LINE);

// ������/д�¼�
bufferevent_enable(bev, EV_READ | EV_WRITE);

// ���ӷ�����
struct sockaddr_in server_addr;
memset(&server_addr, 0, sizeof(server_addr));
server_addr.sin_family = AF_INET;
server_addr.sin_port = htons(port);
inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
bufferevent_socket_connect(bev, (struct sockaddr*)&server_addr, sizeof(server_addr));

// �����¼�ѭ��
event_base_dispatch(base);




ʹ��bufferevent_socket_new��������һ���µ�bufferevent�����ṩһ���Ѿ��򿪵�socket��
���socket���������Ѿ����ܵ�һ�������ӣ�Ҳ���������Ѿ����������ӵ�Զ�̷�������socket��

����evconnlistener_new_bind��������ֻ��Ҫ�ṩһ��Ҫ�����ĵ�ַ��struct sockaddr�ṹ����
libevent���Զ�Ϊ�㴴��socket�����󶨵������ַ�ϡ�

vconnlistener_new_bind��libevent���е�һ�������������ڴ���һ���µ����Ӽ�������connection listener����
���Ӽ���������һ��������socket�ϼ����µ����ӡ������µ����ӵ���ʱ���������������ӣ��������û�ָ���Ļص�������
struct evconnlistener*
    evconnlistener_new_bind(struct event_base* base,
        evconnlistener_cb cb,
        void* ptr,
        unsigned flags,
        int backlog,
        const struct sockaddr* sa,
        int socklen);

base���¼�ѭ���Ļ�������

cb�������ӵ���ʱ�Ļص�������

ptr�����ݸ��ص������Ĳ�����

flags�����ڿ��Ƽ�������Ϊ�ı�־�����õı�־����LEV_OPT_CLOSE_ON_FREE�����ͷż�����ʱ�رյײ��socket��
��LEV_OPT_REUSEABLE��������ͬһ����ַ�ϴ����������������

backlog���������ں�Ϊ��socket�Ŷӵ������������

sa��ָ��Ҫ�����ĵ�ַ��

socklen����ַ�ṹ�Ĵ�С��

evconnlistener_free(listener);//�ͷ�����������




struct event* evsignal_new(struct event_base* base, int sig, event_callback_fn cb, void* arg);


base���¼�ѭ���Ļ�������
sig����Ҫ�������źš����磬����Լ��� SIGINT��ͨ�����û����� Ctrl + C �������� SIGTERM��ͨ���������������ֹ����
cb����ָ�����źŷ���ʱ���õĻص�������
arg�����ݸ��ص������Ĳ�����


struct event* sigint_event;
sigint_event = evsignal_new(base, SIGINT, signal_cb, base);
����������У����Ǵ�����һ���µ��ź��¼������û����� Ctrl + C����ᷢ�� SIGINT �źţ�ʱ��
���� signal_cb �ص�����������Ҳ������ base ��Ϊ�ص������Ĳ�������ͨ���ڻص����������������¼�ѭ����








int bufferevent_socket_connect(struct bufferevent* bev,
    struct sockaddr* address,
    int addrlen);

bufferevent_socket_connect �� libevent ���е�һ�����������ڽ��� TCP ���ӡ�����������첽�ģ�Ҳ����˵��
������������ֱ�����ӽ�����ɣ������ڿ�ʼ���Ӻ���������ء���������ûص�����������������ɻ�ʧ��ʱ�������








1.int bufferevent_write(struct bufferevent* bufev, const void* data, size_t size);
bufferevent_write�ǽ�data������д��bufferevent��д������    





struct evbuffer* input = bufferevent_get_input(bev);   //��ȡ���뻺����
struct evbuffer* output = bufferevent_get_output(bev);//��ȡ���������

struct evbuffer* buf �� libevent ���е�һ���������ͣ���ʾһ���¼���������event buffer���Ķ���
    ����������ڻ����������ݣ�ͨ�����ڻ����������յ������ݣ����ߵȴ����͵���������ݡ�
    һ�� evbuffer ������Զ�̬����������Ӧ��ӵ�����������������
    �����ṩ�˺ܶ��������������������ݡ�ɾ�����ݡ��������ݡ��������ݵȡ�
    /* ����һ���µ� evbuffer */
    struct evbuffer* buf = evbuffer_new();

/* ������ݵ� evbuffer */
char data[] = "Hello, World!";
evbuffer_add(buf, data, strlen(data));

/* �� evbuffer ���Ƴ����� */
char read_data[1024];
evbuffer_remove(buf, read_data, sizeof(read_data));

/* �ͷ� evbuffer */
evbuffer_free(buf);














int bufferevent_write_buffer(struct bufferevent* bufev, struct evbuffer* buf);


bufev��bufferevent ��������д�����ݵ�Ŀ�ꡣ

buf��evbuffer ������Ҫд���������Դ��











size_t bufferevent_read(struct bufferevent* bufev, void* data, size_t size);
bufferevent_read �ǽ�bufferevent�Ķ����������ݶ���data�У�ͬʱ�����������ݴ�bufferevent�Ķ����������

int bufferevent_read_buffer(struct bufferevent* bufev, struct evbuffer* buf);







int evbuffer_add_buffer(struct evbuffer* dst, struct evbuffer* src);
���������� src �����������������ƶ��� dst ������������� src ������









events������һ����־����������ʾbufferevent��״̬�������־�����ܰ������¼���״̬��

BEV_EVENT_READING : �����ڶ�ȡ�����еĴ���
BEV_EVENT_WRITING : ������д������еĴ���
BEV_EVENT_EOF : �Զ�socket�Ѿ��رգ����ļ�������EOF��
BEV_EVENT_ERROR : ��bufferevent�з�����һ����EOF�Ĵ���
BEV_EVENT_TIMEOUT : �ڶ�ȡ��д��ʱ��ʱ��
BEV_EVENT_CONNECTED : ��bufferevent�ɹ��������Ӻ󴥷���