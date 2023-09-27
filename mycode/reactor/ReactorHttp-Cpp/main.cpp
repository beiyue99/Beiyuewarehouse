#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "TcpServer.h"

int main(int argc, char* argv[])
{
#if 0
    if (argc < 3)
    {
        printf("./a.out port path\n");
        return -1;
    }
    unsigned short port = atoi(argv[1]);
    // 切换服务器的工作路径
    chdir(argv[2]);
#else
    unsigned short port = 10000;
    //切换工作目录
    char pwd_path[256] = "";
    char* path = getenv("PWD");
    //如果程序中修改了目录，再调用 getenv("PWD")，它可能还会返回旧的工作目录
    //（除非你的程序自己更新了 "PWD" 环境变量）。而如果你调用 getcwd()，它会返回正确的新工作目录 
    strcpy(pwd_path, path);
    strcat(pwd_path, "/web-http");
    chdir(pwd_path);
#endif
    // 启动服务器
    TcpServer* server = new TcpServer(port, 4);
    server->run();

    return 0;
}