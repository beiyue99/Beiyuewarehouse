#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//c++�׳����쳣һ�������д��������ֱ���˳�
 
// 
//int Mydiv(int a, int b)
//{
//	if (b == 0)
//		return -1; //c���Է���-1��ʾʧ��,����10����-10���ȷʵΪ-1������C���Ե�ȱ�� 
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
//		cout << "����int�쳣 e=" << e << endl;
//	}
//}
//int main()
//{
//	test01();
//	return 0;
//}
	//�쳣���׳��󣬴ӽ���try��ʼ�����쳣���׳�ǰ�����ڼ���ջ�Ϲ�������ж��󶼻ᱻ�Զ���������һ���̳�Ϊջ����
	//����˵����ջ������������Ȼ���ٲ����쳣

//�쳣�Ľӿ�������    void Test() throw(int,char,float){}










//��֤ջ����
//class Exception
//{
//public:
//	Exception() { cout << "�쳣����ͨ���캯�����ã�" << endl; }
//	Exception (  Exception& e)
//	{
//		cout << "�쳣����������ã�" << endl;
//		this->name = e.name;
//	}
//	~Exception() { cout << "�쳣�������������ã�" << endl; }
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
//		cout << "��׽��Exception���͵��쳣" << endl;
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
//	Exception() { cout << "�쳣����ͨ���캯�����ã�" << endl; }
//	Exception ( const Exception& e)
//	{
//		cout << "�쳣����������ã�" << endl;
//		this->name = e.name;
//	}
//	~Exception() { cout << "�쳣�������������ã�" << endl; }
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
//		cout << "��׽��Exception���͵��쳣" << endl;
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
//			throw out_of_range("age��Ч");
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
//		cout << "�����쳣��" << e.what() << endl;
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
//		cout << "δ֪�쳣" << endl;
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


