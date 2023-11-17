#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std; 
//class Person
//{
//public:
//	string m_name;
//	int m_age;
//	Person(string name, int age)
//	{
//		m_name = name;
//		m_age = age;
//	}
//	void setPerson(vector<Person>&v);
//	void setage(vector<Person>&v);
//	void showPoint();
//};
////  创建五个选手    给他们打分      打印分数
//void setage(vector<Person>&v)
//{
//	
//	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		deque<int>d;
//		
//		for (int i = 0; i < 10; i++)
//		{
//			int num1 = rand() % 41+60 ;
//			d.push_back(num1);
//		}
//		sort(d.begin(), d.end());
//		d.pop_back();   d.pop_front();
//		int sum=0;
//		for (deque<int>::iterator it1 = d.begin(); it1 != d.end(); it1++)
//		{
//			sum += *(it1);
//		}
//		int aver = sum / d.size();
//		(*it).m_age = aver;
//
//	}
//}
//void setPerson(vector<Person>& v)
//{
//	string nameSeed = "ABCDE";
//	
//	for (int i = 0; i < 5; i++)
//	{
//		string name = "选手";
//		name += nameSeed[i];
//		int age = 0;
//		Person p(name, age);
//		v.push_back(p);
//	}
//	
//}
//void print(vector<Person>& v)
//{
//	for (vector < Person>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << "姓名：" << (*it).m_name <<"    " << "年龄：" << (*it).m_age << endl;
//	}
//}
//int main()
//{
//	srand(time(NULL));
//	vector<Person> v;
//	setPerson(v);
//	setage(v);
//	print(v);
//}
//