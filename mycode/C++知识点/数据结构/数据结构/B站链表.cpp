#define _crt_secure_no_warnings 1
#include<iostream>
using namespace std;
#include<vld.h>



struct node
{
	int date;
	node* next;
};
 node* initlist_fun()
{
	node* headnode = new node;
	headnode->date = null;
	headnode->next = nullptr;
	return headnode;
}
node* initnode_fun(int date)
{
	node* mynode = new node;
	mynode->date = date;
	mynode->next = nullptr;
	return mynode;
}
void print_fun(node* headnode)
{
	node* pnode = headnode->next;
	while (pnode)
	{
		cout << pnode->date << "  ";
		pnode = pnode->next;
	}
	cout << endl;
}
void insert_fun(node* headnode, int date)
{
	node* mynode = initnode_fun(date);
	mynode->next = headnode->next;
	headnode->next = mynode;
}
void remove_fun(node* headnode, int date)//��ֵ����ɾ��
{
	node* pcurrentnode = headnode->next;
	node* pfrontnode = headnode;
	if (pcurrentnode == nullptr) { cout << "�޷�ɾ����������Ϊ��" << endl; }
	else
	{
		while (pcurrentnode->date != date)
		{
			pfrontnode = pcurrentnode;
			pcurrentnode = pcurrentnode->next;
			if (pcurrentnode == nullptr) { cout << "δ�ҵ������Ϣ" << endl; return; }
		}
		pfrontnode->next = pcurrentnode->next;
		delete pcurrentnode;
		pcurrentnode = nullptr;
	}
}
void remove_fun2(node* headnode, int pos)//��λ��ɾ��
{
	if (headnode->next ==nullptr) { return; }
	node* pcurrentnode = headnode;
	for (int i = 0; i < pos-1; i++)
	{
		pcurrentnode = pcurrentnode->next;
	}
	node* del = pcurrentnode->next;
	pcurrentnode->next = del->next;
	delete del;
	del = nullptr;
}
void destory_fun(node* headnode)
{
	while (headnode != nullptr)
	{
		node* p = headnode->next;
		delete headnode;
		headnode = p;
	}
}



int main()
{
	node* list = initlist_fun();
	insert_fun(list, 1);
	insert_fun(list, 25);
	insert_fun(list, 3);
	cout << "����1 25 3 ��Ĵ�ӡ���Ϊ��" << endl;
	print_fun(list);
	remove_fun(list, 25);
	cout << "ɾ��Ԫ��25��:" << endl;
	print_fun(list);
	remove_fun2(list, 2);
	cout << "ɾ���ڶ���Ԫ�غ�:" << endl;
	print_fun(list);
	destory_fun(list);
}













