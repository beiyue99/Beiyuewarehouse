#include "endpoint.h"
using namespace boost;
int  client_end_point() {
	std::string raw_ip_address = "127.0.0.1";
	unsigned short port_num = 3333;

	boost::system::error_code ec;
	//步骤2.使用IP协议版本无关地址代表。
	asio::ip::address ip_address =
		asio::ip::address::from_string(raw_ip_address, ec);

	if (ec.value() != 0) {
		// 提供的IP地址无效。突破性执行。
		std::cout
			<< "Failed to parse the IP address. Error code = "
			<< ec.value() << ". Message: " << ec.message();
		return ec.value();
	}

	// Step 3.构造函数
	asio::ip::tcp::endpoint ep(ip_address, port_num);

	///步骤4.端点已准备就绪，可用于指定客户端想要的网络中的特定服务器与交流。

	return 0;
}

int  server_end_point(){
	// 步骤1.这里我们假设服务器应用程序已获得协议端口号。
	unsigned short port_num = 3333;

	// 步骤2.创建asio:ip:address类的特殊对象
		// 指定主机上所有可用的IP地址。
		// 这里我们假设服务器通过IPv6协议工作。
	asio::ip::address ip_address = asio::ip::address_v6::any();

	// Step 3.
	asio::ip::tcp::endpoint ep(ip_address, port_num);

	//步骤4.端点已创建，可用于
		// 指定IP地址和端口号
		// 服务器应用程序想要侦听传入连接。
	return 0;
}

int create_tcp_socket() {
	// 步骤1.“io_service”类的实例是套接字构造函数。
	asio::io_context  ios;

	// 步骤2.创建tcp类的对象表示TCP协议IPv4作为底层协议。
	asio::ip::tcp protocol = asio::ip::tcp::v4();

	// Step 3. 正在实例化活动的TCP套接字对象。
	asio::ip::tcp::socket sock(ios);

	boost::system::error_code ec;
	//打开socket。
	sock.open(protocol, ec);

	if (ec.value() != 0) {
		std::cout
			<< "Failed to open the socket! Error code = "
			<< ec.value() << ". Message: " << ec.message();
		return ec.value();
	}
	return 0;
}


//创建一个TCP接收器套接字
int  create_acceptor_socket() { 
	// 步骤1.“io_service”类的实例是套接字构造函数。
	asio::io_context ios;

#if 0
	// Step 2. /步骤2.创建tcp'类的对象表示以IPv6为底层协议的TCP协议。
	asio::ip::tcp protocol = asio::ip::tcp::v6();

	// Step 3.实例化接收器套接字对象。
	asio::ip::tcp::acceptor acceptor(ios);

	//用于存储有关发生的错误的信息,同时打开接收器套间字。
	boost::system::error_code ec;
	acceptor.open(protocol, ec); 

	if (ec.value() != 0) {
		std::cout
			<< "Failed to open the acceptor socket!"
			<< "Error code = "
			<< ec.value() << ". Message: " << ec.message();
		return ec.value();
	}
#else
    asio::ip::tcp::acceptor a(ios, asio::ip::tcp::endpoint (asio::ip::tcp::v4(), 3333));
#endif
	return 0;
	
}


int  bind_acceptor_socket() {

	///步骤1.这里我们假设服务器应用程序已获得协议端口号。
	unsigned short port_num = 3333;

	// Step 2.正在创建终结点。
	asio::ip::tcp::endpoint ep(asio::ip::address_v4::any(),
		port_num);

	// 由接受者的类构造函数使用。
	asio::io_context  ios;

	// Step 3.创建和打开接收器套接字。
	asio::ip::tcp::acceptor acceptor(ios, ep.protocol());

	boost::system::error_code ec;

	// Step 4. Binding the acceptor socket.
	acceptor.bind(ep, ec);

	//  处理错误（如有）。
	if (ec.value() != 0) {
		std::cout << "Failed to bind the acceptor socket."
			<< "Error code = " << ec.value() << ". Message: "
			<< ec.message();

		return ec.value();
	}
	return 0;
}

int  connect_to_end() {
	// Step 1. //步骤1.假设客户端应用程序已经获得IP地址和ip的协议端口号目标服务器。
	std::string raw_ip_address = "127.0.0.1";
	unsigned short port_num = 3333;

	try {
		// Step 2. /步骤2.创建指定目标服务器应用程序。
		asio::ip::tcp::endpoint
			ep(asio::ip::address::from_string(raw_ip_address),
				port_num);

		asio::io_context ios;

		// Step 3. 创建和打开套接字。
		asio::ip::tcp::socket sock(ios, ep.protocol());

		// Step 4. 连接套间字。
		sock.connect(ep);

		// /此时socket“锁”连接到服务器应用程序，并且可以使用向其发送数据或从其接收数据。
	}
	// 在此处使用throw错误情况下的异常。
	catch (system::system_error& e) {
		std::cout << "Error occured! Error code = " << e.code()
			<< ". Message: " << e.what();

		return e.code().value();
	}
    return 0;
}

int dns_connect_to_end() {
	// Step1. /步骤1.假设客户端应用程序已经获得DNS名称和协议端口号将它们表示为字符串。
	std::string host = "samplehost.book";
	std::string port_num = "3333";

	// 由“解析器”和“套接字”使用。
	asio::io_context  ios;

	// 正在创建解析程序的查询。
	asio::ip::tcp::resolver::query resolver_query(host, port_num,
		asio::ip::tcp::resolver::query::numeric_service);

	// 正在创建冲突解决程序。
	asio::ip::tcp::resolver resolver(ios);

	try {
		// Step 2.正在解析DNS名称。
		asio::ip::tcp::resolver::iterator it =
			resolver.resolve(resolver_query);

		// Step 3. Creating a socket.
		asio::ip::tcp::socket sock(ios);

		// Step 4. asio:connect（）方法迭代每个端点，直到成功连接到一个
		//他们中的一个。如果失败，它将抛出异常连接到所有端点，或者如果其他出现错误。
		asio::connect(sock, it);

		// 此时socket连接到服务器应用程序，并且可以使用向其发送数据或从其接收数据。
	}
	catch (system::system_error& e) {
		std::cout << "Error occured! Error code = " << e.code()
			<< ". Message: " << e.what();

		return e.code().value();
	}
	return 0;
}

int accept_new_connection()
{
	const int BACKLOG_SIZE = 30;
	unsigned short port_num = 3333;
	asio::ip::tcp::endpoint ep(asio::ip::address_v4::any(), port_num);
	asio::io_context ios;
	try {
		asio::ip::tcp::acceptor acceptor(ios, ep.protocol());
		acceptor.bind(ep);
		acceptor.listen(BACKLOG_SIZE);
		asio::ip::tcp::socket sock(ios);
		acceptor.accept(sock);
	}
	catch (system::system_error& e) {
		std::cout << "Error occured! Error code = " << e.code()
			<< ". Message: " << e.what();

		return e.code().value();
	}
	return 0;
}
