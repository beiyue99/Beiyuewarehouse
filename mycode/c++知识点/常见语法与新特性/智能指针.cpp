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
//        // �ڳ�Ա�����е��� shared_from_this() ��ȡ���������� shared_ptr
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
//    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>();  //ptr1 �����������ü���Ϊ1��
//    // �ڶ����ڲ����� shared_from_this() ��ȡ���������� shared_ptr
//    ptr1->printShared();  //shared_from_this() ��ȡ��һ���µ�std::shared_ptr�����������ü�������ʱ���ü���Ϊ2��
//    std::cout << "External use count: " << ptr1.use_count() << std::endl;  //  //�ⲿ��� ptr1.use_count()�����ü���Ϊ1��
//    //���ⲿ����� ptr1.use_count()�����ֵ�Ƕ����� sharedPtr �ģ���Ϊ�� printShared 
//    //�л�õ� sharedPtr ��������������������ٵġ�
//    // ���ⲿ�ٴλ�ȡ shared_ptr
//    std::shared_ptr<MyClass> ptr2 = ptr1->shared_from_this();
//    //ptr2 �����������ü�������Ϊ2��
//    std::cout << "External use count after second shared_ptr creation: " << ptr1.use_count() << std::endl;  //  2
//    std::cout << "External use count after second shared_ptr creation: " << ptr2.use_count() << std::endl;  //  2
//
//    ptr1->printShared();  //�ٴλ�ȡ�� std::shared_ptr�����ü�������Ϊ3�� 
//    return 0;
//    //��󣬵� main ��������ʱ��ptr1 �� ptr2 �������������ü�������Ϊ0,��ʱ�������������������
//}



/*


void login::initSignals()
{
    _register = make_shared<Register>();
    // _register->set_login(this);    this��һ����ָ�룬���ܸ�weak_ptr��ֵ

    //_register->set_login(shared_ptr<Login>(this));
    //������ⲿ�ٴδ���һ������ָ��������ͬһ�����󣬾ͻᵼ�����⡣������Ϊ������ͬ������ָ�����
    //�����������ڽ���ʱ���᳢���ͷ���ͬ�Ķ����ڴ档��������£�����һ������ָ������ü���
    //��Ϊ��ʱ�������ͷŶ�����ڴ档Ȼ������ʱ�ⲿ�ĵڶ�������ָ����Ȼ��ʹ�ö���
    //��˵�����ͼ�ͷ���ͬ���ڴ�ʱ���ͻᵼ�¶���Ķ������������ܵ���δ�������Ϊ,������������ü�������

    _register->set_login(shared_from_this());
    //����һ����ǰ�������ָ��,ǰ�����Ѿ���һ������ָ��������˹���
}

*/


























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




// swap����������������ָ����ڴ�



// sharָ������ָͨ��Ķ�����С����ռ����ָ�����ָͨ��Ĵ�Сһ��










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




//#if 1
//
//class B; // ǰ������
//
//class A {
//public:
//    std::shared_ptr<B> b_ptr;
//
//    A() {
//        std::cout << "A ���캯��\n";
//    }
//
//    ~A() {
//        std::cout << "A ��������\n";
//    }
//};
//
//class B {
//public:
//    //std::shared_ptr<A> a_ptr;
//    std::weak_ptr<A> a_ptr;
//
//    B() {
//        std::cout << "B ���캯��\n";
//    }
//
//    ~B() {
//        std::cout << "B ��������\n";
//    }
//};
//
//int main() {
//    // ʹ�� shared pointers ��������
//    std::shared_ptr<A> a = std::make_shared<A>();
//    std::shared_ptr<B> b = std::make_shared<B>();
//    //A�����shared_ptr��a����,�������ü�����Ϊ1����B�����shared_ptr��a,b�������ü���Ϊ2��
//    a->b_ptr = b; //����Ϊ2
//    b->a_ptr = a;//�����weak_ptr������Ϊ1
//    // ѭ������ʱ���� a �� b ����������ʱ����Ϊ���ü�������Ϊ�㣬��������δ������
//    //weak_ptrʱ����������A���������Ϊ0������A������B��shared_ptr��
//    //���B��������ü���Ҳ�����ˣ�����������BҲ������
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
//    // ����һ�� Car ���󣬲��� shared_ptr ��װ
//    std::shared_ptr<Car> car = std::make_shared<Car>("Toyota");
//
//    // �������� Person ���󣬹���ͬһ�� Car ����
//    std::shared_ptr<Person> person1 = std::make_shared<Person>("Alice", car);
//    std::shared_ptr<Person> person2 = std::make_shared<Person>("Bob", car);
//
//    // ��ӡ���ü���
//    std::cout << "Car reference count: " << car.use_count() << "\n";
//
//    // person1 �����٣�����Ϊ person2 ��Ȼ���� Car������ Car ���ᱻ����
//    person1.reset();
//
//    // �ٴδ�ӡ���ü���
//    std::cout << "Car reference count: " << car.use_count() << "\n";
//
//    // person2 �����٣�Car �����ü������ٵ��㣬Car ������
//    person2.reset();
//
//    std::cout << "Car reference count: " << car.use_count() << "\n";
//    return 0;
//}
//
//
//#endif