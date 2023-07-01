#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#include<list>
#include<mutex>

//class A
//{
//public:
//	void inMsgList()
//	{
//		for (int i = 0; i < 100000; i++)
//		{
//			cout << "inMsgList函数执行！" << "插入一个元素:" << " " << i << endl;
//			my_mutex1.lock();
//			msgRecvList.push_back(i);
//			my_cond.notify_one();       //唤醒wait
//			my_mutex1.unlock();
//		}
//	}
//	void outMsgList()
//	{
//		int command = 0;
//		while (1)
//		{
//			unique_lock<mutex>sbguard1(my_mutex1);
//			my_cond.wait(sbguard1, [this]
//				//先拿锁，如果第二个参数返回false，wait将解锁互斥量，并堵塞本行，直到其它线程调用notify_one，再次尝试上锁，并终止堵塞
//		//如果没写第二个参数，那么默认返回false
//				{
//					if (!msgRecvList.empty())   //处理虚假唤醒
//					{
//						return true;
//					}
//					return false;
//				});
//			command = msgRecvList.front();
//			msgRecvList.pop_front();
//			cout << "out函数开始执行！将要移除的元素" << command << "线程id为：" << this_thread::get_id() << endl;
//			sbguard1.unlock();//处理后续逻辑事先解锁 以便另外线程可移执行  但是要注意这时候锁已经解开，另一个线程可能再次调用唤醒函数
//			//但是此时该线程可能正在忙着处理后续逻辑，并未阻塞，所以该次唤醒无效
//		}
//	}
//private:
//	list<int > msgRecvList;
//	mutex my_mutex1;
//	condition_variable my_cond;
//};
//int  main()
//{
//	A  a;
//	thread myInObj(&A::inMsgList, &a);
//	thread myOutObj(&A::outMsgList, &a);
//	thread myOutObj2(&A::outMsgList, &a);
//	myInObj.join();
//	myOutObj.join();
//	myOutObj2.join();
//}