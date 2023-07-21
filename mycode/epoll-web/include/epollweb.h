
#ifndef __EPOLLWEB_H_
#define __EPOLLWEB_H_



#include<stdio.h>
#define PORT 8080
#include<sys/epoll.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<ctype.h>
#include<stdlib.h>
#include<dirent.h>
#include<signal.h>

void send_header(int cfd, int code, char* info, const  char* filetype, int length);
void send_file(int cfd, char* path, struct epoll_event* ev, int epfd, int flag);
void read_client_request(int epfd, struct epoll_event* ev, char* pwd_path);
void epollRun();


#endif