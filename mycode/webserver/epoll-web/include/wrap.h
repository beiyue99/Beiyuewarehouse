#ifndef __WRAP_H_
#define __WRAP_H_
#include<unistd.h>
#include<stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <arpa/inet.h>
#include<string.h>
#include<ctype.h>
int tcp4bind(short port, const char* IP);
void perr_exit(const char* s);
int Accept(int fd, struct sockaddr* sa, socklen_t* salenptr);
int Listen(int fd, int backlog);
int Socket(int family, int type, int protocol);
ssize_t my_read(int fd, char* ptr);
ssize_t Readline(int fd, void* vptr, size_t maxlen);
int hexit(char c);
void decodeMsg(char* to, char* from);
const char* getFileType(const char* name);

#endif