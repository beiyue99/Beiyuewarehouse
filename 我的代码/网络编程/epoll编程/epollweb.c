#include "stdio.h"
#include "wrap.h"
#define PORT 8080
#include<sys/epoll.h>
#include<fcntl.h>
#include<sys/stat.h>
#include"serverhttp.h"
#include<ctype.h>
#include<stdlib.h>
#include<dirent.h>
#include<signal.h>
//������Ϣͷ
void send_header(int cfd, int code, char* info,const  char* filetype,int length)//�ļ���������״̬�У�״̬��Ϣ
{
	//����״̬��
	char buf[1024] = "";
	int len = 0;
	len = sprintf(buf, "HTTP/1.1 %d %s\r\n", code, info);
	//send(cfd, buf, strlen(buf));��������0����ô�����׼ȷ����������len��¼����
	if (send(cfd, buf, len, 0) < 0)
	{
		perror("send header failed");
		return;
	}
	//������Ϣͷ
	len = sprintf(buf, "Content-Type:%s\r\n", filetype);
	if (send(cfd, buf, len, 0) < 0)
	{
		perror("send header failed");
		return;
	}
	if (length > 0)
	{
		len = sprintf(buf, "Content-Length:%d\r\n", length);
		if (send(cfd, buf, len, 0) < 0)
		{
			perror("send header failed");
			return;
		}
	}
	//����
	if (send(cfd, "\r\n", 2, 0) < 0)
	{
		perror("send header failed");
		return;
	}
}
	


//�����ļ�
//���ʹ��ļ�
//д������������, д����ȥ, д����ȥ����EPOLLOUT, 
//��û�з��͵����ݱ���, ��д�¼�����, д��ȥ
//���� send() ʱû�м�����Ƿ��Ѿ����������е����ݡ���һЩ����£�
//�������绺����������send() ���ܻᷢ�Ͳ�������Ȼ�󷵻ء�
//��� send() ֻ�����˲������ݣ���ô�ļ���һ���ֿ��ܾͶ�ʧ�ˡ�

//�� libevent �У�����ͨ�����ûص��������¼���ʵ���������
//��� send ������Ϊ���������������ܷ������ݣ����������һ�� EV_WRITE �¼���
//Ȼ������ݱ�����ĳ���ط�������ĳ������������������
//Ȼ���ڿ�д�¼��Ļص��������ٴγ��Է������ݡ�
void send_file(int cfd, char* path,struct epoll_event*ev,int epfd,int flag)
{
	int fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("open file failed");
		// �˴����ǿ����Ƴ����ӣ���Ϊ�޷������κ����ݸ��ͻ���
		epoll_ctl(epfd, EPOLL_CTL_DEL, cfd, ev);
		close(cfd);
		return;
	}
	char buf[1024] = "";
	int len = 0;
	while (1)
	{
		len = read(fd, buf, sizeof(buf));
		if (len < 0)
		{
			perror("read file failed");
			break;
		}
		else if (len == 0)
		{
			break;
		}
		else
		{
			int n = 0;
			//if (n=send(cfd, buf, len, 0) < 0)
			if ((n = send(cfd, buf, len, 0)) < 0)
			{
				perror("send file failed");
				break;
			}
			printf("len=%d\n", n);
			//�� Unix ϵͳ�У��ı��ļ�����ͨ����һ�����з� (\n) ����
		}
	}
	close(fd);
	//�ر�cfd������	
	if (flag == 1)
	{
		close(cfd);
		epoll_ctl(epfd, EPOLL_CTL_DEL, cfd, ev);
	}
}












void read_client_request(int epfd, struct epoll_event* ev,char*pwd_path)
{
	//��ȡ����(�ȶ�ȡһ���ڰ������ж�ȡ�ӵ�)
	char buf[1024] = "";
	char tmp[1024] = "";
	int n = Readline(ev->data.fd, buf, sizeof(buf));
	if (n <= 0)
	{
		printf("close or err\n");
		epoll_ctl(epfd, EPOLL_CTL_DEL, ev->data.fd, ev);
		close(ev->data.fd);
		return;
	}
	printf("%s\n", buf);
	int ret = 0;
	while ((ret = Readline(ev->data.fd, tmp, sizeof(tmp))) > 0);
	//printf("read ok\n");
	//��������
	//�ж��Ƿ�Ϊget����get����Ŵ���
	//�õ�����������ļ�.����Է�û�������ļ�
	//�����ڷ���error.html
	//����������GET / a.txt HTTP, / 1.1\RIN
	char method[256] = "";
	char content[256] = "";
	char protocol[256] = "";
	sscanf(buf, "%[^ ] %[^ ] %[^ \r\n]", method, content, protocol);
	//"%[^ ]"����˼�Ƕ�ȡһ�������ķǿո��ַ���ֱ��������һ���ո�Ϊֹ
	printf("[%s] [%s] [%s]\n", method, content, protocol);

	if (strcasecmp(method, "get") == 0)
	{
		char* strfile = content + 1;
		decodeMsg(strfile, strfile);
		//GET HTTP/1.1\R\N
		if (*strfile == 0) // ���û�������ļ�, Ĭ������ǰĿ¼
			strfile = "./";
			// �ж�������ļ��ڲ���
			struct stat s;
		//stat������C�����б�������ȡ�����ļ�����Ϣ
		if (stat(strfile, &s) < 0)  //������	 
		{
			printf("file not found\n");
			//ȷ�� error.html �ļ�������·��
			char errorFilePath[1024] = "";
			sprintf(errorFilePath, "%s/error.html", pwd_path);
			printf("Error file path: %s\n", errorFilePath);
			//�ȷ��ͱ�ͷ(״̬����Ϣͷ����)
			send_header(ev->data.fd, 404, "NOT FOUND", getFileType("*.html"), 0);
            //�����ļ�error.html 
			send_file(ev->data.fd, "error.html",ev,epfd,1);
		}
		else
		{
			if (S_ISREG(s.st_mode))
			{
				printf("file\n");
				//�ȷ��ͱ�ͷ(״̬����Ϣͷ����)
				send_header(ev->data.fd,200,"OK", getFileType(strfile),s.st_size);
                //�����ļ�
				send_file(ev->data.fd, strfile,ev,epfd,1);
			}
			else if (S_ISDIR(s.st_mode))
			{
				printf("dir\n");
				//����һ���б���ҳ
				send_header(ev->data.fd, 200, "OK", getFileType("*.html"), 0);
				send_file(ev->data.fd,"dir_header.html", ev, epfd,0);
				struct dirent** mylist = NULL;
				char buf[1024] = "";
				int len = 0;
				int n = scandir(strfile, &mylist, NULL, alphasort);
				for (int i = 0; i < n; i++)
				{
					//printf("%s\n", mylist[i]->d_name);
					if (mylist[i]->d_type == DT_DIR)
					{
						len = sprintf(buf, "<li><a href=%s/ >%s</a></li>", mylist[i]->d_name, mylist[i]->d_name);
					}
					else
					{
						len = sprintf(buf, "<li><a href=%s >%s</a></li>", mylist[i]->d_name, mylist[i]->d_name);
					}
					send(ev->data.fd,buf,len ,0);
					free(mylist[i]);
				}
				free(mylist);
				send_file(ev->data.fd, "dir_tail.html", ev, epfd, 1);
			}
		}
	}
}









int main(int argc, char const* argv[])
{
	signal(SIGPIPE, SIG_IGN);
	//�л�����Ŀ¼
	//��ȡ��ǰĿ¼�Ĺ���·��
	char pwd_path[256] = "";
	char *path = getenv("PWD");
	//����������޸���Ŀ¼���ٵ��� getenv("PWD")�������ܻ��᷵�ؾɵĹ���Ŀ¼
	//��������ĳ����Լ������� "PWD" ���������������������� getcwd()�����᷵����ȷ���¹���Ŀ¼ 
	strcpy(pwd_path, path);
	strcat(pwd_path, "/web-http");
	chdir(pwd_path);



	//�����׽��ְ�
	int lfd = tcp4bind(PORT, NULL);
	// ����
	Listen(lfd, 128);
	// ������
	int epfd = epoll_create(1);
	// lfd����
	struct epoll_event ev,evs[1024];
	ev.data.fd = lfd;
	ev.events = EPOLLIN;
	epoll_ctl(epfd, EPOLL_CTL_ADD, lfd, &ev);
	//ѭ������
	while (1)
	{
		int nready =  epoll_wait(epfd, evs, 1024, -1);
		if (nready == 0)
		{
			perror("");
			break;
		}
		else
		{
			for (int i = 0; i < nready; i++)
			{
				//�ж��Ƿ���Lfd
					if (evs[i].data.fd == lfd && evs[i].events & EPOLLIN)
					{
						struct sockaddr_in cliaddr;
						char ip[16] = "";
						socklen_t len = sizeof(cliaddr);
						int cfd = Accept(lfd, (struct sockaddr*)&cliaddr, &len);
						printf("new client ip=%s port=%d\n",
						inet_ntop(AF_INET, &cliaddr.sin_addr.s_addr, ip, 16),
						ntohs(cliaddr.sin_port));
						//����cfdΪ������
						int flag = fcntl(cfd, F_GETFL);
						flag |= O_NONBLOCK;
						fcntl(cfd, F_SETFL, flag);
						//����
						ev.data.fd = cfd;
						ev.events = EPOLLIN;
						epoll_ctl(epfd, EPOLL_CTL_ADD, cfd, &ev);
					}
					else if (evs[i].events & EPOLLIN)//cfd
					{
						read_client_request( epfd ,&evs[i],pwd_path);
					}
			}
		}
	}
	return 0;
}




//send_file ������һ��ѭ����������ȡ�ͷ����ļ����ݡ�����ʹ�õ��� send ϵͳ���ã�
//����һ��ͬ��������˵����������������ں����������������������ý���������
//ֱ�����㹻�Ŀռ����洢�µ����ݡ�Ȼ������� socket �Ǳ�����Ϊ�������ģ���������ں˻��������ˣ�send ����������һ������
//
//��� send_file ����û�д���������������Ե� send ���ش���ʱ����Ϳ����� 
//"send file failed: Resource temporarily unavailable" �Ĵ�����Ϣ��
//
//����Բ�ȡ�������ַ�ʽ֮һ�����������⣺
//
//��Ϊ����ģʽ��������ڷ����ļ�����֮ǰ�� socket ��������Ϊ����ģʽ��Ȼ���ڷ������ļ����ٰ������ûط�����ģʽ��
//
//��ȷ��������� send������ԸĽ���� send_file �����������ܹ���ȷ��������� send��
//��� send ����һ�������Ҵ����� EAGAIN �� EWOULDBLOCK���������ͣ�������ݣ�
//Ȼ��ȴ� socket ��д�¼���EPOLLOUT���ټ������͡���������������Ҫ��δ���͵����ݺ��ļ��������洢��ĳ����Ȼ���� socket ��дʱ�ټ������͡�
//
//
//
//
//���������������� HTTP �������ڳ�����ͻ��˷�������ʱ�������� "Resource temporarily unavailable" ����
//��ͨ����ζ����Ľ��̳��Խ�����һ���ᱻ������ϵͳ���ã��������ϵͳ��������ĳ��ԭ���޷�������ɡ�����Ĵ����У����ϵͳ������ send�������ڽ����ݴӷ��������͵��ͻ��ˡ�
//
//�������ͨ�����������������
//
//�ڷ�����ģʽ�£�������� send ���������ں˵������������������ô send �����᷵�ش��󣬲����ô�����Ϊ EAGAIN �� EWOULDBLOCK����������£���Ӧ���Ժ��ٴγ��Է������ݡ�
//
//������ģʽ�£���� send ���������֮ǰ���ź��жϣ���ô send ����Ҳ�᷵�ش��󣬲����ô�����Ϊ EINTR����������£�����������ٴγ��Է������ݡ�
//
//��ķ������ڷ��ʹ������ݣ����ļ����ݣ�ʱ�����ܻ����������ĵ�һ�������Ϊ�˽��������⣬����ԸĽ���� send_file ������
//�����ܹ���ȷ��������� send��������˵����� send ����һ�������Ҵ����� EAGAIN �� EWOULDBLOCK����ô��Ӧ����ͣ�������ݣ��ȴ� socket ��д��EPOLLOUT���ټ������͡�
//
//�������ͨ�������ӡ�����һ�г��֣����������Ϊ�������ڴ������ݷ��ͺ��״�������������������������Ҳ��������Ϊ send �����ڷ������һ��������ʱ�����˴���



//��Ĵ����ڷ����ļ�ʱû�д�����ܷ����ġ���Դ��ʱ�����ã�EAGAIN �� EWOULDBLOCK�����Ĵ��������������Ϊ���绺�������������㳢�Է���һ���ϴ���ļ�ʱ���ܿ��ܻ��������������
//�� send() �����޷�����������������ʱ�������ܻᷢ�Ͳ������ݲ������ѷ������ݵ���������Ĵ���û�м�����ֿ����ԣ����Ե� send() ����ֻ�����˲�������ʱ��ʣ������ݾͻᶪʧ��
//
//����������ķ������޸� send_file ������ʹ���ܹ��� send() ����ֻ���Ͳ�������ʱ��ȷ����������˵����� send() �������ص�ֵС���㳢�Է��͵���������
//��ô����Ҫ��ʣ������ݱ���������Ȼ�����Ժ��ٴγ��Է��͡�
//
//���⣬����Ҫ���� socket Ϊ������ģʽ������ epoll ��ע�� EPOLLOUT �¼����������� socket ���Է��͸�������ʱ����Ϳ����յ�һ��֪ͨ��
//
//����Ҫע�⣬��Ĵ����ڶ�ȡ�ͷ����ļ�ʱʹ����ͬһ��������������ܻᵼ���ڳ��Է���ʣ������ʱ�����˲������ݡ�
//��Ӧ��ʹ�����������Ļ�������һ�����ڶ�ȡ�ļ�����һ�����ڴ洢��δ���͵����ݡ�
//
//�����Ĵ����ڴ��� HTTP ����ʱû����ȷ����ֿ鴫����루Chunked transfer encoding����
//���� HTTP / 1.1 �е�һ�ֹ��ܣ�����������ڿ�ʼ������Ӧ֮ǰ����Ҫ֪����Ӧ���ܳ��ȡ�����ڷ��ʹ��ļ�������������Ҫ�ܳ�ʱ�����Ӧ�ǳ����á�
//��Ӧ�ü�� HTTP ����� "Transfer-Encoding" ͷ�����������ֵ�� "chunked"����ô����Ҫʹ�÷ֿ鴫�������������Ӧ��



//���ʹ�� libevent�����ʹ���¼��ص��ͻ����¼���bufferevent������д���ݣ�����ζ�� libevent ����㴦�����绺�������������
//�㲻��Ҫֱ�Ӵ��� send() �� recv() ϵͳ���á�һ������������ݵ� libevent �������������libevent �ͻᴦ��ʵ�ʵķ��Ͳ���������������д��������
//
//���⣬libevent ֧�ַ����� IO ��ˮƽ������level - triggered��ģʽ�������㲻��Ҫ�ֶ����³��Զ�д������
//
//Ȼ������ʹʹ���� libevent������Ȼ��Ҫ���� HTTP �ֿ鴫���������⡣libevent ������ HTTP Э��ľ��崦������Ҫ�Լ����� HTTP �������Ӧ����������ֿ鴫����롣