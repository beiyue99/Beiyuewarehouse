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
//LinkList init_fun()   //��ʼ������
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
//	}  //�ҵ�����λ�õ�ǰ�����λ��
//	struct LinkNode* newNode = new(LinkNode);//�����½ڵ�ṹ��
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
//    LinkNode* newNode = p1->pHeader.next; //�����Ľڵ�ṹ�����ͷ��������ʵ�������ݵĽṹ��
//	for (int i = 0; i < p1->m_Size; i++)
//	{
//		myprint(newNode->date);
//		newNode = newNode->next;
//	}
//}
//void remove_fun(LinkList list, int pos)//��λ�ý���ɾ��
//{
//	if (list == nullptr) { return; }
//	struct LList* mylist = (LList*)list;
//	if (pos<0 || pos>mylist->m_Size-1)
//	{
//		return;
//	}
//	struct LinkNode* pCurrent = &mylist->pHeader;
//	for (int i = 0; i < pos-1; i++)  //�ҵ���ɾ��λ�õ�ǰ�����λ��
//	{
//		pCurrent = pCurrent->next;
//	}
//	struct LinkNode* pDel = pCurrent->next;  //��¼��ɾ���Ľڵ�
//	pCurrent->next = pDel->next;
//	delete pDel;  pDel = nullptr;
//	mylist->m_Size--;
//}
//void removefun2(LinkList list, void* date,int(*myCompare)(void*,void*))//��ֵɾ��Ԫ��
//{
//	if (list == nullptr) { return; }  if (date == nullptr) { return; }
//	struct LList* mylist = (LList*)list;
//	LinkNode* pPrev = &mylist->pHeader;   //������������ָ�����
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
//	LinkNode* p1 = mylist->pHeader.next;//p1Ϊ��ʵ�����ݵĽڵ�ṹ��
//	for (int i = 0; i < mylist->m_Size; i++)
//	{
//		LinkNode* p = p1->next;//��¼��һ���ڵ�
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
//	Person p1 = { "��1", 18 };
//	Person p2 = { "��2", 28 };
//	Person p3 = { "��3", 38 };
//	Person p4 = { "��4", 48 };
//	Person p5 = { "��5", 58 };
//	Person p6 = { "��6", 68 };
//	insert_fun(list, 0, &p1);
//	insert_fun(list, 1, &p2);
//	insert_fun(list, 1, &p3);
//	insert_fun(list, 0, &p4);
//	insert_fun(list,-1, &p5);
//	insert_fun(list, 0, &p6);
//	foreach_fun(list, myprint);
//	cout << "��Ҫ��λ��ɾ����3��λ�õ�Ԫ������" << endl;
//	remove_fun(list,3);
//	foreach_fun(list, myprint);
//	Person p = { "��6",68 };
//	cout << "��Ҫ��ֵɾ����Ϊ��6��Ԫ������" << endl;
//	removefun2(list, &p, comparePerson);
//	foreach_fun(list, myprint);
//	cout << "��ʱ����ĳ���Ϊ:"<<Size(list) << endl;
//	cout << "��Ҫ�����������" << endl;
//	clear(list);
//	cout << "��ʱ����ĳ���Ϊ:"<<Size(list) << endl;
//	cout << "��Ҫ����������!" << endl;
//	destroy(list);
//	list = nullptr;
//}
//int main()
//{
//	test01();
//}














