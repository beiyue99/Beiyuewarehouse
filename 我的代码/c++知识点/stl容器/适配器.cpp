#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<functional>





//��������
//class Myprint:public binary_function<int,int,void>
//{
//public:
//	void operator ()(int v,int val) const
//	{
//		cout << v +val<< "  ";
//		cout << v << "   " << val << endl;
//	}
//};
//int main()
//{
//	vector<int> v;
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//	int num = 100;
//	for_each(v.begin(), v.end(), bind2nd(Myprint(),num));          //������������2Ԫ��������ת��Ϊ1Ԫ��������
//}
   //bind1st����һ������v��Ϊnumֵ��bind2nd���ڶ�������val��Ϊnumֵ












//  ȡ��������   not1 ����һԪ�������󣬴�ʱ�̳е���unary_function         not2���ڶ�Ԫ��������

//class MyCompare:public binary_function<int,int,bool>
//{
//public:
//	bool operator()(int v1, int v2)  const
//	{
//		return v1 > v2;
//	}
//};
//
//void print(int v)
//{
//	cout << v << " ";
//}
//int main()
//{
//	vector<int> v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(rand() % 100);
//	}
//	for_each(v.begin(), v.end(), print); cout << endl;
//	sort(v.begin(), v.end(), not2(MyCompare()));                         //ȡ�� ԭ���Ӵ�С����Ϊ��С����
//	for_each(v.begin(), v.end(), print); cout << endl;
//}



// ptr_fun  ����ͨ����תΪ��������   �磺   prt_fun(Myprint);




