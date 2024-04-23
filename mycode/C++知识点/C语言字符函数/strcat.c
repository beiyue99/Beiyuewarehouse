#define _CRT_SECURE_NO_WARNINGS 1
//追加字符串到目标字符串后 返回目标字符串的首地址
//#include<stdio.h>
//char* my_strcat(char* str1, const char* str2)
//{
//	char* tmp = str1;
//	while (*str1)
//	{
//		str1++;
//	}
//	while (*str1++ = *str2++)  {}
//	return tmp;
//}
//int main()
//{
//	char str1[20] = "fafwaf";    //目标字符数组必须给定大小，不然发生错误
//	char str2[] = "fggg";
//	printf("%s", my_strcat(str1, str2));
//}




//#include<stdio.h>
//char* my_strncat(char* s1, const char* s2, int n) 
//{
//    char* s3 = s1;
//    while (*s1 != '\0')
//    {
//        ++s1;
//    }
//    while (n--)
//    {
//        *s1++ = *s2++;
//    }
//   
//    return s3;
//}
//void main()
//{
//    char ftr[100] = "ff";
//    char* dtr = "hello word";
//    printf("字符串受限连接后：%s\n", my_strncat(ftr, dtr, 8));
//}