#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>

//int main()
//{
//	string s1 = "ffawafa";
//	s1.append(s1, 3, 2);    �ӵ�������ʼ�أ�������׷�ӵ�����
//	cout << s1;
//}








//int main()
//{
//	string qqname("qqid@2377142053");
//	string name = "�⿡��";
//	name.append(qqname, qqname.find('@') + 1, 10);      //�ҵ������±� �����򷵻�-1
//	cout << name;// �⿡��2377142053
//}



//	s2.replace(1, 3, "1111");     // ��1λ���������ַ��滻Ϊ�ַ���1111
//size �� lenth ���Ƿ��س���        







// �ַ����Ĳ���ͽ�ȡ����

//int main()
//{
//	string s1 = "abcdef";
//	string s2=s1.insert(2, "222");  //�ӵڶ���λ�ò��롰222��       s1����  substr�Ļ�s1����,����
//	cout << s2 << endl;
//	//ab222cdef
//	s1.erase(2, 4);    //�ӵڶ���λ�ã�ɾ���ĸ�       abdef
//	cout << s1 << endl;
//}





//int main()
//{
//	string s1 = "abcde";
//	string s2 = s1.substr(1, 3);  //��ȥbcd���s2,s1����.    s2= bcd    
//	cout << s2 << endl;
//	cout << s1;
//}
//


//strcmp(s1[2].c_str(), s1[1].c_str())  ����ֵΪ0����1����-1������Ϊ0ʱ���ַ������
// string�ڲ���װ���ַ����ȽϺ���:    str1.compare(str2)  ����ֵ��strcmpһ��    

//string��find������û�ҵ�����һ�������������npos
//cout << (s1.find('3') == s1.npos);





String��ԭ��Ϊ��


#include <cstring> // For strlen, strcpy, etc.

class String
{
public:
    // ���캯��
    String(const char* str = nullptr)      //����Ĭ��ֵΪnullptr
    {
        if (str == nullptr) {
            m_data = new char[1];
            *m_data = '\0';
        }
        else {
            int length = strlen(str);
            m_data = new char[length + 1];
            strcpy(m_data, str);
        }
    }

    // �������캯��
    String(const String& other)
    {
        int length = strlen(other.m_data);
        m_data = new char[length + 1];
        strcpy(m_data, other.m_data);
    }

    // ��������
    ~String()
    {
        delete[] m_data;
    }

    // ��ֵ���������
    String& operator=(const String& other)
    {
        if (this != &other) {
            delete[] m_data;
            int length = strlen(other.m_data);
            m_data = new char[length + 1];
            strcpy(m_data, other.m_data);
        }
        return *this;
    }

private:
    char* m_data;
};

