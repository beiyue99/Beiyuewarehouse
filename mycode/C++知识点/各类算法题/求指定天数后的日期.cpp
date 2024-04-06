#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<iomanip>
//int main()
//{
//	int y, m, d, k;
//	cin >> y >> m >> d >> k;
//	int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	for (int i = 0; i < k; i++)
//	{
//		if (y % 400 == 0 ||( y % 100 != 0 && y % 4 == 0))
//		{
//			arr[2] = 29;
//		}
//		else { arr[2] = 28; }
//		d++;
//		if (d > arr[m])
//		{
//			d = 1;
//			m++;
//		}
//		if (m > 12)
//		{
//			m = 1;
//			y++;
//		}
//	}
//	cout << setw(4) << y << "-" << setfill('0') << setw(2) << m << "-" << setfill('0') << setw(2) << d << endl;
//	printf("%04d-%02d-%02d", y, m, d);
//}