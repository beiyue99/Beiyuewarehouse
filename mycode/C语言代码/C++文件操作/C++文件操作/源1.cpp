#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<fstream>
#include<sstream>



//  ofstream д����    ifstream ������    fstream ��д����












	//cout.put('a').put('b') << endl; ���ab




	//cout.write("chain aaa", 7);    ���ǰ�߸��ַ��������ո�ռһ���ַ�



 
//Get()������


//1.   cout << cin.get(); �����һ���ַ��İ�˹������ֵ


	
        



//2.      ch = cin.get();   ����    cin.get(ch);   ������ĵ�һ���ַ���ȡ��ch��





//3.   char buf[20];   cin.get(buf, 6, ' ');  �������ǰ5���ַ����浽buf�У�����������ֹͣ����������������,�����޽�����




//Getline()����:      ǰ������get�÷�����


//1.  char buf[20];cin.getline(buf, 5); cout << buf;       ��ȡ4��

//2.  char buf[20];cin.getline(buf, 5, 'c'); cout << buf;  ��ȡ4��������cֹͣ��ȡ ��������c
// 
// 
//3.  string str; getline(cin, str);cout << str;           ��ȡ���У���Ҫ����ͷ�ļ�sstream





// cin.ignore(10,'a')   ����10�� ����aֹͣ����





//cin.read(buf, 10);   ��ȡ10�������з�Ҳ���������ı��ţ�����ռ�����ַ���С









	//  ch=cin.peek();       �õ�����ĵĵ�һ���ַ� ����ȡ��



// cin.putback(ch) ��ch�ַ��Żػ�����




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


//��������
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




//����string����
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




//string ����ת����

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


//����תstring

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
////��ȥ�ո� �������


 



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





