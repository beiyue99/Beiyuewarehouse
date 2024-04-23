#pragma once
#include<iostream>
using namespace std;
struct LinkNode
{
	struct LinkNode* next;
};
struct LQueue
{
	LinkNode pheader;
	int m_size;
	LinkNode* pTail;
};
typedef void* LinkQueue;
LinkQueue init_fun();
void push_fun(LinkQueue queue, void* date);
void pop_fun(LinkQueue queue);
void* get_front(LinkQueue queue);
void* get_back(LinkQueue queue);
int get_size(LinkQueue queue);
int isEmpty(LQueue* queue);
void destory_fun(LQueue* queue);