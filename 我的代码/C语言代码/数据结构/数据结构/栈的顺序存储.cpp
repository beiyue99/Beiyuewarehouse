//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<iostream>
//using namespace std;
//#include<iomanip>
//#include<vld.h>
//
//#define MAX 1024
//struct SStack
//{
//	void* date[MAX];
//	int m_Size;
//};
//typedef void* SeqStack;
////初始化栈
//SeqStack init_fun()
//{
//	SStack *myStack = new (SStack);
//	if (myStack == nullptr) { return nullptr; }
//	//memset(myStack->date, 0, sizeof(void*) * MAX);
//	myStack->m_Size = 0;
//	return myStack;
//}
////入栈
//void push_fun(SeqStack stack, void* date)
//{
//	if (date == nullptr && stack == nullptr) { return ; }
//	SStack* myStack = (SStack*)stack;
//	myStack->date[myStack->m_Size] = date;
//	myStack->m_Size++;
//}
////出栈   本质是尾删
//void pop_fun(SeqStack stack)
//{
//	SStack* mystack = (SStack*)stack;
//	mystack->date[mystack->m_Size - 1] = nullptr;
//	mystack->m_Size--;
//}
////返回栈顶  本质是返回最后一个元素
//void* getTop_fun(SeqStack stack)
//{
//	SStack* mystack = (SStack*)stack;
//	return mystack->date[mystack->m_Size - 1];
//}
////返回栈大小
//int getSize_fun(SeqStack stack)
//{
//	SStack* mystack = (SStack*)stack;
//	return mystack->m_Size;
//}
////判断是否为空
//int isEmpty(SeqStack stack)
//{
//	if (stack == nullptr) { return -1; }//传入空指针也是真，此时栈也是空的
//	SStack* mystack = (SStack*)stack;
//	if (mystack->m_Size == 0) { return 1; }
//	else return 0;
//}
////销毁栈
//void destroy_fun(SeqStack stack)
//{
//	delete stack;
//	stack = nullptr;
//}
//
//
//
//
//
//
//
//
//
//struct Person
//{
//	char name[20];
//	int age;
//};
//
//
//void test01()
//{
//	SeqStack stack = init_fun();
//	Person p1 = { "赵1", 18 };
//	Person p2 = { "赵2", 28 };
//	Person p3 = { "赵3", 38 };
//	Person p4 = { "赵4", 48 };
//	Person p5 = { "赵5", 58 };
//	Person p6 = { "赵6", 68 };
//	push_fun(stack, &p1);
//	push_fun(stack, &p2);
//	push_fun(stack, &p3);
//	push_fun(stack, &p4);
//	push_fun(stack, &p5);
//	push_fun(stack, &p6);
//	cout << getSize_fun(stack) << endl;
//	while (isEmpty(stack) == 0)
//	{
//		Person* pTop = (Person*)getTop_fun(stack);
//		cout << pTop->name << "  " << pTop->age << endl;
//		pop_fun(stack);
//	}
//	cout << getSize_fun(stack) << endl;
//	destroy_fun(stack);
//	stack = nullptr;
//}
//
//
//int main()
//{
//	test01();
//}