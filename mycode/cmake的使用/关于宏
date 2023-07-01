




在进行程序测试的时候,我们可以在代码中添加一些宏定义,
通过这些宏来控制这些代码是否生效,如下所示:

#include <stdio.h>
#define NUMBER 3
int main()
{
  int a 10;
#ifdef DEBUG
  printf("我是一个程猿,我不会爬树..\n"):
#endif
  for(int i=0;i<NUMBER;++i)
    printf("hello,GCC!!!\n");
  return 0;
}


为了让测试更灵活,我们可以不在代码中定义这个宏,而是在测试的时候去把它定义出来,
其中一种方式就是在gcc/g++命令中去指定,如下:
gcc test.c -DDEBUG -o app

在Cmake中我们也可以做类似的事情,对应的命令叫做add_definitions:

add_definitions(-D宏名称)  #在cmake文件写入宏名称，就相当于宏被构建了
