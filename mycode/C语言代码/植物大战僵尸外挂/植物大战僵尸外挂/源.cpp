#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>
int main()
{
	HWND hh /*���ھ�����൱�ڴ���ID*/ = FindWindow(L"MainWindow", L"Plants vs. Zombies GOTY ");
	if (hh == NULL)
	{
		printf("ֲ���ս��ʬδ����");
		return 0;
	}
	unsigned long  dwPID = 0;
	GetWindowThreadProcessId(hh, &dwPID);      //ͨ�����ھ����ȡPID
	if (dwPID == 0)
	{
		printf("��ȡ���̵�PIDʧ��,������ţ�%d\n", GetLastError());
		return 0;
	}
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPID);   //����PID��ȡֲ���ս��ʬ���̾��
	if (hProcess == NULL)
	{
		printf("��ֲ���ս��ʬ����ʧ�ܣ�������룺%d\n", GetLastError());
		return 0;
	}


	int dwSunshineBaseAddress = 0x77959C;   //�������ַ
	int dwSunshineAddressValue = 0;           
	if (FALSE == ReadProcessMemory
	(
		hProcess,                                   //���̾��
		(void*)dwSunshineBaseAddress,                //��ȡ���ݵ���ʼ��ַ
		&dwSunshineAddressValue,                    //������ݵĵ�ַ
		sizeof(int),                      //��ȡ�ֽ���
		NULL                                    //ʵ�ʶ�ȡ�ֽ���
	))											
	{											
		printf("��ȡ��̬����ʧ�ܣ��������%d\n", GetLastError());
		return 0;
	}


	int dwSunshineFirstOffsetAddress = 0x868;
	int dwSunshineOffsetFirstValue = 0;
	if (FALSE == ReadProcessMemory
	(
		hProcess,                                                                        //���̾��
		(void*)(dwSunshineAddressValue + dwSunshineFirstOffsetAddress),			      //��ȡ���ݵ���ʼ��ַ
		&dwSunshineOffsetFirstValue,                                    			     //������ݵĻ�������ַ
		sizeof(int),                                          			     //��ȡ�ֽ���
		NULL                                                            			 //ʵ�ʶ�ȡ�ֽ���
	))
	{
		printf("һ��ƫ�Ƶ�ַ��ȡʧ�ܣ�������ţ�%d\n", GetLastError());
		return 0;
	}



	int dwSunshineOffsetSecondAddress = 0x5578;
	int dwSunshine = 0;
	if (FALSE == ReadProcessMemory
	(
		hProcess,                                                                        //���̾��
		(void*)(dwSunshineOffsetFirstValue + dwSunshineOffsetSecondAddress),             //��ȡ���ݵ���ʼ��ַ
		&dwSunshine,                                                                     //������ݵĻ�������ַ
		sizeof(int),                                                           //��ȡ�ֽ���
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
		(void*)(dwSunshineOffsetFirstValue + dwSunshineOffsetSecondAddress),
		&newSunshine,
		sizeof(int),
		NULL
	))
	{
		printf("�޸�����ֵʧ�ܣ�������ţ�%d\n", GetLastError());
		return 0;
	}
	printf("����ֵ�޸ĳɹ���");
	return 0;
}
