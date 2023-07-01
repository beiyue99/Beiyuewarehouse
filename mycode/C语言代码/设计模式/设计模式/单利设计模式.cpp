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
//		cout << "测试" << endl;
//	}
//};
//A* A::Mya = nullptr;
//int main()
//{
//	A* pa1 = A::Geta();
//	A* pa2 = A::Geta();
//	//delete pa1;                  //这里可以手动delete，也可以创建一个回收类，用来自动回收堆区内存
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
//		cout << "Creat被执行了！" << endl;
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
//		call_once(g_flag, Creat);//第一给线程执行的时候 标记为true,第二个线程遇到这个函数就不会执行了
//		cout << "call_once执行完毕！" << endl;
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
//		cout << "测试" << endl;
//	}
//};
//A* A::Mya = nullptr;
//void mythread()
//{
//	cout << "线程开始执行！" << endl;
//	A* a1 = A::Geta();
//	cout << "线程执行完毕！" << endl;
//}
//int main()
//{
//	//A* pa1 = A::Geta();
//	//delete pa1;                  //这里可以手动delete，也可以创建一个回收类，用来自动回收堆区内存
//	thread myobj1(mythread);
//	thread myobj2(mythread);
//	myobj1.join();
//	myobj2.join();
//}


