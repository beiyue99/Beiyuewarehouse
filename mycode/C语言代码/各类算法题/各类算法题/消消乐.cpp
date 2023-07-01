#define _CRT_SECURE_NO_WARNINGS 1
#include<stack>
#include<iostream>
using namespace std;

//输入：
//abbc
//复制
//输出：
//ac
#include<vector>
#include<algorithm>


//用算法库adjcent_find
//char name[300005] = { 0 };
//int main()
//{
//	vector<char> v1;
// //   char* name = { 0 };
//	//cin >> name;
//	//cout << name;
//	// 这种写法不可取 要强行向字符指针name指向的内存地址总写字符串，但是这个name指向地址是不确定的
//	// （因为定义name指针变量时没有初始化它的指向），所以报错以免写入到非法的内存区域中。
//	// +++++++++++++++++++++++++++++++++++++++++++++++++++
//	//const char* name = { 0 };
//	//cin >> name;
//	// 这种方法也不可取，const修饰的值不可改变
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
//		//  erase  的奇怪用法
//		v1.erase(it, it2);
//	}
//	for (auto iter : v1)
//	{
//		cout << iter << "";
//	}
//}






//输入：
//abbc
//复制
//输出：
//ac
//用栈
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