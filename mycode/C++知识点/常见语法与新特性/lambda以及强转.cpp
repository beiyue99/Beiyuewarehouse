

//int main()
//{
//	int i = 10;
// //	//�ӵ��ںű�ʾ��ֵ�������б��� &��ʾ�����ò������б��� ���������Ի��ʹ��
//	[i](int elem)//����в������Լ����С����
//	{
//		cout << i << endl;
//		cout << elem << endl;
//	}(200);
//}




//#include<vector>
//int main()
//{
//	vector<int> v1{ 3,4 };
//	vector<int> v2{ 1,2,3,4,5,6,7,8 };
//	auto it = find_if(v2.begin(), v2.end(), [](int elem) { return elem > 3 && elem % 2; });
//	cout << distance(v2.begin(), it) << endl;
//}



//#include<vector>
//int main()
//{
//	vector<int> v1{ 1,2,3,4,5,6 };
//	auto it = adjacent_find(v1.begin(), v1.end(), [](int elem1, int elem2) {return elem1 >= 4 && elem2 >= 4; });
//	if (it == v1.end())                          // �ı�˺����Ĺ��ܣ�����Ԫ�ط��ش��ڵ���4��Ԫ�ص�����
//	{
//		cout << "have not this elem!" << endl;
//	}
//	else cout << distance(v1.begin(), it);
//}






//int main()
//{
//	int a = 97;
//	char c;
//	c = static_cast<char>(a);
//	cout << c << endl;
//	//  static_cast�������õ��������ͣ����о��м̳й�ϵ��ָ�������  �縸��ָ�������ָ���໥ת��
//}




//  dynamic_cast  ת�����м̳й�ϵ��ָ������ã���ת��ǰ��Զ�����м��

// ��飺 �������תΪ����ָ�룬�ǰ�ȫ�ģ��������ת���࣬����ȫ��������





//  const_cast ����ָ�������,���Լ��ϻ���ȡ��const




//int main()
//{
//	int a = 10;
//	const int& b = a;
//	
//	int& c = const_cast<int&>(b);
//	c = 20; cout << a << b << c;     
//}




//   reinterpret_cast   ǿ������ת��

