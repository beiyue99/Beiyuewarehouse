//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<Windows.h>
//int main()
//{
//	HWND hh /*���ھ�����൱�ڴ���ID*/ = FindWindow(L"MainWindow", L"ֲ���ս��ʬ���İ�");
//	
//	unsigned long  dwPID = 0;
//	GetWindowThreadProcessId(hh, &dwPID);      //ͨ�����ھ����ȡPID
//	
//	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPID);   //����PID��ȡֲ���ս��ʬ���̾��
//
//
//	int dwSunshineBaseAddress = 0x77959C;   //�������ַ
//	int dwSunshineAddressValue = 0;
//	ReadProcessMemory
//	(
//		hProcess,                                   //���̾��
//		(void*)dwSunshineBaseAddress,                //��ȡ���ݵ���ʼ��ַ
//		&dwSunshineAddressValue,                    //������ݵĵ�ַ
//		sizeof(int),                      //��ȡ�ֽ���
//		NULL                                    //ʵ�ʶ�ȡ�ֽ���
//	);
//
//
//	int dwSunshineFirstOffsetAddress = 0x868;
//	int dwSunshineOffsetFirstValue = 0;
//	ReadProcessMemory
//	(
//		hProcess,                                                                        //���̾��
//		(void*)(dwSunshineAddressValue + dwSunshineFirstOffsetAddress),			      //��ȡ���ݵ���ʼ��ַ
//		&dwSunshineOffsetFirstValue,                                    			     //������ݵĻ�������ַ
//		sizeof(int),                                          			     //��ȡ�ֽ���
//		NULL                                                            			 //ʵ�ʶ�ȡ�ֽ���
//	);
//	
//
//
//
//	int dwSunshineOffsetSecondAddress = 0x5578;
//	int dwSunshine = 0;
//	ReadProcessMemory
//	(
//		hProcess,                                                                        //���̾��
//		(void*)(dwSunshineOffsetFirstValue + dwSunshineOffsetSecondAddress),             //��ȡ���ݵ���ʼ��ַ
//		&dwSunshine,                                                                     //������ݵĻ�������ַ
//		sizeof(int),                                                           //��ȡ�ֽ���
//		NULL                                                                         //ʵ�ʶ�ȡ�ֽ���
//	);
//	
//	printf("��ʱ������%d", dwSunshine);
//
//	int newSunshine = 0;
//	printf("\n������Ҫ�޸ĵ�����ֵ��");
//	scanf("%d", &newSunshine);
//	WriteProcessMemory
//	(
//		hProcess,
//		(void*)(dwSunshineOffsetFirstValue + dwSunshineOffsetSecondAddress),
//		&newSunshine,
//		sizeof(int),
//		NULL
//	);
//	printf("����ֵ�޸ĳɹ���");
//	return 0;
//}
