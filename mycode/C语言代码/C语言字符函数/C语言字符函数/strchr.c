#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//char* my_strchr(char* s1, char c)// �����ַ������״γ����ַ�c��λ�ã��ҵ�����ָ�룬�Ҳ�������NULL 
//{
//   
//    for ( ;*s1 != c; ++s1)
//    {
//        if (*s1 == '\0')
//        {
//            return NULL;
//        }
//    }
//    return s1;
//}
//int main()
//{
//    char arr[10] = "gaefaga";
//    printf("%s", my_strchr(arr,'e'));
//}




//#include<stdio.h>
//char* my_strrchr(char* si, char c)//�����ַ��������һ�δγ����ַ�c��λ�ã��ҵ�����ָ�룬�Ҳ�������NULL 
//{
//    char* p = NULL;
//    while (*si != '\0')
//    {
//        if (*si ==  c)
//        {
//            p =  si;
//        }
//        si++;
//    }
//    return p;
//}
//int main()
//{
//    char arr[10] = "gaefagea";
//    printf("%s", my_strrchr(arr,'e'));
//}





//char* my_strnchr(const char* di, char c, int n)//�ַ������Ҹ����ַ����� n �γ��ֵ�λ��
//{
//   
//    int count = 0;
//    for (; *di != '\0'; di++)
//    {
//        if (*di == c)
//        {
//            count += 1;
//        }
//        if (count == n)
//        {
//            return di;
//        }
//    }
//    return NULL;
//}
//int main()
//{
//    char arr[10] = "gaefaega";
//    printf("%s", my_strnchr(arr,'e',2));
//}
