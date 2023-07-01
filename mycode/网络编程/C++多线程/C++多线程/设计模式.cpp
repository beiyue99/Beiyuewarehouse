#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
#include<thread>
#include<mutex>
#include<vld.h>
class A
{
private:
	A(){}
private:
	static A* Mya;
public:
	static A* Geta()
	{
		if (Mya == nullptr)
		{
			Mya = new A();
		}
		return Mya;
	}
};
A* A::Mya = nullptr;
int main()
{
	A* pa1 = A::Geta();
	A* pa2 = A::Geta();
}