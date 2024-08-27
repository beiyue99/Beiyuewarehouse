//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//void* my_memset(void* arr, int v, size_t n)
//{
//	while (n--)
//	{
//		*(char*)arr = *(char*)v;
//		arr = (char*)arr + 1;
//
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,7,8,9,10 };
//	my_memset(arr, 1, 20);
//	//因为memset是对每个字节进行赋值的，已知一个int为4字节，
// 那么memset赋值时为二进制00000001000000010000000100000001 = 16843009，并不是单纯的1
//
//	for (int i = 0; i < 9; i++)
//	{
//		printf("%d  ", arr[i]);
//	}
//	return 0;
//}
//
//
//
//
