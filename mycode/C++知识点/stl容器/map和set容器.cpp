#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<stack>
#include<algorithm>
#include<list>
#include<set>
#include<map>
#include<vector>




//��ֵ�ԣ�  map����ÿ��Ԫ�ض���pair �����Ѿ�����ʱ���ٴβ������������ôβ�����Ч




//vector<int> v1(n); ������ vector �У����е�Ԫ�ض�����ʼ��Ϊ0��
//�������Ҫ��ʼ��Ϊ�ض���ֵ�������ʹ�� vector<int> v1(n, value);
//vector<int> v1(n) ��һ�� vector �������� vector<int> v1[n] ��һ�����飬ÿ��Ԫ�ض��� vector ����
//��set�����У�����Ԫ�ص�ֵ���������ļ�ֵ�����Ե�����ָ���Ԫ�ص�ֵ���ܱ��޸ģ�
//��Ϊ�޸�Ԫ�ص�ֵ���ᵼ�¼�ֵ�����仯���ƻ���set�����������ԣ�


//	m.insert(pair<int, int>(2, 20)); //   ����д�뷽ʽ���Ƽ� �˽����
//	m.insert(make_pair(4, 40));      //   �Ƽ�ʹ��
//	cout << m[5] << endl;                    //   û�в����ֵΪ5��Ԫ�� ������Ϊ0





//	set<int>::iterator it = S.find(220);   
//  �ҵ����ظ�Ԫ�صĵ����������򷵻�end������
// map������find��������Ϊ��ֵ�����Ƿ��иü�����
//set<int, Mycompare> S2;       //������ν����������������˳��

