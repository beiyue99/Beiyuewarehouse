#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>






















//
//template<typename T,int N>
//void fun(T(&p)[N])
//{
//	cout << N << "," << typeid(T).name() << "," << p[2] << endl;
//}
//
//int main()
//{
//	int b[42] = { 1,2,3,4,5 };
//	fun(b);
//}
//
//








//template<typename T>
//class A1
//{
//public:
//	void print()
//	{
//		cout << "A1" << endl;
//	}
//};
//template<template <typename T> class D>      //参数是一个类，且这个类是个模板
//class B
//{
//public:
//	D<int>a;
//	void print();
//};
//template<template <typename x> class T>
//void B<T>::print()
//{
//	cout << "B" << endl;
//	a.print();
//}
//
//int main()
//{
//	B<A1>b1;
//	b1.print();
//}
//











//类模板继承类模板
//template<typename T1>
//class A
//{
//public:
//	T1 a;
//	A(T1 a)
//	{
//		this->a = a;
//	}
//	void printa()
//	{
//		cout << a<<"aaaaa" << endl;
//	}
//};
//template<typename T1, typename T2>
//class B :public A<T1>
//{
//public:
//	T2 b;
//	B(T1 a,T2 b):A<T1>(a),b(b)    {}
//	void printb()
//	{
//		cout <<b<< "bbbbb" << endl;
//	}
//};
//
//int main()
//{
//	B<int, float> b(111, 3.142);
//	b.printa();
//	b.printb();
//}










//类模板   继承类类型  参数
//template<typename T>
//class A
//{
//public:
//	T a;
//	A(T a)
//	{
//		this->a = a;
//	}
//	void print()
//	{
//		cout << a << "aaaaa" << endl;
//	}
//};
//template<typename T1,typename T2>
//class B :public T2
//{
//public:
//	T1 b;
//	B(T2 f,T1 n):T2(f),b(n){}      //调用A的构造函数，用f赋值
//	void printb()
//	{
//		cout << b << "bbbbb" << endl;
//	}
//};
//
//int main()
//{
//	B<    float,A<int>  > b(123, 41.2414);     //指定T2的类型为  类A， T1的类型为int
//	b.print();
//	b.printb();
//}















//bool mycompare(T& t1, T& t2)



//template<>bool mycompare(Person& p1, Person& p2)      重写的时候跟重写前对应，&对应&










//template<class T,int  len> 重载[]运算符一般这样声明模板参数






//class A
//	static int count;
//	cout << "int count:" << A<int>::count << ";";
//	cout << "double count:" << A<double>::count << ";" << endl;;
//  两个不同类型下的静态成员conut不是同一个



