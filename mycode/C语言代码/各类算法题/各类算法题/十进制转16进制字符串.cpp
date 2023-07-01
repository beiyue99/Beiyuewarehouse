#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
using namespace std;








//
//
//string toHexString(int n)
//{
//    string res;
//    while (n != 0) {
//        //计算当前对16取余的结果
//        int mod = n % 12;
//        if (mod >= 0 && mod <= 9) {
//            char c = mod + '0';
//            res = c + res;
//        }
//        else {
//            char c = mod - 10 + 'A';
//            res = c + res;
//        }
//        n = n / 12;
//    }
//    return res;
//}
//
//
//int main() {
//
//    int n;
//    cin >> n;
//
//    string hexStr = toHexString(n);
//    cout << hexStr << endl;
//    return 0;
//}




//求十进制转为二进制的位数和值
//string s1;
//int main()
//{
//	int n;
//	cin >> n;
//	int num = 0;
//	while (n)
//	{
//		char a = (n % 2) + '0';
//		s1 = a + s1;
//		n /= 2;
//		num++;
//	}
//	cout << num << "   " << s1;
//}

