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
////��ʼ������
//LinkList initfun()
//{
//	LList* mylist = new(LList);
//	mylist->pPhead.next = nullptr;
//	mylist->m_Size = 0;
//	return mylist;
//}
////��������
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
//	LinkNode* p = (LinkNode*)date;  //ȡ���û����ݵ�ǰ�ĸ��ֽ�
//	p->next = pCurrent->next;
//	pCurrent->next = p;
//	mylist->m_Size++;
//}
////����Person������
//struct Person
//{
//	LinkNode* node;
//	char name[20];
//	int age;
//};
//
//
//
////��ӡ����
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
////��ֵɾ��Ԫ��
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
//		if (myComoare(p2, date))   //�ҵ���ʱ��p2��Ҫɾ����Ԫ��
//		{
//			p1->next = p2->next;
//			mylist->m_Size--;
//		}
//		p1 = p1->next;  p2 = p2->next;
//	}
//}
////��λ��ɾ��Ԫ��
//void removefun(LinkList list, int pos)
//{
//	LList* mylist = (LList*)list;
//	LinkNode* pCurrent = &mylist->pPhead;
//	for (int i = 0; i < pos; i++)
//	{
//		pCurrent = pCurrent->next;
//	}
//	LinkNode* Del = pCurrent->next;   //��ǰҪɾ����Ԫ��
//	pCurrent->next = Del->next;
//	mylist->m_Size--;
//}
////���
//void clear(LinkList list)
//{
//	LList* mylist = (LList*)list;
//	mylist->m_Size = 0;
//	mylist->pPhead.next = nullptr;
//}
////�õ�����
//int  Size(LinkList list)
//{
//	LList* mylist = (LList*)list;
//	return mylist->m_Size;
//}
////����
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
//    Person p1 = { NULL,"��1", 18 };
//	Person p2 = { NULL,"��2", 28 };
//	Person p3 = { NULL,"��3", 38 };
//	Person p4 = { NULL,"��4", 48 };
//	Person p5 = { NULL,"��5", 58 };
//	Person p6 = { NULL,"��6", 68 };
//	insertfun(list, &p1, 0);
//	insertfun(list, &p2, 1);
//	insertfun(list, &p3, 0);
//	insertfun(list, &p4, -1);
//	insertfun(list, &p5, 0);
//	insertfun(list, &p6, 100);
//	foreachfun(list, myprint);
//	cout << "ɾ��������Ԫ��" << endl;
//	removefun(list, 2);
//	foreachfun(list, myprint);
//	cout << "ɾ����Ϊ5" << endl;
//	Person p{ nullptr,"��5",58 };
//	removefun2(list, &p,mycompare);
//	foreachfun(list, myprint);
//	cout << "��տ�ʼ" << endl;
//	clear(list);
//	cout << "��պ�ĳ���:" <<Size(list)<< endl;
//	destroy(list);
//}
//int main()
//{
//	test01();
//}
//
//
//
