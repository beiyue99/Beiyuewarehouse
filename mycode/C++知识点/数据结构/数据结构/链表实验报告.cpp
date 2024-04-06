#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//请写出满足以下基本操作的算法的操作步骤和算法的描述。
//1．初始化一个空的单链表L。
//2．判断L是否是空。
//3．将值33, 24, 231, 3, 11几个结点依次链入L中。
//4．获取L的长度。
//5．将值为11的结点插入到L的第3个位置。
//6．在L首端插入值为25 的结点。
//7．删除L中第4个位置的结点。
//8．查找L中第3个位置结点的值。
//9．遍历并输出L中的所有结点。

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
//LinkList GetPos(LinkList HeadNode, int pos)//返回pos位置的节点
//{
//	LinkList p = HeadNode;
//	for (int i = 0; i < pos; i++)
//	{
//		p = p->next;
//	}
//	return p;
//}
//void print(LinkList HeadNode)  //遍历
//{
//	LinkList p = HeadNode->next;
//	while (p)
//	{
//		cout << p->data << " ";
//		p = p->next;
//	}
//}
//void remove_fun(LinkList HeadNode, int pos) //按位置删除
//{
//	LinkList p = HeadNode;
//	for (int i = 0; i < pos-1; i++)
//	{
//		p = p->next;
//	}
//	LinkList del = p->next;  //要删除的节点
//	p->next = del->next;
//	delete del;
//	del = nullptr;
//}
//void insert_fun(LinkList HeadNode, int pos,int x)//按位置插入
//{
//	if (pos < 1) { return; }
//	LinkList Node = HeadNode;
//	for (int i = 1; i < pos; i++)
//	{
//		if (Node->next != nullptr)
//		{
//			Node = Node->next;   //找到待插入位置的前驱结点
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
//	cout << "将要求的五个元素依次插入后：" << endl;
//	insert_fun(L1, 1, 33);
//	insert_fun(L1, 2, 24);
//	insert_fun(L1, 3, 231);
//	insert_fun(L1, 4, 3);
//	insert_fun(L1, 5, 31);
//	print(L1);
//	cout << endl << "算上头结点后，链表长度为:" << " " << GetLen(L1) << endl;
//	cout << "数组是否为空？" << isEmpty(L1) << endl;
//	insert_fun(L1, 3, 11);
//	cout << "将11插入到第三个位置后:" << endl;
//	print(L1);
//	cout << endl << "再首部插入25后:" << endl;
//	insert_fun(L1, 1, 25);
//	print(L1); 
//	cout << endl << "删除第四个位置的节点后:" << endl;
//	remove_fun(L1, 4);
//	print(L1);
//	cout << endl << "查找第三个位置的元素:" << GetPos(L1, 3)->data << endl;
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
//		p = (p->next);          //找到前驱位置节点      下标0表示第一个位置，以此类推
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
//	Apple a1{ "小苹果",25 };
//	Apple a2{ "红苹果",29 };
//	Apple a3{ "大苹果",48 };
//	Apple a4{ "大红苹果",90 };
//	LList* L1 = init_fun();
//	insert_fun(L1, 0, &a1);
//	insert_fun(L1, 1, &a2);
//	insert_fun(L1, 2, &a3);
//	insert_fun(L1, 3, &a4);
//	print(*L1,myPrint);
//	cout << "翻转后：" << endl;
//	reverse_fun(*L1);
//	print(*L1,myPrint);
//	//del(L1);
//	//L1 = nullptr;
//}















