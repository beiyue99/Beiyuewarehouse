#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;







// 模板的特化
template< typename T1, typename T2>
class A
{
public:
	void print()
	{
		cout << "A<T1,T2> print !" << endl;
	}
private:
	T1 a1;
	T2 a2;
};


template<>
class A<int,int>
{
public:
	void print()
	{
		cout << "A<itn ,int > print !" << endl;
	}
private:
	int a1;
	int a2;
};
int main()
{
	A<int, float>a1;
	a1.print();
	A<int,int>a2;
	a2.print();
}







//
//template<typename T>
//class A
//{
//public:
//	static int s;              //不依赖模板类型
//};
//template<typename T>
//int A<T>::s = 111;
//
//template<>
//int A<int>::s = 122;
//
//int main()
//{
//	cout << A<float>::s << endl;
//	cout << A<char>::s << endl;
//	cout << A<int>::s << endl;
//}







//template<typename T>
//class A
//{
//public:
//	static T s2;//依赖模板类型
//};
//
//template<>
//float A<float>::s2= 333.33;
//
//int main()
//{
//	cout << A<float>::s2 << endl;
//	cout << A<char>::s2 << endl;
//	cout << A<int>::s2 << endl;
//}
//
//





//
//template<typename T>
//void test(const T& parm)
//{
//	cout << "void const T& parm" << endl;
//}
//template<typename T>
//void test( T* parm)     //模板特化匹配度必须是百分之百，比如此处加上const 将会调用主模板
//{ 
//	cout << "void T* parm" << endl;
//}
//void test(double parm)
//{
//	cout << "test double parm" << endl;
//}
//int main()
//{
//	int a = 10;
//	test(100);
//	test(&a);       
//	test(2.3);
//}




//
//template<typename T1,typename T2>
//class Test
//{
//public:
//	Test() { cout << "common template run!" << endl; }
//};
//template<typename T1, typename T2>
//class Test<T1*, T2*>
//{
//public:
//	Test() { cout << "ptr template run!" << endl; }
//};
//template<typename T2>
//class Test<int, T2>
//{
//public:
//	Test() { cout << "int_single template run!" << endl; }
//};
//template<>
//class Test<int, int>
//{
//public:
//	Test() { cout << "int_double run!" << endl; }
//};
//
//int main()
//{
//	Test<int*, int*> t1;
//	Test<int, double> t2;
//}



//
//template<int N>
//class Sum
//{
//public:
//	enum
//	{
//		value = N + Sum<N - 1>::value
//	};
//};
//template<>
//class Sum<0>
//{
//public:
//	enum
//	{
//		value = 0
//	};
//};
//int main()
//{
//	cout << Sum<100>::value;
//
//}


