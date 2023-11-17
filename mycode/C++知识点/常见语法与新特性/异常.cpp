#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//c++抛出的异常一旦不进行处理，程序会直接退出
 
// 
//int Mydiv(int a, int b)
//{
//	if (b == 0)
//		return -1; //c语言返回-1表示失败,但是10除以-10结果确实为-1，这是C语言的缺陷 
//	return a / b;
//}
//int Mydiv2(int a, int b)
//{
//	if (b == 0)
//		throw 0;
//	return a / b;
//}
//void test01()
//{
//	try
//	{
//		int ret = Mydiv2(10, 0);
//			cout <<"ret=:"<< ret << endl;
//	}
//	catch (int e)
//	{
//		cout << "捕获到int异常 e=" << e << endl;
//	}
//}
//int main()
//{
//	test01();
//	return 0;
//}
	//异常被抛出后，从进入try开始，到异常被抛出前，这期间在栈上构造的所有对象都会被自动析构，这一过程称为栈解旋
	//就是说，先栈解旋析构对象，然后再捕获异常

//异常的接口声明：    void Test() throw(int,char,float){}










//验证栈解旋
//class Exception
//{
//public:
//	Exception() { cout << "异常的普通构造函数调用！" << endl; }
//	Exception (  Exception& e)
//	{
//		cout << "异常拷贝构造调用！" << endl;
//		this->name = e.name;
//	}
//	~Exception() { cout << "异常的析构函数调用！" << endl; }
//	string name;
//};
//void fun2()
//{
//
//	try
//	{
//		Exception e1;
//		throw  e1;
//	}
//	catch (Exception& e)
//	{
//		cout << "捕捉到Exception类型的异常" << endl;
//	}
//}
//int main()
//{
//	fun2();
//}




//
//class Exception
//{
//public:
//	Exception() { cout << "异常的普通构造函数调用！" << endl; }
//	Exception ( const Exception& e)
//	{
//		cout << "异常拷贝构造调用！" << endl;
//		this->name = e.name;
//	}
//	~Exception() { cout << "异常的析构函数调用！" << endl; }
//	string name;
//};
//void fun2()
//{
//
//	try
//	{
//		throw  Exception();
//	}
//	catch (Exception&e)
//	{
//		cout << "捕捉到Exception类型的异常" << endl;
//	}
//}
//int main()
//{
//	fun2();
//}
//












//class Person
//{
//public:
//	int age;
//	Person(int age)
//	{
//		if (age < 0 || age>150)
//			throw out_of_range("age无效");
//		this->age = age;
//	}
//};
//void test01()
//{
//	try
//	{
//		Person p1(200);
//	}
//	catch (exception& e)
//	{
//		cout << "捕获到异常：" << e.what() << endl;
//	}
//}
//int main()
//{
//	test01();
//}






#include<vector>

//int main()
//{
//	vector<int> v1{ 1,23,4,56,1 };
//	try
//	{
//		cout << v1.at(10) << endl;
//	}
//	catch (const exception& except)
//	{
//		cout << except.what() << endl;
//	}
//}    








//	int divide(int divisior, int dividend)
//	{
//		if (!dividend)
//		{
//			throw "dividend is zero!";
//		}
//		return divisior / dividend;
//	}
//	void clientIputNum(const string& str, int& num)
//	{
//		cout << str << endl;
//		while (cin >> num, !cin.eof())
//		{
//			if (cin.bad())
//			{
//				throw runtime_error("cin is corrupted!");
//			}
//			if (cin.fail())
//			{
//				cin.clear();
//				cin.ignore(numeric_limits<streamsize>::max(), '\n');
//				cout << "number format error,please input again!" << endl;
//				continue;
//			}
//			break;
//		}
//	}
//int main()
//{
//	int divisior = 0;
//	int dividend = 0;
//	clientIputNum("please input divisior", divisior);
//	clientIputNum("please input dividend",dividend);
//	try
//	{
//		cout << divide(divisior, dividend) << endl;
//	}
//	catch (const string& str)
//	{
//		cout << "excption occers,excption is:" << str<< endl;
//	}
//	catch (...)
//	{
//		cout << "未知异常" << endl;
//	}
//	return 0;
//}







//
//#include<memory>
//#include<vector>
//int main()
//{
//	vector < shared_ptr<int>> shared_int_vec;
//	try
//	{
//		while (1)
//		{
//			unique_ptr<int>uniqueI(new int[100000]());
//			shared_int_vec.push_back(move(uniqueI));
//		}
//	}
//	catch (const bad_alloc& except)
//	{
//		cout << except.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "unknown exception!" << endl;
//	}
//	return 0;
//}





//
//template<typename T>
//void test(T&& elem)
//{
//	cout << typeid(T).name() << endl;
//	cout << typeid(elem).name() << endl;
//}
//
//
//int main()
//{
//	
//	test(10);
//	return 0;
//}


