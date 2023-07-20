#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <ctype.h>
#include <event2/event.h>
#include <event2/bufferevent.h>

const char* getFileType(const char* name) {
    char* ext = strrchr(name, '.');
    if (!ext) return "text/plain";
    if (strcmp(ext, ".html") == 0 || strcmp(ext, ".htm") == 0) return "text/html";
    if (strcmp(ext, ".jpg") == 0 || strcmp(ext, ".jpeg") == 0) return "image/jpeg";
    if (strcmp(ext, ".gif") == 0) return "image/gif";
    if (strcmp(ext, ".png") == 0) return "image/png";
    if (strcmp(ext, ".css") == 0) return "text/css";
    if (strcmp(ext, ".au") == 0) return "audio/basic";
    if (strcmp(ext, ".wav") == 0) return "audio/wav";
    if (strcmp(ext, ".avi") == 0) return "video/x-msvideo";
    if (strcmp(ext, ".mpeg") == 0 || strcmp(ext, ".mpg") == 0) return "video/mpeg";
    if (strcmp(ext, ".mp3") == 0) return "audio/mpeg";
    return "text/plain";
}

void send_directory_listing(struct bufferevent* bev, const char* directory);

void send_header(struct bufferevent* bev, int code, const char* info, const char* file_type, int length) {
    char buf[1024] = { 0 };
    sprintf(buf, "HTTP/1.1 %d %s\r\n", code, info);
    bufferevent_write(bev, buf, strlen(buf));
    sprintf(buf, "Content-Type: %s\r\n", file_type);
    bufferevent_write(bev, buf, strlen(buf));
    if (length > 0) {
        sprintf(buf, "Content-Length: %d\r\n", length);
        bufferevent_write(bev, buf, strlen(buf));
    }
    sprintf(buf, "\r\n");
    bufferevent_write(bev, buf, strlen(buf));
}

void send_file(struct bufferevent* bev, const char* file) {
    char buf[4096] = { 0 };
    const char* file_type = getFileType(file);
    int fd = open(file, O_RDONLY);
    if (fd == -1) {
        send_header(bev, 404, "Not Found", "text/html", 0);
        bufferevent_write(bev, "<h1>404: Not Found</h1>", 23);
    }
    else {
        struct stat st;
        if (fstat(fd, &st) == -1) {
            perror("fstat");
            close(fd);
            return;
        }
        send_header(bev, 200, "OK", file_type, st.st_size);
        sprintf(buf, "\r\n");  // 添加空行
        bufferevent_write(bev, buf, strlen(buf));
        ssize_t bytes_read;
        while ((bytes_read = read(fd, buf, sizeof(buf))) > 0) {
            bufferevent_write(bev, buf, bytes_read);
        }
    }
    close(fd);
}


int hexit(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    return 0;
}

void decodeMsg(char* to, char* from) {
    for (; *from != '\0'; ++to, ++from) {
        if (from[0] == '%' && isxdigit(from[1]) && isxdigit(from[2])) {
            *to = hexit(from[1]) * 16 + hexit(from[2]);
            from += 2;
        }
        else {
            *to = *from;
        }
    }
    *to = '\0';
}

void send_directory_listing(struct bufferevent* bev, const char* directory) {
    DIR* dir = opendir(directory);
    if (dir == NULL) {
        perror("opendir error");
        return;
    }

    struct dirent* entry;
    char buf[1024];
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(buf, sizeof(buf), "<li><a href=\"%s/%s\">%s</a></li>", directory, entry->d_name, entry->d_name);
        bufferevent_write(bev, buf, strlen(buf));
    }

    closedir(dir);
}

void read_cb(struct bufferevent* bev, void* arg) {
    char line[8192] = { 0 };
    char method[16], path[256], protocol[16];

    bufferevent_read(bev, line, sizeof(line));
    sscanf(line, "%[^ ] %[^ ] %[^ \r\n]", method, path, protocol);

    if (strcasecmp(method, "GET") == 0) {
        char* strfile = path + 1;
        decodeMsg(strfile, strfile);

        if (*strfile == '\0') { // 如果没有请求文件，默认请求当前目录
            strfile = "./";
        }

        struct stat s;
        if (stat(strfile, &s) < 0) { // 不存在
            printf("File not found\n");
            char             errorFilePath[1024] = { 0 };
            char* currentDir = getcwd(NULL, 0); // 获取当前工作目录
            sprintf(errorFilePath, "%s/error.html", currentDir);
            printf("Error file path: %s\n", errorFilePath);
            send_header(bev, 404, "Not Found", getFileType("*.html"), 0);
            send_file(bev, errorFilePath);
            free(currentDir); // 释放获取到的当前工作目录内存
        }
        else {
            if (S_ISDIR(s.st_mode)) { // 请求的是目录
                send_directory_listing(bev, strfile);
            }
            else { // 请求的是文件
                send_file(bev, strfile);
            }
        }
    }
    else {
        send_header(bev, 405, "Method Not Allowed", "text/html", 0);
        bufferevent_write(bev, "<h1>405: Method Not Allowed</h1>", 31);
    }
    bufferevent_enable(bev, EV_READ);  // 继续监听客户端数据

}

void write_cb(struct bufferevent* bev, void* arg) {
    // Do nothing
}

void error_cb(struct bufferevent* bev, short events, void* arg) {
    if (events & BEV_EVENT_EOF) {
        printf("Connection closed\n");
    }
    else if (events & BEV_EVENT_ERROR) {
        printf("Some other error\n");
    }
    bufferevent_free(bev);
}

void do_accept(evutil_socket_t fd, short events, void* arg) {
    struct event_base* base = (struct event_base*)arg;
    struct sockaddr_in client;
    socklen_t len = sizeof(client);
    int client_fd = accept(fd, (struct sockaddr*)&client, &len);
    evutil_make_socket_nonblocking(client_fd);

    struct bufferevent* bev = bufferevent_socket_new(base, client_fd, BEV_OPT_CLOSE_ON_FREE);
    bufferevent_setcb(bev, read_cb, write_cb, error_cb, NULL);
    bufferevent_enable(bev, EV_READ);
}

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket error");
        exit(1);
    }
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        perror("bind error");
        exit(1);
    }

    if (listen(sockfd, 10) == -1) {
        perror("listen error");
        exit(1);
    }

    struct event_base* base = event_base_new();
    struct event* ev = event_new(base, sockfd, EV_READ | EV_PERSIST, do_accept, base);

    event_add(ev, NULL);
    event_base_dispatch(base);

    return 0;
}

