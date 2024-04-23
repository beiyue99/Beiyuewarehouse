#define _CRT_SECURE_NO_WARNINGS 1
// 在目标字符串中寻找子字符串，返回目标字符串中，与子字符串相同的字符串首地址

//#include<stdio.h>
//char* my_strstr(const char* str1, const char* str2)
//{
//	char*s1 = str1;
//	char*s2 = str2;
//	char*s3= str1;
//	if (str2 == '\0')
//	{
//		return str1;
//	}
//	while (*s3)
//	{
//		s1 = s3;
//		s2 = str2;
//		while (*s1 && *s2 && *s1 == *s2)
//		{
//			s1++;    s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return s3;
//		}
//			s3++;
//	}
//		return NULL;
//}
//int main()
//{
//	char arr1[] = "abbbbcdef";
//	char arr2[] = "bbx";
//	printf("%s", my_strstr(arr1, arr2));
//	return 0;
//}