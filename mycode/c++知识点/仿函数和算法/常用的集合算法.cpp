#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>



// v1��v2�Ĳ   ��ָv1�б�v2��Ķ���
  

//  set_intersection  �����������Ľ���    ���������������������У�ͬ��   ���������   ����ֵΪ�������һ��Ԫ�صĵ�����
//  set_union                     ����
//  set_difference                �

//
//int main()
//{
//	vector<int > v1{ 1,2,3,4,5,6 };
//	vector<int> v2{ 3,5,7 };
//	vector<int> v3;
//	v3.resize(v1.size());
//	auto itt=set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
//	for (auto it = v3.begin(); it != v3.end(); it++)     //��ӡ3 5 0 0 0   ����3 5   ȡ������v3.end����itt
//	{
//		cout << *it << "  ";
//	}
//}
