
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<Windows.h>
//int main()
//{
//	HWND hh = FindWindow(L"MainWindow", L"Plants vs. Zombies GOTY ");
//	unsigned long wPID = 0;
//	GetWindowThreadProcessId(hh, &wPID);
//	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, wPID);
//	int BassAddress = 0x77959C;
//	int value = 0;
//	ReadProcessMemory(hProcess, (void*)BassAddress, &value, sizeof(int), NULL);
//	int FirstAddress = 0x950;
//	int Firstvalue = 0;
//	ReadProcessMemory(hProcess, (void*)(value + FirstAddress), &Firstvalue, sizeof(int), NULL);
//	int SecondAddress = 0x50;
//	int Secondvalue = 0;
//	ReadProcessMemory(hProcess, (void*)(Firstvalue + SecondAddress), &Secondvalue, sizeof(int), NULL);
//	printf( "当前的金币值为%d", Secondvalue*10);
//	int newSunshine = 0;
//	printf("\n请输入要修改的金币值：");
//	scanf("%d", &newSunshine);
//	int a = newSunshine / 10;
//	 WriteProcessMemory(hProcess,(void*)(Firstvalue + SecondAddress),&a,sizeof(int),NULL);
//	printf("金币值修改成功。");
//}
//
//
//
//
//
//
