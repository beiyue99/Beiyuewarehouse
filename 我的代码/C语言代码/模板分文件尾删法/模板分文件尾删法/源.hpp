#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
using namespace std;
template<class T>
class MyArray
{
public:
	MyArray(int capacity)
	{
		m_Capacity = capacity;
		m_Size = 0;
		this->pAddress = new T[m_Capacity];
		cout << "MyArra有参构造的调用" << endl;
	}
	MyArray(const MyArray& arr)
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];/*m_pAddress = arr.pAddress;*/
		for (int i = 0; i < m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		cout << "MyArray拷贝构造的调用" << endl;

	}
	//opetator =   防止浅拷贝的问题
	MyArray& operator=(MyArray& arr)
	{
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Size = 0;
			this->m_Capacity = 0;
		}
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		cout << "MyArra重载的调用" << endl;

		return *this;
	}
	//尾插法
	void Push_Back(const T& val)
	{
		if (this->m_Capacity == this->m_Size)
		{
			cout << "已满"; return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}
	//尾删法
	void Pop_Back()
	{
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;//让用户访问不到 ，即为尾删。
	}
	//重载[]，以便访问数组元素。
	T& operator[](int index)
	{
		return this->pAddress[index];
	}
	//返回数组容量

	int GetCapacity()
	{
		return this->m_Capacity;
	}
	//返回数组大小

	int GetSize()
	{
		return this->m_Size;
	}
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
		cout << "MyArra析构的调用" << endl;

	}
private:
	T* pAddress;//指针指向堆区开辟的真实数组
	int m_Capacity;
	int m_Size;
};
