#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//#include<vld.h>
//
//
//
//struct Node
//{
//	int date;
//	Node* next;
//};
// Node* initlist_fun()
//{
//	Node* headNode = new Node;
//	headNode->date = NULL;
//	headNode->next = nullptr;
//	return headNode;
//}
//Node* initNode_fun(int date)
//{
//	Node* myNode = new Node;
//	myNode->date = date;
//	myNode->next = nullptr;
//	return myNode;
//}
//void print_fun(Node* headNode)
//{
//	Node* pNode = headNode->next;
//	while (pNode)
//	{
//		cout << pNode->date << "  ";
//		pNode = pNode->next;
//	}
//	cout << endl;
//}
//void insert_fun(Node* headNode, int date)
//{
//	Node* myNode = initNode_fun(date);
//	myNode->next = headNode->next;
//	headNode->next = myNode;
//}
//void remove_fun(Node* headNode, int date)//��ֵ����ɾ��
//{
//	Node* pCurrentNode = headNode->next;
//	Node* pFrontNode = headNode;
//	if (pCurrentNode == nullptr) { cout << "�޷�ɾ����������Ϊ��" << endl; }
//	else
//	{
//		while (pCurrentNode->date != date)
//		{
//			pFrontNode = pCurrentNode;
//			pCurrentNode = pCurrentNode->next;
//			if (pCurrentNode == nullptr) { cout << "δ�ҵ������Ϣ" << endl; return; }
//		}
//		pFrontNode->next = pCurrentNode->next;
//		delete pCurrentNode;
//		pCurrentNode = nullptr;
//	}
//}
//void remove_fun2(Node* headNode, int pos)//��λ��ɾ��
//{
//	if (headNode->next ==nullptr) { return; }
//	Node* pCurrentNode = headNode;
//	for (int i = 0; i < pos-1; i++)
//	{
//		pCurrentNode = pCurrentNode->next;
//	}
//	Node* del = pCurrentNode->next;
//	pCurrentNode->next = del->next;
//	delete del;
//	del = nullptr;
//}
//void destory_fun(Node* headNode)
//{
//	while (headNode != nullptr)
//	{
//		Node* p = headNode->next;
//		delete headNode;
//		headNode = p;
//	}
//}
//
//
//
//int main()
//{
//	Node* list = initlist_fun();
//	insert_fun(list, 1);
//	insert_fun(list, 25);
//	insert_fun(list, 3);
//	cout << "����1 25 3 ��Ĵ�ӡ���Ϊ��" << endl;
//	print_fun(list);
//	remove_fun(list, 25);
//	cout << "ɾ��Ԫ��25��:" << endl;
//	print_fun(list);
//	remove_fun2(list, 2);
//	cout << "ɾ���ڶ���Ԫ�غ�:" << endl;
//	print_fun(list);
//	destory_fun(list);
//}
//












