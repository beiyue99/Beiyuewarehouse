#include<stdio.h>
#include"head.h"
int main()
{
    int a=10;
    int b=2;
    printf("a+b=%d\n",add(a,b));
    printf("a-b=%d\n",sub(a,b));
    printf("a*b=%d\n",mul(a,b));
    printf("a/b=%f\n",div(a,b));
    return 0;
}