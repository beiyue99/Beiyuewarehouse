#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>
int main()
{
	HWND hh /*窗口句柄，相当于窗口ID*/ = FindWindow(L"MainWindow", L"植物大战僵尸中文版");
	
	unsigned long int dwPID = 0;
	GetWindowThreadProcessId(hh, &dwPID);      //通过窗口句柄获取PID

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPID);   //根据PID获取植物大战僵尸进程句柄


	unsigned long dwSunshineBaseAddress = 0x6AA00C;
	unsigned long dwSunshineAddressValue = 0;
	if (FALSE == ReadProcessMemory
	(
		hProcess,                                    //进程句柄
		(void*)dwSunshineBaseAddress,               //基地址
		&dwSunshineAddressValue,                     //数据
		sizeof(unsigned long),                       //读取字节数
		NULL                                    //实际读取字节数
	))
	{
		printf("获取静态变量失败，错误代码%d\n", GetLastError());
		return 0;
	}
	unsigned long dwSunshineOffsetValue = 0x768;
	unsigned long dwSunshineOffsetFirstValue = 0;


	unsigned long dwSunshineOffsetSecondValue = 0x5560;
	unsigned long dwSunshine = 0;
	if (FALSE == ReadProcessMemory
	(
		hProcess,                                                                        //进程句柄
		(LPVOID)(dwSunshineOffsetFirstValue + dwSunshineOffsetSecondValue),              //基地址
		&dwSunshine,                                                                     //数据
		sizeof(unsigned long),                                                           //读取字节数
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
		(LPVOID)(dwSunshineOffsetFirstValue + dwSunshineOffsetSecondValue),
		&newSunshine,
		sizeof(unsigned long),
		NULL
	))
	{
		printf("修改阳光值失败，错误代号：%d\n", GetLastError());
		return 0;
	}
	printf("阳光值修改成功。");
	return 0;
}