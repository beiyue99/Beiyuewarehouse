#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<functional>






//v.resize(15)        重新设置大小为15  且容量也随着扩充，超出部分补零。
//  重置的大小小于容量，容量不发生变化,只会改变大小。
//v.resize(15，100)   重新设置大小为15   多出的空间填充100


//vector<int>(v).swap(v)             
//这句代码首先创建了一个新的vector(临时)，它的size和capacity都等于原vector的size，
//然后通过swap函数将新的vector和原vector的内容进行交换。
//这样，原vector的内容就被替换成了新vector的内容，而原vector之前占用的大量内存也随着新vector的销毁而被释放。
//所以，这句代码的执行后，vector v的容量就被减少至了它的大小。
//需要注意的是，这个操作是有代价的，因为它需要创建原vector的一个完整拷贝。如果vector的大小非常大，
//那么这个操作可能会非常耗时。所以，这个操作应该只在确实需要减少vector占用的内存时才使用。




