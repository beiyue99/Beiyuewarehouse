#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
using namespace std;
#include<iomanip>
#include<vector>

















//class MyClass : public std::enable_shared_from_this<MyClass> {
//public:
//    MyClass() {
//        std::cout << "Constructing MyClass " << std::endl;
//    }
//
//    void printShared() {
//        // 在成员函数中调用 shared_from_this() 获取与对象关联的 shared_ptr
//        std::shared_ptr<MyClass> sharedPtr = shared_from_this();
//        std::cout << "Use count: " << sharedPtr.use_count() << std::endl;
//    }
//
//    ~MyClass() {
//        std::cout << "Destructing MyClass" << std::endl;
//    }
//};
//
//int main() {
//    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>();  //ptr1 被创建，引用计数为1。
//    // 在对象内部调用 shared_from_this() 获取与对象关联的 shared_ptr
//    ptr1->printShared();  //shared_from_this() 获取了一个新的std::shared_ptr，增加了引用计数，此时引用计数为2。
//    std::cout << "External use count: " << ptr1.use_count() << std::endl;  //  //外部输出 ptr1.use_count()，引用计数为1。
//    //在外部输出了 ptr1.use_count()，这个值是独立于 sharedPtr 的，因为在 printShared 
//    //中获得的 sharedPtr 是在其作用域结束后销毁的。
//    // 在外部再次获取 shared_ptr
//    std::shared_ptr<MyClass> ptr2 = ptr1->shared_from_this();
//    //ptr2 被创建，引用计数增加为2。
//    std::cout << "External use count after second shared_ptr creation: " << ptr1.use_count() << std::endl;  //  2
//    std::cout << "External use count after second shared_ptr creation: " << ptr2.use_count() << std::endl;  //  2
//
//    ptr1->printShared();  //再次获取了 std::shared_ptr，引用计数增加为3。 
//    return 0;
//    //最后，当 main 函数结束时，ptr1 和 ptr2 超出作用域，引用计数减少为0,此时对象的析构函数被调用
//}



/*


void login::initSignals()
{
    _register = make_shared<Register>();
    // _register->set_login(this);    this是一个裸指针，不能给weak_ptr赋值

    //_register->set_login(shared_ptr<Login>(this));
    //如果在外部再次创建一个智能指针来管理同一个对象，就会导致问题。这是因为两个不同的智能指针对象
    //在其生命周期结束时都会尝试释放相同的对象内存。这种情况下，当第一个智能指针的引用计数
    //减为零时，它会释放对象的内存。然而，此时外部的第二个智能指针仍然在使用对象，
    //因此当它试图释放相同的内存时，就会导致对象的二次析构，可能导致未定义的行为,解决方案是引用计数共享。

    _register->set_login(shared_from_this());
    //返回一个当前类的智能指针,前提是已经有一个智能指针对它做了管理
}

*/


























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




// swap函数交换两个智能指针的内存



// shar指针是普通指针的二倍大小，独占智能指针跟普通指针的大小一样










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




//#if 1
//
//class B; // 前向声明
//
//class A {
//public:
//    std::shared_ptr<B> b_ptr;
//
//    A() {
//        std::cout << "A 构造函数\n";
//    }
//
//    ~A() {
//        std::cout << "A 析构函数\n";
//    }
//};
//
//class B {
//public:
//    //std::shared_ptr<A> a_ptr;
//    std::weak_ptr<A> a_ptr;
//
//    B() {
//        std::cout << "B 构造函数\n";
//    }
//
//    ~B() {
//        std::cout << "B 析构函数\n";
//    }
//};
//
//int main() {
//    // 使用 shared pointers 创建对象
//    std::shared_ptr<A> a = std::make_shared<A>();
//    std::shared_ptr<B> b = std::make_shared<B>();
//    //A对象的shared_ptr被a持有,所以引用计数变为1。而B对象的shared_ptr被a,b持有引用计数为2。
//    a->b_ptr = b; //计数为2
//    b->a_ptr = a;//如果用weak_ptr，计数为1
//    // 循环引用时，当 a 和 b 超出作用域时，因为引用计数都不为零，析构函数未被调用
//    //weak_ptr时，出作用域，A对象计数变为0，由于A持有了B的shared_ptr，
//    //因此B对象的引用计数也减少了，最后出作用域B也析构。
//    return 0;
//}
//
//
//#else:
//
//#include <iostream>
//#include <memory>
//#include <string>
//
//class Car {
//public:
//    std::string model;
//
//    Car(const std::string& _model) : model(_model) {
//        std::cout << "Car " << model << " created.\n";
//    }
//
//    ~Car() {
//        std::cout << "Car " << model << " destroyed.\n";
//    }
//};
//
//class Person {
//public:
//    std::string name;
//    std::shared_ptr<Car> car_ptr;
//
//    Person(const std::string& _name, const std::shared_ptr<Car>& _car_ptr)
//        : name(_name), car_ptr(_car_ptr) {
//        std::cout << "Person " << name << " created.\n";
//    }
//
//    ~Person() {
//        std::cout << "Person " << name << " destroyed.\n";
//    }
//};
//
//int main() {
//    // 创建一个 Car 对象，并用 shared_ptr 包装
//    std::shared_ptr<Car> car = std::make_shared<Car>("Toyota");
//
//    // 创建两个 Person 对象，共享同一个 Car 对象
//    std::shared_ptr<Person> person1 = std::make_shared<Person>("Alice", car);
//    std::shared_ptr<Person> person2 = std::make_shared<Person>("Bob", car);
//
//    // 打印引用计数
//    std::cout << "Car reference count: " << car.use_count() << "\n";
//
//    // person1 被销毁，但因为 person2 仍然引用 Car，所以 Car 不会被销毁
//    person1.reset();
//
//    // 再次打印引用计数
//    std::cout << "Car reference count: " << car.use_count() << "\n";
//
//    // person2 被销毁，Car 的引用计数减少到零，Car 被销毁
//    person2.reset();
//
//    std::cout << "Car reference count: " << car.use_count() << "\n";
//    return 0;
//}
//
//
//#endif