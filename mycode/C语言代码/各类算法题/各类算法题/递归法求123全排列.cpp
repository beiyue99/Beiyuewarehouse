#define _CRT_SECURE_NO_WARNINGS 1
//#include<vld.h>
#include<iostream>
using namespace std;

//void swap(char* a, char* b)
//{
//	char tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//void Permutation(char* p1, char* p2)  
//{
//		for (char* p3 = p2; *p3 != '\0'; p3++)
//		{
//			swap(*p3, *p2);
//			Permutation(p1, p2 + 1);
//			swap(*p3, *p2);             //1230   1230         打印123    打印132    回溯到123  打印 213  
//		}
//		if (*p2 == '\0')
//		{
//			cout << p1 << endl;
//		}
//}
//int main()
//{
//	char test[] = "123";
//	Permutation(test, test);
//}






//
//int n;  // 输出1~n的全排列
//const int maxn = 13;
//int P[maxn];
//bool hashTable[maxn] = { false }; // 此数记录是否含有此元素
//void generateP(int index)
//{
//	if (index == n+1 )
//	{
//		for (int i = 1; i <=n; i++)
//		{
//			cout << P[i] << "\t";
//		}
//		cout << endl;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		if (hashTable[i] == false)
//		{
//			P[index] = i;
//			hashTable[i] = true;
//			generateP(index + 1);
//			hashTable[i] = false;
//		}
//	}
//}
//int main()
//{
//	n = 3;
//	generateP(1);
//	return 0;
//}







//cout << fixed << setprecision(1) << height - temp << " " << h;     输出小数点后几位


//冒泡排序每轮都能将最大或者最小的元素沉底，所以后几轮不需要比较下标大的元素

//cin 遇到空格停止读取 ，而getline不会












