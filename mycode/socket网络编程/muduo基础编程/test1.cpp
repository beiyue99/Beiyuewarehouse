#include<iostream>
#include<muduo/net/TcpServer.h>
#include<muduo/net/EventLoop.h>
#include<iostream>
#include<functional>
using namespace std;
using namespace muduo;
using namespace muduo::net;
using namespace placeholders;

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
    ChatServer(EventLoop* loop,//事件循环
    const InetAddress& listenAddr,//监听地址
    const string &nameArg)   //服务器名字
        :loop_(loop),
        server_(loop,listenAddr,nameArg)
        {
            //给服务器注册用户连接的创建和断开回调
            server_.setConnectionCallback(std::bind(&ChatServer::onConnection,this,_1));
            //给服务器注册用户读写事件回调
            server_.setMessageCallback(std::bind(&ChatServer::onMessage,this,_1,_2,_3));
                //设置服务器端的线程数量
            server_.setThreadNum(4);    //一个i/o线程，三个work线程
            //启动服务器(事件循环)
            void start()
            {
                server_.start();
            }
          
        }
    
    private:
    //专门处理用户的连接创建和断开epoll listenfd accept
    void onConnection(const tcpConnectionPtr&conn)
    {
        if(conn->connected())
        {
            cout<<conn->peerAddress().toIpPort()<<"->"<<conn->localAddress().toIpPort()<<"satee:online"<<endl;
        }
        else
        {
            cout<<conn->peerAddress().toIpPort()<<"->"<<conn->localAddress().toIpPort()<<"satee:offline"<<endl;
            conn->shutdown();  //close(fd);
            //loop_->quit();  //服务器退出
        }
    }
    //专门处理用户的读写事件
    void onMessage(const tcpConnectionPtr& conn,//  连接
    Buffer* buf,  //缓冲区
    Timestamp time //接收到数据的时间信息)
    {
        string buf=buffer->retrieveAsString();
        cout<<"recv date: "<<buf<<"time: "<<time.toString()<<endl;
        conn->send(buf);
    }
    TcpServer server_;  
    EventLoop *loop_;    
}

int main()
{
    EventLoop loop;  //epoll
    InetAddress  addr("127.0.0.1",6000);
    ChatServer server(&loop,addr,"ChatServer");
    chatServer.start();
    loop.loop();   // epoll_wait以阻塞方式等待新用户连接，已连接用户的读写事件
    return 0;
}