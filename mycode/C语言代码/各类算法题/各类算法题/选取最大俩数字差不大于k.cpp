#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>
#include<string.h>
#include <stdlib.h>
#include<string>
#include<math.h>

#include <iostream>
#include <algorithm>
#include <vector>
//
//int main()
//{
//    int count, dist;
//    vector<int> num;
//
//    cin >> count >> dist;
//
//    for (int i = 0; i < count; i++) {
//        int temp;
//        cin >> temp;
//        num.push_back(temp);
//    }
//
//   sort(num.begin(), num.end(), less<int>());   // ����
//
//
//
//
//
//
//
//    int max_num = 0;     // ������Ԫ����������ʱ����ѡ����������
//    auto fir = num.begin();
//    auto las = fir;
//
//    // ÿ��Ԫ�ض�������
//    for (; fir != num.end(); ++fir)
//    {
//        while (*las - *fir <= dist && las != num.end()) 
//        {
//            las++;    // �ҳ���һ���뱻����Ԫ�� ��ֵ����dist������
//        }
//        max_num = max(max_num, static_cast<int>(las - fir));
//        if (las == num.end()) {
//            break;
//        }
//    }
//
//    cout << max_num << endl;
//
//    return 0;
//}
