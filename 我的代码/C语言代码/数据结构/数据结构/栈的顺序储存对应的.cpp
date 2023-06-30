//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<iostream>
//using namespace std;
//#include<iomanip>
////#include<vld.h>
//
//#include"栈的顺序存储.hpp"
//
////初始化栈
//SeqStack init_fun()
//{
//	SStack *myStack = new (SStack)();
//	if (myStack == nullptr) { return nullptr; }
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
