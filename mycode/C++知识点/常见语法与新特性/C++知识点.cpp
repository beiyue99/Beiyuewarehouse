#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
using namespace std;
#include<iomanip>
//#include<vld.h>
#include<vector>
#include<algorithm>
#include <string>
#include <algorithm>
using namespace std;
//#include <boost/algorithm/string.hpp>
//#include<gsl/string_span>



//在C++11中添加了定义原始字符串的字面量, 定义方式为:R“xXx(原始字符串)xXx”其中()两边的字符串可以省略。原始
//字面量R可以直接表示字符串的实际含义, 而不需要额外对字符串做转译或连接等操作。

//原始字面量的用法
//string str2 R"(D:\hello\world\test.text)";




//在使用中建议将const和constexpr的功能区分开, 即凡是表达“只读”语义
//的场景都使用const, 表达“常量”语义的场景都使用constexpr。

//在定义常量时, const和constexpr是等价的, 都可以在程序的编译阶段计算出结果, 例如:
const int m = f();
//不是常量表达式,m的值只有在运行时才会获取。

const int i = 520;
// 是一个常量表达式

const int j = 1 + 1;
// 是一个常量表达式


constexpr int i = 520;
// 是一个常量表达式

constexpr int j = i + 1;
// 是一个常量表达式


//对于C++内置类型的数据, 可以直接用constexpr修饰, 但如果是自定义的数据类型(用struct或者class实现), 直接
//用constexpr修饰是不行的。

constexpr T  t{ 100 };  //T是个类或结构体，这样是可以的





// 加上default关键字，认为使用系统默认函数
// 加上delete关键字，编译期不再生成此函数
// 加上override关键字，防止子类重写虚函数写错函数名




//int main()
//{
//	int arr[4] = { 2,35,5,5 };
//	cout << accumulate(arr, arr + 4, 0);
//}




// fill          三个参数，指定区间和需要填充的值
//int main()
//{
//	int arr[10] = { 0 };
//	fill(arr, arr + 10, 22);
//	for (auto it : arr)
//	{
//		cout << it << " ";
//	}
//}








// 右值引用只能绑定右值      
//int main()
//{
//	int i = 29;
//	int&& p = move(i);  //  move的作用是将左值改为右值，move i 后就不要再使用i了
//	cout << p;
//}




// 真正的常量储存在代码区和常量区  "dada"等储存在常量区   2,45,6，等储存在代码区 无法以任何方式修改
// const 修饰的储存在栈区或堆区   可以通过mutable关键字修改
// 函数体也是存放在代码区



// 静态变量和全局变量在编译期就确定了地址，储存在静态变量区




//  正数按原码储存，负数按补码储存 
//  负数的反码：   在原码的基础上，符号位不变，其余按位取反
//  负数的补码（也就是反码加一）








//int main()
//{
//	
//	int* a2 = new int[5] {2,3};       // 其余3个默认为0
//	cout << "-----" << endl;
//	int a3[5] = { 3 ,4,5,6};
//	int(*a1)[5] = &a3;              // 只能用数组的地址来赋值
//	printf("=--=-=-=-=-=-=-=-\n");
//	printf("%d", **a1);      // 结果为3
//	printf("%d", *a1[0]);      // 结果为3
//	printf("%d", a1[0][0]);  // 结果为3
//	printf("%d", a1[0][1]);  // 结果为4  第一个只能为0 不然越界
//	printf("%p\n", a1);
//	printf("%p\n", a1[0]);
//	printf("%p\n",a3 );
//	printf("%p\n", &a3);   //这4个地址相同，a3和&a3地址值相同  但第一个是首元素地址，第二个代表整个数组的地址
//	cout << sizeof(a1) <<"  " <<sizeof(a1[0]);   //8和20
//
//}




constexpr 只能定义编译期常量，⽽ const 可以定义编译期常量，也可以定义运⾏期常量


为了可以在编译过程展开，constexpr函数被隐式转换成了内联函数

constexpr int square(int x) {
    return x * x;
}

int main() {
    constexpr int result1 = square(5);   // 编译期计算
    int y = 10;
    constexpr int result2 = square(y);   // 错误，参数不是常量表达式
}



通常情况下，编译器会进行各种优化以提高程序的性能，例如将变量缓存在寄存器中，这样可以加快访问速度。
但是对于某些特殊的变量，如硬件寄存器、多线程共享变量等，其值可能会在程序的执行过程中被外部因素改变，
这就需要使用 volatile 关键字来告诉编译器不要对这些变量进行优化。而是要每次都从内存中读取该变量的值。




有const修饰成员变量，如果没有直接初始化，在构造函数中初始化必须在初始化列表进行初始化，否则构造函数会报错
因为 const 成员变量的值必须在对象创建时就确定，并且不能再修改。初始化列表调用时机大于构造函数体内部
class A
{
public:
    const int m_a;
    int m_b;
    A() :m_a(11), m_b(10) {}
};

