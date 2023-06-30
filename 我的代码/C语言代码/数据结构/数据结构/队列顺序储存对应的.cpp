//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//#include"队列的顺序储存.h"
//#include"动态数组.hpp"
//SeqQueue init_SeQueue()
//{
//	struct dynamicArray* array = init_fun(MAX);
//	return array;
//}
//void push_fun(SeqQueue queue, void* date)
//{
//	struct dynamicArray* array =(dynamicArray*) queue;
//	if(array->m_Size==MAX)
//	{
//		return;
//	}
//	insert_fun(array, date, array->m_Size);
//}
//void pop_fun(SeqQueue queue)
//{
//	dynamicArray* arr = (dynamicArray*)queue;
//	if (arr->m_Size == 0)
//	{
//		return;
//	}
//	remove_fun(arr, 0);
//}
//void* get_front(SeqQueue queue)
//{
//	dynamicArray* arr = (dynamicArray*)queue;
//	return arr->pArrd[0];
//}
//void* get_back(SeqQueue queue)
//{
//	dynamicArray* arr = (dynamicArray*)queue;
//	return arr->pArrd[arr->m_Size-1];
//}
//int get_size(SeqQueue queue)
//{
//	dynamicArray* arr = (dynamicArray*)queue;
//	return arr->m_Size;
//}
//int isEmpty(SeqQueue queue)
//{
//	dynamicArray* arr = (dynamicArray*)queue;
//	if (arr->m_Size == 0)
//	{
//		return 1;
//	}
//	return 0;
//}
//void destroy_fun(SeqQueue queue)
//{
//	destroy((dynamicArray*)queue); 
//}
//struct Person
//{
//	char name[20];
//	int age;
//};
//
//void test01()
//{
//	SeqQueue myQueue = init_SeQueue();
//	Person p1 = { "aaa",10 };
//	Person p2 = { "bbb",10 };
//	Person p3 = { "ccc",10 };
//	Person p4 = { "ddd",10 };
//	Person p5= { "eee",10 };
//	push_fun(myQueue, &p1);
//	push_fun(myQueue, &p2);
//	push_fun(myQueue, &p3);
//	push_fun(myQueue, &p4);
//	push_fun(myQueue, &p5);
//	while (isEmpty(myQueue)==0)
//	{
//		Person* personFront = (Person*)get_front(myQueue);
//		cout << "队头元素姓名：" << personFront->name << "队头元素年龄：" << personFront->age << endl;
//		Person* personback = (Person*)get_back(myQueue);
//		cout << "队尾元素姓名：" << personback->name << "队尾元素年龄：" << personback->age << endl;
//		cout << "+++++++++++++++++++++++++++++++++++++++++" << endl;
//		pop_fun(myQueue);
//	}
//	cout << "队列大小：" << get_size(myQueue) << endl;
//	destroy_fun(myQueue);
//}
//int main()
//{
//	test01();
//}