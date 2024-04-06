#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<iostream>
using namespace std;
#include<iomanip>
#include<vld.h>
#include"动态数组.hpp"

//初始化动态数组
dynamicArray* init_fun(int capacity)
{
	dynamicArray* arr = new(dynamicArray)();
	arr->m_Capacity = capacity;
	arr->m_Size = 0;
	arr->pArrd = new void*[sizeof(void*)*arr->m_Capacity]();
	return arr;
}
//插入数据
void insert_fun(dynamicArray* arr, void* date, int pos)
{
	if (pos<0 || pos>arr->m_Size)
	{
		pos = arr->m_Size;
	}
	if (arr->m_Size == arr->m_Capacity)
	{
		int newcapacity = arr->m_Capacity * 2;
		void** newspace = new void* [sizeof(void*) * newcapacity]();
		memcpy(newspace, arr->pArrd, sizeof(void*)*(arr->m_Capacity));
		delete arr->pArrd;
		arr->pArrd = newspace;
		arr->m_Capacity = newcapacity;
	}

	//将元素后移
	for (int i = arr->m_Size - 1; i >= pos; i--)
	{
		arr->pArrd[i+1] = arr->pArrd[i];
	}
	arr->pArrd[pos] = date;
	arr->m_Size++;
}
//遍历元素
void foreach_fun(dynamicArray* arr,void(*myPrint)(void*))
{
	for (int i = 0; i < arr->m_Size; i++)
	{
		myPrint(arr->pArrd[i]);
	}
}
//按位置删除元素
void remove_fun(dynamicArray*arr, int pos)
{
	for (int i = pos; i < arr->m_Size; i++)
	{
		arr->pArrd[i] = arr->pArrd[i+1];
	}
	arr->m_Size--;
}

//按值删除元素
void remove_fun2(dynamicArray*arr,void* date,int myCompare(void*date1,void* date2))
{
	for (int i = 0; i < arr->m_Size; i++)
	{
		if (myCompare(arr->pArrd[i], date))
		{
			remove_fun(arr, i);
			break;
		}
	}
}

//销毁数组
void destroy(dynamicArray* arr)
{
	if (arr->pArrd != nullptr) { delete arr->pArrd; }
	arr->pArrd = nullptr;
	delete arr;
	arr = nullptr;
}

struct Person
{
	char name[20];
	int age;
};
void printPerson(void* arr)
{
	Person* p = (Person*)arr;
	cout << p->name << "  " << p->age << endl;
}
int mycompare(void*date1, void* date2)
{
	Person* p1 = (Person*)date1;
	Person* p2 = (Person*)date2;
	return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}

void test01()
{
	
	dynamicArray* arr = init_fun(5);
	Person p1 = { "赵1", 18 };
	Person p2 = { "赵2", 28 };
	Person p3 = { "赵3", 38 };
	Person p4 = { "赵4", 48 };
	Person p5 = { "赵5", 58 };
	Person p6 = { "赵6", 68 };
	cout << arr->m_Capacity << "  " << arr->m_Size << endl;
	insert_fun(arr, &p1, 0);
	insert_fun(arr, &p2, 1);
	insert_fun(arr, &p3, 0);
	insert_fun(arr, &p4, -1);
	insert_fun(arr, &p5, 0);
	insert_fun(arr, &p6, 0);
	cout << arr->m_Capacity << "  " << arr->m_Size << endl;
	foreach_fun(arr, printPerson);
	cout << "我要按位置删除第3个元素啦！" << endl;
	remove_fun(arr, 2);
	foreach_fun(arr, printPerson);
	cout << "我要按值删除名为赵5的元素啦！" << endl;
	struct Person p = { "赵5",58 };
	remove_fun2(arr, &p, mycompare);
	foreach_fun(arr, printPerson);
	cout << "我要销毁数组啦！" << endl;
	destroy(arr);
	arr = nullptr;
}
int main()
{
	test01();
}