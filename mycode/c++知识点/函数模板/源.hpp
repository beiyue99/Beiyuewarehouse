#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<type_traits>
//using namespace std;
//template<typename T>
//struct get_type
//{
//	using type = T;
//};
//template<typename T>
//struct get_type<T*>
//{
//	using type = T;
//};
//template<typename T>
//class MyArray
//{
//	using it = T*;
//	using const_it = const T*;
//public:
//	MyArray(size_t count);
//	MyArray(const initializer_list<T>& list);
//	MyArray(initializer_list<T>&& list);
//	~MyArray();
//	it begin()const;
//	const_it cbegin()const;
//	T& operator[](unsigned count)const
//	{
//		return date[count];
//	}
//	T* date;
//};
//template<typename T>
//MyArray<T>::MyArray(size_t count)
//{
//	if (count)
//	{
//		date = new T[count];
//	}
//	else date = nullptr;
//}
//template<typename T>
//typename MyArray<T>::it MyArray<T>::begin()const
//{
//	return date;
//}
//template<typename T>
//typename MyArray<T>::const_it MyArray<T>::cbegin()const
//{
//	return date;
//}
//template<typename T>
//MyArray<T>::~MyArray()
//{
//	if (date)
//	{
//		delete []date;
//	}
//}
//template<typename T>
//MyArray<T>::MyArray(const initializer_list<T>& list)
//{
//	if (list.size())
//	{
//		unsigned count = 0;
//		date = new T[list.size()];
//		if (is_pointer<T>::value)
//		{
//			for (auto elem : list)
//			{
//				date[count++] = new typename get_type<T>::type(*elem);
//			}
//		}
//		else 
//		{
//			for (const auto& elem : list)
//			{
//				date[count++] = elem;
//			}
//		}
//	}
//	else date = nullptr;
//}
//template<typename T>
//MyArray<T>::MyArray(initializer_list<T>&& list)
//{
//	if (list.size())
//	{
//		unsigned count = 0;
//		date = new T[list.size()];
//		for (const auto& elem : list)
//		{
//			date[count++] = elem;
//		}
//	}
//	else date = nullptr;
//}