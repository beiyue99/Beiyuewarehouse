errno 在errno.h中定义，用来保存程序最后一次出错的错误码
   printf("fopen:%s\n",strerror(errno)); 解析错误码
    perror("fopen");  直接显示错误信息，此函数更为方便

ulimit -a    //显示系统资源
ulimit -n  2000  //修改打开最大文件数


open函数正常返回文件描述符，否则返回-1  
int open(const char* pathname,int flags,mode_t mode);
第一个参数是文件路径及文件名，第二个是对文件的行为标志 O_WRONLY  O_RDONLY  O_RDWR
mode这个参数只在文件不存在时有效，指新建文件的权限

  1 #include<stdio.h>
  2 #include<errno.h>
  3 #include<string.h>
  4 #include<sys/types.h>
  5 #include<sys/stat.h>
  6 #include<fcntl.h>
  7 #include<unistd.h>


  9 int main()
 10 {   
 11     int fd=-1;
 12     fd=open("txt",O_RDONLY);
 13     if(fd==-1)
 14     {   
 15         perror("open");
 16         return 1;
 17     }   
 18     close(fd);
 19     return 0;
 20 }
 21 
 

 





 fd=open("txt",O_WRONLY | O_CREAT,0644);
 如果没有该文件，就创建，并指明权限
 
 O_EXCL与O_CREAT同时使用   如果文件存在，则报错 
 fd=open("txt",O_WRONLY | O_CREAT | EXCL ,0644); 会报错说文件已经存在
 
 
 fd=open("txt",O_WRONLY | O_TRUNC | O_CREAT,0644);
 如果文件不存在就创建文件，如果文件存在就清空文件
 
 fd=open("txt",O_WRONLY | O_APPEND);
 以只写并且以追加的方式的方式打开文件
 
 
 
 
 write和read函数
 
  ret=write(fd,str,strlen(str));  //成功返回字节长度，失败返回-1
  ret=read(fd,buf,SIZE);  //读入buf，成功返回实际读到的字节长度




lseek函数 改变文件的偏移量
如果偏移的的字节超过了文件开头就出错返回，如果超过了文件末尾，再次写入会增大文件尺寸
off_t lseek(int fd,off_t offset,int whence);
whence的取值   SEEK_SET 从开头偏移     EEK_CUR从当前位置偏移        SEEK_END 从末尾偏移

write(fd,"ABCDEFG",7);
ret=lseek(fd,32,SEEK_SET); 
 write(fd,"1234567890",10);
 int a=read(fd,buf,SIZE);
先写入7个然后偏移32，使指针指向文件末尾,增大了文件尺寸，即使又写入10字节，但指针仍指向末尾。
因此如果读取文件内容，则读取不到。使用 lseek（fd,0,SEEK_SET)使文件指针指向文件开头就行了
read:42 ABCDEFGorld   read将字符0也读入，但是%s遇到0就停止了



stat函数：获取文件状态信息  当文件是一个符号链接时，lstat返回的是该符号链接本身的信息，而stat返回的是该链接指向的文件的信息。  
path：文件名   buf：保存文件信息的结构体     成功返回0失败返回-1
调用stat函数，将文件信息传入结构体
int stat(const char*path,struct stat *buf);



  1 #include<stdio.h>
  2 #include<string.h>
  3 #include<stdlib.h>
  4 #include<sys/types.h>
  5 #include<sys/stat.h>
  6 #include<unistd.h>
  7 int main()
  8 {   
  9     int ret=-1;
 10     struct stat s;
 11     ret=stat("txt",&s);
 12     if(ret==-1)
 13     {   
 14         perror("stat");
 15         return 1;
 16     }   
 17     printf("st_dev:%ld\n",s.st_dev);
 18     printf("st_nlink: %ld\n",s.st_nlink);
 19     printf("st_size: %ld\n",s.st_size);
 20     return 0;
 21 }   




:r !head -10 stat.c     //把stat.c前10行复制到当前文件  r代表读，！代表执行命令，不是强制，在写的时候才会有强制。









  8 int show_file_type(struct stat *s)
  9 {   
 10     switch(s->st_mode&S_IFMT)
 11     {   
 12         case S_IFREG:
 13             printf("该文件是普通文件\n");
 14             break;
 15         case S_IFDIR:
 16             printf("该文件是目录  \n");
 17             break;
 18         case S_IFCHR:
 19             printf("该文件是字符设备\n");
 20             break;
 21         case S_IFBLK:
 22             printf("该文件是块设备 \n");
 23             break;
 24         case S_IFSOCK:
 25             printf("该文件是套件子文件\n");
 26             break;
 27         case S_IFIFO:
 28             printf("该文件是管道  \n");
 29             break;
 30         case S_IFLNK:
 31             printf("该文件是符号链接n");
 32             break;
 33         default:
 34             printf("未知的文件类型\n");
 35     }
 36     return 0;
 37 }
 38 int main(int argc,char **argv)
 39 {   
 40     int ret=-1; 
 41     struct stat s;
 42     if(2!=argc)
 43     {
 44         printf("usage: ./a.out filename\n");
 45         return 1;
 46     }
 47     ret=stat(argv[1],&s);
 48     if(ret==-1)
 49     {
 50         perror("stat");
 51         return 1;
 52     }
 53     show_file_type(&s);
 54     return 0;
 55 }
 
 
 ./a.out  /dev/input/mouse1
输出内容：    该文件是字符设备


还有第二个版本用法，如下：

if(S_ISREG(s->st_mode))
{ 
     printf("该文件是普通文件");
}







 38 int show_permission(struct stat*s)
 39 {   
 40     if(s->st_mode&S_IRUSR)
 41     {
 42         printf("r");
 43     }
 44     else printf("-");
 45     if(s->st_mode&S_IWUSR)
 46     {
 47         printf("w");
 48     }
 49     else printf("-");
 50     if(s->st_mode&S_IXUSR)
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
 13     if(fd==-1)
 14     {   
 15         perror("open");
 16         return 1;
 17     }   
 18     printf("fd=%d\n",fd);
 19     newfd=dup(fd);
 20     if(newfd==-1)
 21     {   
 22         perror("dup");
 23         return 1;
 24     }   
 25     printf("newfd=%d\n",newfd);
 26     write(fd,"ABCDEFG",7);
 27     write(newfd,"1234567",7);
 28     close(fd);
 29     close(newfd);
 30 }





int dup2(int oldfd，int newfd) //如果newfd已经跟别的文件关联了，会先断裂关联，再使用







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
 12     int fd=-1;
 13     int ret=-1;
 14     int newfd=-1;
 15     fd=open("txt",O_WRONLY | O_CREAT,0644);
 16     if(fd==-1)
 17     {
 18         perror("open");
 19         return 1;
 20     }
 21     printf("fd=%d\n",fd);
 22     newfd=fcntl(fd,F_DUPFD,0);
 23     if(newfd==-1)
 24     {
 25         perror("fcntl");
 26         return 1;
 27     }
 28     printf("newfd=%d\n",newfd);
 29     write(fd,"123456789",9);
 30     write(newfd,"ABCDEFGH",8);
 31     close(fd);
 32     close(newfd);
 33 }


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




getcwd(char*buf,size_t size)
//获取当前工作的目录,第一个参数是缓冲区，用来储存工作目录，第二个参数是缓冲区大小.失败返回NULL
chdir(const char*path)  
//修改当前工作目录  失败返回-1   

  5 #define SIZE 32
  6 int main()
  7 {   
  8     int ret=-1;
  9     char buf[SIZE]={0};
 10     if(getcwd(buf,SIZE)==NULL)
 11     {   
 12         perror("getcwd");
 13         return 1;
 14     }   
 15     printf("buf: %s\n",buf);
 16     ret=chdir("/home/wjf/dir1/xxxxxx");
 17     if(ret==-1)
 18     {   
 19         perror("chdir");
 20         return 1;
 21     }   
 22     memset(buf,0,SIZE);
 23     if(getcwd(buf,SIZE)==NULL)
 24     {   
 25         perror("getcwd");
 26         return 1;
 27     }   
 28     printf("buf %s\n",buf);
 29     return 0;
 30 }





opendir //打开目录，成功返回目录的结构体指针，失败返回NULL
dir =opendir("test");

closedir //关闭目录 ，返回0和-1
closedir(dir);









struct dirent* readdir(DIR*dir);
//成功返回目录结构体指针，失败返回NULL
  7 int main()
  8     {
  9         DIR*dir=NULL;
 10         struct dirent *d=NULL;
 11         dir =opendir("test");
 12         if(dir==NULL)
 13         {
 14             perror("opendir");
 15             return 1;
 16         }
 17         printf("打开目录成功\n");
 18         while(1)
 19         {
 20             d=readdir(dir);
 21             if(d==NULL)
 22             {
 23                 break;    //readdir不要用perror
 24             }
 25             printf("d_type:%d d_name: %s\n",d->d_type,d->d_name);
 26         }
 27 
 28         closedir(dir);
 29         return 0;
 30     }










  7 int main()
  8     {
  9         DIR*dir=NULL;
 10         struct dirent *d=NULL;
 11         dir =opendir("test");
 12         if(dir==NULL)
 13         {
 14             perror("opendir");
 15             return 1;
 16         }
 17         printf("打开目录成功\n");
 18         while(1)
 19         {
 20             d=readdir(dir);
 21             if(d==NULL)
 22             {
 23                 break;
 24             }
 25             if(d->d_type==DT_DIR)
 26             {
 27                 printf("is a directory! %s\n",d->d_name);
 28             }
 29             if(d->d_type==DT_BLK)
 30             {
 31                 printf("is a block devic! %s\n",d->d_name);
 32             }
 33             if(d->d_type==DT_CHR)
 34             {
 35                 printf("is a character device! %s\n",d->d_name);
 36             }
 37             if(d->d_type==DT_FIFO)
 38             {
 39                 printf("is a FIFO! %s\n",d->d_name);
 40             }
 41             if(d->d_type==DT_LNK)
 42             {
 43                 printf("is a symbolic link! %s\n",d->d_name);
 44             }
 45             if(d->d_type==DT_REG)
 46             {
 47                 printf("is a regular file! %s\n",d->d_name);
 48             }
 49             if(d->d_type==DT_SOCK)
 50             {
 51                 printf("is a UNIX domain socket! %s\n",d->d_name);
 52             }
 53             if(d->d_type==DT_UNKNOWN)
 54             {
 55                 printf("is unknown! %s\n",d->d_name);
 56             }
 57 
 58         }




















 
 
 