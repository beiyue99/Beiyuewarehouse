#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<iostream>
using namespace std;
#include<iomanip>
#include<vld.h>
#include"��̬����.hpp"

//��ʼ����̬����
dynamicArray* init_fun(int capacity)
{
	dynamicArray* arr = new(dynamicArray)();
	arr->m_Capacity = capacity;
	arr->m_Size = 0;
	arr->pArrd = new void*[sizeof(void*)*arr->m_Capacity]();
	return arr;
}
//��������
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

	//��Ԫ�غ���
	for (int i = arr->m_Size - 1; i >= pos; i--)
	{
		arr->pArrd[i+1] = arr->pArrd[i];
	}
	arr->pArrd[pos] = date;
	arr->m_Size++;
}
//����Ԫ��
void foreach_fun(dynamicArray* arr,void(*myPrint)(void*))
{
	for (int i = 0; i < arr->m_Size; i++)
	{
		myPrint(arr->pArrd[i]);
	}
}
//��λ��ɾ��Ԫ��
void remove_fun(dynamicArray*arr, int pos)
{
	for (int i = pos; i < arr->m_Size; i++)
	{
		arr->pArrd[i] = arr->pArrd[i+1];
	}
	arr->m_Size--;
}

//��ֵɾ��Ԫ��
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

//��������
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
	Person p1 = { "��1", 18 };
	Person p2 = { "��2", 28 };
	Person p3 = { "��3", 38 };
	Person p4 = { "��4", 48 };
	Person p5 = { "��5", 58 };
	Person p6 = { "��6", 68 };
	cout << arr->m_Capacity << "  " << arr->m_Size << endl;
	insert_fun(arr, &p1, 0);
	insert_fun(arr, &p2, 1);
	insert_fun(arr, &p3, 0);
	insert_fun(arr, &p4, -1);
	insert_fun(arr, &p5, 0);
	insert_fun(arr, &p6, 0);
	cout << arr->m_Capacity << "  " << arr->m_Size << endl;
	foreach_fun(arr, printPerson);
	cout << "��Ҫ��λ��ɾ����3��Ԫ������" << endl;
	remove_fun(arr, 2);
	foreach_fun(arr, printPerson);
	cout << "��Ҫ��ֵɾ����Ϊ��5��Ԫ������" << endl;
	struct Person p = { "��5",58 };
	remove_fun2(arr, &p, mycompare);
	foreach_fun(arr, printPerson);
	cout << "��Ҫ������������" << endl;
	destroy(arr);
	arr = nullptr;
}
int main()
{
	test01();
}