#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//���ҵ�һ������ 2022 ����С���������ת���ɶ�����֮����͵� 6 ��������ΪȫΪ 0
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









//8518 ��һ���ǳ������������������������ 16 ������������ֵΪ(8518)16 = 8 * 16 * 16 * 16 + 5 * 16 * 16 + 1 * 16 + 8 = 34072��
//�� 34072 ������ 8518 ����������
//9558 Ҳ������һ������������ 16 ����ʱ�� 38232��
//��ʵ����Ϊ 1 ���� 0 �� 9 �����㿴�� 16 ���ƺ����Լ�����������1������
//���ʣ���������Ϊ 1 ��������С�������������������Ƕ��٣�
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









//�� 2022 ��ֳɲ�ͬ�������ĺͣ���������ֳɼ�����
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
//��������
//һ���ַ�������������Ҷ��ʹ����������ͬ�����Ϊһ�����Ĵ������� lanqiaoaiqnal ��һ�����Ĵ���
//С����һ���ַ������뽫����ַ����ұ߼���һЩ�ַ���ʹ���Ϊһ�����Ĵ���
//����ж��ַ������������̵Ļ��Ĵ���
//�����ʽ
//����һ�а���һ���ַ�������СдӢ����ĸ��ɡ�
//�����ʽ
//���һ�а����𰸡�
//��������
//lanqiao
//�������
//lanqiaoaiqnal
//��������
//banana
//�������
//bananab
//��������
//noon
//�������
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
//С����һ������ a[1], a[2], ..., a[n]��ÿ�ο��Խ������ڵ�����Ԫ�أ�����Ϊ����Ԫ���нϴ���Ǹ���
//���ʣ�Ҫͨ�����������б�Ϊ��С������������У��ܴ�������Ϊ���٣�
//�����ʽ
//����һ�а���һ������ n ����ʾ���г��ȡ�
//�ڶ��а��� n ����������ʾ���������С�
//�����ʽ
//���һ�а���һ����������ʾ���ٴ��۵�ֵ��
//��������
//4
//1 5 2 1
//�������
//12


