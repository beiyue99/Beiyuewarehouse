#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>
#include<stack>
//class Solution {
//public:
//    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
//        int n = pushV.size();
//        stack<int> s;//����ջ
//        int j = 0;//������ջ���±�
//        for (int i = 0; i < n; i++) {
//            //��ջ��ջΪ�ջ���ջ�������ڳ�ջ����
//            while (j < n && (s.empty() || s.top() != popV[i])) {
//                s.push(pushV[j]);
//                j++;
//            }
//            //ջ�����ڳ�ջ����
//            if (s.top() == popV[i])
//                s.pop();
//            else
//                return false;
//        }
//        return true;
//    }
//};



