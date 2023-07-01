#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
#include"Դ.hpp"


void printArray(MyArray<int>& arr)
{
	for (int i = 0; i < arr.GetSize(); i++)
	{
		cout << arr[i] << endl;
	}
}

void test01()
{
	MyArray<int>arr1(5);
	for (int i = 0; i < 5; i++)
	{
		arr1.Push_Back(i);
	}
	cout << "arr1�Ĵ�ӡ���Ϊ��" << endl;

	printArray(arr1);
	cout << "arr1������Ϊ��" << arr1.GetCapacity() << endl;
	cout << "arr1�Ĵ�СΪ��" << arr1.GetSize() << endl;


	MyArray<int>arr2(arr1);
	cout << "arr2������Ϊ��" << arr2.GetCapacity() << endl;
	cout << "arr2�Ĵ�СΪ��" << arr2.GetSize() << endl;
	cout << "arr2�Ĵ�ӡ���Ϊ��" << endl;
	printArray(arr2);
	arr2.Pop_Back();
	cout << "arr2βɾ���״̬��" << endl;
	printArray(arr2);
	cout << "arr2������Ϊ��" << arr2.GetCapacity() << endl;
	cout << "arr2�Ĵ�СΪ��" << arr2.GetSize() << endl;
}










class Person
{
public:
	int m_age;
	string m_name;
	Person() {}
	Person(string name, int age)
	{
		m_age = age;
		m_name = name;
	}
};

void printPArray(MyArray<Person>& arr)
{
	for (int i = 0; i < arr.GetSize(); i++)
	{
		cout << "������" << arr[i].m_name << "���䣺" << arr[i].m_age << endl;
	}

}
void test02()
{

	MyArray<Person>arr(10);
	Person p1("槼�", 22);
	Person p2("����", 34);
	Person p3("����", 55);
	Person p4("����", 412);
	Person p5("����", 55);

	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);
	printPArray(arr);
	cout << "arr������Ϊ��" << arr.GetCapacity() << endl;
	cout << "arr�Ĵ�СΪ��" << arr.GetSize() << endl;

}



int main()
{

	test02();
}