#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include"队列的链式储存.h"
LinkQueue init_fun()
{
	LQueue* myqueue = new(LQueue);
	myqueue->pheader.next = nullptr;
	myqueue->m_size = 0;
	myqueue->pTail = &myqueue->pheader;
	return myqueue;
}
void push_fun(LinkQueue queue, void* date)
{
	LQueue* myqueue = (LQueue*)queue;
	LinkNode* myNode = (LinkNode*)date;
	myqueue->pTail->next = myNode;
	myNode->next = nullptr;
	myqueue->pTail = myNode;
	myqueue->m_size++;
}
void pop_fun(LinkQueue queue)
{
	LQueue* myqueue = (LQueue*)queue;
	LinkNode* pFirst = myqueue->pheader.next;
	myqueue->pheader.next = pFirst->next;
	myqueue->m_size--;
}
void* get_front(LinkQueue queue)
{
	LQueue* myqueue = (LQueue*)queue;
	return myqueue->pheader.next;
}
void* get_back(LinkQueue queue)
{
	LQueue* myqueue = (LQueue*)queue;
	return myqueue->pTail;
}
int get_size(LinkQueue queue)
{
	LQueue* myqueue = (LQueue*)queue;
	return myqueue->m_size;
}
int isEmpty(LQueue* queue)
{
	if (queue->m_size == 0)
	{
		return 1;
	}
	return 0;
}
void destory_fun(LQueue* queue)
{
	delete queue;
	queue = nullptr;
}
struct Person
{
	void* p;
	char name[20];
	int age;
};

void test01()
{
	LinkQueue myQueue = init_fun();
	Person p1 = {nullptr, "aaa",10 };
	Person p2 = {nullptr, "bbb",10 };
	Person p3 = {nullptr, "ccc",10 };
	Person p4 = {nullptr, "ddd",10 };
	Person p5= { nullptr, "eee",10 };
	push_fun(myQueue, &p1);
	push_fun(myQueue, &p2);
	push_fun(myQueue, &p3);
	push_fun(myQueue, &p4);
	push_fun(myQueue, &p5);
	while (isEmpty((LQueue*)myQueue)==0)
	{
		Person* personFront = (Person*)get_front(myQueue);
		cout << "队头元素姓名：" << personFront->name << "队头元素年龄：" << personFront->age << endl;
		Person* personback = (Person*)get_back(myQueue);
		cout << "队尾元素姓名：" << personback->name << "队尾元素年龄：" << personback->age << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++" << endl;
		pop_fun(myQueue);
	}
	cout << "队列大小：" << get_size(myQueue) << endl;
	destory_fun((LQueue*)myQueue);
}
int main()
{
	test01();
}