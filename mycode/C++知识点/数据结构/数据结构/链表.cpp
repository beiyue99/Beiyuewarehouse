//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<iostream>
//using namespace std;
//#include<iomanip>
//#include<vld.h>
//
//
//
//
//
//
//struct LinkNode    
//{
//	void* date;                
//  LinkNode* next;   
//};
//struct LList   
//{
//  LinkNode pHeader;
//	int m_Size;      
//};
//typedef void* LinkList;
//LinkList init_fun()   //初始化链表
//{
//	struct LList* mylist = new(struct LList);
//	if (mylist == nullptr) { return nullptr; }
//	mylist->pHeader.date = nullptr;
//	mylist->pHeader.next = nullptr;
//	mylist->m_Size = 0;
//	return mylist;
//}
//void insert_fun(LinkList list, int pos, void* date)
//{
//	if (list == nullptr) { return; }
//	if (date == nullptr) { return; }
//	struct LList* mylist = (LList*)list;
//	if (pos<0 || pos>mylist->m_Size)
//	{
//		pos = mylist->m_Size; 
//	}  
//	struct LinkNode* pCurrent = &mylist->pHeader;
//	for (int i = 0; i < pos; i++)
//	{
//		pCurrent = pCurrent->next;
//	}  //找到插入位置的前驱结点位置
//	struct LinkNode* newNode = new(LinkNode);//创建新节点结构体
//	newNode->next = nullptr;
//	newNode->date = date;
//	newNode->next = pCurrent->next;  
//	pCurrent->next = newNode;
//	mylist->m_Size++;  
//}
//
//
//
//struct Person
//{
//	char name[20];
//	int age;
//};
//void myprint( void* date)
//{
//	Person* p = (Person*)date;
//	cout << p->name << "  " << p->age << endl;
//}
//void foreach_fun(LinkList list, void(*myPrint)(void*date))
//{
//	LList* p1 = (LList*)list;
//    LinkNode* newNode = p1->pHeader.next; //创建的节点结构体就是头结点后面真实储存数据的结构体
//	for (int i = 0; i < p1->m_Size; i++)
//	{
//		myprint(newNode->date);
//		newNode = newNode->next;
//	}
//}
//void remove_fun(LinkList list, int pos)//按位置进行删除
//{
//	if (list == nullptr) { return; }
//	struct LList* mylist = (LList*)list;
//	if (pos<0 || pos>mylist->m_Size-1)
//	{
//		return;
//	}
//	struct LinkNode* pCurrent = &mylist->pHeader;
//	for (int i = 0; i < pos-1; i++)  //找到待删除位置的前驱结点位置
//	{
//		pCurrent = pCurrent->next;
//	}
//	struct LinkNode* pDel = pCurrent->next;  //记录待删除的节点
//	pCurrent->next = pDel->next;
//	delete pDel;  pDel = nullptr;
//	mylist->m_Size--;
//}
//void removefun2(LinkList list, void* date,int(*myCompare)(void*,void*))//按值删除元素
//{
//	if (list == nullptr) { return; }  if (date == nullptr) { return; }
//	struct LList* mylist = (LList*)list;
//	LinkNode* pPrev = &mylist->pHeader;   //创建两个辅助指针变量
//	LinkNode* pCurrent = mylist->pHeader.next;
//	for (int i = 0; i < mylist->m_Size; i++)
//	{
//		if (myCompare(date, pCurrent->date))
//		{
//			pPrev->next = pCurrent->next;
//			delete pCurrent;
//			pCurrent = nullptr;
//			mylist->m_Size--;   break;
//		}
//		pPrev = pCurrent;
//		pCurrent = pCurrent->next;
//	}
//}
//int comparePerson(void* date1, void* date2)
//{
//	Person* p1 = (Person*)date1;
//	Person* p2 = (Person*)date2;
//	return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
//}
//int Size(LinkList list)
//{
//	LList* mylist = (LList*)list;
//	return mylist->m_Size;
//}
//void clear(LinkList list)
//{
//	LList* mylist = (LList*)list;
//	LinkNode* p1 = mylist->pHeader.next;//p1为真实有数据的节点结构体
//	for (int i = 0; i < mylist->m_Size; i++)
//	{
//		LinkNode* p = p1->next;//记录下一个节点
//		delete p1;
//		p1 = p;
//	}
//	mylist->m_Size = 0;
//	mylist->pHeader.next = nullptr;
//}
//void destroy(LinkList list)
//{
//	LList* mylist = (LList*)list;
//	clear(mylist);
//	delete mylist;
//	mylist = nullptr;
//}
//
//
//
//
//void test01()
//{
//	LinkList list = init_fun();
//	Person p1 = { "赵1", 18 };
//	Person p2 = { "赵2", 28 };
//	Person p3 = { "赵3", 38 };
//	Person p4 = { "赵4", 48 };
//	Person p5 = { "赵5", 58 };
//	Person p6 = { "赵6", 68 };
//	insert_fun(list, 0, &p1);
//	insert_fun(list, 1, &p2);
//	insert_fun(list, 1, &p3);
//	insert_fun(list, 0, &p4);
//	insert_fun(list,-1, &p5);
//	insert_fun(list, 0, &p6);
//	foreach_fun(list, myprint);
//	cout << "我要按位置删除第3个位置的元素啦！" << endl;
//	remove_fun(list,3);
//	foreach_fun(list, myprint);
//	Person p = { "赵6",68 };
//	cout << "我要按值删除名为赵6的元素啦！" << endl;
//	removefun2(list, &p, comparePerson);
//	foreach_fun(list, myprint);
//	cout << "此时链表的长度为:"<<Size(list) << endl;
//	cout << "我要清空链表啦！" << endl;
//	clear(list);
//	cout << "此时链表的长度为:"<<Size(list) << endl;
//	cout << "我要销毁链表了!" << endl;
//	destroy(list);
//	list = nullptr;
//}
//int main()
//{
//	test01();
//}














