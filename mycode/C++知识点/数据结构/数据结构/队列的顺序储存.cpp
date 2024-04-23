#define MAX_SIZE 1024

// 定义队列结构
struct SeqQueue
{
    void* data[MAX_SIZE]; // 数据存储数组
    int front; // 队头指针
    int rear;  // 队尾指针
};

// 初始化队列
SeqQueue* init_SeQueue()
{
    SeqQueue* queue = new SeqQueue;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

// 入队操作
void push_fun(SeqQueue* queue, void* data)
{
    if (queue->rear == MAX_SIZE - 1)
    {
        cout << "Queue is full. Push failed." << endl;
        return;
    }
    queue->data[++queue->rear] = data;
}

// 出队操作
void pop_fun(SeqQueue* queue)
{
    if (queue->front > queue->rear)
    {
        cout << "Queue is empty. Pop failed." << endl;
        return;
    }
    queue->front++;
}

// 获取队头元素
void* get_front(SeqQueue* queue)
{
    if (queue->front > queue->rear)
    {
        cout << "Queue is empty. Front element does not exist." << endl;
        return nullptr;
    }
    return queue->data[queue->front];
}

// 获取队尾元素
void* get_back(SeqQueue* queue)
{
    if (queue->front > queue->rear)
    {
        cout << "Queue is empty. Back element does not exist." << endl;
        return nullptr;
    }
    return queue->data[queue->rear];
}

// 获取队列大小
int get_size(SeqQueue* queue)
{
    return queue->rear - queue->front + 1;
}

// 判断队列是否为空
int isEmpty(SeqQueue* queue)
{
    return queue->front > queue->rear;
}

// 销毁队列
void destroy_fun(SeqQueue* queue)
{
    delete queue;
}

int main() {
    SeqQueue* queue = init_SeQueue();

    // 测试入队操作
    int a = 10, b = 20, c = 30;
    push_fun(queue, &a);
    push_fun(queue, &b);
    push_fun(queue, &c);

    // 测试获取队头和队尾元素
    cout << "Front element: " << *(int*)get_front(queue) << endl;
    cout << "Back element: " << *(int*)get_back(queue) << endl;

    // 测试出队操作
    pop_fun(queue);

    // 再次获取队头和队尾元素
    cout << "Front element after pop: " << *(int*)get_front(queue) << endl;
    cout << "Back element after pop: " << *(int*)get_back(queue) << endl;

    // 测试获取队列大小和判断队列是否为空
    cout << "Queue size: " << get_size(queue) << endl;
    cout << "Is queue empty? " << (isEmpty(queue) ? "Yes" : "No") << endl;

    // 销毁队列
    destroy_fun(queue);

    return 0;
}