


fd = open("txt", O_WRONLY | O_CREAT, 0644);
如果没有该文件，就创建，并指明权限


fd = open("txt", O_WRONLY | O_APPEND);
以只写并且以追加的方式的方式打开文件，否则会覆盖原有内容







lseek函数 改变文件的偏移量
如果偏移的的字节超过了文件开头就出错返回，如果超过了文件末尾，再次写入会增大文件尺寸
off_t lseek(int fd, off_t offset, int whence);
whence的取值   SEEK_SET 从开头偏移     EEK_CUR从当前位置偏移        SEEK_END 从末尾偏移

9 int main()
10 {
	11     int fd = -1;
	12     fd = open("txt", O_RDWR);
	13     if (fd == -1)
		14     {
		15         perror("open");
		16         return 1;
		17     }
	18     write(fd, "ABCDEFG", 7);
	19     int ret = lseek(fd, 32, SEEK_SET);
	20     write(fd, "1234567890", 10);
	21     char buf[50];
	22     memset(buf, 0, 50);
	23     lseek(fd, 0, SEEK_SET);
	26     int a = read(fd, buf, 50);
	27     printf("%d\n", a);
	28     close(fd);
	29     return 0;
	30 }
先写入7个然后偏移32，使指针指向文件末尾, 增大了文件尺寸，即使又写入10字节，但指针仍指向末尾。
因此如果读取文件内容，则读取不到。
使用 lseek（fd, 0, SEEK_SET)使文件指针指向文件开头就行了
read : 42    read将字符0也读入，但是 % s遇到0就停止了，所以不会输出数字











stat函数：获取文件状态信息  当文件是一个符号链接时，lstat返回的是该符号链接本身的信息，而stat返回的是该链接指向的文件的信息。

int stat(const char* pathname, struct stat* buf);


1 #include<stdio.h>
2 #include<string.h>
3 #include<stdlib.h>
4 #include<sys/types.h>
5 #include<sys/stat.h>
6 #include<unistd.h>
7 int main()
8 {
	9     int ret = -1;
	10     struct stat s;
	11     ret = stat("txt", &s);
	17     printf("st_dev:%ld\n", s.st_dev);
	18     printf("st_nlink: %ld\n", s.st_nlink);
	19     printf("st_size: %ld\n", s.st_size);
	20     return 0;
	21 }







int show_file_type(struct stat* s)
9 {
10     switch (s->st_mode & S_IFMT)
//S_IFMT 是一个位掩码（bitmask），用于提取文件类型
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
38 int main(int argc, char** argv)
39 {
40     int ret = -1;
41     struct stat s;
42     if (2 != argc)
43     {
44         printf("usage: ./a.out filename\n");
45         return 1;
46     }
47     ret = stat(argv[1], &s);
48     if (ret == -1)
49     {
50         perror("stat");
51         return 1;
52     }
53     show_file_type(&s);
54     return 0;
55 }


. / a.out / dev / input / mouse1
输出内容：    该文件是字符设备


还有第二个版本用法，如下：

if (S_ISREG(s->st_mode))
{
	printf("该文件是普通文件");
}




getcwd(char* buf, size_t size)
//获取当前工作的目录,第一个参数是缓冲区，用来储存工作目录，第二个参数是缓冲区大小.失败返回NULL
chdir(const char* path)
//修改当前工作目录  失败返回-1   





opendir //打开目录，成功返回目录的结构体指针，失败返回NULL
dir = opendir("test");



closedir //关闭目录 ，返回0和-1
closedir(dir);




struct dirent* readdir(DIR * dir);
//成功返回目录结构体指针，失败返回NULL
7 int main()
8     {
9         DIR * dir = NULL;
10         struct dirent* d = NULL;
11         dir = opendir("test");
12         if (dir == NULL)
13         {
14             perror("opendir");
15             return 1;
16         }
17         printf("打开目录成功\n");
18         while (1)
19         {
20             d = readdir(dir);
21             if (d == NULL)
22             {
23                 break;    //readdir不要用perror
24             }
25             printf("d_type:%d d_name: %s\n", d->d_type, d->d_name);
26         }
28         closedir(dir);
29         return 0;
30     }




7 int main()
8     {
9         DIR * dir = NULL;
10         struct dirent* d = NULL;
11         dir = opendir("test");
12         if (dir == NULL)
13         {
14             perror("opendir");
15             return 1;
16         }
17         printf("打开目录成功\n");
18         while (1)
19         {
20             d = readdir(dir);
21             if (d == NULL)
22             {
23                 break;
24             }
25             if (d->d_type == DT_DIR)
26             {
27                 printf("is a directory! %s\n", d->d_name);
28             }
29             if (d->d_type == DT_BLK)
30             {
31                 printf("is a block devic! %s\n", d->d_name);
32             }
33             if (d->d_type == DT_CHR)
34             {
35                 printf("is a character device! %s\n", d->d_name);
36             }
37             if (d->d_type == DT_FIFO)
38             {
39                 printf("is a FIFO! %s\n", d->d_name);
40             }
41             if (d->d_type == DT_LNK)
42             {
43                 printf("is a symbolic link! %s\n", d->d_name);
44             }
45             if (d->d_type == DT_REG)
46             {
47                 printf("is a regular file! %s\n", d->d_name);
48             }
49             if (d->d_type == DT_SOCK)
50             {
51                 printf("is a UNIX domain socket! %s\n", d->d_name);
52             }
53             if (d->d_type == DT_UNKNOWN)
54             {
55                 printf("is unknown! %s\n", d->d_name);
56             }
57
58         }
