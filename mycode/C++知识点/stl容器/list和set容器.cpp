#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<stack>
#include<algorithm>
#include<list>
#include<set>
#include<vector>



// L.remove(n)    删除容器中等于n的元素



// 不可用用[]或者at函数来访问list容器中的数据 只有L1.front()  L1.back()  也可以加加减减双向操作


//L1.reverse() 翻转操作，空参          L1.sort()  排序操作 成员函数，空参




//  set 容器：

//插入数据只有insert方式  不允许插入重复值  插入自动排序
//	set<int>::iterator it = S.find(220);   
//  找到返回该元素的迭代器，否则返回end迭代器
//	int num = S.count(30);   //对于set而言 结果只有0和1




//
//
//
//class Mycompare
//{
//public:
//	bool operator()(int a, int b)  const   //必须加上const
//	{
//		return a > b;
//	}
//};

//	set<int, Mycompare> S2;       //使降序排列传入的元素
//compare是一个类（即函数对象，也称为仿函数），那么可以使用set<int, compare> S2; 
//的写法。这是因为此时的compare是一个类型，符合模板参数的要求。


//bool compare(int a, int b) { // 普通函数定义比较函数，实现降序排序
//    return a > b;
//}
//    std::set<int, bool(*)(int, int)> S2(compare); // 使用普通函数实例化set
//
//
// 
//    auto compare = [](int a, int b) { return a > b; }; // Lambda表达式定义比较函数，实现降序排序
//    std::set<int, decltype(compare)> S2(compare); // 使用lambda表达式实例化set













//
//class Person
//{
//public:
//	string m_name;
//	int m_age;
//	Person(string name, int age)
//	{
//		this->m_age = age;
//		this->m_name = name;
//	}
//};
//class Mycompare
//{
//public:
//	bool operator()( Person p1,  Person p2) const
//	{
//		return p1.m_age > p2.m_age;
//	}
//};
//
//int main()
//{
//	Person p1("刘备", 24);
//	Person p2("关羽", 35);
//	Person p3("张飞",22);
//	set<Person,Mycompare> S;
//	S.insert(p1);
//	S.insert(p2);
//	S.insert(p3);
//	for (set<Person, Mycompare>::iterator it = S.begin(); it != S.end(); it++)
//	{
//		cout << it->m_name << it->m_age << endl;
//	}
//}


