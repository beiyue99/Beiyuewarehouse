#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;






 //万能引用的两个条件     1.一定是函数模板 2. 一定发生了类型推导，即没有指定类型        另外如果加了const，只能传右值
//template<typename T1>
//void fun( T1&& a)   //既能绑定左值，又能绑定右值
//{
//	cout << a << endl;
//}
//int main()
//{
//	int a = 10;
//	fun(a);
//	fun(30);
//}







////
//void fun2(int& a, int& b)
//{
//	cout << a<< b << endl;
//}
//template<typename T1,typename T2>
//
//void fun1(T1&& t1, T2&& t2)         //t2是万能引用，但是t2本身是个左值,所以fun2第二个参数b必须是左值引用
//{
//	fun2(t1, t2);
//
//}
//int main()
//{
//	int a = 10;
//	fun1(a, 24);
//}






//
//void fun2(int& a, int&&b)
//{
//	cout << a << b << endl;
//}
//template<typename T1, typename T2>
//void fun1(T1&& t1, T2&& t2)        
//{
//	fun2(t1, forward<T2>(t2));    //完美转发，将t2转为右值，以便fun2调用
//	//fun2(t1, t2);
//
//}
//int main()
//{
//	int a = 10;
//	fun1(a, 24);
//}






