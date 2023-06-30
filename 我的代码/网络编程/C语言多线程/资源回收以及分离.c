

int pthread_join(pthread_t thread, void** retval);
����:
�ȴ��߳̽���(�˺���������), �������߳���Դ, ���ƽ��̵�wait()����������߳��Ѿ�����, ��ô�ú������������ء�
���� :
thread:���ȴ����̺߳š�
retva1 : �����洢�߳��˳�״̬��ָ��ĵ�ַ��
����ֵ : �ɹ�:0    ʧ�� : ��0







void* fun(void* arg)
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		printf("fun thread do working %d\n", i);
		sleep(1);
	}
	return (void*)0x3;
}
int main(void)
{
	int ret = -1;
	void* retp = NULL;
	pthread_t tid = -1;
	//����һ���߳�
	ret = pthread_create(&tid, NULL, fun, NULL);
	if (0 != ret)
	{
		printf("pthread_create failed....\n");
		return 1;
	}
	printf("main thread running.....\n");
	//�ȴ��߳̽���
	ret = pthread_join(tid, &retp);
	if (0 != ret)
	{
		printf("pthread_join failed...\n");
		return 1;
	}
	printf("retp:%p\n", retp);
	printf("main thread exit.....\n");
	return 0;
}


main thread running.....
fun thread do working 0
fun thread do working 1
fun thread do working 2
fun thread do working 3
fun thread do working 4
retp:0x3
main thread exit.....






//�����д��ĸ
void* fun1(void* arg)
{
	int i = 0;
	for (i = 'A'; i <= 'Z'; i++)
	{
		putchar(i);
		fflush(stdout);
		usleep(100000);//100ms
	}
	return NULL;
}

//���Сд��ĸ
void* fun2(void* arg)
{
	int i = 0;
	for (i = 'a'; i <= 'z'; i++)
	{
		putchar(i);
		fflush(stdout);   //�����ˢ�£��ͻ�����ڻ�����
		usleep(100000);//100ms
	}
	return NULL;
}
//ģ������ַ�
int main(void)
{
	pthread_t tid1, tid2;
	//���������߳�
	pthread_create(&tid1, NULL, fun1, NULL);
	pthread_create(&tid2, NULL, fun2, NULL);
	//�ȴ������߳̽���
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	printf("\n");
	printf("main thread exit....\n");
	return 0;
}

AabBcCDdeEfFgGhHiIjJkKlLmMnNOopPQqrRsStTuUVvwWXxyYZz
main thread exit....








int pthread_detach(pthread_t thread);
����:
ʹ�����߳��뵱ǰ���̷���, ����󲻴�����̲߳������뵱ǰ����, �̷߳����Ŀ���ǽ��߳���Դ�Ļ��չ�
������ϵͳ�Զ������, Ҳ����˵����������߳̽���֮��, ϵͳ���Զ�����������Դ������, �˺�������������
���� :
thread:�̺߳š�
����ֵ :
�ɹ�:0
ʧ�� : ��0



����detach���߳������̷߳��룬���̲߳���ȴ����̡߳�
������̵߳����˽����˳��������������̾ͻ����
��pthread_exit���߳��˳��������ȼ���return ���˳��߳�


int main(void)
{
	int ret = -1;
	pthread_t tid = -1;
	//����һ���߳�
	ret pthread_create(&tid, NULL, fun, NULL);
	if (0 != ret)
	{
		printf("pthread_create failed....\n");
		return 1;
	}
	printf("main thread....tid:%Lu\n", pthread_self())
		//�����̷߳���
		ret pthread_detach(tid);
	if (0 != ret)
	{
		printf("pthread_detach failed...\n");
		return 1;
	}
	printf("������������߳��˳�..,,\n");           //������£���ô�����˳������е��߳�Ҳ��ֹ
	getchar();
	return 0;