#define _CRT_SECURE_NO_WARNINGS 1
//将字符串拷贝至目的字符串所在的地址,返回字符串首地址


//#include<stdio.h>
//char* my_strcpy(char* str1, char* str2)
//{
//	char* tmp = str1;
//	while (*str1++ = *str2++){}
//	return tmp;
//}
//int main()
//{
//	char str1[20] = "fwfafa";
//	char str2[] = "fff";
//	printf("%s",my_strcpy(str1, str2));
//}



//#include<stdio.h>
//char* my_strncpy(char* s1, const char* s2, int n)//字符串的长度受限拷贝
//{
//
//    char* str = s1;
//    while (n--)
//    {
//        *s1++ = *s2++;
//    }
//    return str;
//}
//int main()
//{
//    char arr1[20] = "fawfaw";
//    char arr2[] = "wps";
//    printf("%s", my_strncpy(arr1, arr2, 4));
//}