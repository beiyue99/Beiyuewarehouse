#include<iostream>
#include<muduo/net/TcpServer.h>
#include<muduo/net/EventLoop.h>
using namespace std;
using namespace muduo;
using namespace muduo::net;

/*基于muduo网络库开发服务器程序
1组合TcpServer对象
2创建EventLoop事件循环对象的指针
3明确TcpServer构造函数需要什么参数,输出ChatServer的构造函数
4在当前服务器类的构造函数当中,注册处理连接的回调函数和处理读写事件的回调函数
5设置合适的服务端线程数量

*/

class ChatServer 
{
public:
    // 构造函数，初始化服务器，绑定连接回调和消息回调，设置工作线程数量
    ChatServer(EventLoop* loop, const InetAddress& listenAddr, const string &nameArg)   
        :loop_(loop),
        server_(loop, listenAddr, nameArg)
    {
        // 绑定连接建立和断开时的回调函数
        server_.setConnectionCallback(std::bind(&ChatServer::onConnection, this, std::placeholders::_1));
        // 绑定消息接收时的回调函数
        server_.setMessageCallback(std::bind(&ChatServer::onMessage, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
        // 设置服务器工作线程数量
        server_.setThreadNum(4);    
    }

    // 启动服务器
    void start()
    {
        server_.start();
    }
      
private:
    // 连接回调函数，打印连接信息并在连接断开时关闭连接
    void onConnection(const TcpConnectionPtr& conn)
    {
        if(conn->connected())
        {
            cout<<conn->peerAddress().toIpPort()<<"->"<<conn->localAddress().toIpPort()<<" state: online"<<endl;
        }
        else
        {
            cout<<conn->peerAddress().toIpPort()<<"->"<<conn->localAddress().toIpPort()<<" state: offline"<<endl;
            conn->shutdown();  //关闭连接
        }
    }

    // 消息回调函数，打印接收到的消息并将其回传
    void onMessage(const TcpConnectionPtr& conn, Buffer* buffer, Timestamp time)
    {
        string msg = buffer->retrieveAllAsString();
        cout<<"recv data: "<<msg<<" time: "<<time.toString()<<endl;
        conn->send(msg);  //回传消息
    }

    TcpServer server_;  // 服务器对象
    EventLoop *loop_;  // 事件循环对象   
};

int main()
{
    EventLoop loop;  // 创建事件循环
    InetAddress  addr(6000);  // 创建网络地址对象，监听端口6000
    ChatServer server(&loop,addr,"ChatServer");  // 创建服务器对象
    server.start();  // 启动服务器
    loop.loop();  // 启动事件循环
    return 0;
}
