#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
using namespace std;
#include<iomanip>
#include<vector>





//	shared_ptr<int>sharedI(move (uniqueI));             //通过move移除独占属性


// swap函数交换两个智能指针的内存

// shar指针是普通指针的二倍大小，独占智能指针跟普通指针的大小一样


//weak_ptr 的创建不会影响对象的引用计数，因为 weak_ptr 只是对对象的弱引用，不会影响对象的生命周期






//循环引用
//class B; // 提前声明类 B，以便在类 A 中使用
//
//class A {
//public:
//    std::shared_ptr<B> sharedB; // A 类持有指向 B 类对象的 shared_ptr
//};
//
//class B {
//public:
//    std::shared_ptr<A> sharedA; // B 类持有指向 A 类对象的 weak_ptr
//};
//
//int main() {
//    std::shared_ptr<A> sharedA = std::make_shared<A>();
//    std::shared_ptr<B> sharedB = std::make_shared<B>();
//
//    cout << sharedA.use_count() << endl;   //1
//    cout << sharedB.use_count() << endl;//1
//
//    sharedA->sharedB = sharedB;
//    sharedB->sharedA = sharedA;
//
//
//    cout << sharedA.use_count() << endl;//2
//    cout << sharedB.use_count() << endl;//2
//    return 0;
//}




//循环引用解决方案
class B; // 提前声明类 B，以便在类 A 中使用
class A {
public:
    std::shared_ptr<B> sharedB; // A 类持有指向 B 类对象的 shared_ptr
};

class B {
public:
    std::weak_ptr<A> weakA; // B 类持有指向 A 类对象的 weak_ptr
};

int main() {
    std::shared_ptr<A> sharedA = std::make_shared<A>();
    std::shared_ptr<B> sharedB = std::make_shared<B>();

    cout << sharedA.use_count() << endl;   //1
    cout << sharedB.use_count() << endl;//1

    sharedA->sharedB = sharedB;
    sharedB->weakA = sharedA;


    cout << sharedA.use_count() << endl;//1    弱引用不会增加引用计数
    cout << sharedB.use_count() << endl;//2


    return 0;
}







//智能指针shared_ptr简单实现


#include <iostream>

template<typename T>
class SmartPointer {
private:
    T* ptr;

public:
    SmartPointer(T* p) : ptr(p) {}

    ~SmartPointer() {
        delete ptr;
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }
};

int main() {
    SmartPointer<int> ptr(new int(42));

    std::cout << "Value: " << *ptr << std::endl;
    std::cout << "Address: " << ptr.operator->() << std::endl;

    return 0;
}
