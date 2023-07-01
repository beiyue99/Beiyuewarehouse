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
//   sort(num.begin(), num.end(), less<int>());   // 升序
//
//
//
//
//
//
//
//    int max_num = 0;     // 被遍历元素满足条件时所能选择的最大区间
//    auto fir = num.begin();
//    auto las = fir;
//
//    // 每个元素都被遍历
//    for (; fir != num.end(); ++fir)
//    {
//        while (*las - *fir <= dist && las != num.end()) 
//        {
//            las++;    // 找出第一个与被遍历元素 差值大于dist的索引
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
