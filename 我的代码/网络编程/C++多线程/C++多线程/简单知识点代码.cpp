#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<thread>



//����������вι��캯��������԰Ѳ������룬����������ݴ�����������һ����
//class A
//{
//public:
//	int m_i;
//	A(int a) :m_i(a) { cout << "�вι��죡" << endl; }
//	~A() { cout << "����!" << endl; }
//};
//
//void fun(const   A& a1)
//{
//	cout << &a1;
//	cout << endl << a1.m_i;
//}
//int main()
//{
//	int a = 12;
//	fun(a);
//}
//











//class A
//{
//public:
//	int m_i;
//	A(int a) :m_i(a) { cout << "�вι��캯��ִ�У�" << this <<"  " << "threadid=" << this_thread::get_id() << endl; }
//	A(const A& a) :m_i(a.m_i) { cout << "�������캯��ִ��!" << this <<"  " << "threadid=" << this_thread::get_id() << endl; }
//	~A() { cout << "��������ִ�У�" << this <<"  " << "thradid=" << this_thread::get_id() << endl; }
//	void thread_work(int num)
//	{
//		cout << "���߳�work����ִ�У�" << this <<"  " << "threadid=" << this_thread::get_id() << endl;
//	}
//	void operator()(int num)
//	{
//		cout << "���߳�()ִ��" << this << "threadid=" << this_thread::get_id() << endl;
//	}
//};
//
//int main()
//{
//	A a(10);
//	thread myobj(&A::thread_work, (a), 15);       //������������ �´���¶���     
//	myobj.join();       // ���������ظ��ɵ��ö��󣬴˴�������������Ҳ����һ����Ч����Ψһ������ֻ����ref,������ʹ��&
//	//+++++++++++++++++++++++++++++++
//	//A a(10);
//	//thread myobj(ref(a), 15);
//	//myobj.join();
//}









//#include<vector>
//void print(int i)
//{
//	cout << "�ҵ��߳̿�ʼִ�У�" <<i<< endl;
//	cout << "�ҵ��߳�ִ����ϣ�" << endl;
//}
//int main()
//{
//	vector<thread> mythreads;
//	for (int i = 0; i < 10; i++)
//	{
//		mythreads.push_back(thread(print, i)); //ʮ���߳̿�ʼִ�У�����˳��ȷ��
//	}
//	for (auto it = mythreads.begin(); it != mythreads.end(); it++)
//	{
//		it->join();
//	}
//	cout << "i love china!" << endl;
//}





//
//#include<list>
//#include<mutex>
//
//class A
//{
//public:
//	void inMsgList()
//	{
//		for (int i = 0; i < 100000; i++)
//		{
//			cout << "inMsgList����ִ�У�" << "����һ��Ԫ��:" << " " << i << endl;
//			my_mutex.lock();
//			msgRecvList.push_back(i);
//			my_mutex.unlock();
//		}
//	}
//	void outMsgList()
//	{
//		for (int i = 0; i < 100000; i++)
//		{
//			cout << "outMsg����ִ�У�";
//			//my_mutex.lock();
//			lock_guard<mutex> myguard(my_mutex);
//			if (!msgRecvList.empty())
//			{
//				int command = msgRecvList.front();
//				cout << "��Ҫ�Ƴ���Ԫ��" << command << endl;
//				msgRecvList.pop_front();
//				//my_mutex.unlock();
//			}
//			else
//			{
//				cout << "����Ϊ��" << i << endl;
//				//my_mutex.unlock();
//			}
//		}
//	}
//private:
//	list<int > msgRecvList;
//	mutex my_mutex;
//};
//int  main()
//{
//	A  a;
//	thread myInObj(&A::inMsgList, ref(a));
//	thread myOutObj(&A::outMsgList, &a);
//	myInObj.join();
//	myOutObj.join();
//}








