//
//#include<iostream>
//using namespace std;
//#include<stdio.h>
//#include<iomanip>
//#include<vld.h>
//
//struct dynamicArray
//{
//	void** pAddr;
//	int m_Capacity;
//	int m_Size;
//};
// dynamicArray* init_fun(int capacity)      //初始化结构体
//{
//	if (capacity <= 0) { return NULL; }
//	struct dynamicArray* arr = new(struct dynamicArray);
//	if (arr == NULL) { return NULL; }
//	arr->pAddr = new void* [sizeof(void*) * (capacity)]();
//	arr->m_Capacity = capacity;
//	arr->m_Size = 0;
//	return arr;
//}
//void insert_fun(struct dynamicArray* arr, void* date, int pos)  //插入数据
//{
//	if (arr == NULL) { return; }    if (date == NULL) { return; }
//	if (pos < 0 || pos >= arr->m_Capacity)
//	{
//		pos = arr->m_Size;
//	}
//	if (arr->m_Size == arr->m_Capacity) //数据插满进行扩容
//	{
//		int newCapacity = arr->m_Capacity * 2;
//		void** newSpace = new void* [newCapacity]();
//		memcpy(newSpace, arr->pAddr, sizeof(void*) * arr->m_Capacity);
//		delete arr->pAddr;
//		arr->pAddr = newSpace;
//		arr->m_Capacity = newCapacity;
//	}
//	//将元素往后移动
//	for (int i = arr->m_Size - 1; i >= pos; i--)
//	{
//		arr->pAddr[i + 1] = arr->pAddr[i];
//	}
//	//将数据插入到指定位置
//	arr->pAddr[pos] = date;
//	arr->m_Size++;
//}
//void foreach(struct dynamicArray* arr, void(*myPrint)(void*))   //遍历元素
//{
//	if (arr == NULL) { return; }
//	for (int i = 0; i < arr->m_Size; i++)
//	{
//		myPrint(arr->pAddr[i]);
//	}
//}
//struct Person
//{
//	char name[20];
//	int age;
//};
//void printPerson(void* date)
//{
//	struct Person* p1 = (struct Person*)date;
//	cout << setw(6) << "姓名:" << p1->name << "   " << "年龄:" << p1->age << endl;
//}
//void remove_fun(struct dynamicArray* arr, int pos)   //按照位置删除数据
//{
//	if (pos<0 || pos>arr->m_Size - 1) { return; }
//	for (int i = pos; i < arr->m_Size; i++)
//	{
//		arr->pAddr[i] = arr->pAddr[i + 1];
//	}
//	arr->m_Size--;
//}
//int myfun2(void* arr, void* date)
//{
//	Person* p1 = (Person*)arr;   Person* p2 = (Person*)date;
//	return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
//}
//void remove_fun2(struct dynamicArray* arr, void* date, int(*myFun2)(void*, void*)) //按值删除数据
//{
//	if (arr == nullptr) { return; }  if (date == nullptr) { return; }
//	for (int i = 0; i < arr->m_Size; i++)
//	{
//		if (myfun2(arr->pAddr[i], date))
//		{
//			remove_fun(arr, i); break;
//		}
//	}
//}
//void destroy_fun(dynamicArray* arr1)//销毁数组
//{
//	if (arr1 == nullptr) { return; }
//	if (arr1->pAddr != nullptr)
//	{
//		delete arr1->pAddr;
//		arr1->pAddr = nullptr;
//	}
//	delete arr1;
//	arr1 = nullptr;
//}
//
//
//
//
//
//
//
//
//
//void test01()
//{
//	dynamicArray* arr = init_fun(5);
//	Person p1 = { "赵1", 18 };
//	Person p2 = { "赵2", 28 };
//	Person p3 = { "赵3", 38 };
//	Person p4 = { "赵4", 48 };
//	Person p5 = { "赵5", 58 };
//	Person p6 = { "赵6", 68 };
//	cout << arr->m_Capacity << "  " << arr->m_Size << endl;
//	insert_fun(arr, &p1, 0);
//	insert_fun(arr, &p2, 1);
//	insert_fun(arr, &p3, 0);
//	insert_fun(arr, &p4, -1);
//	insert_fun(arr, &p5, 0);
//	insert_fun(arr, &p6, 0);
//	cout << arr->m_Capacity << "  " << arr->m_Size << endl;
//	foreach(arr, printPerson);
//	cout << "我要按位置删除第3个元素啦！" << endl;
//	remove_fun(arr, 2);
//	foreach(arr, printPerson);
//	cout << "我要按值删除名为赵5的元素啦！" << endl;
//	struct Person p = { "赵5",58 };
//	remove_fun2(arr, &p, myfun2);
//	foreach(arr, printPerson);
//	foreach(arr, printPerson);
//	destroy_fun(arr);
//	arr = nullptr;
//}
//int main()
//{
//	test01();
//}
