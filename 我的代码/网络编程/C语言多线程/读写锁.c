��һ�����̼߳���, �������ж��̼߳�������0k����д�̶߳�������
��һ��д�̼߳���, �������еĶ��̺߳�д�̼߳�����������


��д����Ϊ������д��, ��������:
1)���ĳ�߳������˶���, �����߳̿������������, ����������д����
2)���ĳ�߳�������д��, �����̲߳����������, Ҳ��������д����




int pthread_rwlock_int(pthread_rwlock_t* restrict rwlock, const pthread_rwlockattr_t* restrict attr);
����:
������ʼ��rw1ock��ָ��Ķ�д����
���� :
rwlock:ָ��Ҫ��ʼ���Ķ�д��ָ�롣
attr : ��д��������ָ�롣���attrΪNULL���ʹ��Ĭ�ϵ����Գ�ʼ����д��, ����ʹ��ָ����attr��ʼ����д����
����ʹ�ú�PTHREAD_RWLOCK_INITIALIZER��̬��ʼ����д��, ���� :
	pthread_rwlock_t my_rwlock PTHREAD_RWLOCK_INITIALIZER;
���ַ����ȼ���ʹ��NULLָ����attr��������pthread_rwlock_init()����ɶ�̬��ʼ��, ��֮ͬ������PTHREAD_RWLOCK._INITIALIZER�겻���д����顣
����ֵ :
�ɹ�:0, ��д����״̬����Ϊ�ѳ�ʼ�����ѽ�����
ʧ�� : ��0�����롣




int pthread_rwlock_destroy(pthread_rwlock_t* rwlock);
����:
��������һ����д��, ���ͷ��������������Դ(��ν������ָ������pthread_rwlock_init()�Զ��������Դ)��
���� :
rwlock:��д��ָ�롣
����ֵ :
�ɹ�:0
ʧ�� : ��0������







int pthread_rwlock_rdlock(pthread_rwlock_t * rwlock);
����:
��������ʽ�ڶ�д���ϻ�ȡ����(������)��
���û��д�߳��и���, ����û��д�������ڸ�����, ������̻߳��ȡ������
��������߳�δ��ȡ����, ����������ֱ������ȡ�˸�����һ���߳̿�����һ����д���϶��ִ�ж�������
�߳̿��Գɹ�����pthread._rw1ock_rdlock()����n��, ����֮����̱߳������
pthread_rwlock_unlock()����n�β��ܽ��������
���� :
rwlock:��д��ָ�롣
����ֵ :
�ɹ�:0
ʧ�� : ��0������
int pthread_rwlock_tryrdlock(pthread_rwlock_t * rwlock);
���ڳ����Է������ķ�ʽ���ڶ�д���ϻ�ȡ������
������κε�д�߳��и�������д�������ڸö�д����, ������ʧ�ܷ��ء�








int pthread_rwlock_wrlock(pthread_rwlock_t* rwlock);
����:
�ڶ�д���ϻ�ȡд��(д����)��
���û��д�߳��и���, ����û�ж��߳��и���, ������̻߳��ȡд�� :
	��������߳�δ��ȡд��, ����������ֱ������ȡ�˸�����
	���� :
rw1ock:��д��ָ�롣
����ֵ :
�ɹ�:0
ʧ�� : ��0������
int pthread_rwlock_trywrlock(pthread_rwlock_t * rwlock);
���ڳ����Է������ķ�ʽ���ڶ�д���ϻ�ȡд����
������κεĶ��߻�д�߳��и���, ������ʧ�ܷ��ء�





int pthread_rwlock_unlock(pthread_rwlock_t* rwlock);
����:
�����Ƕ�����д��, ������ͨ���˺���������
���� :
rwlock:��д��ָ�롣
����ֵ :
�ɹ�:0
ʧ�� : ��0������





//ȫ�ֱ���
int num = 0;
//��д������
pthread_rwlock_t rwlock;
//���߳�
void* fun_read(void* arg)
{
	//��ȡ�̵߳ı��
	int index = (int)(intptr_t)arg;
	while (1)
	{
		//�Ӷ�д������
		pthread_rwlock_rdlock(&rwlock);
		printf("�߳�%d��ȡnum��ֵ%d\n", index, num);
		//����
		pthread_rwlock_unlock(&rwlock);
		//���˯��1-3��
		sleep(random() % 3 + 1);
	}
	return NULL;
}

//д�߳�
void* fun_write(void* arg)
{
	int index = (int)(intptr_t)arg;
	while (1)
	{
		//�Ӷ�д��д��
		pthread_rwlock_wrlock(&rwlock);
		num++;
		printf("�߳�%d�޸�num��ֵ%d\n", index, num);
		//����
		pthread_rwlock_unlock(&rwlock);
		//���˯��1-3��
		sleep(random() % 3 + 1);
	}
	return NULL;
}
int main(void)
{
	int i = 0;
	int ret = -1;
	pthread_t tid[8];
	//�����������
	srandom(getpid());
	//��ʼ����д��
	ret = pthread_rwlock_init(&rwlock, NULL);
	if (0 != ret)
	{
		printf("pthread_rwlock_init failed...\n");
		return 1;
	}
	//����8���߳�
	for (i = 0; i < 8; i++)
	{
		//�������߳�
		if (i < 5)
		{
			pthread_create(&tid[i], NULL, fun_read, (void*)(intptr_t)i);
		}
		else
		{
			//����д�߳�
			pthread_create(&tid[i], NULL, fun_write, (void*)(intptr_t)i);
		}
	}
	//���հ˸��̵߳���ԭ
	for (i = 0; i < 8; i++)
	{
		pthread_join(tid[i], NULL);
	}
	//������д��
	pthread_rwlock_destroy(&rwlock);
	return 0;
}

//��ȡ���ݲ��᲻һ�£����������������
�߳�0��ȡnum��ֵ0
�߳�2��ȡnum��ֵ0
�߳�1��ȡnum��ֵ0
�߳�3��ȡnum��ֵ0
�߳�4��ȡnum��ֵ0
�߳�5�޸�num��ֵ1
�߳�6�޸�num��ֵ2
�߳�7�޸�num��ֵ3
�߳�2��ȡnum��ֵ3
�߳�4��ȡnum��ֵ3
�߳�1��ȡnum��ֵ3