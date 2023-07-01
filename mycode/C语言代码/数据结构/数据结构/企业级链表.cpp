//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<iostream>
//using namespace std;
//#include<vld.h>
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//struct LinkNode
//{
//	LinkNode* next;
//};
//struct LList
//{
//	LinkNode pPhead;
//	int m_Size;
//};
//typedef void* LinkList;
////初始化链表
//LinkList initfun()
//{
//	LList* mylist = new(LList);
//	mylist->pPhead.next = nullptr;
//	mylist->m_Size = 0;
//	return mylist;
//}
////插入数据
//void insertfun(LinkList list, LinkList date, int pos)
//{
//	LList* mylist = (LList*)list;
//	if (pos<0 || pos>mylist->m_Size)
//	{
//		pos = mylist->m_Size;
//	}
//	LinkNode* pCurrent = &mylist->pPhead;
//	for (int i = 0; i < pos; i++)
//	{
//		pCurrent = pCurrent->next;
//	}
//	LinkNode* p = (LinkNode*)date;  //取出用户数据的前四个字节
//	p->next = pCurrent->next;
//	pCurrent->next = p;
//	mylist->m_Size++;
//}
////创建Person数据类
//struct Person
//{
//	LinkNode* node;
//	char name[20];
//	int age;
//};
//
//
//
////打印数据
//void myprint(LinkList list)
//{
//	Person*p1 = (Person*)list;
//	cout << p1->name << "  " << p1->age << endl;
//}
//void foreachfun(LinkList list,void(*myPrint)(LinkList))
//{
//	LList* mylist = (LList*)list; 
//	LinkNode* pCurrent = mylist->pPhead.next;
//	
//	for (int i = 0; i < mylist->m_Size; i++)
//	{
//		myPrint(pCurrent);
//		pCurrent = pCurrent->next;
//	}
//}
////按值删除元素
//int mycompare(LinkList date1, LinkList date2)
//{
//	Person* p1 = (Person*)date1;
//	Person* p2 = (Person*)date2;
//	return strcmp(p1->name , p1->name) == 0 && p1->age == p2->age;
//}
//void removefun2(LinkList list, LinkList date, int(*myComoare)(LinkList, LinkList))
//{
//	LList* mylist = (LList*)list;
//	LinkNode* p1 = &mylist->pPhead;
//	LinkNode* p2 = mylist->pPhead.next;
//	for (int i = 0; i < mylist->m_Size; i++)
//	{
//		if (myComoare(p2, date))   //找到此时的p2是要删除的元素
//		{
//			p1->next = p2->next;
//			mylist->m_Size--;
//		}
//		p1 = p1->next;  p2 = p2->next;
//	}
//}
////按位置删除元素
//void removefun(LinkList list, int pos)
//{
//	LList* mylist = (LList*)list;
//	LinkNode* pCurrent = &mylist->pPhead;
//	for (int i = 0; i < pos; i++)
//	{
//		pCurrent = pCurrent->next;
//	}
//	LinkNode* Del = pCurrent->next;   //当前要删除的元素
//	pCurrent->next = Del->next;
//	mylist->m_Size--;
//}
////清空
//void clear(LinkList list)
//{
//	LList* mylist = (LList*)list;
//	mylist->m_Size = 0;
//	mylist->pPhead.next = nullptr;
//}
////得到长度
//int  Size(LinkList list)
//{
//	LList* mylist = (LList*)list;
//	return mylist->m_Size;
//}
////销毁
//void destroy(LinkList list)
//{
//	LList* mylist = (LList*)list;
//	delete mylist;
//	mylist = nullptr;
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
//
//
//
//
//void test01()
//{
//	LinkList list = initfun();
//    Person p1 = { NULL,"赵1", 18 };
//	Person p2 = { NULL,"赵2", 28 };
//	Person p3 = { NULL,"赵3", 38 };
//	Person p4 = { NULL,"赵4", 48 };
//	Person p5 = { NULL,"赵5", 58 };
//	Person p6 = { NULL,"赵6", 68 };
//	insertfun(list, &p1, 0);
//	insertfun(list, &p2, 1);
//	insertfun(list, &p3, 0);
//	insertfun(list, &p4, -1);
//	insertfun(list, &p5, 0);
//	insertfun(list, &p6, 100);
//	foreachfun(list, myprint);
//	cout << "删除第三个元素" << endl;
//	removefun(list, 2);
//	foreachfun(list, myprint);
//	cout << "删除名为5" << endl;
//	Person p{ nullptr,"赵5",58 };
//	removefun2(list, &p,mycompare);
//	foreachfun(list, myprint);
//	cout << "清空开始" << endl;
//	clear(list);
//	cout << "清空后的长度:" <<Size(list)<< endl;
//	destroy(list);
//}
//int main()
//{
//	test01();
//}
//
//
//
