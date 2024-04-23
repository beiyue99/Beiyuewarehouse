#define _CRT_SECURE_NO_WARNINGS 1
#include<vector>
#include<iostream>
#include<functional>
using namespace std;








template<typename iter_type, typename func_type>
void for_each(iter_type first, iter_type last, func_type func)
{
	for (auto iter = first; iter != last; iter++)
	{
		func(*iter);
	}
}
int main()
{
	std::vector<int> ivec{ 1,2,3,4,5 };
	for_each(ivec.begin(), ivec.end(), [](int& elem) {elem++; });
	for (int elem : ivec)
	{
		cout << elem << endl;
	}
}



//添加默认模板参数
//using func_type1 = function<void(int&)>;
typedef void(*func_type1)(int&);
template<typename iter_type, typename func_type=func_type1>
void for_each(iter_type first, iter_type last, func_type func = [](int& elem){elem++; })
{
	for (auto iter = first; iter != last; iter++)
	{
		func(*iter);
	}
}
int main()
{
	std::vector<int> ivec{ 1,2,3,4,5 };
	for_each(ivec.begin(), ivec.end());
	for (auto elem : ivec)
	{
		cout << elem <<"  ";
	}
}




