

#include <sys/select.h>
struct timeval {
	time_t tv_sec;             // seconds *
	suseconds_t tv_usec;   // microseconds*
};
int select(int nfds, fd_set* readfds, fd_set* writefds,
	fd_set* exceptfds, struct timeval* timeout);
//����ֵ�Ǽ�⵽�����������������ļ��������ĸ���


nfds:ί���ں˼��������������������ļ������� + 1  //���1024    ��Window�������������Ч��, ָ��Ϊ - 1����

readfds : ���������������绻��56789  ��5��6���������ݣ���ô����5��6
writefds : ���д�����������绻��78910  ��78910��д����ô����78910
exceptfds: ���û���쳣������NULL��





void FD_CLR(int fd, fd_set * set);// ���ļ�������fd��set������ɾ�� = ��fd��Ӧ�ı�־λ����Ϊ0

int FD_ISSET(int fd, fd_se * set); // �ж��ļ�������fd�Ƿ���set������ = ��fd��Ӧ�ı�־λ������0����1

void FD_SET(int fd, fd_set* set);//���ļ�������fd��ӵ�set������==��fd��Ӧ�ı�־λ����Ϊ1

void FD_ZERO(fd_set* set);// ��set������, �����ļ��ļ���������Ӧ�ı�־λ����Ϊ0, ������û������κ��ļ�������




//���Ա�ÿ��λ�ö�Ӧһ���ļ���������Ĭ��ÿ����־λΪ0������������Ա��ϣ��ͻ�Ѹñ�־λ����Ϊ1
//�����ֲ�������ļ����������ں˻������޸ĸñ�־λΪ0��Ȼ��ͨ��isset�������Ա����������������ļ�������


