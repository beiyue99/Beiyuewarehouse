#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>
int main()
{
	HWND hWnd /*���ھ�����൱�ڴ���ID*/ =FindWindow(L"MainWindow",L"ֲ���ս��ʬ���İ�");
	if (hWnd == NULL)
	{
		printf("ֲ���ս��ʬδ����");
		return 0;
	}
	unsigned int dwPID=0;
	GetWindowThreadProcessId(hWnd, &dwPID);//ͨ�����ھ����ȡPID
	if (dwPID == 0)
	{
		printf("��ȡ���̵�PIDʧ��,������ţ�%d\n",GetLastError());
		return 0;
	}
	printf("����Ϸ��PIDΪ��%d", dwPID);
	HANDLE hProcess=OpenProcess(PROCESS_ALL_ACCESS, FALSE,dwPID);   //����PID��ȡֲ���ս��ʬ���̾��
	if (hProcess == NULL)
	{
		printf("��ֲ���ս��ʬ����ʧ�ܣ�������룺%d\n", GetLastError());
		return 0;
	}


	unsigned long  dwSunshineBaseAddress = 0x6A9EC0;
	unsigned long dwSunshine = 0;
	unsigned long dwSize = 0;
	if (FALSE == ReadProcessMemory
	(
		hProcess,
		(void*)dwSunshineBaseAddress,
		&dwSunshine,
		sizeof(unsigned long),
		&dwSize
	))
	{
		printf("��ȡ��̬����ʧ�ܣ��������%d\n", GetLastError());
		return 0;
	}



	return 0;
} 