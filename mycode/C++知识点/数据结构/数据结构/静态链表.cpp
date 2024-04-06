//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//#define MaxSize 201
//
//enum NodeUse
//{
//	e_Nouse = -1,//  标记，代表未使用
//	e_Last = -2  //  标记，代表最后一个节点
//};
//
//template <typename T>
//struct Node
//{
//	T date;
//	int cur;   //记录下个静态链表节点的数组下标
//};
//
//template <typename T>
//
//class StaticLinkList
//{
//public:
//	StaticLinkList();
//	~StaticLinkList();
//	int find_pos(); 
//	bool ListInsert(int i, const T& e);  
//	bool ListDelete(int i);   //删除第i个位置的元素
//	bool GetElem(int i, T& e);  //获得第i个位置的元素值
//	int LocateElem(const T& e); //返回第一次出现的位置
//	void display();  
//	int GetLength(); 
//	bool isEmpty();
//private:
//	Node<T> m_date[MaxSize];
//	int m_length; //当前长度
//};
//template <typename T>
//StaticLinkList<T>::StaticLinkList()
//{
//	for (int i = 1; i < MaxSize; i++)
//	{
//		m_date[i].cur = e_Nouse;
//	}
//	m_length = 0;
//}
//template <typename T>
//StaticLinkList<T>::~StaticLinkList()
//{
//
//}
//template <typename T>
////在m_date中找一个空闲位置保存数据，如果满了，返回-1
//int StaticLinkList<T>::find_pos()
//{
//	for (int i = 1; i < MaxSize; i++)
//	{
//		if (m_date[i].cur ==e_Nouse)
//		{
//			return i;
//		}
//	}
//	return -1;
//}
//template <typename T>
//
//
//bool StaticLinkList<T>::ListInsert(int ipos,const T&e)//在第i个位置插入指定元素e
//{
//	if (ipos<1 || ipos>(m_length + 1))
//	{
//		cout << "位置不合法，合法位置是1到" << m_length + 1 << "之间" << endl; return false;
//	}
//	int iIdex;//就是空余的数组下标
//	if ((iIdex=find_pos()) == -1)
//	{
//		cout << "静态表已满" << endl;
//		return false;
//	}
//	int iIdexPrev;    // 前驱位置
//	if (ipos == 1)
//	{
//		m_date[iIdex].date = e; //数组[index]元素为e
//		if (m_length == 0)
//		{
//			m_date[iIdex].cur = e_Last; //第一次插入把数组[1]的标记设为last
//		}
//		else
//		{
//			m_date[iIdex].cur = m_date[0].cur;   //
//		}
//		m_date[0].cur = iIdex;
//	}
//	else
//	{
//		int posCount = 0;
//		int tmpcur = m_date[0].cur;//代表第一个元素所在的数组下标位置，dete[tmpcur]可以找到第一个元素
//		while (true)
//		{
//			posCount++;
//			if (posCount == (ipos - 1))  
//			{
//				iIdexPrev = tmpcur;  //  若插入第二个位置 将Last标记传给iIdexPrev,然后退出循环
//				break;
//			}
//			//在第一个位置插的时候，已经把数组1的Cur标记为Last
//			tmpcur = m_date[tmpcur].cur; 
//		}
//		int iTmpCurr = m_date[iIdexPrev].cur;
//		m_date[iIdexPrev].cur = iIdex;// 
//		m_date[iIdex].date = e;
//		m_date[iIdex].cur = iTmpCurr;
//	}
//	cout << "成功在位置为" << ipos << "处插入元素" << e << endl;
//	m_length++;
//	return true;
//}
//template <typename T>
//void  StaticLinkList<T>::display()
//{
//	if (m_length < 1)
//	{
//		return;
//	}
//	int tmpPcur = m_date[0].cur;
//	while (true)
//	{
//		cout << m_date[tmpPcur].date << " " << endl;
//		if ((tmpPcur = m_date[tmpPcur].cur) == e_Last)
//		{
//			break;
//		}
//	}
//}
////int find_pos();  //找到一个空闲位置用于保存数据
////bool ListInsert(int i, const T& e);  //在第i个位置插入指定元素e
////bool ListDelete(int i);   //删除第i个位置的元素
////bool GetElem(int i, T& e);  //获得第i个位置的元素值
////int LocateElem(const T& e); //返回第一次出现的位置
////void display();
////int GetLength();
////bool isEmpty();
//
//
//int main()
//{
//	StaticLinkList<int> L1;
//	L1.ListInsert(1, 12);
//	L1.ListInsert(1, 24);
//	L1.ListInsert(3, 48);
//	L1.ListInsert(2, 100);
//	//L1.ListInsert(5, 190);
//	//L1.ListInsert(4, 300);
//	L1.display();
//	return 0;
//}
//
//
//
//
