#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
using namespace std;
#include<iomanip>
//#include<vld.h>
#include<vector>














//int main()
//{
//	unique_ptr<int>uniqueI = make_unique<int>(100);
//	shared_ptr<int>sharedI(move (uniqueI));             //ͨ��move�Ƴ���ռ����
//}




//int main()
//{
//	// 3�ֳ�ʼ����ʽ
//	int* pi = new int(222);
//	shared_ptr<int> sharedI = make_shared<int>(100);
//	shared_ptr<int> sharedII(new int(1002));
//	shared_ptr<int> sharedIII(pi);
// // ������   sharedI=sharedII
//	cout << *sharedIII;         // ���delete�Ļ� ���ͷ����Σ������������
//}







//int main()
//{
//	shared_ptr<int> sharedI = make_shared<int>(222);
//	cout << sharedI.use_count() << endl;
//	shared_ptr<int> sharedII(sharedI);
//	cout << sharedI.use_count() << endl;
//	cout << sharedI.use_count() << endl;
//	cout << sharedI.unique() << endl; // �����ռ ����1
//// reset �÷�
////	sharedII.reset();   ��ָ���ÿ�
////	sharedII.reset(new int(22));    ���·���ָ����ڴ棬���������new�÷� 
//	 sharedI.get(); //  �����Ƽ�ʹ�õĺ����� ǧ����delete����Ȼ�������
//}


// swap����������������ָ����ڴ�



// sharָ������ָͨ��Ķ�����С����ռ����ָ�����ָͨ��Ĵ�Сһ��

//int main()
//{
//	shared_ptr<int> sharedI(new int[10]);  // ���������Ψһ��ʽ
//	//sharedI[10];    �ᱨ��  ��ȷʹ�÷������£�
//	sharedI.get()[10];
//}








//class B;
//class A
//{
//public:
//	shared_ptr<B> sharedB;
//};
//class B
//{
//public:
//	weak_ptr<A> weakA;
//};
//int main()
//{
//	//shared_ptr<int> sharedI = make_shared<int>(13);
//	//weak_ptr<int> weakI(sharedI);   //����ı��������
//
//	shared_ptr<A>weakA = make_shared<A>();
//	shared_ptr<B>sharedB = make_shared<B>();
//	weakA->sharedB = sharedB;
//	sharedB->weakA = weakA;
//}
//


