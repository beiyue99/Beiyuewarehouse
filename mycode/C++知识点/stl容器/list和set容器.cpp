#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<stack>
#include<algorithm>
#include<list>
#include<set>
#include<vector>







// L.remove(n)    ɾ�������е���n��Ԫ��



// ��������[]����at����������list�����е����� ֻ��L1.front()  L1.back()  Ҳ���ԼӼӼ���˫�����


//L1.reverse() ��ת�������ղ�          L1.sort()  ������� ��Ա�������ղ�








//  set ������

//��������ֻ��insert��ʽ  ����������ظ�ֵ  �����Զ�����
//	set<int>::iterator it = S.find(220);   
//  �ҵ����ظ�Ԫ�صĵ����������򷵻�end������
//	int num = S.count(30);   //����set���� ���ֻ��0��1










//pair����Ĵ�����ʽ
//int main()
//{
//	pair<string, int>p("����", 22);
//	cout << p.first << endl;
//	pair<string, int>p2=make_pair("��s", 22);
//	cout << p2.first << endl;
//}




//
//
//
//class Mycompare
//{
//public:
//	bool operator()(int a, int b)  const   //�������const
//	{
//		return a > b;
//	}
//};

//	set<int, Mycompare> S2;       //ʹ�������д����Ԫ��
//compare��һ���ࣨ����������Ҳ��Ϊ�º���������ô����ʹ��std::set<int, compare> S2; 
//��д����������Ϊ��ʱ��compare��һ�����ͣ�����ģ�������Ҫ��





//bool compare(int a, int b) { // ��ͨ��������ȽϺ�����ʵ�ֽ�������
//    return a > b;
//}
//    std::set<int, bool(*)(int, int)> S2(compare); // ʹ����ͨ����ʵ����set
//
//
//
//
//
// 
// 
// 
//    auto compare = [](int a, int b) { return a > b; }; // Lambda���ʽ����ȽϺ�����ʵ�ֽ�������
//    std::set<int, decltype(compare)> S2(compare); // ʹ��lambda���ʽʵ����set




















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
//	Person p1("����", 24);
//	Person p2("����", 35);
//	Person p3("�ŷ�",22);
//	set<Person,Mycompare> S;
//	S.insert(p1);
//	S.insert(p2);
//	S.insert(p3);
//	for (set<Person, Mycompare>::iterator it = S.begin(); it != S.end(); it++)
//	{
//		cout << it->m_name << it->m_age << endl;
//	}
//}


