#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//#include<stack>
//
//struct BinaryNode
//{
//	char ch;
//	BinaryNode* LChild;
//	BinaryNode* RChild;
//	bool flag;
//};
//BinaryNode nodeA = { 'A',NULL,NULL,0 };
//BinaryNode nodeB = { 'B',NULL,NULL,0 };
//BinaryNode nodeC = { 'C',NULL,NULL,0 };
//BinaryNode nodeD = { 'D',NULL,NULL,0 };
//BinaryNode nodeE = { 'E',NULL,NULL,0 };
//BinaryNode nodeF = { 'F',NULL,NULL,0 };
//BinaryNode nodeG = { 'G',NULL,NULL,0 };
//BinaryNode nodeH = { 'H',NULL,NULL,0 };
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
//void recursion(struct BinaryNode* root) // 递归遍历
//{
//	if (root == nullptr) { return; }
//	recursion(root->LChild);
//	cout << root->ch << endl;
//	recursion(root->RChild);
//}
////非递归遍历
//void norecursion(struct BinaryNode* root)
//{
//	stack<BinaryNode*> s1;
//	s1.push(root);
//	while (!s1. empty())
//	{
//		BinaryNode* tmp = s1.top();
//		s1.pop();
//		if (tmp->flag == 1)
//		{
//			cout << tmp->ch << " ";
//			continue;
//		}
//		tmp->flag = 1;
//		if (tmp->RChild)
//		{
//			s1.push(tmp->RChild);
//		}
//		if (tmp->LChild)
//		{
//			s1.push(tmp->LChild);
//		}
//		s1.push(tmp);
//	}
//}
//void cacullateLeafNum(BinaryNode* root, int* p)//计算叶子数
//{
//	if (root == nullptr) { return; }
//	if (root->LChild == NULL && root->RChild == NULL)
//	{
//		(* p)++;
//	}
//	cacullateLeafNum(root->LChild,p);
//	cacullateLeafNum(root->RChild,p);
//}
//int get_Height(BinaryNode* root)
//{
//	if (root == nullptr) { return 0; }
//	int LHeight = get_Height(root->LChild);
//	int RHeight = get_Height(root->RChild);
//	int height = LHeight > RHeight ? LHeight + 1 : RHeight + 1;
//	return height;
//}
//BinaryNode* Copy_fun(BinaryNode* root)//拷贝树
//{
//	if (root == nullptr) { return nullptr; }
//	BinaryNode* LChild = Copy_fun(root->LChild);
//	BinaryNode* RChild = Copy_fun(root->RChild);
//	BinaryNode* newNode = new(BinaryNode);
//	newNode->LChild = LChild;
//	newNode->RChild = RChild;
//	newNode->ch = root->ch;
//	return newNode;
//}
//void destroy_fun(BinaryNode* root)
//{
//	if (root == NULL) { return; }
//	destroy_fun(root->LChild);
//	destroy_fun(root->RChild);
//	delete root;
//	root = nullptr;
//}
//
//void test01() //遍历
//{
//	recursion(&nodeA);
//}
//void test02()// 求叶子数
//{
//	int num=0;
//	cacullateLeafNum(&nodeA, &num);
//	cout << num << endl;
//}
//void test03() //求深度
//{
//	cout << get_Height(&nodeA) << endl;
//}
//
//int main()
//{
//	zuhe();
//	//test01();
//	//test02();
//	//test03();
//	norecursion(&nodeA);
//	//BinaryNode* newNode = Copy_fun(&nodeA);
//	cout << "+++++++++++++++" << endl;
//	//recursion(newNode);
//	//destroy_fun(newNode);
//}







