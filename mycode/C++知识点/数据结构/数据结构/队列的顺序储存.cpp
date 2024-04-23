#define MAX_SIZE 1024

// ������нṹ
struct SeqQueue
{
    void* data[MAX_SIZE]; // ���ݴ洢����
    int front; // ��ͷָ��
    int rear;  // ��βָ��
};

// ��ʼ������
SeqQueue* init_SeQueue()
{
    SeqQueue* queue = new SeqQueue;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

// ��Ӳ���
void push_fun(SeqQueue* queue, void* data)
{
    if (queue->rear == MAX_SIZE - 1)
    {
        cout << "Queue is full. Push failed." << endl;
        return;
    }
    queue->data[++queue->rear] = data;
}

// ���Ӳ���
void pop_fun(SeqQueue* queue)
{
    if (queue->front > queue->rear)
    {
        cout << "Queue is empty. Pop failed." << endl;
        return;
    }
    queue->front++;
}

// ��ȡ��ͷԪ��
void* get_front(SeqQueue* queue)
{
    if (queue->front > queue->rear)
    {
        cout << "Queue is empty. Front element does not exist." << endl;
        return nullptr;
    }
    return queue->data[queue->front];
}

// ��ȡ��βԪ��
void* get_back(SeqQueue* queue)
{
    if (queue->front > queue->rear)
    {
        cout << "Queue is empty. Back element does not exist." << endl;
        return nullptr;
    }
    return queue->data[queue->rear];
}

// ��ȡ���д�С
int get_size(SeqQueue* queue)
{
    return queue->rear - queue->front + 1;
}

// �ж϶����Ƿ�Ϊ��
int isEmpty(SeqQueue* queue)
{
    return queue->front > queue->rear;
}

// ���ٶ���
void destroy_fun(SeqQueue* queue)
{
    delete queue;
}

int main() {
    SeqQueue* queue = init_SeQueue();

    // ������Ӳ���
    int a = 10, b = 20, c = 30;
    push_fun(queue, &a);
    push_fun(queue, &b);
    push_fun(queue, &c);

    // ���Ի�ȡ��ͷ�Ͷ�βԪ��
    cout << "Front element: " << *(int*)get_front(queue) << endl;
    cout << "Back element: " << *(int*)get_back(queue) << endl;

    // ���Գ��Ӳ���
    pop_fun(queue);

    // �ٴλ�ȡ��ͷ�Ͷ�βԪ��
    cout << "Front element after pop: " << *(int*)get_front(queue) << endl;
    cout << "Back element after pop: " << *(int*)get_back(queue) << endl;

    // ���Ի�ȡ���д�С���ж϶����Ƿ�Ϊ��
    cout << "Queue size: " << get_size(queue) << endl;
    cout << "Is queue empty? " << (isEmpty(queue) ? "Yes" : "No") << endl;

    // ���ٶ���
    destroy_fun(queue);

    return 0;
}