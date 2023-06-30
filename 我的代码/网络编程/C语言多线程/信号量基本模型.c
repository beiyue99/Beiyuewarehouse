6.1�ź�������
�ź����㷺���ڽ��̻��̼߳��ͬ���ͻ���, �ź�����������һ���Ǹ�������������, �����������ƶԹ���
��Դ�ķ��ʡ�
���ʱ�ɸ��ݲ����ź���ֵ�Ľ���ж��Ƿ�Թ�����Դ���з��ʵ�Ȩ��, ���ź���ֵ����0ʱ, ����Է�
��, ����������
PVԭ���Ƕ��ź����Ĳ���, һ��P����ʹ�ź�����1, һ��V����ʹ�ź�����1��
�ź�����Ҫ���ڽ��̻��̼߳��ͬ���ͻ��������ֵ��������
�ź�����������Ϊ : sem_t






int sem_init(sem_t* sem, int pshared, unsigned int value);
����:
����һ���ź�������ʼ������ֵ��һ�������ź����ڱ�ʹ��ǰ�����ȳ�ʼ����
���� :
sem:
�ź����ĵ�ַ��
pshared : ����0, �ź������̼߳乲��(����); ������0, �ź����ڽ��̼乲��
value : �ź����ĳ�ʼֵ��
����ֵ :
�ɹ�:0
ʧ�� : -1




int sem_wait(sem_t * sem);
����:
���ź�����ֵ��1������ǰ, �ȼ���ź���(sem)��ֵ�Ƿ�Ϊ0, ���ź���Ϊ0, �˺���������, ֱ���ź�
������0ʱ�Ž��м�1������
���� :
sem:�ź����ĵ�ַ��
����ֵ :
�ɹ�:0
ʧ�� : -1
int sem_trywait(sem_t * sem);
�Է������ķ�ʽ�����ź������м�1������
������ǰ, �ź�����ֵ����0, ����ź����Ĳ���ʧ��, �����������ء�








int sem_getvalue(sem_t* sem, int* sval);
����:
��ȡsem��ʶ���ź�����ֵ, ������sva1�С�
���� :
sem:�ź�����ַ��
sVa1 : �����ź���ֵ�ĵ�ַ��
����ֵ :
�ɹ�:0
ʧ�� : -1









//�ź�������
sem_t sem;
//�����д��ĸ
void* fun1(void* arg)
{
	int i = 0;
	//������Դ,��������Դ��1
	sem_wait(&sem);
	for (i = 'A'; i <= 'Z'; i++)
	{
		putchar(i);
		fflush(stdout);
		usleep(100000);//100ms
	}
	//�ͷ���Դ��������Դ��1
	sem_post(&sem);
	return NULL;
}




//���Сд��
void* fun2(void* arg)
{
	int i = 0;
	//������Դ,��������Դ��1
	sem_wait(&sem);
	for (i = 'a'; i <= 'z'; i++)
	{
		putchar(i);
		fflush(stdout);
		usleep(100000);//100ms
	}
	//�ͷ���Դ��������Դ��1
	sem_post(&sem);
	return NULL;
}

//ģ������ַ�
int main(void)
{
	int ret = -1;
	pthread_t tid1, tid2;
	//��ʼ��һ���ź���
	ret = sem_init(&sem, 0, 1);
	if (0 != ret)
	{
		printf("sem_init failed...\n");
		return 1;
	}
	printf("��ʼ��һ���ź���ok....\n");
	//���������߳�
	pthread_create(&tid1, NULL, fun1, NULL);
	pthread_create(&tid2, NULL, fun2, NULL);
	//�ȴ������߳̽���
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	printf("\n");
	printf("main thread exit....\n");
	//�����ź���
	sem_destroy(&sem);
	return 0;
}