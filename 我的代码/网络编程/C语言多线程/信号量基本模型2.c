

//����sem1������Ʒ��������ʼֵΪ4��ÿ����һ����Ʒ�������ͻ��һ��
//sem2������Ʒ����ʼֵΪ0��ÿ����һ����Ʒ�������ͻ��һ




//�ڵ�ṹ
typedef struct node
{
	int data;
	struct node* next;
}Node;
//��Զָ������ͷ����ָ��
Node* head = NULL;
//�����ĸ���
sem_t sem_producer;
//��������Ʒ�ĸ���
sem_t sem_customer;
//������
void* producer(void* arg)
{
	Node* pnew = NULL;
	//ѭ��������Ʒ
	while (1)
	{
		//����һ����Դ����
		sem_wait(&sem_producer);
		//����ڵ�ռ�
		pnew = malloc(sizeof(Node));
		if (NULL == pnew)
		{
			printf("malloc failed....\n");
			break;
		}
		memset(pnew, 0, sizeof(Node));
		//��ֵ
		pnew->data = random() % 100 + 1;
		pnew->next = NULL;
		printf("������������Ʒ%d\n", pnew->data);
		//ͷ�巨
		pnew->next = head;
		head = pnew;
		//֪ͨ���������ѽ�����������Ʒ������1
		sem_post(&sem_customer);
		sleep(random() % 3 + 1);
	}
	return NULL;
}


//������
void* customer(void* arg)
{
	Node* tmp = NULL;
	while (1)
	{
		//������Դ����������Ʒ������1
		sem_wait(&sem_customer);
		//����Ϊ�յ�����
		if (NULL == head)
		{
			printf("��Ʒ����Ϊ��..,.����Ϣ2����..n");
		}
		//��һ���ڵ��ַ��ֵ����ʱ����tmp
		tmp = head;
		//headָ������ĵڶ����ڵ�
		head = head->next;
		printf("���������Ĳ�Ʒ%d\n", tmp->data);
		//�ͷſռ�
		free(tmp);
		//�ͷ���Դ������������1
		sem_post(&sem_producer);
		//˯��1-3��
		sleep(random() % 3 + 1);
	}
	return NULL;
}

//û��ʹ�����������������ߺ�������ģ��
int main(void)
{
	int ret = -1;
	pthread_t tid1, tid2;
	//�����������
	srandom(getpid());
	//��ʼ��
	ret = sem_init(&sem_producer, 0, 4);
	if (0 != ret)
	{
		printf("sem_init failed...\n");
		return 1;
	}
	//��ʼ������������Ʒ�ĸ���
	ret = sem_init(&sem_customer, 0, 0);
	if (0 != ret)
	{
		printf("sem_init failed...\n");
		return 1;
	}
	//���������߳�
	pthread_create(&tid1, NULL, producer, NULL);
	pthread_create(&tid2, NULL, customer, NULL);
	//�����߳���Դ
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	//����
	sem_destroy(&sem_producer);
	sem_destroy(&sem_customer);
	return 0;
}