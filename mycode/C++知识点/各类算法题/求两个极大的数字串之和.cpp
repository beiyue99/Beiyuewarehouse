//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//    string solve(string s, string t) 
//    {
//        if (s.size() < t.size()) 
//            return solve(t, s);    // ��s�ĳ���С��t, ����һ�����ߵ�λ��
//        reverse(s.begin(), s.end());    // ��תs
//        reverse(t.begin(), t.end());    // ��תt
//        string ans;
//        int d = 0;    // ��λֵ
//        for (int i = 0; i < s.size(); i++)
//        {    
//            d += s[i] - '0';
//            if (i < t.size()) 
//                d += t[i] - '0';    // ��t��ǰλ��Ϊ0
//            ans += d % 10 + '0';    // ��ǰλ�Ľ��
//            d /= 10;    // ��һ���Ľ�λֵ
//        }
//        if (d) 
//            ans += d  + '0';    // ��d��Ϊ0������һλ
//        reverse(ans.begin(), ans.end());    // ���𰸷�ת
//        return ans;
//    }
//};
//int main()
//{
//    A a;
//    cout<<a.solve("241", "44");
//}



