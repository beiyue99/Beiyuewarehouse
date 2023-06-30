

//主机字节序的ip地址是字符串,网络字节序ip地址是整形   <arpa/inet.h>

int inet_pton(int af, const char* src, void* dst);
//用 inet_pton() 将点分十进制或 IPv6 地址表示法转换为二进制形式
af:地址族(ip地址的家族包括ipv4和ipv6)协议
■AF_INET : ipv4格式的ip地址
■AF_INET6 : ipv6格式的ip地址
src : 传入参数, 对应要转换的点分十进制的ip地址 : 192.168.1.100
dst : 传出参数, 函数调用完成, 转换得到的大端整形IP被写入到这块内存中
返回值 : 成功返回1, 失败返回0或者 - 1


//将大端的整形数,转换为小端的点分十进制的IP地址          
//inet_ntop() 函数将网络字节序的二进制地址转换为可打印的字符串形式，即将地址表示为点分十进制或 IPv6 地址表示法
const char* inet_ntop(int af, const void* src, char* dst, socklen_t size);
参数:
af : 地址族协议
AF_INET : ipv4格式的ip地址
AF_INET6 : ipv6格式的ip地址
srC : 传入参数, 这个指针指向的内存中存储了大端的整形IP地址
dst : 传出参数, 存储转换得到的小端的点分十进制的IP地址
size : 修饰dst参数的, 标记dst指向的内存中最多可以存储多少个字节
返回值 :
成功:指针指向第三个参数对应的内存地址, 通过返回值也可以直接取出转换得到的IP字符串
失败 :NULL





//点分十进制虹P->大端整形
in_addr_t inet_addr(const char* cp);
//大端整形->点分十进制IP
char* inet_ntoa(struct in_addr in);

//这套兼容性差，只针对IPv4，不建议使用








int socket(int domain, int type, int protocol);

domain：指定套接字使用的协议族或地址族，可以是以下常用值之一：
AF_INET：IPv4 网络协议。
AF_INET6：IPv6 网络协议。
AF_UNIX：UNIX 域协议，用于本地进程间通信。

type：指定套接字的类型，可以是以下常用值之一：
SOCK_STREAM：提供可靠的、面向连接的字节流，使用 TCP 协议。
SOCK_DGRAM：提供不可靠的、无连接的数据报服务，使用 UDP 协议。
SOCK_RAW：提供原始网络协议存取。


protocol：指定使用的协议，一般为 0，表示根据 domain 和 type 的取值选择默认协议。







函数 bind() 用于将一个套接字（socket）绑定到一个特定的地址和端口。
bind() 函数将指定的套接字绑定到指定的地址。绑定后，套接字将与该地址相关联，从而可以通过该地址进行通信。
int bind(int sockfd, const struct sockaddr* addr, socklen_t addrlen);
//通常创建in 或者in6的结构体传参，方便初始化
//绑定时 ，端口或者ip必须是大端的
sockfd：要绑定的套接字的文件描述符。
addr：指向要绑定的地址信息的结构体指针，通常是 struct sockaddr 类型的指针，需要进行类型转换。
addrlen：addr 结构体的大小，可以使用 sizeof(struct sockaddr) 来获取。

struct sockaddr {
    sa_family_t sa_family;  // 地址族（协议族）
    char sa_data[14];       // 地址数据
};

sa_family：表示地址族或协议族，可以是 AF_INET（IPv4）、AF_INET6（IPv6）或其他支持的地址族常量。
sa_data：存储地址数据的字段，具体内容和长度取决于地址族的不同


在实际使用中，通常使用更具体的地址结构体类型
//struct sockaddr_in（IPv4 地址结构体）的定义：
struct sockaddr_in {
    sa_family_t sin_family;  // 地址族（协议族）
    in_port_t sin_port;      // 16 位端口号
    struct in_addr sin_addr; // IPv4 地址
    char sin_zero[8];        // 用于补齐，通常设置为全 0
};


sin_family：表示地址族或协议族，设置为 AF_INET 表示 IPv4 地址族。
sin_port：16 位端口号，使用网络字节序存储。
sin_addr：存储 IPv4 地址的字段，类型为 struct in_addr，用于存储 32 位 IPv4 地址。
sin_zero：用于补齐字段，通常设置为全 0。
其中，struct in_addr 是一个用于存储 IPv4 地址的结构体。它的定义如下：
struct in_addr {
    in_addr_t s_addr;  // 存储 IPv4 地址的无符号整数
};
struct in_addr 中的 s_addr 是一个无符号整数，用于存储 32 位的 IPv4 地址。













//struct sockaddr_in6 的定义
struct sockaddr_in6 {
    sa_family_t sin6_family;     // 地址族（协议族）
    in_port_t sin6_port;         // 16 位端口号
    uint32_t sin6_flowinfo;      // 流标识
    struct in6_addr sin6_addr;   // IPv6 地址
    uint32_t sin6_scope_id;      // 作用域标识
};
sin6_family：表示地址族或协议族，设置为 AF_INET6 表示 IPv6 地址族。
sin6_port：16 位端口号，使用网络字节序存储。
sin6_flowinfo：流标识，用于区分同一源地址和目标地址之间不同的流。
sin6_addr：存储 IPv6 地址的字段，类型为 struct in6_addr，用于存储 128 位 IPv6 地址。
sin6_scope_id：作用域标识，用于指示地址的范围（例如，接口的索引）。
其中，struct in6_addr 是一个用于存储 IPv6 地址的结构体。它的定义如下：
struct in6_addr {
    unsigned char s6_addr[16];  // 存储 IPv6 地址的字节数组
};
struct in6_addr 中的 s6_addr 是一个长度为 16 的无符号字符数组，用于存储 IPv6 地址的 16 字节表示。




//将ip和端口存到结构体需要转化为大端，htons() 和 htonl() 是用于在主机字节序(小端)和网络字节序(大端)之间进行字节序转换的函数。






listen() 函数是用于将套接字（socket）设置为监听模式，以便接受传入的连接请求。它用于服务器端程序，用于准备接受客户端的连接。
int listen(int sockfd, int backlog);
sockfd：表示要监听的套接字文件描述符。这个套接字必须已经通过 socket() 函数创建，并且已经通过 bind() 函数绑定了地址。
backlog：表示等待连接队列的最大长度。它指定允许同时等待连接的最大客户端数量（128）。超过这个数量的连接请求将被拒绝。





accept() 函数用于从监听套接字的等待连接队列中接受传入的连接请求，并创建一个新的已连接套接字，用于与客户端进行通信。
int accept(int sockfd, struct sockaddr* addr, socklen_t* addrlen);
sockfd：表示监听套接字的文件描述符，即调用 listen() 函数后返回的套接字。

addr：表示指向用于存储客户端地址信息的结构体指针。当 accept() 函数成功返回后，该结构体将被填充为客户端的地址信息。

addrlen：表示一个指向整数变量的指针，用于指定 addr 结构体的长度。在调用 accept() 之前，需要将 addrlen 设置为 addr 结构体的大小。



函数的返回值为整数类型。如果调用成功，返回值为新创建的已连接套接字的文件描述符。该套接字可以用于与客户端进行通信。
如果调用失败，返回值为 - 1，并设置 errno 来指示错误类型。
accept() 函数会阻塞程序的执行，直到有新的连接请求到达，并且从等待连接队列中取出一个连接请求进行处理。
如果等待连接队列为空，则程序会一直等待，直到有连接请求到达为止。



connect()函数用于在客户端与服务器之间建立网络连接。它的原型如下：
int connect(int sockfd, const struct sockaddr* addr, socklen_t addrlen);

sockfd：一个整数值，表示套接字描述符（socket descriptor）。它是之前使用socket()函数创建的套接字。

addr：一个指向sockaddr结构体的指针，其中包含要连接的目标服务器的地址信息。sockaddr结构体是一个通用的网络地址结构，
需要将其转换为适当的地址类型，如sockaddr_in（用于IPv4）或sockaddr_in6（用于IPv6）。

addrlen：一个表示addr结构体的长度的整数值。可以使用sizeof运算符来获取addr结构体的大小。

connect()函数是一个阻塞函数，即当调用该函数时，程序会一直等待连接建立或发生错误。
如果你希望在建立连接过程中设置超时时间，可以使用select()或poll()等函数实现非阻塞操作。





接收数据
ssize_t read(int sockfd, void* buf, size_t size);
ssize_t recv(int sockfd, void* buf, size_t size,int flags);
参数：     
sockfd:用于通信的文件描述符, accept()函数的返回值
buf : 指向一块有效内存, 用于存储接收是数据
size : 参数buf指向的内存的容量
fags : 特殊的属性, 一般不使用, 指定为0
返回值
大于0 : 实际接收的字节数
等于0 : 对方断开了连接
 - 1 : 接收数据失败了
如果连接没有断开, 接收端接收不到数据, 接收数据的函数会阻塞等待数据到达, 数据到达后函数解除阻塞, 开始接收数据, 当
发送端断开连接, 接收端无法接收到任何数据, 但是这时候就不会阻塞了, 函数直接返回0。



发送数据的函数
ssize_t write(int fd, const void* buf, size_t len);
ssize_t send(int fd const void* buf, size_t len, int flags)
·参数
fd : 通信的文件描述符, accept函数的返回值
buf : 传入参数, 要发送的字符串
len : 要发送的字符串的长度
lags : 特殊的属性, 一般不使用, 指定为0
·返回值 :
大于0:实际发送的字节数, 和参数len是相等的
 - 1 : 发送数据失败了

    read, write属于unistd.h   recv, send属于<sys / socket.h>



    //int setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen);
    //sockfd：套接字描述符，指定要设置选项的套接字。
    //level：选项所属的协议层或套接字层。常用的级别包括 SOL_SOCKET（通用套接字选项）和特定协议的级别，如 IPPROTO_TCP（TCP协议选项）。
    //optname：要设置的选项名称。这是一个整数常量，表示特定选项的标识符。
    //optval：指向包含选项值的缓冲区的指针。
    //optlen：选项值的长度。
//这段代码中的 setsockopt() 函数用于设置服务器套接字的选项。特别是，它使用了 SO_REUSEADDR 和 SO_REUSEPORT 选项。
/*  SO_REUSEADDR 和 SO_REUSEPORT 是套接字选项，用于控制套接字的行为。
它们通常用于在关闭套接字后立即重新启动服务器，而无需等待一段时间以使套接字地址可再次使用。
具体作用如下：
SO_REUSEADDR 选项允许套接字地址（IP地址和端口号）在释放后立即重用。这意味着即使之前的套接字连接尚未完全关闭，也可以立即绑定到相同的地址上。
SO_REUSEPORT 选项允许多个套接字绑定到相同的地址和端口上。这对于实现负载均衡和多进程 / 线程并发处理请求的服务器非常有用。*/




