#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<functional>   //�ڽ���������ͷ�ļ�



//class Transform
//{
//public:
//	int operator()(int v)
//	{
//		return v+100;         //���˵�ͬʱ ÿ��Ԫ�ؼ�100
//	}
//};
//int fun(int v)
//{
//	return v + 100;
//}
//void Myprint(int a)
//{
//	cout << a << " ";
//}
//int main()
//{
//	vector<int> v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	}
//	vector<int>vTarget;
//	vTarget.resize(v.size());          //�������ռ�
//	transform(v.begin(), v.end(), vTarget.begin(), fun);  //transformҲ��������ͨ����
//	for_each(vTarget.begin(), vTarget.end(), ptr_fun(Myprint));    
//}

//sort��for_each�ĵ�����������������ͨ����










// adjacent_find(v.begin(),v.end())   ����  �������ظ�Ԫ�أ����ص�һ��Ԫ�صĵ����������򷵻�end������
//int main()
//{
//	vector<int> v1{ 2,41,41,4,21,4,4 };
//	while (adjacent_find(v1.begin(), v1.end()) != v1.end())
//	{
//		v1.erase(adjacent_find(v1.begin(), v1.end()));
//	}
//	for (auto it : v1)
//	{
//		cout << it << " ";
//	}
//}





// binary_search  ����Ԫ���Ƿ����,������ͼ�      ����������������ʹ��  ��Ϊ�ڲ������Ƕ��ֲ���
//Ҫע�⣬find�������ص������Ԫ�صĵ�ַ������Ҳ���������endλ�õĵ�ַ



//  merge   ����������Ԫ�غϲ��������浽��һ�������У�������������������ģ�
//�Һϲ�����һ��������Ҳ������ģ�merge() ���������




//ʹ��stringstream ����ַ�������֮���ת�� 

//#include<sstream>
//int main()
//{
//	constexpr int  num = 12;          //��ʾ�����ھͿ���ȷ��num��ֵ������ʱ�Զ��滻Ϊ12
//	string s;
//	stringstream strs;
//	strs << num;
//	strs >> s;
//	strs.clear();    //�������clear,��Ȼ���ܳ�������
//	cout << s << endl;
//	const string s1 = "123";
//
//	int a = 0;
//	strs << s1;
//	strs >> a;
//	cout << a;
//}



//
//int main()
//{
//	const char* s1 = "21";
//	int a = atoi(s1);
//	cout << a << endl;
//	string s2 = "28";
//	int b = atoi(s2.c_str());     //��stringתΪconst char*
//	cout << b << endl;
//	const char* s3 = "10";
//	int c = stoi(s3);           // ��atoi�÷�����һ��
//	cout << c << endl;
//	int d = 1888;
//	char name[20];
//    _itoa(d,name,10);              //�°汾VS�Դ˺������а�ȫ��飬Ҫô���Ϻ궨�壬Ҫôʹ��_itoa
//	cout << name << endl;
//}