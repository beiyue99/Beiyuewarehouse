//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<iostream>
//using namespace std;
//#include<iomanip>
//#include<vld.h>
//#include<chrono>
//#include<thread>
//
//
//
//struct Point
//{
//	int x;
//	int y;
//};
//struct City
//{
//	char name[20] = { 0 };
//	Point pp={0};
//};
//
//struct LinkNode
//{
//	void* date;
//	LinkNode* next;
//};
//struct LList
//{
//	LinkNode pHeader;
//	int m_Size;
//};
//typedef void* LinkList;
//LinkList init_fun2()   //��ʼ������
//{
//	struct LList* mylist = new(struct LList);
//	if (mylist == nullptr) { return nullptr; }
//	mylist->pHeader.date = nullptr;
//	mylist->pHeader.next = nullptr;
//	mylist->m_Size = 0;
//	return mylist;
//}
//LinkList list;
//void init_fun(LinkList& list)
//{
//	cout << "���ڳ�ʼ��������..." << endl;
//	chrono::seconds duar(2);
//	this_thread::sleep_for(duar);
//	cout << "�����ʼ���ɹ���" << endl;
//	list = init_fun2();
//}
//void insert_fun(LinkList list, int pos, void* date)
//{
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
//void insert()
//{
//	if (!list) { cout << "�����������ڣ��޷����룡" << endl; return; }
//	string s1; int x; int y; int pos;
//	cout << "������Ҫ����ĳ������ƣ�" << endl;
//	cin >> s1 ;
//	cout << "������Ҫ����ĳ������꣺" << endl;
//	cin >> x >> y ;
//	cout << "������Ҫ����ĳ���λ�ã�" << endl;
//	cin >>  pos;
//	Point* p1 = new Point;
//	City* c1 = new City;
//	p1->x = x;
//	p1->y = y;
//	c1->pp = *p1;
//	strcpy(c1->name, s1.c_str());
//	insert_fun(list, 3, c1);
//	cout << "����" << s1 << "����ɹ���" << endl;
//}
//void myprint(void* date)
//{
//	City* p = (City*)date;
//	cout << p->name << "  " << p->pp.x<<"  "<<p->pp.y  << endl;
//}
//void foreach_fun(LinkList list, void(*myPrint)(void* date))
//{
//	if (!list) { cout << "�����������ڣ�" << endl; return; }
//	LList* p1 = (LList*)list;
//	LinkNode* newNode = p1->pHeader.next; //�����Ľڵ�ṹ�����ͷ��������ʵ�������ݵĽṹ��
//	if (!newNode) { cout << "�����л�δ��������!" << endl; return; }
//	for (int i = 0; i < p1->m_Size; i++)
//	{
//		myprint(newNode->date);
//		newNode = newNode->next;
//	}
//}
//void remove_fun(LinkList& list, int pos)//��λ�ý���ɾ��
//{
//	struct LList* mylist = (LList*)list;
//	if (mylist->m_Size < pos||pos<=0) { cout << "��λ�ò����ڳ��нڵ�" << endl; return; }
//	struct LinkNode* pCurrent = &mylist->pHeader;
//	for (int i = 0; i < pos - 1; i++)  //�ҵ���ɾ��λ�õ�ǰ�����λ��
//	{
//		pCurrent = pCurrent->next;
//	}
//	struct LinkNode* pDel = pCurrent->next;  //��¼��ɾ���Ľڵ�
//	pCurrent->next = pDel->next;
//	delete pDel;  pDel = nullptr;
//	mylist->m_Size--;
//	cout << "�ɹ��Ƴ����ڵ�" << pos << "��λ�õĳ��нڵ�" << endl;
//}
//void remove()
//{
//	if (list == nullptr) { cout << "������������,�޷�ɾ����" << endl; return; }
//	cout << "�����Ƴ��ڼ������У�" << endl;
//	int k;
//	cin >> k;
//	remove_fun(list, k);
//}
//
// 
// 
// 
// 
// 
//void remove_fun2(LinkList& list, void* date, int(*myCompare)(void*, void*))//��ֵɾ��Ԫ��
//{
//	struct LList* mylist = (LList*)list;
//	LinkNode* pPrev = &mylist->pHeader;   //������������ָ�����
//	LinkNode* pCurrent = mylist->pHeader.next;
//	bool flag = false;
//	for (int i = 0; i < mylist->m_Size; i++)
//	{
//		if (myCompare(date, pCurrent->date))
//		{
//			flag = true;
//			pPrev->next = pCurrent->next;
//			delete pCurrent;
//			pCurrent = nullptr;
//			mylist->m_Size--;  
//			cout << "�ѳɹ�ɾ���ó��У�" << endl;
//			break;
//		}
//		pPrev = pCurrent;
//		pCurrent = pCurrent->next;
//	}
//	if (!flag) { cout << "δ�ҵ���س�����Ϣ��" << endl; }
//}
//int compareCity1(const char* s, void* date2)
//{
//	City* p2 = (City*)date2;
//	return   strcmp(s, p2->name) == 0;
//}
//int compareCity2(int a,int b, void* date2)
//{
//	City* p2 = (City*)date2;
//	return   p2->pp.x == a && p2->pp.y == b;
//}
//int compareCity3(int a, int b,int c, void* date2)
//{
//	City* p2 = (City*)date2;
//
//	return ( sqrt( (p2->pp.x - a) * (p2->pp.x - a) + (p2->pp.y - b)* (p2->pp.y - b))) <=c;
//}
//
//void find1(LinkList& list, const char* s) //�����Ʋ���
//{
//	struct LList* mylist = (LList*)list;
//	LinkNode* pPrev = &mylist->pHeader;
//	LinkNode* pCurrent = mylist->pHeader.next;
//	bool flag = false;
//	int count = 0;
//	for (int i = 0; i < mylist->m_Size; i++)
//	{
//		if (compareCity1(s, pCurrent->date))  //pCurrent���Ǹó���
//		{
//			flag = true;
//			count++;
//			cout << "�鵽�˵�" << count<< "����Ϊ" << s << "�ĳ���, �����ڵ�����Ϊ" << ((City*)(pCurrent->date))->pp.x << ", " << ((City*)(pCurrent->date))->pp.y << endl;
//		}
//		pPrev = pCurrent;
//		pCurrent = pCurrent->next;
//	}
//	if (!flag) { cout << "δ�ҵ���س�����Ϣ��" << endl; }
//}
//void find1()
//{
//	if (list == nullptr) { cout << "�����������ڣ��޷����в�����" << endl; return; }
//	string s1;
//	cout << "������Ҫ���ҵĳ�������" << endl;
//	cin >> s1;
//	find1(list, s1.c_str());
//}
//
//
//void find2(LinkList& list, int a,int b) //���������
//{
//	struct LList* mylist = (LList*)list;
//	LinkNode* pPrev = &mylist->pHeader;
//	LinkNode* pCurrent = mylist->pHeader.next;
//	bool flag = false;
//	for (int i = 0; i < mylist->m_Size; i++)
//	{
//		if (compareCity2(a,b, pCurrent->date))  //pCurrent���Ǹó���
//		{
//			flag = true;
//			cout << "�鵽�˵�����Ϊ" << a<<" "<<b << "�ĳ���, �����ڵ�����Ϊ" << ((City*)(pCurrent->date))->name<< endl;
//		}
//		pPrev = pCurrent;
//		pCurrent = pCurrent->next;
//	}
//	if (!flag) { cout << "δ�ҵ���س�����Ϣ��" << endl; }
//}
//void find2()
//{
//	if (list == nullptr) { cout << "�����������ڣ��޷����в�����" << endl; return; }
//	int a, b;
//	cout << "������Ҫ���ҵĳ������꣺" << endl;
//	cin >> a >> b;
//	find2(list, a,b);
//}
//void find3(LinkList& list, int a, int b, int c)
//{
//	struct LList* mylist = (LList*)list;
//	LinkNode* pPrev = &mylist->pHeader;
//	LinkNode* pCurrent = mylist->pHeader.next;
//	bool flag = false;
//	int count = 0;
//	for (int i = 0; i < mylist->m_Size; i++)
//	{
//		if (compareCity3(a,b,c,pCurrent->date))  //pCurrent���Ǹó���
//		{
//			flag = true;
//			count++;
//			cout << "�鵽�˵�"<<count<<"������С��"<<c <<"�ĳ���  "<< ((City*)(pCurrent->date))->name << endl;
//		}
//		pPrev = pCurrent;
//		pCurrent = pCurrent->next;
//	}
//	if (!flag) { cout << "δ�ҵ���س�����Ϣ��" << endl; }
//}
//void find3()
//{
//	if (list == nullptr) { cout << "�����������ڣ��޷����в�����" << endl; return; }
//	int a, b, c;
//	cout << "�������������꣺" << endl;
//	cin >> a >> b;
//	cout << "�����������ĵ�Ϊ���������ҵ������룺" << endl;
//	cin >> c;
//	find3(list, a,b,c);
//}
//void Dis(LinkList list,const char* s1,const char* s2)
//{
//	if (list == nullptr) { cout << "�����������ڣ��޷����в�����" << endl; return; }
//	struct LList* mylist = (LList*)list;
//	LinkNode* pPrev = &mylist->pHeader;
//	LinkNode* pCurrent = mylist->pHeader.next;
//	bool flag1 = false;
//	bool flag2 = false;
//	int arr[4]={0};
//	for (int i = 0; i < mylist->m_Size; i++)
//	{
//		if (compareCity1(s1, pCurrent->date))  //pCurrent���Ǹó���
//		{
//			flag1= true;
//			cout << "�鵽����Ϊ" << ((City*)(pCurrent->date))->name << "�ĳ���,��������Ϊ��" << ((City*)(pCurrent->date))->pp.x <<
//				((City*)(pCurrent->date))->pp.y << endl;
//			arr[0] = ((City*)(pCurrent->date))->pp.x; arr[1] = ((City*)(pCurrent->date))->pp.y;
//		}
//		if (compareCity1(s2, pCurrent->date))  //pCurrent���Ǹó���
//		{
//			flag2 = true;
//			cout << "�鵽����Ϊ" << ((City*)(pCurrent->date))->name << "�ĳ���,��������Ϊ��" << ((City*)(pCurrent->date))->pp.x <<
//				((City*)(pCurrent->date))->pp.y << endl;
//			arr[2] = ((City*)(pCurrent->date))->pp.x; arr[3] = ((City*)(pCurrent->date))->pp.y;
//		}
//		pPrev = pCurrent;
//		pCurrent = pCurrent->next;
//	}
//	if (!flag1) { cout << "δ�ҵ���һ��������Ϣ��" << endl; return; }
//	if (!flag2) { cout << "δ�ҵ��ڶ���������Ϣ��" << endl; return; }
//	cout << "�������еľ���Ϊ:" << sqrt((arr[0] - arr[2]) * (arr[0] - arr[2]) + (arr[1] - arr[3]) * (arr[1] - arr[3])) << endl;
//}
//void Dis()
//{
//	if (list == nullptr) { cout << "�����������ڣ��޷�������" << endl; return; }
//	string s1, s2;
//	cout << "�����������е����ƣ�" << endl;
//	cin >> s1 >> s2;
//	Dis(list, s1.c_str(), s2.c_str());
//}
//int compareCity(void* date1, void* date2)
//{
//	City* p1 = (City*)date1;
//	City* p2 = (City*)date2;
//	return   strcmp(p1->name, p2->name) == 0   &&   p1->pp.x == p2->pp.x && p1->pp.y == p2->pp.y;
//}
//void Size(LinkList list)
//{
//	if (list == nullptr) { cout << "�����������ڣ��޷�������" << endl; return; }
//	LList* mylist = (LList*)list;
//	cout << "���и���Ϊ��" << mylist->m_Size << endl;
//}
//void remove2()
//{
//	if (list == nullptr) { cout << "�����������ڣ��޷�ɾ����" << endl; return; }
//	int x, y;
//	string s1;
//	cout << "������Ҫɾ�����е����ƺ����꣺" << endl;
//	cin >> s1 >> x >> y;
//	Point p{ x,y };
//	City c;
//	strcpy(c.name, s1.c_str());
//	c.pp = p;
//	remove_fun2(list, &c, compareCity);
//}
//void clear(LinkList list)
//{
//	if (list == nullptr) { cout << "�����������ڣ��޷�������" << endl; return; }
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
//	if (list == nullptr) { cout << "�����������ڣ��޷�������" << endl; return; }
//	LList* mylist = (LList*)list;
//	clear(mylist);
//	delete mylist;
//	mylist = nullptr;
//}
//
//void menu()
//{
//	cout << "                                                             " << endl;
//	cout << "*****************************************************" << endl;
//	cout << "|==============��ӭʹ�ó����������ϵͳ=============|" << endl;
//	cout << "|___________________________________________________|" << endl;
//	cout << "|*-----> 0.�˳�����                                *|" << endl;
//	cout << "|*-----> 1.��ʼ����������                          *|" << endl;
//	cout << "|*-----> 2.���������Ϣ                            *|" << endl;
//	cout << "|*-----> 3.��ӡ��������                            *|" << endl;
//	cout << "|*-----> 4.��λ��ɾ����������                      *|" << endl;
//	cout << "|*-----> 5.��ֵɾ����������                        *|" << endl;
//	cout << "|*-----> 6.����������ѯ����                        *|" << endl;
//	cout << "|*-----> 7.�����������ѯ����                      *|" << endl;
//	cout << "|*-----> 8.���Ҹ�������ָ����Χ�ڵĳ���            *|" << endl;
//	cout << "|*-----> 9.���������о���                          *|" << endl;
//	cout << "|*-----> 10.��ȡ���и���                           *|" << endl;
//	cout << "|*-----> 11.��ճ�������                           *|" << endl;
//	cout << "|*-----> 12.���ٳ�������                           *|" << endl;
//	cout << "                                                     " << endl;
//	cout << "��������Ҫѡ��Ĳ���" << endl;
//}
//int main()
//{
//	//Point p1{ 1,2 };
//	//Point p2{ 2,3 };
//	//Point p3{ 3,4 };
//	//City c1{ "a",p1 };
//	//City c2{ "b",p2 };
//	//City c3{ "c",p3 };
//	//init_fun(list);
//	//insert_fun(list, 2, &c1);
//	//insert_fun(list, 2, &c2);
//	//insert_fun(list, 2, &c3);
//	
//
//	int input = 0;
//		do
//		{
//			menu();
//			cin >> input;
//			switch (input)
//			{
//			case 1:
//				init_fun(list);
//				break;
//			case 2:
//				insert();
//				break;
//			case 3:
//				foreach_fun(list,myprint);
//				break;
//			case 4:
//				remove();
//				break;
//			case 5:
//				remove2();
//				break;
//			case 6:
//				find1();
//				break;
//			case 7:
//				find2();
//				break;
//			case 8:
//				find3();
//				break;
//			case 9:
//				Dis();
//				break;
//			case 10:
//				Size(list);
//				break;
//			case 11:
//				clear(list);
//				break;
//			case 12:
//				destroy(list);
//				break;
//			default:
//				break;
//			}
//		} while (input);
//}
//
