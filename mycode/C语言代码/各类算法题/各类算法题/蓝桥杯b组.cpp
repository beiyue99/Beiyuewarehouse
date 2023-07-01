#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//请找到一个大于 2022 的最小数，这个数转换成二进制之后，最低的 6 个二进制为全为 0
#include <algorithm>


//string get(int x)
//{
//	string s;
//	while (x)
//	{
//		s += x % 2 + '0';
//		x /= 2;
//	}
//	if (s[0] == s[1] && s[1] == s[2] && s[2] == s[3]
//		&& s[3] == s[4] && s[4] == s[5] && s[0] == '0')
//	{
//		cout << "res";
//	}
//	reverse(s.begin(), s.end());
//	return s;
//}
//
//int get_res(string s)
//{
//	int res = 0;
//	for (int i = 0; i < s.size(); i++) res = res * 2 + s[i] - '0';
//	cout << res << endl;
//	return res;
//}
//
//int main()
//{
//	// string s;
//	//
//	// int x = 2022;
//	// while(x)
//	// {
//	// s += x % 2 + '0';
//	// x /= 2;
//	// }
//	//
//	// for(int i = 2023; i <= 10000; i ++)
//	// cout << get(i) << endl;
//
//	// 100001000000
//	get_res("100001000000");
//
//	// reverse(s.begin(), s.end());
//	// cout << s << endl;
//
//	return 0;
//}









//8518 是一个非常特殊的数，如果把这个数看成 16 进制数，它的值为(8518)16 = 8 * 16 * 16 * 16 + 5 * 16 * 16 + 1 * 16 + 8 = 34072，
//而 34072 正好是 8518 的整数倍。
//9558 也是这样一个数，当看成 16 进制时是 38232。
//其实长度为 1 的数 0 到 9 都满足看成 16 进制后是自己的整数倍（1倍）。
//请问，除开长度为 1 的数，最小的满足这样条件的数是多少？
//#include<string>
//bool check(int x)
//{
//	string s =to_string(x);
//	int res = 0;
//	for (int i = 0; i < s.size(); i++)  //5236
//	{
//		res = res * 16 + s[i] - '0';    // ( (5*16+2)*16+3  )*16+6
//	}
//	return res % x == 0;
//}
//
//int main()
//{
//	int x = 10;
//	while (true)
//	{
//		if (check(x))
//		{
//			cout << x << endl;
//			break;
//		}
//		x++;
//	}
//
//	return 0;
//}











//const int N = 35, M = 65;
//
//int n = 30, m = 60;
//char g[N][M];
//int f[N][M];
//
//int main()
//{
//	for (int i = 1; i <= n; i++)
//		cin >> g[i] + 1;
//
//
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= m; j++)
//		{
//			f[i][j] = max(f[i - 1][j], f[i][j - 1]) + g[i][j] - '0';
//		}
//	cout << f[n][m] << endl;
//
//	return 0;
//}









//将 2022 拆分成不同的质数的和，请问最多拆分成几个？
//const int N = 2100;
//
//int n = 306, m = 2022;
//int cnt = 0;
//int primes[N];
//bool st[N];
//int f[310][N];
//
//void get_primes(int n)
//{
//	for (int i = 2; i <= n; i++)
//	{
//		if (!st[i])
//		{
//			primes[++cnt] = i;
//			for (int j = i + i; j <= n; j += i) 
//				st[j] = true;
//		}
//	}
//}
//
//int main()
//{
//	get_primes(2022);
//
//	for (int i = 1; i <= n; i++)
//		for (int j = 2; j <= m; j++)
//		{
//			if (primes[i] <= j)
//			{
//				f[i][j] = max(f[i - 1][j], f[i - 1][j - primes[i]] + primes[i]);
//			}
//			else f[i][j] = f[i - 1][j];
//		}
//
//	int j = m, res = 0;
//	for (int i = n; i; i--)
//		if (f[i][j] != f[i - 1][j]) {
//			j -= primes[i];
//			res++;
//			cout << primes[i] << ' ';
//		}
//
//	puts("");
//	cout << res << endl;
//	return 0;
//}







//
//问题描述
//一个字符串如果从左向右读和从右向左读相同，则称为一个回文串，例如 lanqiaoaiqnal 是一个回文串。
//小蓝有一个字符串，请将这个字符串右边加上一些字符，使其成为一个回文串。
//如果有多种方案，请输出最短的回文串。
//输入格式
//输入一行包含一个字符串，由小写英文字母组成。
//输出格式
//输出一行包含答案。
//样例输入
//lanqiao
//样例输出
//lanqiaoaiqnal
//样例输入
//banana
//样例输出
//bananab
//样例输入
//noon
//样例输出
//noon
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//int n;
//string s;
//
//bool check(string s)
//{
//	int i = 0, j = s.size() - 1;
//	while (i < j)
//		if (s[i++] != s[j--])
//			return false;
//	return true;
//}
//
//int main()
//{
//	cin >> s;
//
//	n = s.size();
//	for (int i = 0, len = n; i < n; i++, len--)
//	{
//		string t = s.substr(i, len);
//		if (check(t))
//		{
//			string prev = s.substr(0, i);
//			string post = prev;
//			if (prev.size())
//			{
//				reverse(post.begin(), post.end());
//				cout << prev + t + post << endl;
//				return 0;
//			}
//			else
//			{
//				cout << t << endl;
//				return 0;
//			}
//		}
//	}
//
//	return 0;
//}







//
//小蓝有一个序列 a[1], a[2], ..., a[n]，每次可以交换相邻的两个元素，代价为两个元素中较大的那个。
//请问，要通过交换将序列变为从小到大递增的序列，总代价最少为多少？
//输入格式
//输入一行包含一个整数 n ，表示序列长度。
//第二行包含 n 个整数，表示给定的序列。
//输出格式
//输出一行包含一个整数，表示最少代价的值。
//样例输入
//4
//1 5 2 1
//样例输出
//12


