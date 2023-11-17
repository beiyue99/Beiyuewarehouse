#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<stack>
#include<algorithm>
#include<list>
#include<set>
#include<map>
#include<vector>




//键值对：  map里面每个元素都是pair 当键已经存在时，再次插入这个键，则该次插入无效




//vector<int> v1(n); 创建的 vector 中，所有的元素都被初始化为0。
//如果你想要初始化为特定的值，你可以使用 vector<int> v1(n, value);
//vector<int> v1(n) 是一个 vector 容器，而 vector<int> v1[n] 是一个数组，每个元素都是 vector 容器
//在set容器中，由于元素的值就是容器的键值，所以迭代器指向的元素的值不能被修改，
//因为修改元素的值将会导致键值发生变化，破坏了set容器的有序性；


//	m.insert(pair<int, int>(2, 20)); //   这种写入方式不推荐 了解就行
//	m.insert(make_pair(4, 40));      //   推荐使用
//	cout << m[5] << endl;                    //   没有插入键值为5的元素 输出结果为0





//	set<int>::iterator it = S.find(220);   
//  找到返回该元素的迭代器，否则返回end迭代器
// map容器中find函数参数为键值，找是否有该键存在
//set<int, Mycompare> S2;       //可以用谓词来调整插入排列顺序

