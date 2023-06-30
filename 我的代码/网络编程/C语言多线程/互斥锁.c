

#include <pthread.h>
int pthread_mutex_init(pthread_mutex_t* restrict mutex,
	const pthread_mutexattr_t* restrict attr)
	����:
��ʼ��һ����������
���� :
mutex:��������ַ��������pthread_mutex_t
��
attr : ���û�����������, ͨ���ɲ���Ĭ������, ���ɽ�attr��ΪNULL��
����ʹ�ú�PTHREAD_MUTEX_INITIALIZER��̬��ʼ��������, ���� :
	pthread_mutex_t mutex PTHREAD_MUTEX_INITIALIZER;
���ַ����ȼ���ʹ��NULLָ����attr��������pthread_mutex_init()����ɶ�̬��ʼ��, ��֮ͬ����
��PTHREAD_MUTEX._INITIALIZER�겻���д����顣
����ֵ :
�ɹ�:0, �ɹ��������Ĭ���Ǵ򿪵ġ�
ʧ�� : ��0������


restrict, C�����е�һ�������޶���(Type Qualifiers), ���ڸ��߱�����, �����Ѿ���ָ��������, ����ͨ
������ָ������������ֱ�ӻ��ӵķ�ʽ�޸ĸö�������ݡ�



int pthread_mutex_destroy(pthread_mutex_t* mutex);
����:
����ָ����һ������������������ʹ����Ϻ�, ����Ҫ�Ի�������������, ���ͷ���Դ��
���� :
mutex:��������ַ��
����ֵ :
�ɹ�:0
ʧ�� : ��0������








int pthread_mutex_lock(pthread_mutex_t * mutex);
����:
�Ի���������, ���������Ѿ�����, �����������, ֱ����������������������
���� :
mutex:��������ַ��
����ֵ :
�ɹ�:0
ʧ�� : ��0������
int pthread_mutex_trylock(pthread_mutex_t * mutex);

���øú���ʱ, ��������ĩ����, ������, ����0
��������������, ����ֱ�ӷ���ʧ��, ��EBUSY��








int pthread_mutex_unlock(pthread_mutex_t* mutex);
����:
��ָ���Ļ�����������
���� :
mutex:��������ַ��
����ֵ :
�ɹ�:
ʧ��:��0������












#include<stdio.h>
#include<unistd.h>
#include<pthread.h>


//����������
pthread_mutex_t mutex;


//�����д��ĸ
void* fun1(void* arg)
{
	int i = 0;
	pthread_mutex_lock(&mutex);
	for (i = 'A'; i <= 'Z'; i++)
	{
		putchar(i);
		fflush(stdout);
		usleep(100000);//100ms
	}
	pthread_mutex_unlock(&mutex);
	return NULL;
}

//���Сд��ĸ
void* fun2(void* arg)
{
	int i = 0;
	//pthread_mutex_lock(&mutex);
	for (i = 'a'; i <= 'z'; i++)
	{
		putchar(i);
		fflush(stdout);   //�����ˢ�£��ͻ�����ڻ�����
		usleep(100000);//100ms
	}
	//pthread_mutex_unlock(&mutex);
	return NULL;
}
//ģ������ַ�
int main(void)
{

	int ret = -1;
	pthread_t tid1, tid2;
	//��ʼ��һ�������� ������
	ret = pthread_mutex_init(&mutex, NULL);
	if (ret != 0)
	{
		printf("pthread_mutex_init failed...\n");
		return 1;
	}
	printf("��ʼ��һ���������ɹ�....\n");
	//���������߳�
	pthread_create(&tid1, NULL, fun1, NULL);
	pthread_create(&tid2, NULL, fun2, NULL);
	//�ȴ������߳̽���
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	printf("\n");
	printf("main thread exit....\n");
	//���ٻ����� ������
	pthread_mutex_destroy(&mutex);
	return 0;
}

���ȣ�fun1�̻߳��ȡ����������ʼѭ�������д��ĸ����ѭ����ÿ�ε����У��������һ����д��ĸ��Ȼ�����fflush(stdout); ˢ�������������ȷ����ĸ��������ӡ���նˡ�

Ȼ��fun1�̻߳����usleep(100000); ����ִͣ�У���˯��100���루����˵�ӳ�100���룩�������˯���ڼ䣬fun1�߳���Ȼ���л�������

���ǣ���fun1�߳�˯���ڼ䣬����ϵͳ���ܻ�����̵߳��ȣ����п����л���fun2�߳�ִ�С�����fun2�߳�û�л������ı����������Զ�����ִ�����Сд��ĸ�Ĳ�����

��ˣ�fun1�̺߳�fun2�߳���˯���ڼ���Խ���ִ�У��Ӷ����´�д��ĸ��Сд��ĸ����������������С�






��ֻ��fun1�߳̽��л������ļ����ͽ�������ʱ��fun2�߳���fun1�߳�˯���ڼ��л��ᱻϵͳ����ִ�У���Ϊfun2�߳�û�л������ı�����

����ͬʱ��fun1��fun2�̶߳����л������ļ����ͽ�������ʱ��һ���߳���ִ���ڼ䣬��ʹ��һ���̴߳���˯��״̬����Ҳ�޷���ȡ��������������޷�ִ���Լ�������

��ˣ���ͬʱ��fun1��fun2�̶߳�����������£�ֻ�е�һ���߳�ִ����ϲ��ͷŻ���������һ���̲߳��ܻ�ȡ����������ִ���Լ�������










//��������
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

pthread_mutex_t mutex1;
pthread_mutex_t mutex2;

//�߳�1������
void* fun1(void* arg)
{
	//�߳�1��������Դ1��������Դ2
	pthread_mutex_lock(&mutex1);
	printf("�߳�1����Դ1ok..,.\n");
	pthread_mutex_lock(&mutex2);
	printf("�߳�1����Դ2ok..,.\n");
	printf("�߳�1ִ���ٽ�������..\n");
	//����������
	pthread_mutex_unlock(&mutex1);
	pthread_mutex_unlock(&mutex2);
	return NULL;
}
//�߳�2������
void* fun2(void* arg)
{
	//�߳�2��������Դ2��������Դ1
	pthread_mutex_lock(&mutex2);
	printf("�߳�2������Դ2ok...\n");
	pthread_mutex_lock(&mutex1);
	printf("�߳�2������Դ1ok...\n");
	printf("�߳�2ִ���ٽ�������....\n");
	//����������
	pthread_mutex_unlock(&mutex2);
	pthread_mutex_unlock(&mutex1);
	return NULL;
}
int main(void)
{
	int ret = -1;
	pthread_t tid1, tid2;
	//��ʼ��������
	pthread_mutex_init(&mutex1, NULL);
	pthread_mutex_init(&mutex2, NULL);
	//���������߳�
	pthread_create(&tid1, NULL, fun1, NULL);
	pthread_create(&tid2, NULL, fun2, NULL);
	//�����߳���Դ
	ret = pthread_join(tid1, NULL);
	if (0 != ret)
	{
		("pthread_join failed....In");
		return 1;
	}
	ret = pthread_join(tid2, NULL);
	if (0 != ret)
	{
		printf("pthread_join failed....\n");
		return 1;
	}
	//����
	pthread_mutex_destroy(&mutex1);
	pthread_mutex_destroy(&mutex2);
	return 0;
}
