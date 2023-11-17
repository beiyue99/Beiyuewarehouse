#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>

//int main()
//{
//	string s1 = "ffawafa";
//	s1.append(s1, 3, 2);    从第三个开始截，截两个追加到后面
//	cout << s1;
//}








//int main()
//{
//	string qqname("qqid@2377142053");
//	string name = "吴俊锋";
//	name.append(qqname, qqname.find('@') + 1, 10);      //找到返回下标 ，否则返回-1
//	cout << name;// 吴俊锋2377142053
//}



//	s2.replace(1, 3, "1111");     // 从1位置起，三个字符替换为字符串1111
//size 和 lenth 都是返回长度        







// 字符串的插入和截取函数

//int main()
//{
//	string s1 = "abcdef";
//	string s2=s1.insert(2, "222");  //从第二个位置插入“222”       s1变了  substr的话s1不变,见下
//	cout << s2 << endl;
//	//ab222cdef
//	s1.erase(2, 4);    //从第二个位置，删除四个       abdef
//	cout << s1 << endl;
//}





//int main()
//{
//	string s1 = "abcde";
//	string s2 = s1.substr(1, 3);  //截去bcd存给s2,s1不变.    s2= bcd    
//	cout << s2 << endl;
//	cout << s1;
//}
//


//strcmp(s1[2].c_str(), s1[1].c_str())  返回值为0或者1或者-1，其中为0时，字符串相等
// string内部封装的字符串比较函数:    str1.compare(str2)  返回值与strcmp一样    

//string的find函数若没找到返回一个极大的数，即npos
//cout << (s1.find('3') == s1.npos);

