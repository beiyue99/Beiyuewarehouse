 

无名管道数据只能在同一个方向流动，
数据只能从管道的一端写入，从另一端读出
它没有名字，只能在具有公共祖先的进程（父子，兄弟）之间使用
函数原型： int pipe(int pipefd[2])
功能：创建无名管道

  6 int main()
  7 {   
  8     int fds[2];
  9     int ret=-1;
 10     ret=pipe(fds);
 11     if(ret==-1)
 12     {   
 13         perror("pipe");
 14         return 1;
 15     }   
 16     //fd[0]用于读，1用于写
 17     printf("fd[0]:%d,fd[1]:%d\n",fds[0],fds[1]);
 18     close(fds[0]);
 19     close(fds[1]);
 20     return 0;
 21 }   
创建无名管道，返回3和4   （012）被占用





int main()
  7 {
  8     int fds[2];
  9     int ret=-1;
 10     int pid=-1;
 11     char buf[SIZE]={0};
 12     ret=pipe(fds);
 13     if(ret==-1)
 14     {   
 15         perror("pipe");
 16         return 1;
 17     }
 18     pid=fork();
 19     if(-1==pid)
 20     {   
 21         perror("fork");
 22         return 1; 
 23     }
 24     if(pid==0)
 25     {   
 26         //子进程，关闭写端
 27         close(fds[1]);
 28         ret=read(fds[0],buf,SIZE);
 29         if(ret<0)
 30         {   
 31             perror("read");
 32             exit(-1);
 33         }
 34         printf("child pross  buf:%s \n",buf);
 35         
 36         //关闭读端
 37         close(fds[0]);
 38         exit(0);
 39     }
 40     //父进程，写管道
 41     //关闭读端
 42     close(fds[0]);
 43     ret=write(fds[1],"ABCDEFGHIJK",10);
 44     if(ret<0)
 45     {
 46         perror("write");
 47         return 1;
 48     }   
 49     printf("hello parent process write len: %d\n",ret);
 50     
 51     //关闭写端
 52     close(fds[1]);
 53     return 0;
 56 }
//父进程写，子进程读
//无名管道用于有共同祖先的进程





查看管道缓冲区的函数： long fpathconf(int fd,int name);
可以通过name参数查看不同的属性值。 fd:文件描述符
name: _PC_PIPE_BUF 查看缓冲区大小       _PC_NAME_MAX 查看文件名字字节数上限
返回值：  根据name返回的值意义不同    失败返回-1





设置为非阻塞：
//获取原来的flags
int flags=fcntl(fd[0],F_GETFL);
//设置新的flags
flag=O_NONBLOCK;   //flags=flags | O_NONBLOCK;
fcntl(fd[0],F_SETFL,flags);

//如果写端没有关闭，读端为非阻塞，如果没有数据，直接返回-1







  7 int main()
  8 {   
  9     int fds[2];
 10     int ret=-1;
 11     int pid=-1;
 12     char buf[SIZE]={0};
 13     ret=pipe(fds);
 14     if(ret==-1)
 15     {   
 16         perror("pipe");
 17         return 1;
 18     }
 19     pid=fork();
 20     if(-1==pid)
 21     {   
 22         perror("fork");
 23         return 1;
 24     }
 25     if(pid==0)
 26     {   
 27         //子进程，关闭写端
 28         close(fds[1]);
 29         printf("读取管道的内容\n");
 30         ret=fcntl(fds[0],F_GETFL);
 31         ret|=O_NONBLOCK;
 32         fcntl(fds[0],F_SETFL,ret); //设置读端为非阻
 33         ret=read(fds[0],buf,SIZE);
 34         if(ret<0)
 35         {   
 36             perror("read");
 37             exit(-1);
 38         }
 39         printf("child pross  buf:%s \n",buf);
 40         
 41         //关闭读端
 42         close(fds[0]);
 43         exit(0);
 44     }
 45     //父进程，写管道
 46     //关闭读端
 47     close(fds[0]);
 48     sleep(1);
 49     ret=write(fds[1],"ABCDEFGHIJK",10);
 50     if(ret<0)
 51     {
 52         perror("write");
 53         return 1;
 54     }
 55     printf("hello parent process write len: %d\n",ret);
 56 
 57     //关闭写端
 58     close(fds[1]);
 59     return 0;
 62 }


//设置为非阻塞直接返回



   //无名管道：
     //读的时候
      1 写端没有关闭:
        没有数据的时候去读会被阻塞，有数据的时候就可以读出
      2 写端关闭
        会读取全部内容，然后返回0
      //写的时候
      3：
      管道被写满了，写管道进程写的时候会发生阻塞
      4：
      所有的读端关闭，写管道进程写管道会收到一个信号然后退出。 （写的时候，读端必须开口）







      //有名管道注意事项：
      一个只读而打开的管道进程会阻塞，直到另一个进程为只写打开该管道
      一个只写而打开的管道进程会阻塞，直到另一个进程为只读打开该管道


//有名管道的创建：
int mkfifo(const char* pathname,mode_t mode);
//第一个参数代表创建的管道名字，第二个参数代表文件权限（0666）






  8 int main()
  9 {
 10     int fd=-1;
 11     int ret=-1;
 12     char buf[SIZE]={0};
 13     int i=0;
 14     //以只写的方式打开一个管道文件
 15     fd=open("fifoooo",O_WRONLY);
 16     if(fd==-1)
 17     {
 18         perror("open");
 19         return 1;
 20     }
 21     printf("以只写的方式打开一个管道...\n");
 22 
 23     //写管道
 24     while(1)
 25     {   
 26         sprintf(buf,"hello world %d",i++);
 27         ret=write(fd,buf,strlen(buf));
 28         if(ret<=0)
 29         { 
 30             perror("write");
 31             break;
 32         } 
 33         printf("write info:%d\n",ret);   //写入的字节数
 34         sleep(1); 
 35     } 
 36     //关闭文件
 37     close(fd); 
 38     return 0; 
 39 } 

//.............................................

 10 int main()
 11 {
 12     int fd=-1;
 13     int ret=-1;
 14     char buf[SIZE]={0};
 15     //以只读的方式打开一个管道文件
 16     fd=open("fifoooo",O_RDONLY);
 17     if(fd==-1)
 18     {
 19         perror("open");
 20         return 1;
 21     }
 22     printf("以只读的方式打开一个管道....\n");
 23     //循环读管道
 24     while(1)
 25     {
 26         ret=read(fd,buf,SIZE);
 27         if(ret<=0)
 28         {
 29             perror("read");
 30             break;
 31         }
 32         printf("buf:%s\n",buf);
 33     }
 34     //关闭文件
 35     close(fd);
 36     return 0;
 37 }















    : read !head - n 10 test.c




//通过管道实现双方交互对话
1.写管道2，以至于对方可以读到管道2的内容，同时可读取对方写入管道1的内容
 10 int main()
 11 {
 12     int ret=-1;
 13     char buf[SIZE]={0};
 14     int fdr=-1;
 15     int fdw=-1;
 16     fdr=open("fifo1",O_RDONLY);
 17     if(fdr==-1)
 18     {
 19         perror("open");
 20         return 1;
 21     }
 22     printf("以只读的方式打开管道1...\n");
 23     fdw=open("fifo2",O_WRONLY);
 24     if(fdw==-1)
 25     {
 26         perror("open");
 27         return 1;
 28     }
 29     printf("以只写的方式打开管道2\n");
 30     //循环读写
 31     while(1)
 32     {
 33         //读管道1
 34         ret=read(fdr,buf,SIZE);
 35         if(ret<=0)
 36         {
 37             perror("read");
 38             break;
 39         }
 40         printf("read pip1: %s\n",buf);
 41         //写管道2
 42         fgets(buf,SIZE,stdin);
 43         if('\n'==buf[strlen(buf)-1])
 44         {
 45             buf[strlen(buf)-1]='\0';
 46         }
 47         ret=write(fdw,buf,strlen(buf));
 48         if(ret<=0)
 49         {
 50             perror("write");
 51             break;
 52         }
 53         printf("write pip2:%d\n",ret);
 54     }
 55     close(fdr);
 56     close(fdw);
 57     return 0;
 58 }




//读2写1

10 int main()
 11 {
 12     int ret=-1;
 13     char buf[SIZE]={0};
 14     int fdr=-1;
 15     int fdw=-1;
 16     fdw=open("fifo1",O_WRONLY);
 17     if(fdw==-1)
 18     {
 19         perror("open");
 20         return 1;
 21     }
 22     printf("以只写的方式打开管道1\n");
 23     fdr=open("fifo2",O_RDONLY);
 24     if(fdr==-1)
 25     {
 26         perror("open");
 27         return 1;
 28     }
 29     printf("以只读的方式打开管道2...\n");
 30     //循环读写
 31     while(1)
 32     {
 33         //写管道1
 34         fgets(buf,SIZE,stdin);
 35         if('\n'==buf[strlen(buf)-1])
 36         {
 37             buf[strlen(buf)-1]='\0';
 38         }
 39         ret=write(fdw,buf,strlen(buf));
 40         if(ret<=0)
 41         {
 42             perror("read");
 43             break;
 44         }
 45         printf("write pip2:%d\n",ret);
 46         //读管道2
 47         ret=read(fdr,buf,SIZE);
 48         printf("read: %s\n",buf);
 49         if(ret<=0)
 50         {
 51             perror("write");
 52             break;
 53         }
 54     }
 55     close(fdr);
 56     close(fdw);
 57     return 0;
 58 }







//储存映射函数的使用：
#inlcude<sys/mman.h>
void *mmap(void *addr,size_t length,int prot,int flags,int fd,off_t offset);
//功能： 将一个文件或者对象映射进内存
//参数： 
addr:  指定映射的起始地址。通常为NULL
length: 映射到内存的文件长度
prot: 映射区的保护方式，其中常用的：
       1.读： PROT_READ 
       2.写： PROT_WRITE
       3.读写： PROT_READ | PROT_WROTE
flags: 映射区的特性，一般是：
       1. MAP_SHARED：写入映射区的数据会复制回文件，且允许其它映射该文件的进程共享
       2. MAP_PEIVATE：会产生一个映射区的复制，对此映射区所做的修改不会写会原文件

fd: 所要映射的文件的文件描述符
offset: 文件开始处的偏移量，必须是4k的整数倍，通常为0，表示从头开始映射
返回值： 成功返回映射区首地址，失败返回MAP_FAILED宏



解除关联用 munmap函数  int munmap(void *addr,size_t length);
功能： 释放内存映射区
addr: 使用mmap函数创建的内存映射区的首地址
length: 映射区的大小  
成功返回0   失败返回-1







 10 int main()
 11 {   
 12     int fd=-1;
 13     int ret=-1;
 14     void *addr=NULL;
 15     //已读写的方式打开一个文件
 16     fd=open("txt",O_RDWR);
 17     if(fd==-1)
 18     {   
 19         perror("open");
 20         return 1;
 21     }   
 22     //将文件映射到内存
 23     addr=mmap(NULL,1024,PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);
 24     if(addr==MAP_FAILED)
 25     {   
 26         perror("mmap");
 27         return 1;
 28     }   
 29     printf("文件储存映射ok...\n");
 30     //关闭文件
 31     close(fd);
 32     //写入映射区
 33     memcpy(addr,"1234567890",10);
 34     munmap(addr,1024);
 35     return 0;
 36 } 

//将txt原来的前10个字节覆盖

注意事项：
1.创建映射区的过程中，隐含着一次对映射文件的读操作
2.当MAP_SHARED时，映射区的权限必须小于原文件的权限
3.映射区的释放与文件关闭无关。只要映射建立成功，文件可以立即关闭
4.映射文件大小不能为0
5.创建映射区出错概率高，最好检查返回值

    


//父子进程通过储存映射实现进程通讯
1 #include<sys/wait.h>
2 #include<stdio.h>
3 #include<string.h>
4 #include<sys/types.h>
5 #include<sys/stat.h>
6 #include<sys/mman.h>
7 #include<stdlib.h>
8 #include<fcntl.h>
9 #include<unistd.h>
10
 int main()
 {
     int fd = -1;
     int ret = -1;
     pid_t pid = -1;
     void* addr = NULL;
     //已读写的方式打开一个文件
     fd = open("txt", O_RDWR);
     if (fd == -1)
     {
         perror("open");
         return 1;
     }
     //将文件映射到内存
     addr = mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
     if (addr == MAP_FAILED)
     {
         perror("mmap");
         return 1;
     }
     printf("文件储存映射ok...\n");
     //关闭文件
     close(fd);
     //创建一个子进程
     pid = fork();
     if (pid == -1)
     {
         perror("fork");
         return 1;
     }
     if (pid == 0)
     {
         memcpy(addr, "1234567890", 10);
     }
     else
     {
         wait(NULL);   //阻止父程进程，直到其任何孩子都完成为止
         printf("addr:%s\n", (char*)addr);
     }
     munmap(addr, 1024);
     return 0;
 }








//非父子进程之间利用储存映射进行通讯


//读进程
11 int main()
12 {
13     int fd = -1;
14     int ret = -1;
15     pid_t pid = -1;
16     void* addr = NULL;
17     //以读写的方式打开一个文件
18     fd = open("txt", O_RDWR);
19     if (fd == -1)
20     {
21         perror("open");
22         return 1;
23     }
24     //将文件映射到内存
25     addr = mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
26     if (addr == MAP_FAILED)
27     {
28         perror("mmap");
29         return 1;
30     }
31     printf("文件储存映射ok...\n");
32     //关闭文件
33     close(fd);
34     //读存储映射区
35     printf("addr,%s\n", (char*)addr);
36     munmap(addr, 1024);
37     return 0;
38 }




//写进程
11 int main()
12 {
13     int fd = -1;
14     int ret = -1;
15     pid_t pid = -1;
16     void* addr = NULL;
17     //已读写的方式打开一个文件
18     fd = open("txt", O_RDWR);
19     if (fd == -1)
20     {
21         perror("open");
22         return 1;
23     }
24     //将文件映射到内存
25     addr = mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
26     if (addr == MAP_FAILED)
27     {
28         perror("mmap");
29         return 1;
30     }
31     printf("文件储存映射ok...\n");
32     //关闭文件
33     close(fd);
34     //写存储映射区
35     memcpy(addr, "1234567890", 10);
36     munmap(addr, 1024);
37     return 0;
38 }









//使用匿名映射实现父子间进程通信

 
13 int main()
14 {
15     int ret = -1;
16     pid_t pid = -1;
17     void* addr = NULL;
18     //1.创建匿名映射
19     addr = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
20     if (MAP_FAILED == addr)
21     {
22         perror("mmap");
23         return 1;
24     }
25     //2.创建子进程
26     pid = fork();
27     if (pid == -1)
28     {
29         perror("fork");
30         munmap(addr, 4096);
31         return 1;
32     }
33     //3.父子间通信
34     if (pid == 0)
35     {
36         //子进程写
37         memcpy(addr, "1234567890", 10);
38     }
39     else
40     {
41         //父进程读
42         wait(NULL);
43         printf("parent process %s\n", (char*)addr);
44     }
45     //4.断开映射
46     munmap(addr, 4096);
47     return 0;
48 }








//信号

kill - l 查看不同的信号及其编号


信号产生函数：
int kill(pid_t pid, int sig);        给指定进程发送指定信号

pid有四种情况：
pid>0: 将信号传给进程为pid的进程           pid=0：将信号传递给当前进程所在进程组中的所有进程
pid=-1：将信号传送给系统内所有的进程       pid<-1：将信号传给指定进程组中的所有进程，这个进程组等于pid的绝对值
sig: 信号的编号，这里可以填数字或者编号，也可以填信号的宏定义，最好使用宏名，因为兼容性大
成功返回0，失败返回-1







  7 //父进程杀死子进程
  8 int main()
  9 {   
 10     pid_t pid=-1;
 11     pid=fork();
 12     if(-1==pid)
 13     {   
 14         perror("fork");
 15         return 1;
 16     }
 17     if(pid==0)
 18     {   
 19         while(1)
 20         {   
 21             printf("child process do work...\n");
 22             sleep(1);
 23         }
 24         exit(0);
 25     }
 26     else
 27     {   
 28         //父进程
 29         sleep(3);
 30         printf("准备在父进程内杀死子进程\n");
 31         kill(pid,15);
 32         printf("子进程已死亡\n");
 33     }
 34     return 0;
 35 }





//raise函数  给自己当前进程发送信号。等价于kill(getpid(),sig)
int raise(int sig);     成功返回0，失败返回一个非零值


int mian()
{
    int i=1;
    while(1)
    {
       printf("do working %d\n",i);
       if(i==4)
       {
          //给自己发送编号为15的信号,默认行为是终止进程
          raise(SIGTERM);
       }
       i++;
       sleep(1);
     }
     return 0;
 }
 
 
 void abort(void);
 给自己发送异常终止信号6（SIGABRT），并产生core文件，等价于kill（getpid(),SIGABRT);
 
 
 
 
 
 
 
 
 //alarm函数
 int alarm(int seconds);
 设置闹钟，在指定second之后，内核会给当前进程发送14（SIGALRM)的信号，进程收到该信号默认动作终止，一个进程只有唯一的一个定时器。
 alarm(0): 取消闹钟定时器，返回余下的秒数
 
 
 
 
   8 int main()
  9 {   
 10     unsigned int ret=0;
 11     //设置闹钟，5秒钟之后就超时，发送对应的信号
 12     ret=alarm(5);
 13     printf("上一次闹钟剩下的秒数：%u\n",ret);
 14     sleep(2);
 15     //旧闹钟被新闹钟覆盖
 16     ret=alarm(4);
 17     printf("上一次闹钟剩下的时间是：%u\n",ret);   返回3
 18     printf("按下任意键继续...\n");
 19     getchar();
 20     return 0;
 21 }

 
 
 





 setitimer函数  int setitimer(int which, const struct itimerval* new_value, struct itimerval* old_value);
 功能：设置闹钟定时器，可代替alarm函数，精度微秒us，可以实现周期定时
 which:指定定时方式：
     1.自然定时：ITIMER_REAL->14)SIGALRM计算自然时间
     2.虚拟空间计时（用户空间）:ITIMER_VIRTUAL->26)SIGVTALRM 只计算进程占用cpu时间
     3.运行时计时（用户+内核）:ITIMER_PROF->27)SIGPROF计算占用cpu以及执行系统调用的时间
 new_value: struct itimerval,负责设定timeout时间
 struct itimerval
 {
     struct timerval it_interval; //闹钟触发周期     设定以后每几秒执行
     struct timerval it_value;    //闹钟触发时间     设定第一次执行后所延迟的秒数
 };
 struct timeval
 {
     long tv_sec;  //秒
     long tv_usec  //微秒
 };
 old_value：存放旧的timeout值，一般为NULL;
 返回值：成功返回0失败返回-1
 


 
 定时器一旦触发，闹钟超时会向内核发送一个信号，该信号默认动作是终止进程。所以计时器只会触发一次
     //可以通过信号捕捉函数，使该函数失效

 
 
 
 int main()
 {
     int ret = -1;
     struct itimerval tmo = { 0 };
     //第一次触发时间
     tmo.it_value.tv_sec = 3;
     tmo.it_value.tv_usec = 0;
     //触发周期
     tmo.it_interval.tv_sec = 2;
     tmo.it_interval.tv_usec = 0;
     //设置定时器
     ret = setitimer(ITIMER_REAL, (const struct itimerval*)&tmo, NULL);

     if (ret == -1)
     {
         perror("setitimer");
         return 1;
     }
     printf("按下任意键继续\n");
     getchar();
     return 0;
 }







 //signal函数 
 // 注册信号处理函数，不可用于（SIGKILL,SIGSTOP 信号），即确定收到信号后处理函数的入口地址。此函数不会被阻塞
 //sighandler_t  是一个函数指针，返回值为void,参数类型为int

 sighandler_t signal(int signum, sighandler_t handler);

signum:信号的编号，这里可以填数字，也可以填宏，可以通过命令kill-l查看
handler: 有三种取值
1.SIG_IGN: 忽略该信号
2.SIG_DFL: 执行系统默认操作
3.信号处理函数名:自定义信号处理函数，如func
void func(int signo)
{
    //signo为触发的信号，为signal()第一个参数的值
}

返回值： 成功的话，第一次返回NULL,下一次返回此信号上一次注册的信号处理函数的地址。
如果需要使用此返回值，必须在前面先声明此函数指针的类型
失败返回 SIG_ERR


在此函数中，用不可重入函数，可能出现问题
//该函数尽量避免使用，用sigaction函数取而代之


//kill -9 强制杀死 通过 killall -9 a.out 强制杀死
终端上按Ctrl+c产生中断信号 SIGINT
        Ctrl+\产生中断信号SIGQUIT
        Ctrl+z产生中断信号SIGSTOP



8 void fun1(int signum)
9 {
10     printf("捕捉到信号：%d\n", signum);
11 }
12 void fun2(int signum)
13 {
14     printf("捕捉到信号: %d\n", signum);
15 }
16 int main()
17 {
18     signal(SIGINT, fun1);
19     signal(SIGQUIT, fun2);
20     while (1)
21     {
22         sleep(1);
23     }
24     return 0;
25 }








信号产生且被响应叫做递达状态，信号产生但没有响应叫未决状态
信号产生后，内核把信号发给进程，进程中维护着两个信号集（未决信号集和阻塞信号集），
如果阻塞信号集的值是1，则表示不能通过，信号不能响应
未决信号集可以读，不可以设置，由内核自动设置，用户可以设置阻塞信号集







int sigemptyset(sigset_t* set)       //将集和置空
int sigfillset(sigset_t* set);       //将所有信号加入set集和
int sigdelset   ...   //删除
int sigaddset(sigset_t* set, int signo);//将signo信号加入集和
int sigismember(const sigset_t* set, int signo);//判断信号signo是否存在





7 int main()
8 {
9     int i = 0;
10     //信号集集和
11     sigset_t set;
12     //清空集合
13     sigemptyset(&set);
14     for (i = 1; i < 32; i++)         //共有31个信号
15     {
16         if (sigismember(&set, i))
17         {
18             printf("1");
19         }
20         else
21         {
22             printf("0");
23         }
24     }
25     return 0;
26 }







//可以通过sigprocmask()修改当前的信号掩码来改变信号的阻塞情况
int sigprocmask(int how,const sigset_t *set,sigset_t *oldset);
//检查或修改信号阻塞集，根据how指定的方法对进程的阻塞集进行修改，新的信号阻塞集由set指定，原先的由oldset保存
//参数 how   指定修改方法
1. SIG_BLOCK:向信号阻塞集合中添加set信号集        mask=mask | set 
2. SIG_UNBLOCK:从信号阻塞集合中删除set信号集      mask=mask &- set
3. SIG_SETMASK:替换                               mask=set
//参数 set   要操作的信号集地址      若set为NULL，函数只会把当前的信号阻塞集合保存到oldset中
成功返回0失败返回-1，失败时错误代码可能是EINVAL，表示how不合法




#include<sys/wait.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/time.h>

void fun1(int signum)
{
    printf("捕捉到信号%d\n", signum);
}

void fun2(int signum)
{
    printf("捕捉到信号%d\n", signum);
}
int main()
{
    int ret = -1;
    sigset_t set;
    sigset_t old;
    //ctrl + C
    signal(SIGINT, fun1);
    //ctrl + \ 
    signal(SIGQUIT, fun2);
    printf("按下任意键，阻塞信号2\n");
    getchar();
    sigemptyset(&oldset);
    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    ret = sigprocmask(SIG_BLOCK, &set, &oldset);//阻塞信号2
    if (ret == -1)
    {
        perror("sigprocmask");
        return 1;
    }
    printf("设置阻塞编号为2的信号成功...\n");
    printf("按下任意键解除编号为2的信号的阻塞..\n");
    getchar();
    ret = sigprocmask(SIG_SETMASK, &oldset, NULL);   //替换为原来，即为非阻塞
    if (ret == -1)
    {
        perror("sigprocmask");
        return 1;
    }
    printf("按下任意键退出..\n");
    getchar();
    return 0;
}







sigaction 函数

int sigaction(int signum, const struct sigaction* act, struct sigaction* oldact);



struct sigaction
{
    void(*sa_handler)(int);//旧的信号处理函数指针

    void(*sa_sigaction)(int, siginfo_t*, void*);//新的信号处理函数指针

    sigset_t sa_mask;   //信号阻塞集

    int sa_flags;    //信号处理的方式

    void(*sa_restorer)(void);//已弃用
};




1)
sa_handler、sa_sigaction:信号处理函数指针, 和signal()里的函数指针用法一样, 应根据情况给
sa_sigaction、sa_handler两者之一赋值, 其取值如下:
a)SIG_IGN : 忽略该信号
b)SIG_DFL:执行系统默认动作
c)处理函数名:自定义信号处理函数


2)
sa_mask:信号阻塞集, 在信号处理函数执行过程中, 临时屏蔽指定的信号。


3)
sa_flgs:用于指定信号处理的行为, 通常设置为0, 表使用默认属性。它可以是一下值的“按位或"组合:
 SA RESTART : 使被信号打断的系统调用自动重新发起(已经废弃)
SA NOCLDSTOP : 使父进程在它的子进程暂停或继续运行时不会收到SIGCHLD信号。
 SA NOCLDWAIT : 使父进程在它的子进程退出时不会收到SIGCHLD信号, 这时子进程如果退出也不会成
为僵尸进程。
 SA NODEFER : 使对信号的屏蔽无效, 即在信号处理函数执行期间仍能发出这个信号。
 SA_RESETHAND : 信号处理之后重新设置为默认的处理方式。
 SA_SIGINFO : 使用sa_sigaction成员而不是sa_handler作为信号处理函数。




    
    void fun(int signo)
{
    printf("捕捉到信号%d\n", signo);
}
//演示sigaction函数使用
int main(void)
{
    int ret = -1;
    struct sigaction act;
    //使用旧的信号处理函数指针
    act.sa_handler =fun;
    //标志为默认默认使用旧的信号处理函数指针
    act.sa_flags = 0;
    //信号注册
    ret= sigaction(SIGINT, &act, NULL);
    if (-1 == ret)
    {
        perror("sigaction");
        return 1;
    }
    printf("按下任意键退出,.,,.\n");
    while (1)
    {
        getchar();
    }
    return 0;
}








void fun(int signo)
{
printf("捕捉到信号%d\n", signo);
}
//新的信号处理函数
void funl(int signo, siginfo_t * info, void* context)
{
printf("捕捉到信号%d\n", signo);
}
//演示sigaction函数使用
int main(void)
{
int ret = -1;


#if 0
struct sigaction act;
    //使用旧的信号处理函数指针
    act.sa_handler = fun;
        //标志为默认默认使用旧的信号处理函数指针
        act.sa_flags = 0;


#else
        struct sigaction act;
        //使用新的信号处理函数指针
        act.sa_sigaction = funl;
        //标志指定使用新的信号处理函数指针
        act.sa_flags = SA_SIGINFO;
#endif
            //信号注册
         ret = sigaction(SIGINT, &act, NULL);
    if (-1 == ret)
    {
          perror("sigaction");
          return 1;
    }
        printf("按下任意键退出,.,,.\n");
            while (1)
            {
             getchar();
            }
           return 0;
}







11.1 SIGCHLD信号产生的条件  (17)
1)子进程终止时
2)子进程接收到SIGSTOP信号停止时
3)子进程处在停止态, 接受到SIGCONT后唤醒时



#include<stdio.h>
#include<signal.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>


void fun(int signo)
{
    printf("捕捉到信号:%d\n", signo);         //17
    printf("有子进程退出.,,,\n");
}

int main(void)
{
    pid_t pid = -1;
    struct sigaction act;
    act.sa_handler = fun;
    act.sa_flags = 0;
    //注册信号处理函数
    sigaction(SIGCHLD, &act, NULL);
    //创建一个子进程
    pid = fork();
    if (-1 == pid)
    {
        perror("fork");
        return 1;
    }
    //子进程
    if (0 == pid)
    {
        printf("子进程比较累,先休息两秒钟...\n");
        sleep(2);
        printf("子进程休息好了,太无聊了,就退出了..\n");
        exit(0);
    }
    else
    {
        //父进程
        while (1)
        {
            printf("父进程do working,,.\n");
            sleep(1);
        }
    }
    return 0;
}






11.2如何避免僵尸进程
1)最简单的方法, 父进程通过wait和waitpid等函数等待子进程结束, 但是, 这会导致父进程挂起。
2)如果父进程要处理的事情很多, 不能够挂起, 通过signal函数人为处理信号SIGCHLD, 只要有子进程退出
自动调用指定好的回调函数, 因为子进程结束后, 父进程会收到该信号SIGCHLD, 可以在其回调函数里调用
wait()或waitpid回收。


void fun(int signo)
{
    printf("捕捉到信号:%d\n", signo);         //17
    printf("有子进程退出.,,,\n");
    //非阻塞方式
    while ((waitpid(-1, NULL, WNOHANG)) > 0){}
}

int main(void)
{
    pid_t pid = -1;
    struct sigaction act;
    act.sa_handler = fun;
    act.sa_flags = 0;
    //注册信号处理函数
    sigaction(SIGCHLD, &act, NULL);
    //创建一个子进程
    pid = fork();
    if (-1 == pid)
    {
        perror("fork");
        return 1;
    }
    //子进程
    if (0 == pid)
    {
        printf("子进程比较累,先休息两秒钟...\n");
        sleep(2);
        printf("子进程休息好了,太无聊了,就退出了..\n");
        exit(0);
    }
    else
    {
        //父进程
        while (1)
        {
            printf("父进程do working,,.\n");
            sleep(1);
        }
    }
    return 0;
}
