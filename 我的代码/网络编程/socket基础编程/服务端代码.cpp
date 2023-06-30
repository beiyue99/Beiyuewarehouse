#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

const char* message = "Hello My Client!";
char buffer[BUFFER_SIZE];
int server_fd, new_socket, valread;

int main()
{
    int opt = 1;
    int addrlen = sizeof(struct sockaddr_in);
    struct sockaddr_in address;
    struct sockaddr_in client_addr;
    // �����������׽���
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // ���÷������׽���ѡ��
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) == -1)
    {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // �󶨷�������ַ�Ͷ˿�
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) == -1)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // ������������
    if (listen(server_fd, 5) == -1)
    {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
    //���������ͻ��˷��������������У�һ��һ������
    // �������ȴ��ͻ��˵�����
    while (1)
    {
        if ((new_socket = accept(server_fd, (struct sockaddr*)&client_addr, (socklen_t*)&addrlen)) == -1)
        {
            perror("accept failed");
            continue; // �����ȴ���һ������
        }

        //���ӳɹ�����ӡ�ͻ��˵�IP�Ͷ˿���Ϣ
        char ip[32];
        printf("Client IP: %s, Port: %d\n", inet_ntop(AF_INET, &client_addr.sin_addr.s_addr, ip, sizeof(ip)), ntohs(client_addr.sin_port));

        // ѭ�����պͷ�����Ϣ
        while (1)
        {
            // �ӿͻ��˶�ȡ����
            valread = read(new_socket, buffer, BUFFER_SIZE);
            if (valread == -1) {
                perror("read failed");
                break; // �����ڲ�ѭ���������ȡ��������
            }
            else if (valread == 0) {
                // �ͻ��˶Ͽ�����
                printf("Client disconnected\n");
                break; // �����ڲ�ѭ��������ͻ��˶Ͽ����ӵ����
            }

            printf("Client: %s\n", buffer);

            // �ж�ͨ���Ƿ����
            if (strcmp(buffer, "quit") == 0) {
                break;  // �����ڲ�ѭ��
            }

            // ��ͻ��˷�����Ϣ
            if (send(new_socket, message, strlen(message), 0) == -1) {
                perror("send failed");
                break; // �����ڲ�ѭ����������ʧ�ܵ����
            }
            // ��ջ�����
            memset(buffer, 0, BUFFER_SIZE);
        }
        close(new_socket);
    }
    close(server_fd);
    return 0;
}