#define _CRT_SECURE_NO_WARNINGS 1
//׷���ַ�����Ŀ���ַ����� ����Ŀ���ַ������׵�ַ
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
//	char str1[20] = "fafwaf";    //Ŀ���ַ�������������С����Ȼ��������
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
//    printf("�ַ����������Ӻ�%s\n", my_strncat(ftr, dtr, 8));
//}