
ps命令：
ps- a  // 显示终端上所有进程
ps -u  //显示进程的详细信息
ps -x  //显示没有控制终端的进程 
ps -w  //显示加宽以便显示更多信息
ps -r  //只显示正在运行的进程


top ： 动态显示运行中的进程


sleep 300 &  //在后台运行    ps -a可以显示，执行kill(PID)，终止该进程

killall -9 sleep   //杀死所有名为 sleep的进程



getpid(); 获取进程号   getppid();获取父进程号  getpgid(getpid()); 获取进程组号 



fork()作用是创建一个子进程，会输出两个hello world
  4 int main()
  5 {   
  6     fork();
  7     printf("hello world");
  8     return 0;
  9 }  
  
  
  
  
  
  
  
 //fork函数在子进程中返回0，在父进程中返回子进程的pid

  
  
  
fork()遵从“读时共享，写时拷贝”  如果父进程修改变量的值，会拷贝一份修改，子进程再读取这个变量还是原来的值
  
  
  
  
  

  
  
  
  5 int main()
  6 {   
  7     printf("hello world");
  8     _exit(0);
  9 }  
  return 0 和  exit（0） 友好退出函数
  而 _exit(0)和_Exit(0)等价，是强制退出，不刷新io缓冲区，不会吧hello world 输出到屏幕
  
  
  
  
  
  
  
  wait和waitpid功能一样，都是等待一个子进程结束，回收这个子进程的资源。区别在于，wait函数会阻塞，waitpid可以设置不阻塞，还可以指定等待某个子进程结束
  
  wait函数返回值为已经结束子进程的进程id，失败返回-1，调用该函数的进程会阻塞，直到子进程退出或者收到一个不可忽视的信号才被唤醒继续向下执行，
  若调用该函数的进程没有子进程，那么该函数立即返回。若子进程已经结束，该函数也会立即返回，并且回收已经结束的子进程的资源。
  pid_t wait(int *status)
 status：进程退出时的状态信息。 如果status的值不是NULL，就会把退出时子进程的状态存入其中。直接使用这个值是没有意义的，还需要借助相关宏取出它代表的信息
  
  
  
  
  
    1：     WIFEXITED(status)
  为非0，代表进程正常结束

       WEXITSTATUS(status)
 如果上宏为真，使用此宏->获取进程退出状态，也就是exit的参数       

   2：    WIFSIGNALED(status)
为非0，代表进程异常终止
       WTERMSIG(status)
 如果上宏为真，使用此宏->获得使进程终止的那个信号的编号
 
   
  3：     WIFSTOPPED(status)
为非0，代表进程处于暂停状态

       WSTOPSIG(status)
 如果上宏为真，使用此宏->获得使进程暂停的那个信号的编号
  
  
  4：  WIFCONTINUED(status)
为非0，代表进程暂停后已继续运行
  
  

  
  
  kill-19 暂停任务,kill -18 恢复
  
  
  
  
  
  下面看 waitpid
  pid_t waipid(pit_t pid,int*status,int options);
  
 参数pid的类型: 
 1  pid>0 ： 等待进程id=pid的子进程
 2  pid=0 :  等待同一个进程组中的任何子进程，如果子进程已经加入了别的进程组，便不会等待它
 3  pid=-1:  等待任一子进程，此时和wait函数作用一样
 4  pid< -1: 等待指定进程组中的任何子进程，这个进程组的id等于pid的绝对值
 
 参数options提供了一些额外的选项来控制waitpid（）
 O: 同wait()，阻塞父进程，等待子进程退出
 WNOHANG： 没有任何已经结束的子进程，则立即返回，也就是不等待子进程
 WUNTRACED:如果进程暂停了，此函数马上返回，并且不予以理会子进程的结束状态（极少用到）
 
 
 返回值比较复杂，有三个情况：
 1： 当正常返回的时候，它返回回收的子进程的进程号
 2： 如果设置了选项WNOHANG，而调用函数时发现没有已退出的子进程可等待，返回0
 3： 如果出错返回-1，并设置errno。如当pid所对应的子进程不存在，或者此进程存在，但不是调用进程的子进程，就会出错
  
  
  
  
  7 int main()
  8 {
  9     int ret=-1;
 10     int status=-1;
 11     int pid=-1;
 12     pid=fork();
 13     if(pid==-1)
 14     {
 15         perror("fork");
 16         return 1;
 17     }
 18     if(pid==0)
 19     {
 20         for(int i=0;i<5;i++)
 21         {
 22             printf("child progress %d is  doing things! %d\n",getpid(),i);
 23             sleep(1);
 24         }
 25         exit(10);
 26     }
 27     printf("父进程等待子进程退出\n");
 28 //  ret=wait(&status);
 29 //  ret=waitpid(-1,&status,0);跟wait效果一样
 30 //  ret=waitpid(-1,&status,WNOHANG);不等待子进程，也就是不阻塞
 31 
 32     if(ret==-1)
 33     {
 34         perror("wait");
 35         return 1;
 36     }
 37     printf("父进程回收了子进程的资源\n");
 38     if( WIFEXITED(status))
 39     {
 40         printf("子进程正常退出，状态码为%d\n",WEXITSTATUS(status));
 41     }
 42     else if( WIFSIGNALED(status))
 43     {
 44         printf("子进程被信号%d杀死了...\n",WTERMSIG(status));
 45     }
 46     else if( WIFSTOPPED(status))
 47     {
 48         printf("子进程被信号%d暂停...\n",WSTOPSIG(status));
 49     }
 50     return 0;
 51 }

  
  
  
  
  
  
  孤儿进程： 每当出现一个孤儿进程，内核就会设置孤儿的父进程为init，inti会循环的回收资源，因此孤儿进程没什么危害
  
  
  
  僵尸进程:  死去的子进程不回收变成僵尸
  
  
  
  
  
  
  
    8 int main()
  9     {
 10         int i=0;
 11         int pid=-1;
 12         pid=fork();
 13         if(pid==0)
 14         {
 15             for(i=0;i<3;i++)
 16             {
 17                 printf("子进程运行 %d\n",i);
 18                 sleep(1);
 19             }
 20             printf("子进程死亡\n");
 21             exit(0);
 22         }
 23 //      sleep(100);
 24         printf("父进程退出\n");
 25         return 0;
 26     }

  父进程退出会给子进程收尸，如果父进程一直不退出，那么死去的子进程就是一个僵尸进程
  
  
  
  
  
  
  
  
  
  
  
  
  //进程替换： 通过exec函数族，他们的功能都相似
  execl和execlp需要掌握，其余的了解
  
  进程调用一种exec函数时，该进程安全由新进程替换，从main函数开始执行。并未创建新进程，只是用另一个新进程替换了当前进程的正文，数据，堆和栈。
 
 
 
 
1：
       int execl(const char *pathname, const char *arg, ...
                       /* (char  *) NULL */);
 第一个参数为可执行文件的绝对路径和相对路径，第二个参数为可执行文件的名字，然后是可执行文件的参数，最后一个是NULL，与execlp类似，
     除了第一个参数不同，功能相同   
           
           execl("/bin/ls","ls","-l","/home",NULL);
    
          
          
2：                 
       int execlp(const char *file, const char *arg, ...
                       /* (char  *) NULL */);
                       
  5 int main()
  6 {
  7     printf("hello world\n");
  8     execlp("ls","ls","-l","/home",NULL); //等价于执行ls -l /home //第一个是file文件名，后面是arg0到argn。约定arg0为文件名，argn为NULL
  9     printf("hello 222222222\n");
 10     return 0;
 11 }
      第9行不会执行，因为运行到第八行，进程被替换             
          
          
          
          
          
             
3：                   
       int execv(const char *pathname, char *const argv[]);
       中心代码段：
       char *argv[]={"ls","-l","/home",NULL);
       printf("hello world");
       execv("/bin/ls",argv);
       printf("hello 22222222\n");
       return 0;
       
       
4：
       int execvp(const char *file, char *const argv[]);
       
       中心代码段：
       char *argv[]={"ls","-l","/home",NULL);
       printf("hello world");
       execvp("ls",argv);
       printf("hello 22222222\n");
       return 0;
           
       

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  