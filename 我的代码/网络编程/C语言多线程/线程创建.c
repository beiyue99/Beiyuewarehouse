


int pthread_create(pthread_t* thread,
	const pthread_attr_t* attr,
	void* (*start_routine)(void*)
	void* arg)
	����:
����һ���̡߳�
���� :
thread:�̱߳�ʶ����ַ��
attr : �߳����Խṹ���ַ, ͨ������ΪNULL��
start_routine : �̺߳�������ڵ�ַ��
arg : �����̺߳����Ĳ�����
����ֵ :
�ɹ�:0
ʧ�� : ��0



pthread_create�����ĵڶ���������һ��ָ��pthread_attr_t���͵��߳����Զ����ָ�룬����ָ�����̵߳����ԡ�
�������Ҫ�����̵߳����ԣ����Խ��ò�������ΪNULL�������߳̽�ʹ��POSIX�߳̿��Ĭ������ֵ��
���磬������ʹ��pthread_create�����������̵߳�ʾ�����룬���еڶ�������ΪNULL����ʾʹ��Ĭ���߳����ԣ�
pthread_t thread;
int rc = pthread_create(&thread, NULL, my_thread_func, arg);
�����Ҫ�����̵߳����ԣ���Ҫ��ʹ��pthread_attr_init������ʼ��һ���߳����Զ���
Ȼ��ʹ������pthread_attr�����������߳����Ե�ֵ����󽫸��߳����Զ�����Ϊpthread_create�����ĵڶ����������ݡ�
���磬������ʹ��pthread_create�����������̵߳�ʾ�����룬����ʹ��pthread_attr_init������ʼ���߳����Զ���
Ȼ��ʹ��pthread_attr_setstacksize���������̶߳�ջ�Ĵ�С����󽫸��߳����Զ�����Ϊpthread_create�����ĵڶ����������ݣ�
pthread_t thread;
pthread_attr_t attr;
pthread_attr_init(&attr);
pthread_attr_setstacksize(&attr, 2 * PTHREAD_STACK_MIN);
int rc = pthread_create(&thread,
	&attr, my_thread_func, arg);






��һ���߳��е���pthread_create�����µ��̺߳�, ��ǰ�̴߳�pthread_create���ؼ�������ִ��, ����
���߳���ִ�еĴ��������Ǵ���pthread_create�ĺ���ָ��start_routine������
����pthread_create�Ĵ����벻������errno��, ��˲���ֱ����perror()��ӡ������Ϣ, ��������strerror()
�Ѵ�����ת���ɴ�����Ϣ�ٴ�ӡ��



void* fun(void* arg)
{
	printf("�µ��߳�ִ������ tid:%ld\n", pthread_self());
	return NULL;
}
int main()
{
	int ret = -1;
	pthread_t tid = -1;
	//����һ���߳�
	ret = pthread_create(&tid, NULL, fun, NULL);
	if (ret != 0)
	{
		printf("pthread_create failed...\n");
		return 1;
	}
	printf("main thread tid is : %ld\n", pthread_self());
	return 0;
}

�������̻߳�û��ִ�У����߳̾��Ѿ���������ʱ����ִ��fun�������������
����Ҫ���߳�ִ�У�������getchar��������һ�����߳�












void* fun(void* arg)
{
	printf("�µ��߳�ִ������ tid:%ld\n", pthread_self());
	return NULL;
}
void* fun1(void* arg)
{
	int var = (int)(long)arg;
	printf("�߳�2var=%d\n", var);
	return NULL;
}
int main()
{
	int ret = -1;
	pthread_t tid = -1;
	pthread_t tid2 = -1;

	//����һ���߳�
	ret = pthread_create(&tid, NULL, fun, NULL);
	if (ret != 0)
	{
		printf("pthread_create failed...\n");
		return 1;
	}
	ret = pthread_create(&tid2, NULL, fun1, (void*)0x3);
	if (ret != 0)
	{
		printf("pthread_create failed...\n");
		return 1;
	}
	printf("main thread tid is : %ld\n", pthread_self());
	printf("��������˳�\n");
	getchar();
	return 0;
}