#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<numeric>
//int main()
//{
//	int count = 0;
//	vector<int> v1;
//	for (int i = 1; i < 101; i++)
//	{
//		count += i;
//		v1.push_back(count);
//	}
//	cout << accumulate(v1.begin(), v1.end(), 0);
//}
//















//3 4
//AAAA
//ALAQ
//ALQQ
//�������
//4
//const int N = 15;
//
//int m, n;
//string a[N];
//int ans = 0;
//int len;
//
//// ��飺�� [i][j] ��ʼ�� len ���ַ��Ƿ�һ�£�iadd �� jadd �ֱ��ʾ i �� j ÿһ����ƫ����
//bool check(int i, int j, int iadd, int jadd) {
//    char ch = a[i][j];
//    for (int k = 0; k < len - 1; k++) {
//        i += iadd;
//        j += jadd;
//        if (i < 0 || i >= m || j < 0 || j >= n) return false;
//        if (ch != a[i][j]) return false;
//    }
//    return true;
//}
//
//int main() {
//    cin >> m >> n;
//    for (int i = 0; i < m; i++)
//        cin >> a[i];
//    // ö�ٳ���
//    for (len = min(m, n); len >1; len--) {
//        // ö�ٶ���
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                // ����������
//                ans += (check(i, j, 1, 0) && check(i, j, 0, 1) && check(i + len - 1, j, -1, 1));
//                // ����������
//                ans += (check(i, j, 1, 0) &&check(i, j, 0, -1) && check(i + len - 1, j, -1, -1));
//                // ����������
//                ans += (check(i, j, -1, 0)  && check(i, j, 0, 1)&& check(i - len + 1, j, 1, 1));
//                // ����������
//                ans += (check(i, j, -1, 0)  && check(i, j, 0, -1)&& check(i - len + 1, j, 1, -1));
//            }
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}










//#include<map>
//using namespace std;
//typedef map<int, int>::iterator iter;
//
//string str;
//int n;
//map<int, int> mp;
//
//int main() {
//    char ch = 'Z';
//    cin >> str;
//    n = str.length();
//    for (int i = 0; i < n; i++) {
//        if (str[i] < ch) {
//            ch = str[i];
//            mp.clear();
//        }
//        if (str[i] == ch) {
//            mp[i] = i;
//        }
//    }
//
//    if (mp.size() != n)	// �����ַ�ͬ�Ļ����ý���
//        for (int tmp = 0; mp.size() > 1 && tmp < n; tmp++) {
//            ch = 'Z';
//            for (iter it = mp.begin(); it != mp.end(); it++) {
//                int& idx = it->second;
//                idx = (idx + str[idx] - 'A' + 1) % n;
//                if (str[idx] < ch) {
//                    for (iter i = mp.begin(); i != it; i++)
//                        mp.erase(i);
//                    ch = str[idx];
//                }
//                else if (str[idx] > ch) {
//                    mp.erase(it--);
//                }
//            }
//        }
//    cout << mp.begin()->first << endl;
//    return 0;
//}






