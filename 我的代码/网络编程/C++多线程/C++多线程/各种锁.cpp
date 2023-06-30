//#define _CRT_SECURE_NO_WARNINGS 1
////死锁
//#include<iostream>
//using namespace std;
//#include<mutex>
//#include<chrono>
//#include<list>
//class A
//{
//public:
//	void inMsgList()
//	{
//		for (int i = 0; i < 50000; i++)
//		{
//			unique_lock<mutex>sbguard1(my_mutex1, try_to_lock);       //在没锁的前提下使用try_to_lock
//			if (sbguard1.owns_lock())//拿到了锁
//			{
//				cout << "inMsgList函数执行！" << "插入一个元素:" << " " << i << endl;
//				msgRecvList.push_back(i);
//			}
//			else
//			{
//				cout << "inMsgList执行,但没拿到锁!" << endl;
//			}
//			//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//
//
//
//	/*		cout << "inMsgList函数执行！" << "插入一个元素:" << " " << i << endl;
//			lock(my_mutex1, my_mutex2);
//			msgRecvList.push_back(i);
//			my_mutex2.unlock();
//			my_mutex1.unlock();*/
//		}
//	}
//	void outMsgList()
//	{
//		for (int i = 0; i < 50000; i++)
//		{
//			cout << "outMsg函数执行！";
//			//lock(my_mutex2, my_mutex1);    //一次锁两把，不会出现死锁
//			//lock_guard<mutex> myguard1(my_mutex2,adopt_lock);
//			//lock_guard<mutex> myguard2(my_mutex1,adopt_lock);    //在有锁的前提下，要使用第二个参数代表不再加锁，否则出错
//
//
//			//lock_guard<mutex> myguard2(my_mutex2);
//			lock_guard<mutex> myguard1(my_mutex1);
//
//
//			//unique_lock<mutex> myguard1(my_mutex1); 
//			//unique_lock<mutex> myguard2(my_mutex2);     //此函数也可加参adopt_lock，与lock_guard一样，比lock_guard灵活
//
//
//			chrono::seconds dura(1);
//			this_thread::sleep_for(dura);
//
//
//
//			if (!msgRecvList.empty())
//			{
//				int command = msgRecvList.front();
//				cout << "将要移除的元素" << command << endl;
//				msgRecvList.pop_front();
//			}
//			else
//			{
//				cout << "容器为空" << i << endl;
//			}
//		/*	my_mutex1.unlock();
//			my_mutex2.unlock();*/
//		}
//	}
//private:
//	list<int > msgRecvList;
//	mutex my_mutex1;
//	mutex my_mutex2;
//};
//int  main()
//{
//	A  a;
//	thread myInObj(&A::inMsgList, &a);
//	thread myOutObj(&A::outMsgList, &a);
//	myInObj.join();
//	myOutObj.join();
//}
//
//
//
