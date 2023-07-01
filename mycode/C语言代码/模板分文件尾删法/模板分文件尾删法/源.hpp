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
		cout << "MyArra�вι���ĵ���" << endl;
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
		cout << "MyArray��������ĵ���" << endl;

	}
	//opetator =   ��ֹǳ����������
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
		cout << "MyArra���صĵ���" << endl;

		return *this;
	}
	//β�巨
	void Push_Back(const T& val)
	{
		if (this->m_Capacity == this->m_Size)
		{
			cout << "����"; return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}
	//βɾ��
	void Pop_Back()
	{
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;//���û����ʲ��� ����Ϊβɾ��
	}
	//����[]���Ա��������Ԫ�ء�
	T& operator[](int index)
	{
		return this->pAddress[index];
	}
	//������������

	int GetCapacity()
	{
		return this->m_Capacity;
	}
	//���������С

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
		cout << "MyArra�����ĵ���" << endl;

	}
private:
	T* pAddress;//ָ��ָ��������ٵ���ʵ����
	int m_Capacity;
	int m_Size;
};
