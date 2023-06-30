//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
// typedef  struct ln           //typedef 简化代码
//{
//	double data;   int x;   int y;
//}ln;  //用typedef声明ln为结构体,后面可以直接使用ln
//int Mycmp2(const void* a, const void* b) 
//{ 
//	return ( ( (struct ln*)a)->data > ((struct ln*)b)->data ? 1 : -1); 
//}
//
//int main()
//{
//	ln s[2] = { { 9.33,4,6 }, {3.44,5,7 } };  //ln前面不用加struct
//	qsort(s, 2, sizeof(s[0]), Mycmp2);
//	for (int i = 0; i < 2; i++)
//	{
//		printf("%lf ", s[i].data);
//	}
//	return 0;
//}



////struct student {
////} FF[n] = { {"***", "***"} , {"***", "****"} };
////
////如果在函数体执行的部分初始化就要挨个strcpy了










//
//
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct
//{
//	int weight;
//	int method;
//}ITEM;
//int compare(const void* a, const void* b)
//{
//	ITEM* ia = (ITEM*)a;
//	ITEM* ib = (ITEM*)b;
//	if (ia->method < ib->method || (ia->method == ib->method && ia->weight > ib->weight))
//	{
//		// qsort的比较函数，默认是返回正数，就把左右交换，返回负数，就不交换，因此我们考虑需要交换的情况 
//		return 1;
//	}
//	else 
//	{
//		return -1;
//	}
//}
//
//int main() 
//{
//	ITEM arr[10] = {{1, 5},{6, 4},{2, 8},{3, 1},{4, 1},{2, 9},{9, 5},{1, 4},{5, 6},{9, 4},   //qsort第二个参数是参与排序元素个数
//};
//	qsort(arr, 10, sizeof(arr[0]), compare);
//	printf("weight\tmethod\n");
//	for (int i = 0; i < 10; i++) 
//	{
//		printf("%d\t%d\n", arr[i].weight, arr[i].method);
//	}
//	return 0;
//}



//若要对字符串排序，函数指针只需要return strcmp（）。