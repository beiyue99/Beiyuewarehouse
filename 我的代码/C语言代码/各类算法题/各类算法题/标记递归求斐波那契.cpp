#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>
#include <stdlib.h>
#include<string>
#include<math.h>
#include <algorithm>
#include<sstream>
#include<iomanip>





//
//int ans[2005];
//bool vis[2005];
//int f(int n, int a, int b, int p)
//{
//	if (vis[n])
//	{
//		return ans[n];
//	}
//	vis[n] = true;
//	if (n == 1 || n == 2)
//	{
//		return ans[n] = 1 % p;
//	}
//	else
//	{
//		return ans[n] = a * f(n - 1, a, b, p) % p + b * f(n - 2, a, b, p) % p;
//	}
//}
//	int main()
//	{
//		int n, a, b, p;
//		cin >> n >> a >> b >> p;
//		cout << f(n, a, b, p);
//	}
