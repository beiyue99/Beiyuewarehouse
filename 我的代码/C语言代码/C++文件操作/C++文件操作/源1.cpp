#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<fstream>
#include<sstream>



//  ofstream 写操作    ifstream 读操作    fstream 读写操作












	//cout.put('a').put('b') << endl; 输出ab




	//cout.write("chain aaa", 7);    输出前七个字符，包括空格占一个字符



 
//Get()函数：


//1.   cout << cin.get(); 输出第一个字符的阿斯克码数值


	
        



//2.      ch = cin.get();   或者    cin.get(ch);   将输入的第一个字符读取到ch中





//3.   char buf[20];   cin.get(buf, 6, ' ');  将输入的前5个字符储存到buf中，遇到结束符停止，但不包括结束符,可以无结束符




//Getline()函数:      前两个与get用法相似


//1.  char buf[20];cin.getline(buf, 5); cout << buf;       读取4个

//2.  char buf[20];cin.getline(buf, 5, 'c'); cout << buf;  读取4个，遇到c停止读取 但不包括c
// 
// 
//3.  string str; getline(cin, str);cout << str;           读取所有，需要包含头文件sstream





// cin.ignore(10,'a')   忽略10个 遇到a停止忽略





//cin.read(buf, 10);   读取10个，换行符也包括，中文标点号，汉子占两个字符大小









	//  ch=cin.peek();       得到缓存的的第一个字符 但不取走



// cin.putback(ch) 将ch字符放回缓存区




//
//
//
//int main()
//{
//	string fileName;
//	string fileContent;
//	while (cin >> fileName, !cin.eof())
//	{
//		if (cin.bad())
//		{
//			throw runtime_error("cin is corrupted!");
//		}
//		ifstream ifs(fileName);
//		if (ifs.is_open())
//		{
//			while (getline(ifs, fileContent))
//			{
//				cout << fileContent << endl;
//			}
//			if (ifs.bad())
//			{
//				throw runtime_error("ifs is corrupted");
//			}
//			ifs.close();
//		}
//		else
//		{
//			ifs.clear();
//			ifs.ignore(numeric_limits<streamsize>::max(), '\n');
//			cout << "file not exist,please try again" << endl;
//			continue;
//		}
//	}
//	cout << "process conplate!" << endl;
//	return 0;
//}


//输入整形
//int main()
//{
//	int i = 10;
//	while (cin >> i, !cin.eof())
//	{
//		if (cin.bad())
//		{
//			throw runtime_error("cin is corrupted!");
//		}
//		if (cin.fail())
//		{
//			cin.clear();
//			cin.ignore(numeric_limits<streamsize>::max(), '\n');
//			cout << "date format error,please try again" << endl;
//			continue;
//		}
//		cout << i << endl;
//	}
//	cout << "process complate!" << endl;
//	return 0;
//}




//输入string类型
//int main()
//{
//	string str;
//	while (getline(cin, str), !cin.eof())
//	{
//		if (cin.bad())
//		{
//			throw runtime_error("cin is currpted!");
//		}
//		cout << str << endl;
//	}
//	return 0;
//}




//string 类型转整形

//int main()
//{
//	string str("121424");
//	stringstream strStream(str);
//	int i = 0;
//	strStream >> i;
//	if (strStream.bad())
//	{
//		throw runtime_error("strStream is corrupted!");
//	}
//	else if (strStream.fail())
//	{
//		strStream.clear();
//		strStream.ignore(numeric_limits<streamsize>::max(), '\n');
//		cout << "string format error" << endl;
//	}
//	else
//	{
//		cout << i << endl;
//	}
//	return 0;
//}


//整形转string

//int main()
//{
//	int i = 100;
//	stringstream strStream;
//	strStream << i << endl;
//	{
//		if (strStream.bad())
//		{
//			throw runtime_error("steSteam is corrupted!");
//		}
//		else
//		{
//			cout << strStream.str() << endl;
//		}
//	}
//	return 0;
//}





//int main()
//{
//	string srcString("hello world hello world");
//	string destString;
//	stringstream strStream(srcString);
//	while (strStream >> destString)
//	{
//		cout << destString << endl;
//	}
//	if (strStream.bad())
//	{
//		throw runtime_error("strStream is corrupted!");
//	}
//	return 0;
//}
////除去空格 输出四行


 



//int main()
//{
//	try
//	{
//		while (1)
//		{
//			int* pi = new int[10000000]();
//		}
//	}
//	catch (const bad_alloc& except)
//	{
//		cout << except.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "unknown exception!" << endl;
//	}
//	return 0;
//}





