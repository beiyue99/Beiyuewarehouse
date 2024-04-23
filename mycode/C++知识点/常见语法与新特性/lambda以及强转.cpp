

//int main()
//{
//	int i = 10;
// //	//加等于号表示按值捕获所有变量 &表示按引用捕获所有变量 这两个可以混合使用
//	[i](int elem)//如果有参数可以加这个小括号
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
//	if (it == v1.end())                          // 改变此函数的功能，遍历元素返回大于等于4的元素迭代器
//	{
//		cout << "have not this elem!" << endl;
//	}
//	else cout << distance(v1.begin(), it);
//}






//int main()
//{
//	int a = 97;
//	char c;
//	c = static_cast<char>(a);
//	cout << c << endl;
//	//  static_cast用于内置的数据类型，还有具有继承关系的指针或引用  如父类指针和子类指针相互转换
//}




//  dynamic_cast  转化具有继承关系的指针或引用，在转换前会对对象进行检查

// 检查： 如果子类转为父类指针，是安全的，如果父类转子类，不安全，不允许





//  const_cast 用于指针和引用,可以加上或者取消const




//int main()
//{
//	int a = 10;
//	const int& b = a;
//	
//	int& c = const_cast<int&>(b);
//	c = 20; cout << a << b << c;     
//}




//   reinterpret_cast   强制类型转换

