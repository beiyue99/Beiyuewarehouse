

通过使用setsid命令，可以使进程与其原始终端分离，即使该终端关闭或断开连接，进程仍然在后台运行。
如 setsid . / a.out

之前已经学到，进程组长不可以调用setsid函数，所以可以在组长进程内创建个子进程，然后再子进程内调用。
在进程组组长中创建一个子进程并调用setsid()函数，子进程将成为新的进程组组长，
这是因为只有会话的领导者（即进程组组长）才能创建新的会话。
当子进程成为新的进程组组长后，它将与原始进程组分离，不再受原始进程组中的其他进程的控制。
此时，子进程成为新的会话的领导者，并且不再与原始终端相关联。
原始进程组组长和原始进程组中的其他进程仍然会继续运行，并且仍然会受原始终端的控制。
调用setsid()的子进程将成为新的会话的领导者，   原始进程组组长和其他进程仍然在原始会话中运行。
因此，原始进程组组长和调用setsid()的子进程将分别运行在不同的会话中，彼此独立。
int main()
{
    pid_t pid = -1;
    printf("主进程开始！\n");
    pid = fork();
    if (pid < 0)
    {
        printf("fork函数出现错误！\n");
    }
    else if (pid == 0)
    {
        printf("子进程开始执行！\n");
        setsid();
        for (;;)
        {
            printf("休息一秒！\n");
            sleep(1);
        }
        return 0;
    }
    else
    {
        for (;;)
        {
            sleep(1);
            printf("父进程休息1秒");
        }
        return 0;
    }
    printf("再见！\n");
    return 0;


    在后台运行的进程，按fg可以切换到前台











        sudo find - name "signal.h" | grep - in "SIGHUP"


        输出包含字符串 "SIGHUP" 的行，其中:
    -i 参数表示不区分大小写， - n 参数表示输出匹配行的行号；




        ps - eo pid, ppid, sid, tty, pgrp, comm | grep - E 'bash|PID|nginx'

        这里使用了 - E 选项来支持 | 操作符，同时使用了单引号将正则表达式括起来。


        - e 选项表示显示所有进程，包括不属于当前终端的进程。
        - o 选项后面跟随一个参数，表示要显示的进程信息字段。多个字段可以用逗号, 分隔。





        信号一：睡眠10秒，信号二：睡眠三秒
        假如程序可以捕获信号一和信号二，如果先收到信号一，正睡眠10秒，然后忽然来个信号二，
        那么会跳转处理信号二，此时信号一被打断，信号二处理完之后，继续进入信号一的睡眠


        睡了1秒
        睡了1秒
        Received Signal 1 - Sleeping for 10 seconds
        将要睡10秒
        Received Signal 2 during sleep
        将要睡3秒
        睡了3秒
        睡了10秒
        睡了1秒
        睡了1秒
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

        void handleSignal(int signal) {
        if (signal == SIGUSR1) {
            printf("Received Signal 1 - Sleeping for 10 seconds\n");
            printf("将要睡10秒\n");
            sleep(10);
            printf("睡了10秒\n");

        }
        else if (signal == SIGUSR2) {
            printf("Received Signal 2 during sleep\n");

            printf("将要睡3秒\n");

            sleep(3);
            printf("睡了3秒\n");

            // Handle Signal 2 during sleep
        }
    }

    int main() {
        // 设置信号处理函数
        signal(SIGUSR1, handleSignal);
        signal(SIGUSR2, handleSignal);

        printf("Starting main loop\n");

        while (1) {
            // 主循环
            sleep(1);
            printf("睡了1秒\n");
        }

        return 0;
    }


    如果收到信号一睡眠期间，多次收到信号1，则视为只收到一次信号1，当前睡眠时间过后，继续睡眠一次这个时间