#include "connection.h"
#include "boost/asio.hpp"
#include <iostream>
#include "session.h"
using namespace std;
using namespace boost;

int accept_new_connection(){
	// 服务器端等待连接的队列大小
	const int BACKLOG_SIZE = 30;

	unsigned short port_num = 3333;

	asio::ip::tcp::endpoint ep(asio::ip::address_v4::any(),
		port_num);

	asio::io_context  ios;

	try {
		asio::ip::tcp::acceptor acceptor(ios, ep.protocol());

		acceptor.bind(ep);

		acceptor.listen(BACKLOG_SIZE);

		asio::ip::tcp::socket sock(ios);

		acceptor.accept(sock);
        return 0;

	}
	catch (system::system_error& e) {
		std::cout << "Error occured! Error code = " << e.code()
			<< ". Message: " << e.what();

		return e.code().value();
	}
}




void use_buffer_array(){
	 const size_t  BUF_SIZE_BYTES = 20;
	std::unique_ptr<char[] > buf(new char[BUF_SIZE_BYTES]);
	auto input_buf = asio::buffer(static_cast<void*>(buf.get()), BUF_SIZE_BYTES);
	//buf.get() 时，你获得了一个普通指针
}

void use_const_buffer() {
	std::string buf = "hello world!";
	asio::const_buffer  asio_buf(buf.c_str(), buf.length());
	//asio::const_buffer 有两个参数：指向数据的指针和数据的长度
	std::vector<asio::const_buffer> buffers_sequence;
	buffers_sequence.push_back(asio_buf);
}


void use_buffer_str() {
	asio::const_buffers_1 output_buf = asio::buffer("hello world");
	//asio::const_buffers_1 代表一个常量数据缓冲区序列，它由一个或多个 asio::const_buffer 组成。
	//asio::const_buffers_1 只有一个参数，它是一个指向 asio::const_buffer 对象的迭代器。
	/*std::vector<asio::const_buffer> buffers;
	buffers.push_back(asio::const_buffer(data1, length1));
	buffers.push_back(asio::const_buffer(data2, length2));
	asio::const_buffers_1 buffer_sequence(buffers.begin(), buffers.end());*/

}

void use_stream_buffer() {
	asio::streambuf buf;
	std::ostream output(&buf);
	output << "Message1\nMessage2";
	std::istream input(&buf);
	//文本内容 "Message1\nMessage2" 写入到 asio::streambuf 缓冲区对象 buf ,由换行符 "\n" 分隔。
	std::string message1;
	std::getline(input, message1);	// Now message1 string contains 'Message1'.
	//getline函数会读取一行文本，因此它会读取第一条消息"Message1"，并将其存储在message1中。
}

void  wirte_to_socket(asio::ip::tcp::socket& sock) {
	std::string buf = "Hello World!";
	std::size_t  total_bytes_written = 0;
	//循环发送
	//write_some返回每次写入的字节数
	//total_bytes_written是已经发送的字节数。
	//每次发送buf.length()- total_bytes_written)字节数据
	
	while (total_bytes_written != buf.length()) {
		total_bytes_written += sock.write_some(
			asio::buffer(buf.c_str()+total_bytes_written, 
				buf.length()- total_bytes_written));
		//写入的位置，和要写入的长度
	}
}

int send_data_by_write_some() {
	std::string raw_ip_address = "127.0.0.1";
	unsigned short port_num = 3333;

	try {
		asio::ip::tcp::endpoint
			ep(asio::ip::address::from_string(raw_ip_address),
				port_num);

		asio::io_service ios;

		asio::ip::tcp::socket sock(ios, ep.protocol());

		sock.connect(ep);

		wirte_to_socket(sock);
	}
	catch (system::system_error& e) {
		std::cout << "Error occured! Error code = " << e.code()
			<< ". Message: " << e.what();

		return e.code().value();
	}
	return 0;
}

int send_data_by_send(){
	std::string raw_ip_address = "127.0.0.1";
	unsigned short port_num = 3333;

	try {
		asio::ip::tcp::endpoint
			ep(asio::ip::address::from_string(raw_ip_address),
				port_num);

		asio::io_service ios;

		asio::ip::tcp::socket sock(ios, ep.protocol());

		sock.connect(ep);
		std::string buf = "Hello World!";
		int send_length = sock.send(asio::buffer(buf.c_str(), buf.length()));
		if (send_length <= 0) {
			cout << "send failed" << endl;
			return 0;
		}
	}
	catch (system::system_error& e) {
		std::cout << "Error occured! Error code = " << e.code()
			<< ". Message: " << e.what();

		return e.code().value();
	}
	return 0;
}

int send_data_by_wirte() {
	std::string raw_ip_address = "127.0.0.1";
	unsigned short port_num = 3333;

	try {
		asio::ip::tcp::endpoint
			ep(asio::ip::address::from_string(raw_ip_address),
				port_num);

		asio::io_service ios;

		asio::ip::tcp::socket sock(ios, ep.protocol());

		sock.connect(ep);
		std::string buf = "Hello World!";
		int send_length  = asio::write(sock, asio::buffer(buf.c_str(), buf.length()));
		if (send_length <= 0) {
			cout << "send failed" << endl;
			return 0;
		}
	}
	catch (system::system_error& e) {
		std::cout << "Error occured! Error code = " << e.code()
			<< ". Message: " << e.what();

		return e.code().value();
	}
	return 0;
 }

std::string read_from_socket(asio::ip::tcp::socket& sock) {
	const unsigned char MESSAGE_SIZE = 7;
	char buf[MESSAGE_SIZE];
	std::size_t total_bytes_read = 0;

	while (total_bytes_read != MESSAGE_SIZE) {
		total_bytes_read += sock.read_some(
			asio::buffer(buf + total_bytes_read,
				MESSAGE_SIZE - total_bytes_read));
	}

	return std::string(buf, total_bytes_read);
}


int read_data_by_read_some() {
	std::string raw_ip_address = "127.0.0.1";
	unsigned short port_num = 3333;

	try {
		asio::ip::tcp::endpoint
			ep(asio::ip::address::from_string(raw_ip_address),
				port_num);

		asio::io_service ios;

		asio::ip::tcp::socket sock(ios, ep.protocol());

		sock.connect(ep);

		read_from_socket(sock);
	}
	catch (system::system_error& e) {
		std::cout << "Error occured! Error code = " << e.code()
			<< ". Message: " << e.what();

		return e.code().value();
	}

	return 0;
}

int read_data_by_receive() {
	std::string raw_ip_address = "127.0.0.1";
	unsigned short port_num = 3333;

	try {
		asio::ip::tcp::endpoint
			ep(asio::ip::address::from_string(raw_ip_address),
				port_num);

		asio::io_service ios;

		asio::ip::tcp::socket sock(ios, ep.protocol());

		sock.connect(ep);
		const unsigned char BUFF_SIZE = 7;
		 char buffer_receive[BUFF_SIZE];
		int receive_length =  sock.receive(asio::buffer(buffer_receive, BUFF_SIZE));
		if (receive_length <= 0) {
			cout << "receive failed" << endl;
		}
	}
	catch (system::system_error& e) {
		std::cout << "Error occured! Error code = " << e.code()
			<< ". Message: " << e.what();

		return e.code().value();
	}
	return 0;
}

int read_data_by_read() {
	std::string raw_ip_address = "127.0.0.1";
	unsigned short port_num = 3333;

	try {
		asio::ip::tcp::endpoint
			ep(asio::ip::address::from_string(raw_ip_address),
				port_num);

		asio::io_service ios;

		asio::ip::tcp::socket sock(ios, ep.protocol());

		sock.connect(ep);
		const unsigned char BUFF_SIZE = 7;
		char buffer_read[BUFF_SIZE];
		int receive_length = asio::read(sock, asio::buffer(buffer_read, BUFF_SIZE));
		if (receive_length <= 0) {
			cout << "receive failed" << endl;
		}
	}
	catch (system::system_error& e) {
		std::cout << "Error occured! Error code = " << e.code()
			<< ". Message: " << e.what();

		return e.code().value();
	}

	return 0;
 }

std::string  read_data_by_until(asio::ip::tcp::socket& sock) {
	asio::streambuf buf;

	asio::read_until(sock, buf, '\n');
	//类streambuf提供了一个可变大小的缓冲区，可以在其中读取和写入数据	
	std::string message;


	std::istream input_stream(&buf);
	std::getline(input_stream, message);
	return message;
 }


int async_write_data() {
	std::string raw_ip_address = "127.0.0.1";
	unsigned short port_num = 3333;
	try {
		asio::ip::tcp::endpoint ep(asio::ip::address::from_string(raw_ip_address), port_num);
		asio::io_context  iox;
		auto socket_ptr = std::make_shared<asio::ip::tcp::socket>(iox, ep.protocol());
		auto session_ptr = std::make_shared<Session>(socket_ptr);
		session_ptr->Connect(ep);
		session_ptr->WriteToSocket("Hello world");
		iox.run();
	}
	catch (system::system_error& e) {
		std::cout << "Error occured! Error code = " << e.code() << " . Message: " << e.what();
		return e.code().value();
	}

	return 0;
}

