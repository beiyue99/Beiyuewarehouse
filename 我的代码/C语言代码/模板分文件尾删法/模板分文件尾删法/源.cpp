#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
#include"源.hpp"


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
	cout << "arr1的打印输出为：" << endl;

	printArray(arr1);
	cout << "arr1的容量为：" << arr1.GetCapacity() << endl;
	cout << "arr1的大小为：" << arr1.GetSize() << endl;


	MyArray<int>arr2(arr1);
	cout << "arr2的容量为：" << arr2.GetCapacity() << endl;
	cout << "arr2的大小为：" << arr2.GetSize() << endl;
	cout << "arr2的打印输出为：" << endl;
	printArray(arr2);
	arr2.Pop_Back();
	cout << "arr2尾删后的状态：" << endl;
	printArray(arr2);
	cout << "arr2的容量为：" << arr2.GetCapacity() << endl;
	cout << "arr2的大小为：" << arr2.GetSize() << endl;
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
		cout << "姓名：" << arr[i].m_name << "年龄：" << arr[i].m_age << endl;
	}

}
void test02()
{

	MyArray<Person>arr(10);
	Person p1("妲己", 22);
	Person p2("猴子", 34);
	Person p3("韩信", 55);
	Person p4("吕布", 412);
	Person p5("貂蝉", 55);

	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);
	printPArray(arr);
	cout << "arr的容量为：" << arr.GetCapacity() << endl;
	cout << "arr的大小为：" << arr.GetSize() << endl;

}



int main()
{

	test02();
}