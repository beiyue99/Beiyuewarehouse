
�̹߳�����Դ
1)�ļ���������
2)ÿ���źŵĴ���ʽ
3)��ǰ����Ŀ¼
4)�û�ID����ID
�ڴ��ַ�ռ�(.text / .data / .bss / heap / �����)

�̷߳ǹ�����Դ
1)�߳�id
2)�������ֳ���ջָ��(�ں�ջ)
3)������ջ�ռ�(�û��ռ�ջ)
4)errno����
5)�ź�������
6)�������ȼ�




memset(&tid, 0, sizeof(tid));    �����֪�� tid��ʲô���ͣ�����������ʼ��







int num = 100;
void* fun(void* arg)
{
	printf("brfore num is %d\n", num);
	num++;
	printf("after num is %d\n", num);
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

	//����һ���߳�
	ret = pthread_create(&tid, NULL, fun, NULL);
	if (ret != 0)
	{
		printf("pthread_create failed...\n");
		return 1;
	}
	printf("�����������...\n");
	getchar();
	printf("main num is %d\n", num);
	return 0;
}


���߳���num++��num��Ϊ101��������̴߳����Ҳ��101












#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>


int num = 100;
void* fun(void* arg)
{
	int* pn = (int*)arg;
	printf("brfore num is %d\n", num);
	num++;
	(*pn)++;
	printf("pָ��Ķ�����ֵ��һ��Ľ����%d\n", *pn);
	printf("after num is %d\n", num);
	return NULL;
}
int main()
{
	int* p;
	int ret = -1;
	pthread_t tid = -1;
	p = malloc(sizeof(int));
	memset(p, 0, sizeof(int));	*p = 88;

	//����һ���߳�
	ret = pthread_create(&tid, NULL, fun, (void*)p);
	if (ret != 0)
	{
		printf("pthread_create failed...\n");
		return 1;
	}
	printf("�����������...\n");
	getchar();
	printf("main num is %d\n", num);
	printf("���߳̽��������߳�*p��ֵ��%d\n", *p);

	return 0;
}

�����������...
brfore num is 100
pָ��Ķ�����ֵ��һ��Ľ����89
after num is 101

main num is 101
���߳̽��������߳� * p��ֵ��89