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



//	m.insert(pair<int, int>(2, 20)); //   这种写入方式不推荐 了解就行
//	m.insert(make_pair(4, 40));      //   推荐使用
//	cout << m[5] << endl;                    //   没有插入键值为5的元素 输出结果为0





//	set<int>::iterator it = S.find(220);   
//  找到返回该元素的迭代器，否则返回end迭代器
// map容器中find函数参数为键值，找是否有该键存在

