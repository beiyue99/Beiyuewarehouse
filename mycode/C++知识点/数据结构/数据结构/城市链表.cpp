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
//LinkList init_fun2()   //初始化链表
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
//	cout << "正在初始化链表中..." << endl;
//	chrono::seconds duar(2);
//	this_thread::sleep_for(duar);
//	cout << "链表初始化成功！" << endl;
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
//	}  //找到插入位置的前驱结点位置
//	struct LinkNode* newNode = new(LinkNode);//创建新节点结构体
//	newNode->next = nullptr;
//	newNode->date = date;
//	newNode->next = pCurrent->next;
//	pCurrent->next = newNode;
//	mylist->m_Size++;
//}
//void insert()
//{
//	if (!list) { cout << "城市链表不存在，无法插入！" << endl; return; }
//	string s1; int x; int y; int pos;
//	cout << "请输入要插入的城市名称：" << endl;
//	cin >> s1 ;
//	cout << "请输入要插入的城市坐标：" << endl;
//	cin >> x >> y ;
//	cout << "请输入要插入的城市位置：" << endl;
//	cin >>  pos;
//	Point* p1 = new Point;
//	City* c1 = new City;
//	p1->x = x;
//	p1->y = y;
//	c1->pp = *p1;
//	strcpy(c1->name, s1.c_str());
//	insert_fun(list, 3, c1);
//	cout << "城市" << s1 << "插入成功！" << endl;
//}
//void myprint(void* date)
//{
//	City* p = (City*)date;
//	cout << p->name << "  " << p->pp.x<<"  "<<p->pp.y  << endl;
//}
//void foreach_fun(LinkList list, void(*myPrint)(void* date))
//{
//	if (!list) { cout << "城市链表不存在！" << endl; return; }
//	LList* p1 = (LList*)list;
//	LinkNode* newNode = p1->pHeader.next; //创建的节点结构体就是头结点后面真实储存数据的结构体
//	if (!newNode) { cout << "链表中还未储存数据!" << endl; return; }
//	for (int i = 0; i < p1->m_Size; i++)
//	{
//		myprint(newNode->date);
//		newNode = newNode->next;
//	}
//}
//void remove_fun(LinkList& list, int pos)//按位置进行删除
//{
//	struct LList* mylist = (LList*)list;
//	if (mylist->m_Size < pos||pos<=0) { cout << "该位置不存在城市节点" << endl; return; }
//	struct LinkNode* pCurrent = &mylist->pHeader;
//	for (int i = 0; i < pos - 1; i++)  //找到待删除位置的前驱结点位置
//	{
//		pCurrent = pCurrent->next;
//	}
//	struct LinkNode* pDel = pCurrent->next;  //记录待删除的节点
//	pCurrent->next = pDel->next;
//	delete pDel;  pDel = nullptr;
//	mylist->m_Size--;
//	cout << "成功移除处于第" << pos << "个位置的城市节点" << endl;
//}
//void remove()
//{
//	if (list == nullptr) { cout << "城市链表不存在,无法删除！" << endl; return; }
//	cout << "您想移除第几个城市？" << endl;
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
//void remove_fun2(LinkList& list, void* date, int(*myCompare)(void*, void*))//按值删除元素
//{
//	struct LList* mylist = (LList*)list;
//	LinkNode* pPrev = &mylist->pHeader;   //创建两个辅助指针变量
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
//			cout << "已成功删除该城市！" << endl;
//			break;
//		}
//		pPrev = pCurrent;
//		pCurrent = pCurrent->next;
//	}
//	if (!flag) { cout << "未找到相关城市信息！" << endl; }
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
//void find1(LinkList& list, const char* s) //按名称查找
//{
//	struct LList* mylist = (LList*)list;
//	LinkNode* pPrev = &mylist->pHeader;
//	LinkNode* pCurrent = mylist->pHeader.next;
//	bool flag = false;
//	int count = 0;
//	for (int i = 0; i < mylist->m_Size; i++)
//	{
//		if (compareCity1(s, pCurrent->date))  //pCurrent就是该城市
//		{
//			flag = true;
//			count++;
//			cout << "查到了第" << count<< "个名为" << s << "的城市, 它所在的坐标为" << ((City*)(pCurrent->date))->pp.x << ", " << ((City*)(pCurrent->date))->pp.y << endl;
//		}
//		pPrev = pCurrent;
//		pCurrent = pCurrent->next;
//	}
//	if (!flag) { cout << "未找到相关城市信息！" << endl; }
//}
//void find1()
//{
//	if (list == nullptr) { cout << "城市链表不存在！无法进行操作！" << endl; return; }
//	string s1;
//	cout << "请输入要查找的城市名：" << endl;
//	cin >> s1;
//	find1(list, s1.c_str());
//}
//
//
//void find2(LinkList& list, int a,int b) //按坐标查找
//{
//	struct LList* mylist = (LList*)list;
//	LinkNode* pPrev = &mylist->pHeader;
//	LinkNode* pCurrent = mylist->pHeader.next;
//	bool flag = false;
//	for (int i = 0; i < mylist->m_Size; i++)
//	{
//		if (compareCity2(a,b, pCurrent->date))  //pCurrent就是该城市
//		{
//			flag = true;
//			cout << "查到了第坐标为" << a<<" "<<b << "的城市, 它所在的名字为" << ((City*)(pCurrent->date))->name<< endl;
//		}
//		pPrev = pCurrent;
//		pCurrent = pCurrent->next;
//	}
//	if (!flag) { cout << "未找到相关城市信息！" << endl; }
//}
//void find2()
//{
//	if (list == nullptr) { cout << "城市链表不存在！无法进行操作！" << endl; return; }
//	int a, b;
//	cout << "请输入要查找的城市坐标：" << endl;
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
//		if (compareCity3(a,b,c,pCurrent->date))  //pCurrent就是该城市
//		{
//			flag = true;
//			count++;
//			cout << "查到了第"<<count<<"个距离小于"<<c <<"的城市  "<< ((City*)(pCurrent->date))->name << endl;
//		}
//		pPrev = pCurrent;
//		pCurrent = pCurrent->next;
//	}
//	if (!flag) { cout << "未找到相关城市信息！" << endl; }
//}
//void find3()
//{
//	if (list == nullptr) { cout << "城市链表不存在！无法进行操作！" << endl; return; }
//	int a, b, c;
//	cout << "请输入中心坐标：" << endl;
//	cin >> a >> b;
//	cout << "请输入以中心点为中心所查找的最大距离：" << endl;
//	cin >> c;
//	find3(list, a,b,c);
//}
//void Dis(LinkList list,const char* s1,const char* s2)
//{
//	if (list == nullptr) { cout << "城市链表不存在！无法进行操作！" << endl; return; }
//	struct LList* mylist = (LList*)list;
//	LinkNode* pPrev = &mylist->pHeader;
//	LinkNode* pCurrent = mylist->pHeader.next;
//	bool flag1 = false;
//	bool flag2 = false;
//	int arr[4]={0};
//	for (int i = 0; i < mylist->m_Size; i++)
//	{
//		if (compareCity1(s1, pCurrent->date))  //pCurrent就是该城市
//		{
//			flag1= true;
//			cout << "查到了名为" << ((City*)(pCurrent->date))->name << "的城市,它的坐标为：" << ((City*)(pCurrent->date))->pp.x <<
//				((City*)(pCurrent->date))->pp.y << endl;
//			arr[0] = ((City*)(pCurrent->date))->pp.x; arr[1] = ((City*)(pCurrent->date))->pp.y;
//		}
//		if (compareCity1(s2, pCurrent->date))  //pCurrent就是该城市
//		{
//			flag2 = true;
//			cout << "查到了名为" << ((City*)(pCurrent->date))->name << "的城市,它的坐标为：" << ((City*)(pCurrent->date))->pp.x <<
//				((City*)(pCurrent->date))->pp.y << endl;
//			arr[2] = ((City*)(pCurrent->date))->pp.x; arr[3] = ((City*)(pCurrent->date))->pp.y;
//		}
//		pPrev = pCurrent;
//		pCurrent = pCurrent->next;
//	}
//	if (!flag1) { cout << "未找到第一个城市信息！" << endl; return; }
//	if (!flag2) { cout << "未找到第二个城市信息！" << endl; return; }
//	cout << "两个城市的距离为:" << sqrt((arr[0] - arr[2]) * (arr[0] - arr[2]) + (arr[1] - arr[3]) * (arr[1] - arr[3])) << endl;
//}
//void Dis()
//{
//	if (list == nullptr) { cout << "城市链表不存在，无法操作！" << endl; return; }
//	string s1, s2;
//	cout << "请输入两城市的名称：" << endl;
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
//	if (list == nullptr) { cout << "城市链表不存在，无法操作！" << endl; return; }
//	LList* mylist = (LList*)list;
//	cout << "城市个数为：" << mylist->m_Size << endl;
//}
//void remove2()
//{
//	if (list == nullptr) { cout << "城市链表不存在，无法删除！" << endl; return; }
//	int x, y;
//	string s1;
//	cout << "请输入要删除城市的名称和坐标：" << endl;
//	cin >> s1 >> x >> y;
//	Point p{ x,y };
//	City c;
//	strcpy(c.name, s1.c_str());
//	c.pp = p;
//	remove_fun2(list, &c, compareCity);
//}
//void clear(LinkList list)
//{
//	if (list == nullptr) { cout << "城市链表不存在，无法操作！" << endl; return; }
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
//	if (list == nullptr) { cout << "城市链表不存在，无法操作！" << endl; return; }
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
//	cout << "|==============欢迎使用城市链表操作系统=============|" << endl;
//	cout << "|___________________________________________________|" << endl;
//	cout << "|*-----> 0.退出程序                                *|" << endl;
//	cout << "|*-----> 1.初始化城市链表                          *|" << endl;
//	cout << "|*-----> 2.插入城市信息                            *|" << endl;
//	cout << "|*-----> 3.打印城市链表                            *|" << endl;
//	cout << "|*-----> 4.按位置删除城市链表                      *|" << endl;
//	cout << "|*-----> 5.按值删除城市链表                        *|" << endl;
//	cout << "|*-----> 6.按城市名查询城市                        *|" << endl;
//	cout << "|*-----> 7.按城市坐标查询城市                      *|" << endl;
//	cout << "|*-----> 8.查找给定坐标指定范围内的城市            *|" << endl;
//	cout << "|*-----> 9.计算两城市距离                          *|" << endl;
//	cout << "|*-----> 10.获取城市个数                           *|" << endl;
//	cout << "|*-----> 11.清空城市链表                           *|" << endl;
//	cout << "|*-----> 12.销毁城市链表                           *|" << endl;
//	cout << "                                                     " << endl;
//	cout << "请输入您要选择的操作" << endl;
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
