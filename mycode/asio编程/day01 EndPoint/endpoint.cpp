#include "endpoint.h"
using namespace boost;
int  client_end_point() {
	std::string raw_ip_address = "127.0.0.1";
	unsigned short port_num = 3333;

	boost::system::error_code ec;
	//����2.ʹ��IPЭ��汾�޹ص�ַ����
	asio::ip::address ip_address =
		asio::ip::address::from_string(raw_ip_address, ec);

	if (ec.value() != 0) {
		// �ṩ��IP��ַ��Ч��ͻ����ִ�С�
		std::cout
			<< "Failed to parse the IP address. Error code = "
			<< ec.value() << ". Message: " << ec.message();
		return ec.value();
	}

	// Step 3.���캯��
	asio::ip::tcp::endpoint ep(ip_address, port_num);

	///����4.�˵���׼��������������ָ���ͻ�����Ҫ�������е��ض��������뽻����

	return 0;
}

int  server_end_point(){
	// ����1.�������Ǽ��������Ӧ�ó����ѻ��Э��˿ںš�
	unsigned short port_num = 3333;

	// ����2.����asio:ip:address����������
		// ָ�����������п��õ�IP��ַ��
		// �������Ǽ��������ͨ��IPv6Э�鹤����
	asio::ip::address ip_address = asio::ip::address_v6::any();

	// Step 3.
	asio::ip::tcp::endpoint ep(ip_address, port_num);

	//����4.�˵��Ѵ�����������
		// ָ��IP��ַ�Ͷ˿ں�
		// ������Ӧ�ó�����Ҫ�����������ӡ�
	return 0;
}

int create_tcp_socket() {
	// ����1.��io_service�����ʵ�����׽��ֹ��캯����
	asio::io_context  ios;

	// ����2.����tcp��Ķ����ʾTCPЭ��IPv4��Ϊ�ײ�Э�顣
	asio::ip::tcp protocol = asio::ip::tcp::v4();

	// Step 3. ����ʵ�������TCP�׽��ֶ���
	asio::ip::tcp::socket sock(ios);

	boost::system::error_code ec;
	//��socket��
	sock.open(protocol, ec);

	if (ec.value() != 0) {
		std::cout
			<< "Failed to open the socket! Error code = "
			<< ec.value() << ". Message: " << ec.message();
		return ec.value();
	}
	return 0;
}


//����һ��TCP�������׽���
int  create_acceptor_socket() { 
	// ����1.��io_service�����ʵ�����׽��ֹ��캯����
	asio::io_context ios;

#if 0
	// Step 2. /����2.����tcp'��Ķ����ʾ��IPv6Ϊ�ײ�Э���TCPЭ�顣
	asio::ip::tcp protocol = asio::ip::tcp::v6();

	// Step 3.ʵ�����������׽��ֶ���
	asio::ip::tcp::acceptor acceptor(ios);

	//���ڴ洢�йط����Ĵ������Ϣ,ͬʱ�򿪽������׼��֡�
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

	///����1.�������Ǽ��������Ӧ�ó����ѻ��Э��˿ںš�
	unsigned short port_num = 3333;

	// Step 2.���ڴ����ս�㡣
	asio::ip::tcp::endpoint ep(asio::ip::address_v4::any(),
		port_num);

	// �ɽ����ߵ��๹�캯��ʹ�á�
	asio::io_context  ios;

	// Step 3.�����ʹ򿪽������׽��֡�
	asio::ip::tcp::acceptor acceptor(ios, ep.protocol());

	boost::system::error_code ec;

	// Step 4. Binding the acceptor socket.
	acceptor.bind(ep, ec);

	//  ����������У���
	if (ec.value() != 0) {
		std::cout << "Failed to bind the acceptor socket."
			<< "Error code = " << ec.value() << ". Message: "
			<< ec.message();

		return ec.value();
	}
	return 0;
}

int  connect_to_end() {
	// Step 1. //����1.����ͻ���Ӧ�ó����Ѿ����IP��ַ��ip��Э��˿ں�Ŀ���������
	std::string raw_ip_address = "127.0.0.1";
	unsigned short port_num = 3333;

	try {
		// Step 2. /����2.����ָ��Ŀ�������Ӧ�ó���
		asio::ip::tcp::endpoint
			ep(asio::ip::address::from_string(raw_ip_address),
				port_num);

		asio::io_context ios;

		// Step 3. �����ʹ��׽��֡�
		asio::ip::tcp::socket sock(ios, ep.protocol());

		// Step 4. �����׼��֡�
		sock.connect(ep);

		// /��ʱsocket���������ӵ�������Ӧ�ó��򣬲��ҿ���ʹ�����䷢�����ݻ����������ݡ�
	}
	// �ڴ˴�ʹ��throw��������µ��쳣��
	catch (system::system_error& e) {
		std::cout << "Error occured! Error code = " << e.code()
			<< ". Message: " << e.what();

		return e.code().value();
	}
    return 0;
}

int dns_connect_to_end() {
	// Step1. /����1.����ͻ���Ӧ�ó����Ѿ����DNS���ƺ�Э��˿ںŽ����Ǳ�ʾΪ�ַ�����
	std::string host = "samplehost.book";
	std::string port_num = "3333";

	// �ɡ����������͡��׽��֡�ʹ�á�
	asio::io_context  ios;

	// ���ڴ�����������Ĳ�ѯ��
	asio::ip::tcp::resolver::query resolver_query(host, port_num,
		asio::ip::tcp::resolver::query::numeric_service);

	// ���ڴ�����ͻ�������
	asio::ip::tcp::resolver resolver(ios);

	try {
		// Step 2.���ڽ���DNS���ơ�
		asio::ip::tcp::resolver::iterator it =
			resolver.resolve(resolver_query);

		// Step 3. Creating a socket.
		asio::ip::tcp::socket sock(ios);

		// Step 4. asio:connect������������ÿ���˵㣬ֱ���ɹ����ӵ�һ��
		//�����е�һ�������ʧ�ܣ������׳��쳣���ӵ����ж˵㣬��������������ִ���
		asio::connect(sock, it);

		// ��ʱsocket���ӵ�������Ӧ�ó��򣬲��ҿ���ʹ�����䷢�����ݻ����������ݡ�
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
