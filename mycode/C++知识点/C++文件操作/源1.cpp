

//  ofstream 写操作    ifstream 读操作    fstream 读写操作








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





