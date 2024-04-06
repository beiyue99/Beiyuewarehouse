#define _CRT_SECURE_NO_WARNINGS 1




//利用虚析构解决父类指针释放无法释放子类堆区属性

//纯虚析构需要代码实现  如果子类没有堆取数据，可以不写虚析构或者纯虚析构





//  对于多继承，继承虚表，生成指向虚表的指针，比如子类的生成vptr1指向某一父类的虚表，该虚表第后两个内容分别为空指针和type_info

//用const修饰的对象只能调用const修饰的成员函数，普通对象可以调用任何函数


//  子类如果想访问父类中的数据需要加上作用域  如 s.base::m_a
//  子类如果出现与父类同名的成员函数，那么会隐藏掉所有父类的同名成员函数，不加作用域，访问不到


//虚继承解决菱形继承的问题   class sheep:virtrual public animal{};
//发生虚继承之后，共同属性就只有一份   从两个父类继承下来的东西不再是两份数据，而是两个vbptr（虚基类指针），指向虚基类表，
//然后通过偏移量，都指向那份相同的数据
//注意，是中间两个子类虚继承父类，而不是最后的子类虚继承两个中间类

//利用virtrual关键字，修饰成员函数，实现动态多态，也就是地址晚绑定   子类重写的时候，virtrual关键字可以省略	


//空类占1个字节，在成员函数前加上virtual之后，变为4个字节，因为多了个虚函数表指针（vfptr）
//当子类继承的时候，把这个虚函数指针继承下来，指向自己的虚函数表，当子类重写的时候，
// 就会改变子类虚函数表的函数，父类虚函数表里的函数不发生改变




//	Test() { m_a = 0; c = 0; }            //1     
//	const int c;

////	const数据成员  只能在构造函数的初始化列表中完成初始化，不可在函数中进行赋值操作，因此1错误。
//                     应该改为初始化列表赋值法 Test() :m_a(0),c(2) {  }    















//
//
//class A1
//{
//public:
//	virtual void a()
//	{
//		cout << "A1::a" << endl;
//	}
//	virtual void b()
//	{
//		cout << "A1::b" << endl;
//	}
//	virtual void c()
//	{
//		cout << "A1::c" << endl;
//	}
//};
//
//
//class A2
//{
//public:
//	virtual void d()
//	{
//		cout << "A2::d" << endl;
//	}
//	virtual void e()
//	{
//		cout << "A2::e" << endl;
//	}
//};
//
//class B :public A1
//{
//public:
//	virtual void  b()
//	{
//		cout << "B::b" << endl;
//	}
//	virtual void d()
//	{
//		cout << "B::d" << endl;
//	}
//	virtual void f()
//	{
//		cout << "B::f" << endl;
//	}
//	virtual void g()
//	{
//		cout << "B::g" << endl;
//	}
//
//
//};
//int main()
//{
//	B b;
//	int* pvptr = (int*)&b;
//	int* vptr = (int*)*pvptr;
//	typedef void (*pfunc)();      //定义返回值为void ，参数为空的函数指针，名为pfunc
//	//for (int i = 0; vptr[i] != NULL; i++)
//	//{
//	//	pfunc pfun = pfunc(vptr[i]);
//	//	pfun();
//	//}
//	//a b c f g
//	cout << "++++++++++++++++++++" << endl;
//	long* vptr2 = (long*)*(pvptr + 1);
//	for (unsigned i = 0; vptr2[i] != NULL; i++)
//	{
//		pfunc pfun = pfunc(vptr2[i]);
//		pfun();
//	}
//	return 0;
//}

