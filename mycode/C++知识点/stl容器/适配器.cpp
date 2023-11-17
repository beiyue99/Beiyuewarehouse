#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<functional>





//绑定适配器
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
//	for_each(v.begin(), v.end(), bind2nd(Myprint(),num));          //绑定适配器，将2元函数对象转变为1元函数对象
//}
   //bind1st将第一个参数v绑定为num值，bind2nd将第二个参数val绑定为num值












//  取反适配器   not1 用于一元函数对象，此时继承的是unary_function         not2用于二元函数对象

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
//	sort(v.begin(), v.end(), not2(MyCompare()));                         //取反 原来从大到小，改为从小到大。
//	for_each(v.begin(), v.end(), print); cout << endl;
//}



// ptr_fun  把普通函数转为函数对象   如：   prt_fun(Myprint);




