#include <iostream>
#include <vector>
#include <cstring>
#include <thread>
#include <fcntl.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <arpa/inet.h>

constexpr int MAX_EVENTS = 10;
constexpr int BUFFER_SIZE = 1024;

std::vector<int> client_sockets; // �ͻ����׽����б�

void handle_client(int client_socket);

void epoll_event_loop(int epoll_fd)
{
    epoll_event events[MAX_EVENTS];
    bool should_continue = true;
    while (should_continue)
    {
        int event_count = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
        if (event_count == -1) {
            perror("epoll_wait error");
            break;
        }

        for (int i = 0; i < event_count; ++i) 
        {
            int event_fd = events[i].data.fd;
            if (event_fd == STDIN_FILENO) 
            {
                // �����׼�����¼�
                char input_buffer[BUFFER_SIZE];
                ssize_t bytes_read = read(event_fd, input_buffer, BUFFER_SIZE);
                if (bytes_read == -1) 
                {
                    perror("Failed to read from stdin");
                    break;
                }

                // �����׼��������
                std::string input_data(input_buffer, bytes_read);
                //���� input_buffer �е�ǰ bytes_read ���ַ���Ϊ��ʼ���ݴ洢�� input_data �С�
                std::cout << "recive standard date:" << input_data << std::endl;
                if (input_data == "quit\n") //��Ϊ read() ������ȡ�����ݰ����˻��з� \n��
                {
                    std::cout << "Server is shutting down..." << std::endl;
                    should_continue = false;
                    break;
                }

            }
            else if (events[i].events & EPOLLIN)
            {
                // ����ͻ��������¼�
                sockaddr_in client_address{};
                socklen_t client_address_len = sizeof(client_address);
                int client_socket = accept(event_fd, reinterpret_cast<sockaddr*>(&client_address), &client_address_len);
                if (client_socket == -1) 
                {
                    perror("Failed to accept client connection");
                    break;
                }

                // ���ÿͻ����׽���Ϊ������ģʽ
                int client_flags = fcntl(client_socket, F_GETFL, 0);
                fcntl(client_socket, F_SETFL, client_flags | O_NONBLOCK);

                // ���ͻ����׽���ע�ᵽ epoll ����
                epoll_event client_event{};
                client_event.events = EPOLLIN | EPOLLET;
                client_event.data.fd = client_socket;
                if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, client_socket, &client_event) == -1)
                {
                    perror("Failed to add client socket to epoll");
                    close(client_socket);
                    break;
                }
                std::cout << "New client connected. Socket: " << client_socket << std::endl;

                // ���ͻ����׽�����ӵ��ͻ����׽����б�
                client_sockets.push_back(client_socket);

                // ����һ���̴߳���ͻ�������
                std::thread client_thread(handle_client, client_socket);
                client_thread.detach(); // �ں�̨�����߳�
            }
        }
    }
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    while (true) {
        memset(buffer, 0, BUFFER_SIZE);  // ��ս��ջ�����
        ssize_t bytes_read = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);

        if (bytes_read == -1)
        {
            if (errno == EAGAIN || errno == EWOULDBLOCK)
            {
                // ��ʱ�޿ɶ����ݣ�������һ��ѭ���ȴ�
                continue;
            }
            else
            {
                perror("Failed to read client socket");
                close(client_socket);
                break;
            }
        }
        else if (bytes_read == 0)
        {
            // �ͻ������ӹر�
            std::cout << "Client disconnected. Socket: " << client_socket << std::endl;
            close(client_socket);
            break;
        }

        std::cout << "Received data from client. Socket: " << client_socket << ", Data: " << buffer << std::endl;

        const char* response = "Server received your message";
        send(client_socket, response, strlen(response), 0);
    }
}

int main() {
    // �����׽���
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Failed to create socket");
        return -1;
    }
    // �����׽��ֵ�ַ����
    int reuseaddr = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &reuseaddr, sizeof(reuseaddr)) == -1) {
        perror("Failed to set socket options");
        close(server_socket);
        return -1;
    }

    // �󶨺ͼ����׽���
    sockaddr_in server_address{};
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);
    if (bind(server_socket, reinterpret_cast<const sockaddr*>(&server_address), sizeof(server_address)) == -1) {
        perror("Failed to bind");
        close(server_socket);
        return -1;
    }

    if (listen(server_socket, SOMAXCONN) == -1) {
        perror("Failed to listen");
        close(server_socket);
        return -1;
    }

    // ����epoll����
    int epoll_fd = epoll_create(1);
    if (epoll_fd == -1) {
        perror("Failed to create epoll");
        close(server_socket);
        return -1;
    }

    // ע������׽��ֺͱ�׼���뵽epoll����
    epoll_event event{};
    event.events = EPOLLIN;
    event.data.fd = server_socket;
    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, server_socket, &event) == -1) {
        perror("Failed to add server socket to epoll");
        close(server_socket);
        close(epoll_fd);
        return -1;
    }

    event.data.fd = STDIN_FILENO;
    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, STDIN_FILENO, &event) == -1) {
        perror("Failed to add stdin to epoll");
        close(server_socket);
        close(epoll_fd);
        return -1;
    }

    // �����¼�ѭ��
    epoll_event_loop(epoll_fd);

    // �ر��׽��ֺ�epoll����
    close(server_socket);
    close(epoll_fd);

    return 0;
}