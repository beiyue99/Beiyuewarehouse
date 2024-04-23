#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <stdio.h>
#include<vector>
#include<mutex>
#include<thread>
#include<chrono>

//恶汉模式
class Myclass
{
private:
	Myclass() {};
	static mutex m_mutex;
	static Myclass* m_instance;
public:
	~Myclass() { cout << "Myclass 析构调用！" << endl; };
	Myclass& operator=(const Myclass&) = delete;
	Myclass(const Myclass&) = delete;
	static Myclass* GetInstance()
	{
		if (m_instance == nullptr)
		{
			lock_guard<mutex> L1(m_mutex);
			if (m_instance == nullptr)
			{
				m_instance = new Myclass();
				static huishou h1;
			}
		}
		return m_instance;
	}
	class huishou
	{
	public:
		~huishou()
		{
			cout << "huishou析构函数调用！" << endl;
			if (m_instance != nullptr)
			{
				delete m_instance;
				m_instance = nullptr;
			}
		}
	};

};
mutex Myclass::m_mutex;
Myclass* Myclass::m_instance = nullptr;



void fun()

{
	Myclass* m1 = Myclass::GetInstance();
}

int main()
{
	fun();
	this_thread::sleep_for(chrono::seconds(5));
	return 0;
}







#include <iostream>
#include <mutex>

class Myclass
{
private:
	Myclass() {}
	~Myclass() { std::cout << "Myclass 析构调用！" << std::endl; }
	Myclass(const Myclass&) = delete;
	Myclass& operator=(const Myclass&) = delete;

public:
	static Myclass* GetInstance()
	{
		static Myclass m_instance;
		return &m_instance;
	}
};
void fun()
{
	Myclass* m1 = Myclass::GetInstance();
}
int main()
{
	fun();
	this_thread::sleep_for(chrono::seconds(5));
	return 0;
}
