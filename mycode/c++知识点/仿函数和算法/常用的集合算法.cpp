#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>



// v1和v2的差集   是指v1中比v2多的东西
  

//  set_intersection  求两个容器的交集    两个容器必须是有序序列，同下   有五个参数   返回值为交集最后一个元素的迭代器
//  set_union                     并集
//  set_difference                差集

//
//int main()
//{
//	vector<int > v1{ 1,2,3,4,5,6 };
//	vector<int> v2{ 3,5,7 };
//	vector<int> v3;
//	v3.resize(v1.size());
//	auto itt=set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
//	for (auto it = v3.begin(); it != v3.end(); it++)     //打印3 5 0 0 0   或者3 5   取决于用v3.end还是itt
//	{
//		cout << *it << "  ";
//	}
//}
