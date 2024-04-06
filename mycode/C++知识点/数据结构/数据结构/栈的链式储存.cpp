#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<iostream>
using namespace std;
#include<iomanip>
//
//struct LinkNode
//{
//	struct LinkNode* next;
//};
//struct LStack
//{
//	struct LinkNode pHead;
//	int m_Size;
//};
//typedef void* LinkStack;
////≥ı ºªØ
//LinkStack init_fun()
//{
//	LStack* mystack = new(LStack);
//	mystack->m_Size = 0;
//	mystack->pHead .next =nullptr;
//	return mystack;
//}
////»Î’ª
//void push_fun(LinkStack stack, void* date)
//{
//	LStack* mystack = (LStack*)stack;
//	LinkNode* myNode = (LinkNode*)date;
//	myNode->next = mystack->pHead.next;
//	mystack->pHead.next = myNode;
//	mystack->m_Size++;
//}
////≥ˆ’ª
//void pop_fun(LinkStack stack)
//{
//	LStack* mystack = (LStack*)stack;
//	if (mystack->m_Size == 0) { return; }
//	LinkNode* pFirst = mystack->pHead.next;
//	mystack->pHead.next = pFirst->next;
//	mystack->m_Size--;
//}
////∑µªÿ’ª∂•
//void* get_Top(LinkStack stack)
//{
//	LStack* mystack = (LStack*)stack;
//	if (mystack->m_Size == 0) { return nullptr; }
//	return mystack->pHead.next;
//}
////∑µªÿ’ª¥Û–°
//int get_Size(LinkStack stack)
//{
//	LStack* mystack = (LStack*)stack;
//	return mystack->m_Size;
//}
////≈–∂œ «∑ÒŒ™ø’
//int isEmpty(LinkStack stack)
//{
//	LStack* mystack = (LStack*)stack;
//	if (mystack->m_Size == 0)
//	{
//		return true;
//	}
//	else return false;
//}
////œ˙ªŸ’ª
//void destory(LinkStack stack)
//{
//	LStack* mystack = (LStack*)stack;
//	mystack->pHead.next = nullptr;
//	delete mystack;
//}
//
//
//
//struct Person
//{
//	void* p;
//	char name[20];
//	int age;
//};
//
//
//void test01()
//{
//	LinkStack mystack = init_fun();
//	Person p1 = {nullptr,"’‘1", 18 };
//	Person p2 = {nullptr,"’‘2", 28 };
//	Person p3 = {nullptr,"’‘3", 38 };
//	Person p4 = {nullptr,"’‘4", 48 };
//	Person p5 = {nullptr,"’‘5", 58 };
//	Person p6 = {nullptr,"’‘6", 68 };
//	cout << get_Size(mystack) << endl;
//	push_fun(mystack, &p1);
//	push_fun(mystack, &p2);
//	push_fun(mystack, &p3);
//	push_fun(mystack, &p4);
//	push_fun(mystack, &p5);
//	push_fun(mystack, &p6);
//	cout << get_Size(mystack) << endl;
//	while (isEmpty(mystack) == 0)
//	{
//		Person* p = (Person*)get_Top(mystack);
//		cout << p->name << "  " << p->age << endl; 
//		LStack* stack = (LStack*)mystack;
//		pop_fun(stack);
//	}
//	destory(mystack);
//	mystack = nullptr;
//}
//
//
//
//int main()
//{
//	test01();
//}
//
//
//
//
//



