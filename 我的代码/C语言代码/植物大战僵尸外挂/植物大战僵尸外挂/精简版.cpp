#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>
int main()
{
	HWND hh /*���ھ�����൱�ڴ���ID*/ = FindWindow(L"MainWindow", L"ֲ���ս��ʬ���İ�");
	
	unsigned long int dwPID = 0;
	GetWindowThreadProcessId(hh, &dwPID);      //ͨ�����ھ����ȡPID

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPID);   //����PID��ȡֲ���ս��ʬ���̾��


	unsigned long dwSunshineBaseAddress = 0x6AA00C;
	unsigned long dwSunshineAddressValue = 0;
	if (FALSE == ReadProcessMemory
	(
		hProcess,                                    //���̾��
		(void*)dwSunshineBaseAddress,               //����ַ
		&dwSunshineAddressValue,                     //����
		sizeof(unsigned long),                       //��ȡ�ֽ���
		NULL                                    //ʵ�ʶ�ȡ�ֽ���
	))
	{
		printf("��ȡ��̬����ʧ�ܣ��������%d\n", GetLastError());
		return 0;
	}
	unsigned long dwSunshineOffsetValue = 0x768;
	unsigned long dwSunshineOffsetFirstValue = 0;


	unsigned long dwSunshineOffsetSecondValue = 0x5560;
	unsigned long dwSunshine = 0;
	if (FALSE == ReadProcessMemory
	(
		hProcess,                                                                        //���̾��
		(LPVOID)(dwSunshineOffsetFirstValue + dwSunshineOffsetSecondValue),              //����ַ
		&dwSunshine,                                                                     //����
		sizeof(unsigned long),                                                           //��ȡ�ֽ���
		NULL                                                                         //ʵ�ʶ�ȡ�ֽ���
	))
	{
		printf("��ȡ����ֵʧ�ܣ�������ţ�%d\n", GetLastError());
		return 0;
	}
	printf("��ʱ������%d", dwSunshine);

	int newSunshine = 0;
	printf("\n������Ҫ�޸ĵ�����ֵ��");
	scanf("%d", &newSunshine);
	if (FALSE == WriteProcessMemory
	(
		hProcess,
		(LPVOID)(dwSunshineOffsetFirstValue + dwSunshineOffsetSecondValue),
		&newSunshine,
		sizeof(unsigned long),
		NULL
	))
	{
		printf("�޸�����ֵʧ�ܣ�������ţ�%d\n", GetLastError());
		return 0;
	}
	printf("����ֵ�޸ĳɹ���");
	return 0;
}