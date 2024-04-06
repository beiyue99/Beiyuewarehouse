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
//			//ͷ�巨
//		/*	Node<T>* s = new Node<T>;
//			s->date = a[i];
//			s->next = first->next;
//			first->next = s;*/
//			//β�巨
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
//	Node<T>*  Get(int i)//����,��λ�ò���,���ؽڵ�ָ��
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
//	int Locate(T x)//��λ����λ�ö�λ������λ���±�
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
//		cout << "û�ҵ�������ֵΪ"; return 0;
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
//	void InsertAfter(Node<T>*p,T x)//����
//	{
//		Node<T>* s = new Node<T>;
//		s->date = x;
//		s->next = p->next;
//		p->next = s;
//	}
//	void InsertBefore(Node<T>* p, T x)//���� ʱ�临�Ӷ�Ϊn
//	{
//		Node<T>* q = first;
//		while (q->next != p) q = q->next;      //ǰ��   ��Ҫ�ҵ�ǰ��ڵ��λ�ã�Ȼ���ٺ��
//		InsertAfter(q, x);
//	}
//	void InsertBefore2(Node<T>* p, T x)//����  ʱ�临�Ӷ�Ϊ1
//	{
//		Node<T>* s = new Node<T>;
//		*s = *p;                      //�����s��pһ����ʹ��p����һ����p���ٰ�p�Ķ�������
//		p->next = s;
//		p->date = x;
//	}
//	void Delete(Node<T>*p)//ɾ��
//	{ 
//		if (p->next!=nullptr)           //ʱ�临�Ӷ�Ϊ1
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
//	cout << "����1421Ԫ�����ڵ�λ��" << endl;
//	cout << L1.Locate(14212) << endl;
//	cout << "���������Ԫ��" << endl;
//	cout << L1.Get(3)->date<< endl;          //�õ�������λ�õĽڵ�
//	cout << "ɾ�������Ԫ��" << endl;
//	L1.Delete(L1.Get(5));
//	L1.print();
//	cout << endl;
//	cout << "�ڵ�����Ԫ�صĺ������28" << endl;
//	L1.InsertAfter(L1.Get(3), 28);
//	L1.print();
//	cout <<endl<< "�ڵ��ĸ�Ԫ�ص�ǰ�����88" << endl;
//	L1.InsertBefore(L1.Get(4), 88);
//	L1.print();
//	cout << endl<<"�ڵ�����Ԫ�ص�ǰ�����7" << endl;
//	L1.InsertBefore2(L1.Get(6), 7);
//	L1.print();
//	cout << endl;
//	cout << "��ʱ����Ϊ��" << L1.Length();
//}




