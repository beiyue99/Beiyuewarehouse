//#define _CRT_SECURE_NO_WARNINGS 1
////����
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
//			unique_lock<mutex>sbguard1(my_mutex1, try_to_lock);       //��û����ǰ����ʹ��try_to_lock
//			if (sbguard1.owns_lock())//�õ�����
//			{
//				cout << "inMsgList����ִ�У�" << "����һ��Ԫ��:" << " " << i << endl;
//				msgRecvList.push_back(i);
//			}
//			else
//			{
//				cout << "inMsgListִ��,��û�õ���!" << endl;
//			}
//			//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//
//
//
//	/*		cout << "inMsgList����ִ�У�" << "����һ��Ԫ��:" << " " << i << endl;
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
//			cout << "outMsg����ִ�У�";
//			//lock(my_mutex2, my_mutex1);    //һ�������ѣ������������
//			//lock_guard<mutex> myguard1(my_mutex2,adopt_lock);
//			//lock_guard<mutex> myguard2(my_mutex1,adopt_lock);    //��������ǰ���£�Ҫʹ�õڶ������������ټ������������
//
//
//			//lock_guard<mutex> myguard2(my_mutex2);
//			lock_guard<mutex> myguard1(my_mutex1);
//
//
//			//unique_lock<mutex> myguard1(my_mutex1); 
//			//unique_lock<mutex> myguard2(my_mutex2);     //�˺���Ҳ�ɼӲ�adopt_lock����lock_guardһ������lock_guard���
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
//				cout << "��Ҫ�Ƴ���Ԫ��" << command << endl;
//				msgRecvList.pop_front();
//			}
//			else
//			{
//				cout << "����Ϊ��" << i << endl;
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
