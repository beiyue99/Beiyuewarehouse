#define _CRT_SECURE_NO_WARNINGS 1



//
//
//#include<iostream>
//#include<iomanip>
//using namespace std;
//class Jz
//{
//public:
//    int arr[2][3];
//   friend ostream& operator<<(ostream& os, Jz& jz);
//   void input();
//   Jz& operator+(Jz& jz);
//};
//void Jz::input()
//{
//    for (int i = 0; i < 2; i++)
//    {
//        if(i==0)
//        cout << "请输入矩阵第一行元素：" << endl;
//        else
//        cout << "请输入矩阵第二行元素：" << endl;
//        for (int j = 0; j < 3; j++)
//        {
//            cin >> arr[i][j];
//        }
//    }
//}
// ostream& operator<<(ostream& os, Jz& jz)
//{
//     for (int i = 0; i < 2; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             cout<<setw(3) << jz.arr[i][j];
//         }
//         cout << endl;
//     }
//     return os;
//}
// Jz& Jz::operator+(Jz& jz)
// {
//     for (int i = 0; i < 2; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             this->arr[i][j] += jz.arr[i][j];
//         }
//     }
//     return *this;
// }
//
//
// int main()
// {
//     Jz j1, j2;
//     j1.input();  
//     j2.input();
//     cout << j1;
//     cout << "-----------------" << endl;
//     cout << j2;
//     cout << "-----------------" << endl;
//     cout << (j1 + j2);
// }












//
//
//
//
//#include <iostream>
//#include <iomanip>   //使用流操作符，如设置显示宽度setw(int)
//#include <cstdlib>      //使用system()
//#include <windows.h>   //使用Sleep()
//#include <conio.h>      //使用_kbhit()
//using namespace std;
//class Watch
//{
//public:
//    int m_hour;
//    int m_min;
//    int m_sec;
//    Watch():m_sec(0),m_min(0),m_hour(0){}
//    Watch& run();
//     friend ostream& operator<<(ostream& os,Watch&w);
//};
//ostream& operator<<(ostream& os,Watch&w)
//{
//    cout << setw(2) << w.m_hour << ":"<<setw(2) << w.m_min << ":"<<setw(2) << w.m_sec << endl;
//    return os;
//}
//Watch& Watch::run()
//{
//    m_sec++;
// 
//    if (m_sec == 60)
//    {
//        m_sec = 0;
//        m_min++;
//    }
//    if (m_min == 60)
//    {
//        m_min = 0;
//        m_hour++;
//    }
//    return *this;
//}
//int main()
//{
//    Watch w1;
//    system("color B");
//    while (true)
//    {
//        cout << w1;
//        Sleep(1000);
//        system("cls");
//        w1.run();
//    }
//}