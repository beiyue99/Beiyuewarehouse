#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<sstream>








//int main()
//{
//	char a = 'a';
//	cout << char('a' + 1);   //字符的加减会转化为ASII码的加减   输出b
//}
//
//



//调用 cin.getline() 时，如果输入的数据中包含了换行符，这个换行符会被留在输入缓冲区中，
//从而影响后续的输入操作。因此，在调用 getline() 前需要使用 getchar() 来从输入缓冲区中读取并丢弃换行符
//char arr1[100], arr2[100];
//int len1, len2;
//int main()
//{
//	int n = 0;
//	cin >> n;
//	getchar();//除去缓冲区的换行符，防止被getline当做一行读入
//	for (int i = 0; i < n; i++)
//	{
//		cin.getline(arr1, sizeof(arr1));
//		len1 = strlen(arr1);
//		if (len1 > len2)
//		{
//			len2 = len1;
//			strcpy(arr2, arr1);
//		}
//	}
//	cout << arr2 << endl;
//}
//
//

