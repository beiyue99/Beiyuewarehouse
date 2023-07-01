#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//
//int fun(int n, int m)
//{
//	n = n % m;
//	vector<int> V1;
//	while (1)
//	{
//		V1.push_back(n);
//		n *= 10;
//		n %= m;
//		if (n == 0) { return 0; }
//		if (find(V1.begin(), V1.end(), n) != V1.end())
//		{
//			return (int)distance( find(V1.begin(), V1.end(), n),V1.end());
//		}
//	}
//}
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	cout << fun(n, m);
//}




//
//int main()
//{
//	char c;
//	cin >> c;
//	if (c >= 'A' && c <= 'Z')
//	{
//		for (int i = 0; i <= c - 'A'; i++)
//		{
//			for (int j = 0; j <c - 'A'-i; j++)
//			{
//				cout << " ";
//			}
//			for (int j = 0; j <=i; j++)   //输出前半对称
//			{
//				cout << char('A' + j);
//			}
//			for (int j =i; j>0; j--)
//			{
//				cout << char(j + 'A'-1);
//			}
//			cout << endl;
//		}
//	}
//	else
//	{
//		for (int i = 0; i <= c - '1'; i++)
//		{
//			for (int j = 0; j < c - '1' - i; j++)
//			{
//				cout << " ";
//			}
//			for (int j = 0; j <= i; j++)   //输出前半对称
//			{
//				cout << (1 + j);
//			}
//			for (int j = i; j > 0; j--)
//			{
//				cout <<j;
//			}
//			cout << endl;
//		}
//	}
//}






