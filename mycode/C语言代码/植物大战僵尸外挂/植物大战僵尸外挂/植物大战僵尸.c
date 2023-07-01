#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>
int main()
{
	HWND hWnd /*窗口句柄，相当于窗口ID*/ =FindWindow(L"MainWindow",L"植物大战僵尸中文版");
	if (hWnd == NULL)
	{
		printf("植物大战僵尸未运行");
		return 0;
	}
	unsigned int dwPID=0;
	GetWindowThreadProcessId(hWnd, &dwPID);//通过窗口句柄获取PID
	if (dwPID == 0)
	{
		printf("获取进程的PID失败,错误代号：%d\n",GetLastError());
		return 0;
	}
	printf("此游戏的PID为：%d", dwPID);
	HANDLE hProcess=OpenProcess(PROCESS_ALL_ACCESS, FALSE,dwPID);   //根据PID获取植物大战僵尸进程句柄
	if (hProcess == NULL)
	{
		printf("打开植物大战僵尸进程失败，错误代码：%d\n", GetLastError());
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
		printf("获取静态变量失败，错误代码%d\n", GetLastError());
		return 0;
	}



	return 0;
} 