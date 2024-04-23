#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>






//  copy   将容器中的元素拷贝到另一个容器中   copy()有三个参数
//int main()
//{
//	int arr1[4] = { 1,2,3,4 };
//	int arr2[4] = { 0 };
//	copy(arr1, arr1 + 4, arr2);
//	for ( auto it : arr2)
//	{
//		cout << it << " ";
//	}
//}

// replace  将容器中的元素替换为新元素      replace(开始迭代器，结束迭代器，旧元素，新元素）  共四个参数



// swap 互换两个容器的元素                  有两个参数，分别为这两个容器
//int main()
//{
//	int arr1[3] = { 1,2,3 };
//	int arr2[3] = { 4,5,6};
//	swap(arr1, arr2);
//	cout << arr2[0];
//}


//  replace_if  满足条件的元素替换为新元素    replace_if(开始迭代器，结束迭代器，谓词，新元素）
//#include<algorithm>
//int main()
//{
//	int arr[4] = { 15,7,3,88 };
//	replace_if(arr, arr + 4,  [](int a) noexcept{return a < 10; }, 100);
//	for (const auto it : arr)
//	{
//		cout << it << " ";
//	}
//}





