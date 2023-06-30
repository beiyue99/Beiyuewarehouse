������ȫ��

int pthread_cancel(pthread_t thread);
����:
ɱ��(ȡ��)�߳�
���� :
thread:Ŀ���߳�ID��
����ֵ :
�ɹ�:0
ʧ�� : ������
�˺���ȡ���̻߳�����ʱ��ֻ��ȡ��ͳһ�����е��߳�
���߳��˳������̲߳��˳�, ���߳�Ӧ����pthread_exit



pthread_create()
//����ԭ�ͣ�int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
����������
thread : ָ�� pthread_t ���͵�ָ�룬���ڷ����´����̵߳� ID��
attr : ָ�� pthread_attr_t ���͵�ָ�룬����ָ���´����̵߳����ԡ��������Ҫָ�����ԣ����Դ��� NULL��
start_routine : ���̵߳���ں�����
arg : ���ݸ����߳���ں����Ĳ�����
��������ֵ��
�ɹ������� 0��
ʧ�ܣ����ش����롣


void* thread_function(void* arg) {
    // �̵߳�ִ���߼�
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_attr_t attr;

    // ��ʼ���߳�����
    pthread_attr_init(&attr);

    // �����߳�Ϊ����״̬
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    // �����̣߳���������Ϊ�ڶ�����������
    pthread_create(&thread, &attr, thread_function, NULL);

    // �����߳�����
    pthread_attr_destroy(&attr);

    // ����Ҫ���� pthread_join

    return 0;
}
�����߳�Ϊ����״̬�����̲߳����ٶԸ��߳̽�����Դ���ջ�ȴ����������Ϊ���߳̽��ڽ���ʱ�Զ��ͷ���Դ



pthread_join()
����ԭ�ͣ�int pthread_join(pthread_t thread, void** retval);
�������ã��ȴ�һ���߳̽���������ȡ�̷߳���ֵ��
����������
thread : �ȴ��������߳� ID��
retval : ָ�� void ����ָ���ָ�룬���ڷ����̵߳ķ���ֵ��
��������ֵ��
�ɹ������� 0��
ʧ�ܣ����ش����롣






pthread_exit()
����ԭ�ͣ�void pthread_exit(void* retval);
�������ã�ʹ��ǰ�߳��˳���������һ��ָ���ķ���ֵ��
����������
retval : �̵߳ķ���ֵ��
��������ֵ���ޡ�








pthread_mutex_init()
����ԭ�ͣ�int pthread_mutex_init(pthread_mutex_t* mutex, const pthread_mutexattr_t* attr);
�������ã���ʼ��һ����������
����������
mutex : ָ�� pthread_mutex_t ���͵�ָ�룬����ָ��Ҫ��ʼ���Ļ�������
attr : ָ�� pthread_mutexattr_t ���͵�ָ�룬����ָ�������������ԡ��������Ҫָ�����ԣ����Դ��� NULL��
��������ֵ��
�ɹ������� 0��
ʧ�ܣ����ش����롣







pthread_mutex_lock()
����ԭ�ͣ�int pthread_mutex_lock(pthread_mutex_t * mutex);
�������ã�����һ����������
����������
mutex : ָ�� pthread_mutex_t ���͵�ָ�룬����ָ��Ҫ�����Ļ�������
��������ֵ��
�ɹ������� 0��
ʧ�ܣ����ش����롣








pthread_mutex_unlock()
����ԭ�ͣ�int pthread_mutex_unlock(pthread_mutex_t * mutex);
�������ã�����һ����������
����������
mutex : ָ�� pthread_mutex_t ���͵�ָ�룬����ָ��Ҫ�����Ļ�������
��������ֵ��
�ɹ������� 0��
ʧ�ܣ����ش����롣







pthread_cond_init()
����ԭ�ͣ�int pthread_cond_init(pthread_cond_t * cond, const pthread_condattr_t * attr);
�������ã���ʼ��һ������������
����������
cond : ָ�� pthread_cond_t ���͵�ָ�룬����ָ��Ҫ��ʼ��������������
attr : ָ�� pthread_condattr_t ���͵�ָ�룬����ָ���������������ԡ��������Ҫָ�����ԣ�����
���� NULL��
��������ֵ��
�ɹ������� 0��
ʧ�ܣ����ش����롣







pthread_cond_wait()
����ԭ�ͣ�int pthread_cond_wait(pthread_cond_t * cond, pthread_mutex_t * mutex);
�������ã��ȴ�һ�������������źţ����ҽ���һ����������ʹ�������߳̿��Է��ʱ������Ĺ�����Դ��
����������
cond : ָ�� pthread_cond_t ���͵�ָ�룬����ָ��Ҫ�ȴ�������������
mutex : ָ�� pthread_mutex_t ���͵�ָ�룬����ָ��Ҫ�����Ļ�������
��������ֵ��
�ɹ������� 0��
ʧ�ܣ����ش����롣






pthread_cond_signal()
����ԭ�ͣ�int pthread_cond_signal(pthread_cond_t * cond);
�������ã�����һ���źŸ��ȴ�һ�������������̡߳�
����������
cond : ָ�� pthread_cond_t ���͵�ָ�룬����ָ��Ҫ�����źŵ�����������
��������ֵ��
�ɹ������� 0��
ʧ�ܣ����ش����롣





pthread_t pthread_self(void);
����:��ȡ�̺߳š� �˺����ܻ�ɹ�





int pthread_equal(pthread_t t1, pthread_t t2);
����:
�ж��̺߳�t1��t2�Ƿ���ȡ�Ϊ�˷�����ֲ, ����ʹ�ú������Ƚ��߳�ID
����ֵ   ��ȷ��ط��㣬����ȷ�����

