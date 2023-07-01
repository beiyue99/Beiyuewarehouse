#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>
int main()
{
	HWND hh /*窗口句柄，相当于窗口ID*/ = FindWindow(L"MainWindow", L"Plants vs. Zombies GOTY ");
	if (hh == NULL)
	{
		printf("植物大战僵尸未运行");
		return 0;
	}
	unsigned long  dwPID = 0;
	GetWindowThreadProcessId(hh, &dwPID);      //通过窗口句柄获取PID
	if (dwPID == 0)
	{
		printf("获取进程的PID失败,错误代号：%d\n", GetLastError());
		return 0;
	}
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPID);   //根据PID获取植物大战僵尸进程句柄
	if (hProcess == NULL)
	{
		printf("打开植物大战僵尸进程失败，错误代码：%d\n", GetLastError());
		return 0;
	}


	int dwSunshineBaseAddress = 0x77959C;   //阳光基地址
	int dwSunshineAddressValue = 0;           
	if (FALSE == ReadProcessMemory
	(
		hProcess,                                   //进程句柄
		(void*)dwSunshineBaseAddress,                //读取数据的起始地址
		&dwSunshineAddressValue,                    //存放数据的地址
		sizeof(int),                      //读取字节数
		NULL                                    //实际读取字节数
	))											
	{											
		printf("获取静态变量失败，错误代码%d\n", GetLastError());
		return 0;
	}


	int dwSunshineFirstOffsetAddress = 0x868;
	int dwSunshineOffsetFirstValue = 0;
	if (FALSE == ReadProcessMemory
	(
		hProcess,                                                                        //进程句柄
		(void*)(dwSunshineAddressValue + dwSunshineFirstOffsetAddress),			      //读取数据的起始地址
		&dwSunshineOffsetFirstValue,                                    			     //存放数据的缓存区地址
		sizeof(int),                                          			     //读取字节数
		NULL                                                            			 //实际读取字节数
	))
	{
		printf("一级偏移地址获取失败，错误代号：%d\n", GetLastError());
		return 0;
	}



	int dwSunshineOffsetSecondAddress = 0x5578;
	int dwSunshine = 0;
	if (FALSE == ReadProcessMemory
	(
		hProcess,                                                                        //进程句柄
		(void*)(dwSunshineOffsetFirstValue + dwSunshineOffsetSecondAddress),             //读取数据的起始地址
		&dwSunshine,                                                                     //存放数据的缓存区地址
		sizeof(int),                                                           //读取字节数
		NULL                                                                         //实际读取字节数
	))
	{
		printf("获取阳光值失败，错误代号：%d\n", GetLastError());
		return 0;
	}
	printf("此时的阳光%d", dwSunshine);

	int newSunshine = 0;
	printf("\n请输入要修改的阳光值：");
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
		printf("修改阳光值失败，错误代号：%d\n", GetLastError());
		return 0;
	}
	printf("阳光值修改成功。");
	return 0;
}
