//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//void* my_memcpy(void* arr2, const void* arr1, size_t n)
//{
//
//	void* ret = arr2;
//	while (n--)
//	{
//		/**(char*)arr2 = *(char*)arr1;
//		arr1 =  (char*)arr1 + 1;
//		arr2 = (char*)arr2 + 1;*/
//		
//					
//		*((char*)arr2 + n) = *((char*)arr1 + n);
//			
//		/*2.内存重叠处理措施：
//
//			（1）当源内存的首地址大于目标内存的首地址时，实行正向拷贝；
//			（2）当源内存的首地址小于目标内存的首地址时，实行反向拷贝 。*/
//	}
//	return ret;
//}
//
//
//
//
//
//int main()
//{
//	int i = 0;
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	my_memcpy(arr1+3, arr1 , 20);
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d", arr1[i]);
//	}
//
//	return 0;
//}
//



