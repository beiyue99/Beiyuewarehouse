//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//    string solve(string s, string t) 
//    {
//        if (s.size() < t.size()) 
//            return solve(t, s);    // 若s的长度小于t, 交换一下两者的位置
//        reverse(s.begin(), s.end());    // 翻转s
//        reverse(t.begin(), t.end());    // 翻转t
//        string ans;
//        int d = 0;    // 进位值
//        for (int i = 0; i < s.size(); i++)
//        {    
//            d += s[i] - '0';
//            if (i < t.size()) 
//                d += t[i] - '0';    // 若t当前位不为0
//            ans += d % 10 + '0';    // 当前位的结果
//            d /= 10;    // 下一步的进位值
//        }
//        if (d) 
//            ans += d  + '0';    // 若d不为0，增加一位
//        reverse(ans.begin(), ans.end());    // 将答案翻转
//        return ans;
//    }
//};
//int main()
//{
//    A a;
//    cout<<a.solve("241", "44");
//}



