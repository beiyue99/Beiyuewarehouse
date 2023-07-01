#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//#include<vld.h>


//class Test
//{
//public:
//	Test() = default;
//	//Test(const Test& t)
//	//{
//	//	if (t.str)
//	//	{
//	//		str = new char[strlen(t.str) + 1];
//	//		strcpy(this->str, t.str);
//	//	}
//	//	else this->str = nullptr;
//	//}
//	Test(Test&& t) noexcept    //用移动构造省去开辟堆区内存
//	{
//		if (t.str)
//		{
//			str = t.str;
//			t.str = nullptr;
//		}
//		else this->str = nullptr;
//	}
//	char* str = nullptr;
//};
//Test fun()
//{
//	Test tt;
//	tt.str =(char*)("fafa");  //堆区内存 fafa
//	return tt;
//}
//int main()
//{
//	Test t1 = fun(); //  堆区内存赋给t1
//	//delete t1.str;      //若不用移动构造,不把t1的堆区内容销毁，会造成内存泄漏
//	//使用了移动构造 默认拷贝赋值已经不起作用，t1=t2或t1(t2)失效，只可以通过函数返回值的方式赋值
//}
// 
 



