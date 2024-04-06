//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//#define MaxSize 201
//
//enum NodeUse
//{
//	e_Nouse = -1,//  ��ǣ�����δʹ��
//	e_Last = -2  //  ��ǣ��������һ���ڵ�
//};
//
//template <typename T>
//struct Node
//{
//	T date;
//	int cur;   //��¼�¸���̬����ڵ�������±�
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
//	bool ListDelete(int i);   //ɾ����i��λ�õ�Ԫ��
//	bool GetElem(int i, T& e);  //��õ�i��λ�õ�Ԫ��ֵ
//	int LocateElem(const T& e); //���ص�һ�γ��ֵ�λ��
//	void display();  
//	int GetLength(); 
//	bool isEmpty();
//private:
//	Node<T> m_date[MaxSize];
//	int m_length; //��ǰ����
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
////��m_date����һ������λ�ñ������ݣ�������ˣ�����-1
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
//bool StaticLinkList<T>::ListInsert(int ipos,const T&e)//�ڵ�i��λ�ò���ָ��Ԫ��e
//{
//	if (ipos<1 || ipos>(m_length + 1))
//	{
//		cout << "λ�ò��Ϸ����Ϸ�λ����1��" << m_length + 1 << "֮��" << endl; return false;
//	}
//	int iIdex;//���ǿ���������±�
//	if ((iIdex=find_pos()) == -1)
//	{
//		cout << "��̬������" << endl;
//		return false;
//	}
//	int iIdexPrev;    // ǰ��λ��
//	if (ipos == 1)
//	{
//		m_date[iIdex].date = e; //����[index]Ԫ��Ϊe
//		if (m_length == 0)
//		{
//			m_date[iIdex].cur = e_Last; //��һ�β��������[1]�ı����Ϊlast
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
//		int tmpcur = m_date[0].cur;//�����һ��Ԫ�����ڵ������±�λ�ã�dete[tmpcur]�����ҵ���һ��Ԫ��
//		while (true)
//		{
//			posCount++;
//			if (posCount == (ipos - 1))  
//			{
//				iIdexPrev = tmpcur;  //  ������ڶ���λ�� ��Last��Ǵ���iIdexPrev,Ȼ���˳�ѭ��
//				break;
//			}
//			//�ڵ�һ��λ�ò��ʱ���Ѿ�������1��Cur���ΪLast
//			tmpcur = m_date[tmpcur].cur; 
//		}
//		int iTmpCurr = m_date[iIdexPrev].cur;
//		m_date[iIdexPrev].cur = iIdex;// 
//		m_date[iIdex].date = e;
//		m_date[iIdex].cur = iTmpCurr;
//	}
//	cout << "�ɹ���λ��Ϊ" << ipos << "������Ԫ��" << e << endl;
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
////int find_pos();  //�ҵ�һ������λ�����ڱ�������
////bool ListInsert(int i, const T& e);  //�ڵ�i��λ�ò���ָ��Ԫ��e
////bool ListDelete(int i);   //ɾ����i��λ�õ�Ԫ��
////bool GetElem(int i, T& e);  //��õ�i��λ�õ�Ԫ��ֵ
////int LocateElem(const T& e); //���ص�һ�γ��ֵ�λ��
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
