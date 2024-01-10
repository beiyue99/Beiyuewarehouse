



 

38 int show_permission(struct stat* s)
39 {
    40     if (s->st_mode & S_IRUSR)
        41     {
        42         printf("r");
        43     }
    44     else printf("-");
    45     if (s->st_mode & S_IWUSR)
        46     {
        47         printf("w");
        48     }
    49     else printf("-");
    50     if (s->st_mode & S_IXUSR)
        51     {
        52         printf("x");
        53     }
    54     else printf("-");
    55     return 0;
    56 }
//获得所属者的权限
S_IR后面是USR GRP OTH分别代表所属者、所属组、其他




 












int dup(int oldfd):通过oldfd复制出一个新的文件描述符，与oldfd指向同一个文件。失败返回-1


  1 #include<stdio.h>
  2 #include<string.h>
  3 #include<stdlib.h>
  4 #include<sys/types.h>
  5 #include<sys/stat.h>
  6 #include<fcntl.h>
  7 #include<unistd.h>
  8 int main()
  9 {   
 10     int fd=-1;
 11     int newfd=-1;
 12     fd=open("txt",O_RDWR | O_CREAT,0644);
 18     printf("fd=%d\n",fd);
 19     newfd=dup(fd);
 25     printf("newfd=%d\n",newfd);
 26     write(fd,"ABCDEFG",7);
 27     write(newfd,"1234567",7);
 28     close(fd);
 29     close(newfd);
 30 }







fcntl的5种功能:
1.复制一个现有的文件描述符（F_DUPFD)  返回一个大于或等于第三个参数的最小可用数字
2.获得/设置文件操作符标记(F_GETFD/F_SETFD)
3.获得/设置文件状态标记(F_GETFL/F_SETFL)
4.获得/设置异步io所有权(F_GETOWN/F_SETOWN)
5.获得/设置记录锁(F_GETLK/F_SETLK)

ret=fcntl(fd,F_GETFL);   返回文件状态标记，第三个参数不需要，如果写了也会被忽略
if(ret&O_APPEND)  //如果为真，printf之前就已经有追加了，否则之前没有
ret=ret | O_APPEND;  //设置ret，带有追加标记
ret=fcnlt(fd,F_SETFL,ret); //给文件添加标记


2 #include<stdio.h>
3 #include<string.h>
4 #include<stdlib.h>
5 #include<sys/types.h>
6 #include<sys/stat.h>
7 #include<fcntl.h>
8 #include<unistd.h>
9
10 int main()
11 {
	12     int fd = -1;
	13     int ret = -1;
	14     int newfd = -1;
	15     fd = open("txt", O_WRONLY | O_CREAT, 0644);
	21     printf("fd=%d\n", fd);
	22     newfd = fcntl(fd, F_DUPFD, 0);
	28     printf("newfd=%d\n", newfd);
	29     write(fd, "123456789", 9);
	30     write(newfd, "ABCDEFGH", 8);
	31     close(fd);
	32     close(newfd);
	33 }
































 
 
 