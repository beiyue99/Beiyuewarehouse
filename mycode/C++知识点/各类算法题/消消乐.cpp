#define _CRT_SECURE_NO_WARNINGS 1
#include<stack>
#include<iostream>
using namespace std;

//���룺
//abbc
//����
//�����
//ac
#include<vector>
#include<algorithm>


//���㷨��adjcent_find
//char name[300005] = { 0 };
//int main()
//{
//	vector<char> v1;
// //   char* name = { 0 };
//	//cin >> name;
//	//cout << name;
//	// ����д������ȡ Ҫǿ�����ַ�ָ��nameָ����ڴ��ַ��д�ַ������������nameָ���ַ�ǲ�ȷ����
//	// ����Ϊ����nameָ�����ʱû�г�ʼ������ָ�򣩣����Ա�������д�뵽�Ƿ����ڴ������С�
//	// +++++++++++++++++++++++++++++++++++++++++++++++++++
//	//const char* name = { 0 };
//	//cin >> name;
//	// ���ַ���Ҳ����ȡ��const���ε�ֵ���ɸı�
//	// ++++++++++++++++++++++++++++++++++++++++++++++++++++
//	cin >> name;
//	int len = strlen(name);
//	for (int i = 0; i < len; i++)
//	{
//		v1.push_back(name[i]);
//	}
//	while (adjacent_find(v1.begin(), v1.end()) != v1.end())
//	{
//		vector<char>::iterator it = adjacent_find(v1.begin(), v1.end());
//		auto it2 = it + 2;
//		//  erase  ������÷�
//		v1.erase(it, it2);
//	}
//	for (auto iter : v1)
//	{
//		cout << iter << "";
//	}
//}






//���룺
//abbc
//����
//�����
//ac
//��ջ
//char name[300005];
//int main()
//{
//	stack<char>s1;
//	cin >> name;
//	for (int i = 0; name[i] != '\0'; i++)
//	{
//		if (s1.empty() || s1.top() != name[i])
//		{
//			s1.push(name[i]);
//		}
//		else if (s1.top() == name[i])
//		{
//			s1.pop();
//		}
//	}
//	if (s1.empty())
//	{
//		cout << "0" << endl;
//	}
//	else
//	{
//		string s;
//		while (!s1.empty())
//		{
//			s = s1.top() + s;
//			s1.pop();
//		}
//		cout << s;
//	}
//}