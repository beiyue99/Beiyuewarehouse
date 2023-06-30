//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<Windows.h>
//int main()
//{
//	HWND hh /*窗口句柄，相当于窗口ID*/ = FindWindow(L"MainWindow", L"植物大战僵尸中文版");
//	
//	unsigned long  dwPID = 0;
//	GetWindowThreadProcessId(hh, &dwPID);      //通过窗口句柄获取PID
//	
//	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPID);   //根据PID获取植物大战僵尸进程句柄
//
//
//	int dwSunshineBaseAddress = 0x77959C;   //阳光基地址
//	int dwSunshineAddressValue = 0;
//	ReadProcessMemory
//	(
//		hProcess,                                   //进程句柄
//		(void*)dwSunshineBaseAddress,                //读取数据的起始地址
//		&dwSunshineAddressValue,                    //存放数据的地址
//		sizeof(int),                      //读取字节数
//		NULL                                    //实际读取字节数
//	);
//
//
//	int dwSunshineFirstOffsetAddress = 0x868;
//	int dwSunshineOffsetFirstValue = 0;
//	ReadProcessMemory
//	(
//		hProcess,                                                                        //进程句柄
//		(void*)(dwSunshineAddressValue + dwSunshineFirstOffsetAddress),			      //读取数据的起始地址
//		&dwSunshineOffsetFirstValue,                                    			     //存放数据的缓存区地址
//		sizeof(int),                                          			     //读取字节数
//		NULL                                                            			 //实际读取字节数
//	);
//	
//
//
//
//	int dwSunshineOffsetSecondAddress = 0x5578;
//	int dwSunshine = 0;
//	ReadProcessMemory
//	(
//		hProcess,                                                                        //进程句柄
//		(void*)(dwSunshineOffsetFirstValue + dwSunshineOffsetSecondAddress),             //读取数据的起始地址
//		&dwSunshine,                                                                     //存放数据的缓存区地址
//		sizeof(int),                                                           //读取字节数
//		NULL                                                                         //实际读取字节数
//	);
//	
//	printf("此时的阳光%d", dwSunshine);
//
//	int newSunshine = 0;
//	printf("\n请输入要修改的阳光值：");
//	scanf("%d", &newSunshine);
//	WriteProcessMemory
//	(
//		hProcess,
//		(void*)(dwSunshineOffsetFirstValue + dwSunshineOffsetSecondAddress),
//		&newSunshine,
//		sizeof(int),
//		NULL
//	);
//	printf("阳光值修改成功。");
//	return 0;
//}
