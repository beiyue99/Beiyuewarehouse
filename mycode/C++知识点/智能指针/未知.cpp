#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
using namespace std;
#include<iomanip>
#include<vector>

























//	shared_ptr<int>sharedI(move (uniqueI));             //ͨ��move�Ƴ���ռ����


// swap����������������ָ����ڴ�

// sharָ������ָͨ��Ķ�����С����ռ����ָ�����ָͨ��Ĵ�Сһ��


//weak_ptr �Ĵ�������Ӱ���������ü�������Ϊ weak_ptr ֻ�ǶԶ���������ã�����Ӱ��������������






//ѭ������
//class B; // ��ǰ������ B���Ա����� A ��ʹ��
//
//class A {
//public:
//    std::shared_ptr<B> sharedB; // A �����ָ�� B ������ shared_ptr
//};
//
//class B {
//public:
//    std::shared_ptr<A> sharedA; // B �����ָ�� A ������ weak_ptr
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




//ѭ�����ý������
class B; // ��ǰ������ B���Ա����� A ��ʹ��
class A {
public:
    std::shared_ptr<B> sharedB; // A �����ָ�� B ������ shared_ptr
};

class B {
public:
    std::weak_ptr<A> weakA; // B �����ָ�� A ������ weak_ptr
};

int main() {
    std::shared_ptr<A> sharedA = std::make_shared<A>();
    std::shared_ptr<B> sharedB = std::make_shared<B>();

    cout << sharedA.use_count() << endl;   //1
    cout << sharedB.use_count() << endl;//1

    sharedA->sharedB = sharedB;
    sharedB->weakA = sharedA;


    cout << sharedA.use_count() << endl;//1    �����ò����������ü���
    cout << sharedB.use_count() << endl;//2


    return 0;
}







//����ָ��shared_ptr��ʵ��


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
