//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
// typedef  struct ln           //typedef �򻯴���
//{
//	double data;   int x;   int y;
//}ln;  //��typedef����lnΪ�ṹ��,�������ֱ��ʹ��ln
//int Mycmp2(const void* a, const void* b) 
//{ 
//	return ( ( (struct ln*)a)->data > ((struct ln*)b)->data ? 1 : -1); 
//}
//
//int main()
//{
//	ln s[2] = { { 9.33,4,6 }, {3.44,5,7 } };  //lnǰ�治�ü�struct
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
////����ں�����ִ�еĲ��ֳ�ʼ����Ҫ����strcpy��










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
//		// qsort�ıȽϺ�����Ĭ���Ƿ����������Ͱ����ҽ��������ظ������Ͳ�������������ǿ�����Ҫ��������� 
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
//	ITEM arr[10] = {{1, 5},{6, 4},{2, 8},{3, 1},{4, 1},{2, 9},{9, 5},{1, 4},{5, 6},{9, 4},   //qsort�ڶ��������ǲ�������Ԫ�ظ���
//};
//	qsort(arr, 10, sizeof(arr[0]), compare);
//	printf("weight\tmethod\n");
//	for (int i = 0; i < 10; i++) 
//	{
//		printf("%d\t%d\n", arr[i].weight, arr[i].method);
//	}
//	return 0;
//}



//��Ҫ���ַ������򣬺���ָ��ֻ��Ҫreturn strcmp������