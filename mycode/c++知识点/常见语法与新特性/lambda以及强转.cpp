#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<functional>
#include<algorithm>
#include<vector>





//lambda���ʽ��
//ʡȥ�˺�������Ĺ��̣�ֱ�ӿ���ʹ��



//int main()
//{
//	int i = 10;
//	[i]     
//	(int elem)//����в������Լ����С����
//	//�ӵ��ںű�ʾ��ֵ�������б��� &��ʾ�����ò������б��� ���������Ի��ʹ��
//	// i��ʾ��ֵ��������i &i��ʾ�����õ�������i
//	{
//		cout << i << endl;
//		cout << elem << endl;
//	}(200);
//}




//#include<vector>
//int main()
//{
//	vector<int> v1{ 3,4 };
//	vector<int> v2{ 1,2,3,4,5,6,7,8 };
//	auto it = find_if(v2.begin(), v2.end(), [](int elem) { return elem > 3 && elem % 2; });
//	cout << distance(v2.begin(), it) << endl;
//}



//#include<vector>
//int main()
//{
//	vector<int> v1{ 1,2,3,4,5,6 };
//	auto it = adjacent_find(v1.begin(), v1.end(), [](int elem1, int elem2) {return elem1 >= 4 && elem2 >= 4; });
//	if (it == v1.end())                          // �ı�˺����Ĺ��ܣ�����Ԫ�ط��ش��ڵ���4��Ԫ�ص�����
//	{
//		cout << "have not this elem!" << endl;
//	}
//	else cout << distance(v1.begin(), it);
//}









//lambda���ʽ�ĳ����÷���
//
//using pf_type = void(*)(int);
//void myfunc(pf_type pf, int i)
//{
//	pf(i);
//}
//
//int main()
//{
//	int i1 = 10;
//	myfunc([](int i)                  //lambda���ʽ��Ϊ����ָ����󣬲����б����Ϊ��
//		{
//			cout << i << endl;
//			cout << "lambda" << endl;
//		}, 200);
//}
//




//
//#include<functional>
//
////using pf_type = void(*)(int);
//using func_type =function<void(int)>;        //�ô˺������溯��ָ�룬������lambda���ʽ������
//
//void myfunc(func_type func, int i)
//{
//	func(i);
//}
//
//int main()
//{
//	int i1 = 10;
//	myfunc([i1](int i)                  
//		{
//			cout << i << endl;
//			cout << i1 << endl;
//			cout << "lambda" << endl;
//		}, 200);
//}
//
//
//













//int main()
//{
//	int a = 97;
//	char c;
//	c = static_cast<char>(a);
//	cout << c << endl;
//	//  static_cast�������õ��������ͣ����о��м̳й�ϵ��ָ�������  �縸��ָ�������ָ���໥ת��
//}








//  dynamic_cast  ת�����м̳й�ϵ��ָ������ã���ת��ǰ��Զ�����м��

// ��飺 �������תΪ����ָ�룬�ǰ�ȫ�ģ��������ת���࣬����ȫ��������





//  const_cast ����ָ�������,���Լ��ϻ���ȡ��const




//int main()
//{
//	int a = 10;
//	const int& b = a;
//	
//	int& c = const_cast<int&>(b);
//	c = 20; cout << a << b << c;     
//}




//   reinterpret_cast   ǿ������ת��

