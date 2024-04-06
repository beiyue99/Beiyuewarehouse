#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//#include<vld.h>
#include"Õ»µÄË³Ðò´æ´¢.hpp"

//
//struct BinaryNode
//{
//	char ch;
//	BinaryNode* LChild;
//	BinaryNode* RChild;
//	int flag;
//};
//BinaryNode nodeA = { 'A',NULL,NULL,0};
//BinaryNode nodeB = { 'B',NULL,NULL,0};
//BinaryNode nodeC = { 'C',NULL,NULL,0};
//BinaryNode nodeD = { 'D',NULL,NULL,0};
//BinaryNode nodeE = { 'E',NULL,NULL,0};
//BinaryNode nodeF = { 'F',NULL,NULL,0};
//BinaryNode nodeG = { 'G',NULL,NULL,0};
//BinaryNode nodeH = { 'H',NULL,NULL,0};
//void zuhe()
//{
//	nodeA.LChild = &nodeB;
//	nodeA.RChild = &nodeF;
//	nodeB.RChild = &nodeC;
//	nodeC.LChild = &nodeD;
//	nodeC.RChild = &nodeE;
//	nodeF.RChild = &nodeG;
//	nodeG.LChild = &nodeH;
//}
//
//int main()
//{
//	zuhe();
//	SStack *stack =(SStack*) init_fun();
//	push_fun(stack, &nodeA);
//	while (getSize_fun(stack) > 0)
//	{
//		BinaryNode* node = (BinaryNode*)getTop_fun(stack);
//		pop_fun(stack);
//		if (node->flag == 1)
//		{
//			cout << node->ch  << endl;
//			continue;
//		}
//		node->flag = 1;
//		if (node->RChild != nullptr)
//		{
//			push_fun(stack, node->RChild);
//		}
//		if (node->LChild != nullptr)
//		{
//			push_fun(stack, node->LChild);
//		}
//		push_fun(stack, node);
//	}
//	destroy_fun(stack);
//}
