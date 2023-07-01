#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#define _EVENT_SIZE_ 1024
// server
int main(int argc, const char* argv[])
{
    // �����������׽���
    int lfd = socket(AF_INET, SOCK_STREAM, 0);
    if (lfd == -1)
    {
        perror("socket error");
        exit(1);
    }

    // ��
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(9999);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);  

    // ���ö˿ڸ���
    int opt = 1;
    setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // �󶨶˿�
    int ret = bind(lfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if (ret == -1)
    {
        perror("bind error");
        exit(1);
    }

    // ����
    ret = listen(lfd, 64);
    if (ret == -1)
    {
        perror("listen error");
        exit(1);
    }

    // ����һ��epollģ��
    int epfd = epoll_create(100);
    if (epfd == -1)
    {
        perror("epoll_create");
        exit(0);
    }

    // ��epollʵ���������Ҫ���Ľڵ�, ����ֻ�м������ļ�������
    struct epoll_event ev;
    ev.events = EPOLLIN;  
    // �� epoll ģ����ָ��Ҫ���ӵ��ļ����������¼�������������£�����ʾ���ļ����������пɶ�����ʱ������ epoll �¼�
    ev.data.fd = lfd;
    ret = epoll_ctl(epfd, EPOLL_CTL_ADD, lfd, &ev);
    if (ret == -1)
    {
        perror("epoll_ctl");
        exit(0);
    }

    struct epoll_event evs[_EVENT_SIZE_];
    int size = sizeof(evs) / sizeof(struct epoll_event);
    // �������
    while (1)
    {
        // ����һ��, ���һ��
        int num = epoll_wait(epfd, evs, size, -1);
        for (int i = 0; i < num; ++i)
        {
            // ȡ����ǰ���ļ�������
            int curfd = evs[i].data.fd;
            // �ж�����ļ��������ǲ������ڼ�����
            if (curfd == lfd)
            {
                // �����µ�����
                int cfd = accept(curfd, NULL, NULL);
                ev.events = EPOLLIN;     //����EPOLLET  ��ʾ��Ե����  Ȼ����Ҫ���÷���������
                ev.data.fd = cfd;
                ret = epoll_ctl(epfd, EPOLL_CTL_ADD, cfd, &ev);
                if (ret == -1)
                {
                    perror("epoll_ctl-accept");
                    exit(0);
                }
            }
            else
            {
                // ����ͨ�ŵ��ļ�������
                // ��������
                char buf[1024];
                memset(buf, 0, sizeof(buf));
                int len = recv(curfd, buf, sizeof(buf), 0);
                if (len == 0)
                {
                    printf("The client has disconnected!\n");
                    // ������ļ���������epollģ����ɾ��
                    epoll_ctl(epfd, EPOLL_CTL_DEL, curfd, NULL);
                    close(curfd);
                }
                else if (len > 0)
                {
                    //STDOUT_FILENO: ������ֱ��д���׼������ǽ�����������նˣ�ͨ���������н��棩
                    // write(STDOUT_FILENO,buf,1en);   ���͵���ǰ�նˣ������������д���
                    printf("client say: %s\n", buf);
          /*        ��� buf �����һ���ַ����ǿ��ַ�(\0)������ʹ�� printf �������ʱ���ܻᵼ�����������Ľ����
                    ʹ�� write ����ֱ����� buf �����ݣ��������ַ����Ľ�β���ַ�����ˣ���ʹ���һ���ַ����ǿ��ַ���
                    Ҳ����������룬write �����ᰴ��ָ���ĳ��������
                    printf ������ͨ��Ѱ���ַ����Ľ�β���ַ�(\0) ��ȷ���ַ����Ľ���λ�õġ���� buf �����һ���ַ����ǿ��ַ���
                    �� printf �����������ȡ�ڴ��е��������ݣ�ֱ��������һ�����ַ�Ϊֹ������ܵ���������������������
                    Ϊ�˱�������������������ȷ�� buf ���Կ��ַ���β���ַ���������ȷָ��Ҫ������ֽ�����*/

                    send(curfd, buf, len, 0);
                    //���һ�ζ������һ�ζ����������£����ӡ���룬�����ǽ������
                    // send(fd, buf, strlen(buf) + 1, 0);
                    //strlen(buf) + 1 ��ֵͨ������ȷ���������Ͱ����ַ�����β�Ŀ��ַ���'\0'����
                    //���Ҫ���͵����ݲ����Կ��ַ���β���ַ�������ֻ����ͨ���ֽ����ݣ�����Ҫ�ڵ����������м�һ��ֱ��ʹ�����ݵĳ��ȼ��ɡ�
                }
                else
                {
                    perror("recv");
                    exit(0);
                }
            }
        }
    }

    return 0;
}


