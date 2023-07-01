//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
////与memcpy相比，它可以实现重叠拷贝
//void* my_memmove(void* des, const void* source, size_t n)
//{
//	void* ret = source;
//	if (des < source)
//	{
//		while (n--)
//		{
//			*(char*)des = *(char*)source;
//			des = (char*)des + 1;
//			source = (char*)source + 1;
//		}
//	}
//	else
//	{
//		while (n--)
//		{
//			*((char*)des + n) = *((char*)source + n);
//
//		}
//	}
//	return ret;
//}
//
//int main()
//{
//	int i = 0;
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	my_memmove(arr1, arr1 + 3, 20);
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d", arr1[i]);
//	}
//
//	return 0;
//}


