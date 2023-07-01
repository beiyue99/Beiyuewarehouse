#define _CRT_SECURE_NO_WARNINGS 1
#include<stack>
#include<iostream>
using namespace std;
//char s[50005];
//stack<int> s1;
//int ans[50005];
//int main()
//{
//	int len;
//	cin >> s;
//	len = strlen(s);
//	bool f = true;
//	for (int i = 0; i < len; i++)
//	{
//		if (s[i] == '(')
//		{
//			s1.push(i + 1);     
//		}
//		else
//		{
//			if (!s1.empty())
//			{
//				ans[i + 1] = s1.top(); // 记录第n个位置上的右括号匹配掉的左括号位置
//				s1.pop();
//			}
//			else
//			{
//				f = false;
//				break;
//			}
//		}
//	}
//	if (!s1.empty())
//	{
//		f = false;
//	}
//	if (!f)
//	{
//		cout << "no!" << endl;
//	}
//	else
//	{
//		cout << "yes!" << endl;
//		for (int i = 1; i <= len; i++)
//		{
//			if (ans[i])
//			{
//				cout << ans[i] << " :" << " " << i << endl;
//			}
//		}
//	}
//}







//汉诺塔
//stack <int> s1[3];
//void move(int x, int y)
//{
//	//if (s1[x].empty()) { return; }
//	int temp = s1[x].top();
//	s1[x].pop();
//	s1[y].push(temp);
//	cout << x << "-->" << y << endl;
//}
//void hanoi(int A, int B, int C,int n)
//{
//	if (n== 0)
//	{
//		//move(A, C);
//		return;
//	}
//	hanoi(A, C, B, n - 1);//A上n-1个盘子借助C移动到B
//	move(A, C);           //A上最后一个盘移到C
//	hanoi(B, A, C, n - 1);//B上的n-1个盘子也就是所有盘子借助A移动到C
//}
//
//int main()
//{
//
//	int n;
//	cin >> n;
//	for (int i = n; i >= 1; i--)
//	{
//		s1[0].push(i);
//	}
//	hanoi(0, 1, 2, n);
//	while (!s1[2].empty())
//	{
//		cout << s1[2].top() << " ";
//		s1[2].pop();
//	}
//}







