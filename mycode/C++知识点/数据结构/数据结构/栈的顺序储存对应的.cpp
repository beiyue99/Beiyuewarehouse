//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<iostream>
//using namespace std;
//#include<iomanip>
////#include<vld.h>
//
//#include"ջ��˳��洢.hpp"
//
////��ʼ��ջ
//SeqStack init_fun()
//{
//	SStack *myStack = new (SStack)();
//	if (myStack == nullptr) { return nullptr; }
//	myStack->m_Size = 0;
//	return myStack;
//}
////��ջ
//void push_fun(SeqStack stack, void* date)
//{
//	if (date == nullptr && stack == nullptr) { return ; }
//	SStack* myStack = (SStack*)stack;
//	myStack->date[myStack->m_Size] = date;
//	myStack->m_Size++;
//}
////��ջ   ������βɾ
//void pop_fun(SeqStack stack)
//{
//	SStack* mystack = (SStack*)stack;
//	mystack->date[mystack->m_Size - 1] = nullptr;
//	mystack->m_Size--;
//}
////����ջ��  �����Ƿ������һ��Ԫ��
//void* getTop_fun(SeqStack stack)
//{
//	SStack* mystack = (SStack*)stack;
//	return mystack->date[mystack->m_Size - 1];
//}
////����ջ��С
//int getSize_fun(SeqStack stack)
//{
//	SStack* mystack = (SStack*)stack;
//	return mystack->m_Size;
//}
////�ж��Ƿ�Ϊ��
//int isEmpty(SeqStack stack)
//{
//	if (stack == nullptr) { return -1; }//�����ָ��Ҳ���棬��ʱջҲ�ǿյ�
//	SStack* mystack = (SStack*)stack;
//	if (mystack->m_Size == 0) { return 1; }
//	else return 0;
//}
////����ջ
//void destroy_fun(SeqStack stack)
//{
//	delete stack;
//	stack = nullptr;
//}
