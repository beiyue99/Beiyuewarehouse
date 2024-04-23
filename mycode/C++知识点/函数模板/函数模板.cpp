#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>






template<typename T>
class A1
{
public:
	void print()
	{
		cout << "A1" << endl;
	}
};
template<template <typename T> class D>      //参数是一个类，且这个类是个模板
class B
{
public:
	D<int>a;
	void print();
};
template<template <typename x> class T>
void B<T>::print()
{
	cout << "B" << endl;
	a.print();
}

int main()
{
	B<A1>b1;
	b1.print();
}














//类模板   继承类类型  参数
template<typename T>
class A
{
public:
	T a;
	A(T a)
	{
		this->a = a;
	}
	void print()
	{
		cout << a << "aaaaa" << endl;
	}
};
template<typename T1,typename T2>
class B :public T2
{
public:
	T1 b;
	B(T2 f,T1 n):T2(f),b(n){}      //调用A的构造函数，用f赋值
	void printb()
	{
		cout << b << "bbbbb" << endl;
	}
};

int main()
{
	B<    float,A<int>  > b(123, 41.2414);     //指定T2的类型为  类A， T1的类型为int
	b.print();
	b.printb();
}
























#include <iostream>
using namespace std;

template <typename T>
class A {
public:
	static int count;
};

template <typename T>
int A<T>::count = 0;

int main() {
	A<int>::count = 5;
	A<double>::count = 10;

	cout << "int count: " << A<int>::count << ";" << endl;
	cout << "double count: " << A<double>::count << ";" << endl;

	return 0;
}



