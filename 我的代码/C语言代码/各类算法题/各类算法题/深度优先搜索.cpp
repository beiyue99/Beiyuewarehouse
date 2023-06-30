#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//
//int n, m;
//string maze[110];
//bool vis[110][110];
//
//bool islegal(int x, int y)
//{
//	return 0 <= x && x < n && 0 <= y && y < m && maze[x][y] != '*' && !vis[x][y];
//}
//bool dfs(int x, int y)
//{
//	if (!islegal(x, y))
//	{
//		return false;
//	}
//	if (maze[x][y] == 'T')
//	{
//		return true;
//	}
//	vis[x][y] = 1;
//	maze[x][y] = 'm';
//	if (dfs(x - 1, y) || dfs(x, y - 1) || dfs(x + 1, y) || dfs(x, y + 1))
//	{//      上               左               下                右
//		return true;
//	}
//	vis[x][y] = 0;
//	maze[x][y] = '.';
//	return false;
//}
//
//int main()
//{
//	while (1)
//	{
//		cin >> n >> m;
//		for (int i = 0; i < n; i++)
//		{
//			cin >> maze[i];
//		}
//		int x = 0, y = 0;
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < m; j++)
//			{
//				if (maze[i][j] == 'S')
//				{
//					x = i;
//					y = j;
//				}
//			}
//		}
//		if (dfs(x, y))
//		{
//			cout << "++++++++++++++" << endl;
//			for (int i = 0; i < n; i++)
//			{
//				cout << maze[i] << endl;
//			}
//			cout << "++++++++++++++++++++" << endl;
//		}
//		else 
//		{
//			cout << "no!" << endl;
//		}
//	}
//}











//计数迷宫出口
//#include<iostream>
//using namespace std;
//int n, m;
//string maze[110];
//bool vis[110][110];
//int ans = 10000000;
//bool islegal(int x, int y)
//{
//	return 0 <= x && x < n && 0 <= y && y < m && maze[x][y] != '*' && !vis[x][y];
//}
//bool dfs(int x, int y,int step)
//{
//	if (!islegal(x, y))
//	{
//		return false;
//	}
//	if (maze[x][y] == 'T')
//	{
//		if (step < ans)
//		{
//			ans = step;
//		}
//		return  true;
//	}
//	vis[x][y] = 1;
//	maze[x][y] = 'm';
//	if (dfs(x - 1, y,step+1) || dfs(x, y - 1, step + 1) || dfs(x + 1, y, step + 1) || dfs(x, y + 1, step + 1))
//	{
//		return true;
//	}
//	vis[x][y] = 0;
//	maze[x][y] = '.';
//	return false;
//}
//
//int main()
//{
//	while (1)
//	{
//		cin >> n >> m;
//		for (int i = 0; i < n; i++)
//		{
//			cin >> maze[i];
//		}
//		int x = 0, y = 0;
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < m; j++)
//			{
//				if (maze[i][j] == 'S')
//				{
//					x = i;
//					y = j;
//				}
//			}
//		}
//		if (dfs(x, y,0))
//		{
//			cout << "++++++++++++++" << endl;
//			for (int i = 0; i < n; i++)
//			{
//				cout << maze[i] << endl;
//			}
//			cout << ans << endl;
//			cout << "++++++++++++++++++++" << endl;
//		}
//		else 
//		{
//			cout << "no!" << endl;
//		}
//	}
//}

















//找峡谷草丛个数

//
//char mp[105][105];
//bool vis[105][105];
//int n, m;
//
//
//
//void dfs(int x, int y)
//{
//	if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || mp[x][y] == '.')
//	{
//		return;
//	}
//	vis[x][y] = true;
//	dfs(x - 1, y);
//	dfs(x + 1, y);
//	dfs(x , y-1);
//	dfs(x , y+1);
//}
//int main()
//{
//	int cnt = 0;
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//	{
//		cin>>mp[i];
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (!vis[i][j] && mp[i][j] == '#')
//			{
//				dfs(i, j);
//				cnt++;
//			}
//		}
//	}
//	cout << cnt;
//}










//迷宫的出口数量
//int n, m,x,y,ans;
//char mp[15][15];
//bool vis[15][15];
//void dfs(int x, int y)
//{
//	if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || mp[x][y] == '#')
//	{
//		return;
//	}
//	if (mp[x][y] == 'e')
//	{
//		ans++;
//		return;
//	}
//	vis[x][y] = true;
//	dfs(x - 1, y);
//	dfs(x + 1, y);
//	dfs(x , y-1);
//	dfs(x , y+1);
//	vis[x][y] = false;
//}
//int main()
//{
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//	{
//	cin>> mp[i];
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (mp[i][j] == 'S')
//			{
//				x = i;
//				y = j;
//			}
//		}
//	}
//	dfs(x, y);
//	cout << ans;
//}






//求最大蛋糕数


//
//int n, m, cnt, ans;
//char mp[1005][1005];
//bool vis[1005][1005];
//void dfs(int x, int y)
//{
//	if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || mp[x][y] == '.')
//	{
//		return;
//	}
//	vis[x][y] = true;
//	cnt++;
//}
//
//
//
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cin >> mp[i][j];
//		}
//	}
//}