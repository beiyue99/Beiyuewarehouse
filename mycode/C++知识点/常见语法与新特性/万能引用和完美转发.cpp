#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;






 //�������õ���������     1.һ���Ǻ���ģ�� 2. һ�������������Ƶ�����û��ָ������        �����������const��ֻ�ܴ���ֵ
//template<typename T1>
//void fun( T1&& a)   //���ܰ���ֵ�����ܰ���ֵ
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
//void fun1(T1&& t1, T2&& t2)         //t2���������ã�����t2�����Ǹ���ֵ,����fun2�ڶ�������b��������ֵ����
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
//	fun2(t1, forward<T2>(t2));    //����ת������t2תΪ��ֵ���Ա�fun2����
//	//fun2(t1, t2);
//
//}
//int main()
//{
//	int a = 10;
//	fun1(a, 24);
//}






