#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//��д���������»����������㷨�Ĳ���������㷨��������
//1����ʼ��һ���յĵ�����L��
//2���ж�L�Ƿ��ǿա�
//3����ֵ33, 24, 231, 3, 11���������������L�С�
//4����ȡL�ĳ��ȡ�
//5����ֵΪ11�Ľ����뵽L�ĵ�3��λ�á�
//6����L�׶˲���ֵΪ25 �Ľ�㡣
//7��ɾ��L�е�4��λ�õĽ�㡣
//8������L�е�3��λ�ý���ֵ��
//9�����������L�е����н�㡣

//#include<iostream>
//using namespace std;
//typedef struct LNode 
//{
//	int data;                     
//	struct LNode* next;
//}LNode, * LinkList;
//
//LinkList initlist_fun()
//{
//	LinkList HeadNode = new(LNode);
//	HeadNode->data = NULL;
//	HeadNode->next = nullptr;
//	return HeadNode;
//}
//LinkList initNode_fun(int x)
//{
//	LinkList Node = new(LNode);
//	Node->data = x;
//	Node->next = nullptr;
//	return Node;
//}
//LinkList GetPos(LinkList HeadNode, int pos)//����posλ�õĽڵ�
//{
//	LinkList p = HeadNode;
//	for (int i = 0; i < pos; i++)
//	{
//		p = p->next;
//	}
//	return p;
//}
//void print(LinkList HeadNode)  //����
//{
//	LinkList p = HeadNode->next;
//	while (p)
//	{
//		cout << p->data << " ";
//		p = p->next;
//	}
//}
//void remove_fun(LinkList HeadNode, int pos) //��λ��ɾ��
//{
//	LinkList p = HeadNode;
//	for (int i = 0; i < pos-1; i++)
//	{
//		p = p->next;
//	}
//	LinkList del = p->next;  //Ҫɾ���Ľڵ�
//	p->next = del->next;
//	delete del;
//	del = nullptr;
//}
//void insert_fun(LinkList HeadNode, int pos,int x)//��λ�ò���
//{
//	if (pos < 1) { return; }
//	LinkList Node = HeadNode;
//	for (int i = 1; i < pos; i++)
//	{
//		if (Node->next != nullptr)
//		{
//			Node = Node->next;   //�ҵ�������λ�õ�ǰ�����
//		}
//	}
//	LinkList NewNode = initNode_fun(x);
//	NewNode->next = Node->next;
//	Node->next = NewNode;
//}
//string isEmpty(LinkList HeadNode)
//{
//	if (HeadNode->next == nullptr) { return "true"; }
//	else return "false";
//}
//int GetLen(LinkList HeadNode)
//{
//	int i = 0;
//	while (HeadNode)
//	{
//		i++;
//		HeadNode = HeadNode->next;
//	}
//	return i;
//}
//
//
//
//
//
//
//
//int main()
//{
//	LinkList L1 = initlist_fun();
//	cout << "��Ҫ������Ԫ�����β����" << endl;
//	insert_fun(L1, 1, 33);
//	insert_fun(L1, 2, 24);
//	insert_fun(L1, 3, 231);
//	insert_fun(L1, 4, 3);
//	insert_fun(L1, 5, 31);
//	print(L1);
//	cout << endl << "����ͷ����������Ϊ:" << " " << GetLen(L1) << endl;
//	cout << "�����Ƿ�Ϊ�գ�" << isEmpty(L1) << endl;
//	insert_fun(L1, 3, 11);
//	cout << "��11���뵽������λ�ú�:" << endl;
//	print(L1);
//	cout << endl << "���ײ�����25��:" << endl;
//	insert_fun(L1, 1, 25);
//	print(L1); 
//	cout << endl << "ɾ�����ĸ�λ�õĽڵ��:" << endl;
//	remove_fun(L1, 4);
//	print(L1);
//	cout << endl << "���ҵ�����λ�õ�Ԫ��:" << GetPos(L1, 3)->data << endl;
//
//}









//#include<Windows.h>
//#include<iostream>
//using namespace std;
//
//struct Apple
//{
//	string name;
//	int price;
//};
//struct LinkNode
//{
//	Apple* date;
//	LinkNode* next;
//};
//struct LList
//{
//	LinkNode pHead;
//	int m_size;
//};
//
//
//LList* init_fun()
//{
//	LList* mylist = new (LList);
//	mylist->pHead.date = NULL;
//	mylist->pHead.next = nullptr;
//	mylist->m_size = 0;
//	return mylist;
//}
//void insert_fun(LList* mylist, int pos, Apple* date)
//{
//	if (pos > mylist->m_size || pos < 0)
//	{
//		pos = mylist->m_size;
//	}
//	LinkNode* p = &mylist->pHead;
//	for (int i = 0; i < pos; i++)
//	{
//		p = (p->next);          //�ҵ�ǰ��λ�ýڵ�      �±�0��ʾ��һ��λ�ã��Դ�����
//	}
//	LinkNode* newNode = new (LinkNode);
//	newNode->date = date;
//	newNode->next = nullptr;
//	p->next = newNode;
//	mylist->m_size++;
//}
//void myPrint(Apple* date)
//{
//	cout << date->name << "  " << date->price<<'\t';
//}
//void print(LList mylist,void (* myPrint)(Apple* date))
//{
//	while (mylist.pHead.next)
//	{
//		myPrint(mylist.pHead.next->date);
//		mylist.pHead = *mylist.pHead.next;
//	}
//}
//void reverse_fun(LList& mylist)
//{
//	LinkNode* pC = mylist.pHead.next->next;
//	mylist.pHead.next->next = nullptr;
//	while (pC!=nullptr)
//	{
//		LinkNode* p = pC->next;
//		pC->next = mylist.pHead.next;
//		mylist.pHead.next = pC;
//		pC = p;
//	}
//}
//void del(LList* mylist)
//{
//	LinkNode* Pc = mylist->pHead.next;
//	while (Pc)
//	{
//		LinkNode* p = Pc->next;
//		delete Pc;
//		Pc = p;
//	}
//	delete mylist;
//}
//
//
//int main()
//{
//	Apple a1{ "Сƻ��",25 };
//	Apple a2{ "��ƻ��",29 };
//	Apple a3{ "��ƻ��",48 };
//	Apple a4{ "���ƻ��",90 };
//	LList* L1 = init_fun();
//	insert_fun(L1, 0, &a1);
//	insert_fun(L1, 1, &a2);
//	insert_fun(L1, 2, &a3);
//	insert_fun(L1, 3, &a4);
//	print(*L1,myPrint);
//	cout << "��ת��" << endl;
//	reverse_fun(*L1);
//	print(*L1,myPrint);
//	//del(L1);
//	//L1 = nullptr;
//}















