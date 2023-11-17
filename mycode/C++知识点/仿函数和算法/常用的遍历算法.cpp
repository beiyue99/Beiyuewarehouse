#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<functional>   //内建函数对象头文件



//class Transform
//{
//public:
//	int operator()(int v)
//	{
//		return v+100;         //搬运的同时 每个元素加100
//	}
//};
//int fun(int v)
//{
//	return v + 100;
//}
//void Myprint(int a)
//{
//	cout << a << " ";
//}
//int main()
//{
//	vector<int> v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	}
//	vector<int>vTarget;
//	vTarget.resize(v.size());          //必须给予空间
//	transform(v.begin(), v.end(), vTarget.begin(), fun);  //transform也可以用普通函数
//	for_each(vTarget.begin(), vTarget.end(), ptr_fun(Myprint));    
//}

//sort，for_each的第三个参数可以是普通函数










// adjacent_find(v.begin(),v.end())   查找  相邻且重复元素，返回第一个元素的迭代器，否则返回end迭代器
//int main()
//{
//	vector<int> v1{ 2,41,41,4,21,4,4 };
//	while (adjacent_find(v1.begin(), v1.end()) != v1.end())
//	{
//		v1.erase(adjacent_find(v1.begin(), v1.end()));
//	}
//	for (auto it : v1)
//	{
//		cout << it << " ";
//	}
//}





// binary_search  查找元素是否存在,返回真和假      必须在有序数列中使用  因为内部查找是二分查找
//要注意，find函数返回的是这个元素的地址，如果找不到，返回end位置的地址



//  merge   将两个容器元素合并，并储存到另一个容器中，两个容器必须是有序的，
//且合并到另一个容器中也是有序的，merge() 有五个参数




//使用stringstream 完成字符和数字之间的转换 

//#include<sstream>
//int main()
//{
//	constexpr int  num = 12;          //表示编译期就可以确定num的值，运行时自动替换为12
//	string s;
//	stringstream strs;
//	strs << num;
//	strs >> s;
//	strs.clear();    //必须调用clear,不然可能出现问题
//	cout << s << endl;
//	const string s1 = "123";
//
//	int a = 0;
//	strs << s1;
//	strs >> a;
//	cout << a;
//}



//
//int main()
//{
//	const char* s1 = "21";
//	int a = atoi(s1);
//	cout << a << endl;
//	string s2 = "28";
//	int b = atoi(s2.c_str());     //将string转为const char*
//	cout << b << endl;
//	const char* s3 = "10";
//	int c = stoi(s3);           // 跟atoi用法大致一样
//	cout << c << endl;
//	int d = 1888;
//	char name[20];
//    _itoa(d,name,10);              //新版本VS对此函数进行安全检查，要么加上宏定义，要么使用_itoa
//	cout << name << endl;
//}