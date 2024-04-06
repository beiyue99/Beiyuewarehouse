//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//int arr[100];
//int arr2[100];
//bool juge(int n)
//{
//	int i = 0;
//	while (n)
//	{
//		arr[i++] = n % 10;
//		n /= 10;
//	}
//	for (int j = 0; j < i / 2; j++)
//	{
//		if (arr[j] != arr[i - j - 1])
//		{
//			return false;
//		}
//	}
//	return true;
//}
//int reverse(int n)
//{
//	int temp = 0;
//	while (n)
//	{
//		temp = temp * 10 + n % 10;
//		n /= 10;
//	}
//	return temp;
//}
//int main()
//{
//	int n;
//	cin >> n;
//	int i = 0;
//	arr2[i] = n;
//	while (!juge(n))
//	{
//		n += reverse(n);
//		i++;
//		arr2[i] = n;
//	}
//	cout << i << endl;
//	for (int j = 0; j <= i; j++)
//	{
//		cout << arr2[j] << " ";
//	}
//}