#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>
#include<stack>
//class Solution {
//public:
//    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
//        int n = pushV.size();
//        stack<int> s;//辅助栈
//        int j = 0;//遍历入栈的下标
//        for (int i = 0; i < n; i++) {
//            //入栈：栈为空或者栈顶不等于出栈数组
//            while (j < n && (s.empty() || s.top() != popV[i])) {
//                s.push(pushV[j]);
//                j++;
//            }
//            //栈顶等于出栈数组
//            if (s.top() == popV[i])
//                s.pop();
//            else
//                return false;
//        }
//        return true;
//    }
//};



