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
//	shared_ptr<int>sharedI(move (uniqueI));             //通过move移除独占属性
//}




//int main()
//{
//	// 3种初始化方式
//	int* pi = new int(222);
//	shared_ptr<int> sharedI = make_shared<int>(100);
//	shared_ptr<int> sharedII(new int(1002));
//	shared_ptr<int> sharedIII(pi);
// // 还可以   sharedI=sharedII
//	cout << *sharedIII;         // 如果delete的话 回释放两次，进而程序出错
//}







//int main()
//{
//	shared_ptr<int> sharedI = make_shared<int>(222);
//	cout << sharedI.use_count() << endl;
//	shared_ptr<int> sharedII(sharedI);
//	cout << sharedI.use_count() << endl;
//	cout << sharedI.use_count() << endl;
//	cout << sharedI.unique() << endl; // 如果独占 返回1
//// reset 用法
////	sharedII.reset();   将指针置空
////	sharedII.reset(new int(22));    重新分配指向的内存，这里必须用new用法 
//	 sharedI.get(); //  极不推荐使用的函数， 千万不能delete，不然程序崩溃
//}


// swap函数交换两个智能指针的内存



// shar指针是普通指针的二倍大小，独占智能指针跟普通指针的大小一样

//int main()
//{
//	shared_ptr<int> sharedI(new int[10]);  // 创建数组的唯一方式
//	//sharedI[10];    会报错  正确使用方法如下：
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
//	//weak_ptr<int> weakI(sharedI);   //不会改变计数基数
//
//	shared_ptr<A>weakA = make_shared<A>();
//	shared_ptr<B>sharedB = make_shared<B>();
//	weakA->sharedB = sharedB;
//	sharedB->weakA = weakA;
//}
//


