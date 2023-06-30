#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
//#include"栈的顺序存储.hpp"
using namespace std;
//
//int isLeft(char ch)
//{
//	return ch == '(';
//}
//int isRight(char ch)
//{
//	return ch == ')';
//}
//void printError(const char* str, const char* errorMsg,const char* p)
//{
//	cout << "错误信息：" << errorMsg << endl << str << endl;
//	int num = p - str;
//	for (int i = 0; i < num; i++)
//	{
//		cout << " ";
//	}
//	cout << "A" << endl;
//}
//void test01()
//{
//	const char* str = "5+5*(6)+9/3*1-(1+3(";
//	const char* p = str;
//	SeqStack myStack = init_fun();
//	while (*p != '\0')
//	{ 
//		if (isLeft(*p))
//		{
//			push_fun(myStack, (void*)p);  
//		}
//		if (isRight(*p))
//		{
//			if (getSize_fun(myStack) > 0)
//			{
//				pop_fun(myStack);
//			}
//			else
//			{
//				printError(str, "右括号没有匹配到左括号",p);
//				break;
//			}
//		}
//		p++;
//	}
//	while (getSize_fun(myStack) > 0)
//	{
//		printError(str, "左括号没有匹配到右括号", (const char*)getTop_fun(myStack));
//		pop_fun(myStack);
//	}
//	destroy_fun(myStack);
//	myStack = nullptr;
//}
//int main()
//{
//	test01();
//}













//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#define MAX 50
//typedef char DataType;
//typedef struct {
//	DataType data[MAX];
//	int top;
//}SeqStack;
//void initStack(SeqStack& S) {
//	S.top = -1;
//}
//int StackEmpty(SeqStack& S) {
//	if (S.top == -1) {
//		return 1;
//	}
//	return 0;
//}
//int Push(SeqStack& S, DataType x) {
//	if (S.top == MAX - 1) {
//		return 0;
//	}
//	else {
//		S.top++;
//		S.data[S.top] = x;
//		return 1;
//	}
//}
//int Pop(SeqStack& S) {
//	if (S.top == -1) {
//		return 0;
//	}
//	else {
//		S.top--;
//
//		return 1;
//	}
//}
//int gettop(SeqStack& S, char& y) {
//	if (S.top == -1) {
//		return 0;
//	}
//	else {
//		y = S.data[S.top];
//		return 1;
//	}
//}
//int pipei(char x, char y)           //取栈顶元素   ([ ))结果正确       [())结果错误
//{
//	if     ( (x == '(') &&( y == ')')  || (x == '[') && (y == ']') || (x == '{') && (y == '}'))
//	{
//		return 1;
//	}
//	else
//		return 0;
//}
//void Match(char str[], int length) {
//	SeqStack S;
//	initStack(S);
//	char topdata=0;
//	for (int i = 0; i < length; i++) 
//	{
//		if (str[i] == '(' || str[i] == '[' || str[i] == '{') 
//		{//左括号入栈 
//			Push(S, str[i]);
//		}
//		else if(str[i] == ')' || str[i] == ']' || str[i] == '}')
//		{//右括号匹配 
//			if (StackEmpty(S)) 
//			{
//				printf("右括号多余\n"); return;
//			}
//			else 
//			{
//				gettop(S, topdata);      //取栈顶元素   ([ ))结果正确       [())结果错误
//				if (pipei(topdata, str[i]))
//				{
//					Pop(S);
//				}
//				else
//				{
//					printf("左右括号不同类\n"); return;
//			    }
//			}
//		}
//
//	}
//	if (StackEmpty(S)) 
//	{    //若栈空，则匹配成功 
//		printf("匹配成功\n");
//	}
//	else
//		printf("左括号多余\n");//栈不空，左括号多余 
//}
//int main() {
//	char str[MAX];
//	int n;
//	scanf("%d", &n);
//	scanf("%s", &str);
//	Match(str, n);
//	return 0;
//}















#include<iostream>
using namespace std;
#include<stack>

