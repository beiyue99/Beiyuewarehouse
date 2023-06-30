//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//int cmp_double(const void* a, const void* b)
//{
//	return (*(double*)a > *(double*)b ? 1 : -1);
//}
//
////在对浮点或者double型的⼀定要⽤三⽬运算符，因为要是使⽤像整型那样相减的话，如果是两个很接近的数则可能返回⼀个很⼩的⼩数（⼤于 - 1，⼩于1），
////⽽cmp的返回值是int型，因此会将这个⼩数返回0，系统认为是相等，失去了本来存在的⼤⼩关系
//
//int main()
//{
//	double num[4] = { 5.2,1.6,7.4,2.5};
//
//	qsort(num, 4, sizeof(num[0]), cmp_double);
//	for (int i = 0; i < 4; i++)
//	{
//		printf("%lf   ", num[i]);
//	}
//}