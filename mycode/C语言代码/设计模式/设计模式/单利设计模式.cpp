#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
#include<thread>
#include<mutex>
#include<vld.h>
//class A
//{
//private:
//	A(){}
//	static A* Mya;
//public:
//	static A* Geta()
//	{
//		if (Mya == nullptr)
//		{
//			Mya = new A;
//		    B b1;
//		}
//		return Mya;
//	}
//	class B
//	{
//	public:
//		~B()
//		{
//			if (Mya)
//			{
//				delete Mya;
//				Mya = nullptr;
//			}
//		}
//	};
//	void func()
//	{
//		cout << "����" << endl;
//	}
//};
//A* A::Mya = nullptr;
//int main()
//{
//	A* pa1 = A::Geta();
//	A* pa2 = A::Geta();
//	//delete pa1;                  //��������ֶ�delete��Ҳ���Դ���һ�������࣬�����Զ����ն����ڴ�
//}
//






//
//mutex resource_mutex;
//once_flag g_flag;
//
//class A
//{
////public:
////	static mutex mutex1;
//	static void Creat()
//	{
//		chrono::milliseconds dura(20);
//		this_thread::sleep_for(dura);
//		cout << "Creat��ִ���ˣ�" << endl;
//		Mya = new A;
//		static B b1;
//	}
//private:
//	A() {}
//	static A* Mya;
//public:
//	static A* Geta()
//	{
//	/*	if (Mya ==nullptr)
//		{
//			unique_lock<mutex> mymutex(mutex1);
//			if (Mya == nullptr)
//			{
//				Mya = new A;
//				B b1;
//			}
//		}
//		return Mya;*/
//		call_once(g_flag, Creat);//��һ���߳�ִ�е�ʱ�� ���Ϊtrue,�ڶ����߳�������������Ͳ���ִ����
//		cout << "call_onceִ����ϣ�" << endl;
//		return Mya;
//	}
//	class B
//	{
//	public:
//		~B()
//		{
//			if (Mya)
//			{
//				delete Mya;
//				Mya = nullptr;
//			}
//		}
//	};
//	void func()
//	{
//		cout << "����" << endl;
//	}
//};
//A* A::Mya = nullptr;
//void mythread()
//{
//	cout << "�߳̿�ʼִ�У�" << endl;
//	A* a1 = A::Geta();
//	cout << "�߳�ִ����ϣ�" << endl;
//}
//int main()
//{
//	//A* pa1 = A::Geta();
//	//delete pa1;                  //��������ֶ�delete��Ҳ���Դ���һ�������࣬�����Զ����ն����ڴ�
//	thread myobj1(mythread);
//	thread myobj2(mythread);
//	myobj1.join();
//	myobj2.join();
//}


