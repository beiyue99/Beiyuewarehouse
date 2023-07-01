//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<vld.h>
//using namespace std;
//
//template<typename T>
//class Node
//{
//public:
//	T date;
//	Node<T>* next;
//};
//
//template<typename T>
//class LList
//{
//public:
//	LList(T a[], int n)
//	{
//		first = new Node<T>;
//		first->next = nullptr;
//	    tail = first;
//		for (int i = 0; i < n; i++)
//		{
//			//头插法
//		/*	Node<T>* s = new Node<T>;
//			s->date = a[i];
//			s->next = first->next;
//			first->next = s;*/
//			//尾插法
//			Node<T>*s = new Node<T>;
//			s->date = a[i];
//			s->next = tail->next;
//			tail->next = s;
//			tail = s;
//		} 
//	}
//	int Length()
//	{
//		Node<T>* p = first;
//		int i = 0;
//		while (p)
//		{
//			p = p->next;
//			i++;
//		}
//		return i;
//	}
//	Node<T>*  Get(int i)//查找,按位置查找,返回节点指针
//	{
//		if (i < 1) return nullptr;
//		Node<T>* p = first;
//		int j = 0;
//		while (j < i && p)
//		{
//			p = p->next;
//			j++;
//		}
//		return p;
//	}
//	int Locate(T x)//定位，按位置定位，返回位置下标
//	{
//		Node<T>* p = first;
//		int j = 0;
//		while (p)
//		{
//			if (p->date == x)
//			{
//				return j;
//			}
//			p = p->next;
//			j++;
//		}
//		cout << "没找到，返回值为"; return 0;
//	}
//	void print()
//	{
//		Node<T>* p = first->next;
//		while (p)
//		{
//			cout << p->date << " ";
//			p = p->next;
//		}
//	}
//	void InsertAfter(Node<T>*p,T x)//插入
//	{
//		Node<T>* s = new Node<T>;
//		s->date = x;
//		s->next = p->next;
//		p->next = s;
//	}
//	void InsertBefore(Node<T>* p, T x)//插入 时间复杂度为n
//	{
//		Node<T>* q = first;
//		while (q->next != p) q = q->next;      //前插   需要找到前面节点的位置，然后再后插
//		InsertAfter(q, x);
//	}
//	void InsertBefore2(Node<T>* p, T x)//插入  时间复杂度为1
//	{
//		Node<T>* s = new Node<T>;
//		*s = *p;                      //创造个s跟p一样，使得p的下一个是p，再把p的东西改了
//		p->next = s;
//		p->date = x;
//	}
//	void Delete(Node<T>*p)//删除
//	{ 
//		if (p->next!=nullptr)           //时间复杂度为1
//		{
//			p->date = p->next->date;
//			Node<T>* q = p->next;
//			p->next = q->next;
//			delete q;
//		}
//	}
//	~LList()
//	{
//		while (first != nullptr)
//		{
//			Node<T>* p = first;
//			first = first->next;
//			delete p;
//		}
//	}
//private:
//	Node<T>* first;
//	Node<T>* tail;
//};
//
//int main()
//{
//	int arr[] = { 2,1421,3,1,4,142,1,222 };
//	LList<int> L1(arr, 8);
//	L1.print();
//	cout << endl;
//	cout << "查找1421元素所在的位置" << endl;
//	cout << L1.Locate(14212) << endl;
//	cout << "输出第三个元素" << endl;
//	cout << L1.Get(3)->date<< endl;          //得到第三个位置的节点
//	cout << "删除第五个元素" << endl;
//	L1.Delete(L1.Get(5));
//	L1.print();
//	cout << endl;
//	cout << "在第三个元素的后面插入28" << endl;
//	L1.InsertAfter(L1.Get(3), 28);
//	L1.print();
//	cout <<endl<< "在第四个元素的前面插入88" << endl;
//	L1.InsertBefore(L1.Get(4), 88);
//	L1.print();
//	cout << endl<<"在第六个元素的前面插入7" << endl;
//	L1.InsertBefore2(L1.Get(6), 7);
//	L1.print();
//	cout << endl;
//	cout << "此时长度为：" << L1.Length();
//}




