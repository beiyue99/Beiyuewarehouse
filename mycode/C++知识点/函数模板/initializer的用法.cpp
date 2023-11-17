#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include"源.hpp"

//using namespace std;
//int main()
//{
//	////左值类型初始化
//	//initializer_list<int> iLst{ 1,2,3,4,5 };
//	//vector<int> v1(iLst);
//	////右值
//	//vector<int>v2{ 1,23,3,5,6 };
//	int i1 = 10, i2 = 20, i3 = 30, i4 = 40;
//	initializer_list<int*> iList{ &i1,&i2,&i3, & i4 };
//	MyArray<int*> arrayPi(iList);
//	for (unsigned i = 0; i < 4; i++)
//	{
//		cout << *arrayPi[i] << endl;
//	}
//	return 0;
//	
//}