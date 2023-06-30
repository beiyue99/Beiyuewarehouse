//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<iostream>
//using namespace std;
//#include<queue>
//enum ChildSigh
//{
//	E_Root,
//	E_ChildLeft,
//	E_ChildRight
//};
//template<typename T>
//struct BinaryTreeNode
//{
//	T date;
//	BinaryTreeNode* leftChild;
//	BinaryTreeNode* rightChild;
//};
//
//template<typename T>
//class BinaryTree
//{
//public:
//	BinaryTree()
//	{
//		root = nullptr;
//	}
//	~BinaryTree()
//	{
//		ReleaseNode(root);
//	}
//	//�����ڵ�
//	BinaryTreeNode<T>* CreateNode(BinaryTreeNode<T>* ParentNode, ChildSigh PointSign, const T& e)
//	{
//		BinaryTreeNode<T>* myNode = new BinaryTreeNode<T>;
//		myNode->date = e;
//		myNode->leftChild = nullptr;
//		myNode->rightChild = nullptr;
//		if (PointSign == E_Root)
//		{
//			root = myNode;
//		}
//		if (PointSign == E_ChildLeft)
//		{
//			ParentNode->leftChild = myNode;
//		}
//		else if (PointSign == E_ChildRight)
//		{
//			ParentNode->rightChild = myNode;
//		}
//		return myNode;
//	}
//	//������չ��������ǰ���������һ�Ŷ�����
//	void CreatBT(char* pstr)
//	{
//		CreatBTs(root, pstr);
//	}
//	//������չ��������ǰ���������һ�Ŷ��������ӵݹ麯��
//	void CreatBTs(BinaryTreeNode<T>*& pNode, char*& pstr2)
//	{
//		if (*pstr2 == '#')
//		{
//			pNode = nullptr;
//		}
//		else
//		{
//			pNode = new BinaryTreeNode<T>;
//			pNode->date = *pstr2;
//			CreatBTs(pNode->leftChild, ++pstr2);
//			CreatBTs(pNode->rightChild, ++pstr2);
//		}
//
//	}
//	//�������,�ж��Ƿ�Ϊ��ȫ������
//	void levelOrder()
//	{
//		BinaryTreeNode<T>* pNode = this->root;
//		bool b1 = true;
//		queue<BinaryTreeNode<T>*> q1;
//		if (pNode != nullptr)
//		{
//			BinaryTreeNode<T>* tmpNode;
//			q1.push(pNode);
//			while (!q1.empty())
//			{
//				tmpNode = q1.front();
//				q1.pop();
//				cout << (char)tmpNode->date << " ";
//				if (tmpNode->leftChild == nullptr && tmpNode->rightChild != nullptr)
//				{
//					b1 = false;
//				}
//				if (tmpNode->leftChild != nullptr)
//				{
//					q1.push(tmpNode->leftChild);
//				}
//				if (tmpNode->rightChild != nullptr)
//				{
//					q1.push(tmpNode->rightChild);
//				}
//			}
//			if (b1 == true) { cout << "��ȫ������" << endl; }
//			else cout << "����ȫ������" << endl;
//		}
//		else
//			return;
//	}
//	//ǰ�����
//	void preOrder()
//	{
//		preOrder(root);
//	}
//	void preOrder(BinaryTreeNode<T>* pNode)
//	{
//		if (pNode != nullptr)
//		{
//			cout << (char)pNode->date << " ";
//			preOrder(pNode->leftChild);
//			preOrder(pNode->rightChild);
//		}
//	}
//	//�ͷŽڵ�
//	void ReleaseNode(BinaryTreeNode<T>* PNode)
//	{
//		if (PNode != nullptr)
//		{
//			ReleaseNode(PNode->leftChild);
//			ReleaseNode(PNode->rightChild);
//		}
//		delete PNode;
//	}
//	// ��������ڵ����
//	int GetNum()
//	{
//		return GetNum(root);
//	}
//	int GetNum(BinaryTreeNode<T>* pNode)
//	{
//		if (pNode == nullptr) { return 0; }
//		return GetNum(pNode->leftChild) + GetNum(pNode->rightChild) + 1;
//	}
//	//��������߶�
//	int GetHeight()
//	{
//		return GetHeight(root);
//	}
//	int GetHeight(BinaryTreeNode<T>* pNode)
//	{
//		if (pNode == nullptr) { return 0; }
//		int Lheight = GetHeight(pNode->leftChild);
//		int Rheight = GetHeight(pNode->rightChild);
//		if (Lheight > Rheight)
//		{
//			return Lheight + 1;
//		}
//		else return Rheight + 1;
//	}
//	//��ֵ����ĳ���ڵ㲢����
//	BinaryTreeNode<T>* SearchElem(const T& e)
//	{
//		return SearchElem(root, e);
//	}
//	BinaryTreeNode<T>* SearchElem(BinaryTreeNode<T>* pNode, const T& e)
//	{
//		if (pNode == nullptr) { return nullptr; }
//		if (pNode->date == e) { return pNode; }
//		BinaryTreeNode<T>* tmpNode = SearchElem(pNode->leftChild, e);
//		if (tmpNode != nullptr)
//		{
//			return tmpNode;
//		}
//		return SearchElem(pNode->rightChild, e);
//	}
//	//����ĳ���ڵ�ĸ��׽ڵ�
//	BinaryTreeNode<T>* GetParent(BinaryTreeNode<T>* sNode)
//	{
//		return GetParent(root, sNode);
//	}
//	BinaryTreeNode<T>* GetParent(BinaryTreeNode<T>* pNode, BinaryTreeNode<T>* sNode)
//	{
//		if (pNode == nullptr || sNode == nullptr) { return nullptr; }
//		if (pNode->leftChild == sNode || pNode->rightChild == sNode)
//		{
//			return pNode;
//		}
//		BinaryTreeNode<T>* p = GetParent(pNode->leftChild, sNode);
//		if (p != nullptr)
//			return p;
//		else return GetParent(pNode->rightChild, sNode);
//	}
//	//���Ŀ���
//	void CopyTree(BinaryTree<T>* TargetTree)
//	{
//		CopyTree(root, TargetTree->root);
//	}
//	void CopyTree(BinaryTreeNode<T>* pSource, BinaryTreeNode<T>*& pTargetTree)
//	{
//		if (pSource == nullptr) { pTargetTree = nullptr; }
//		else
//		{
//			pTargetTree = new BinaryTreeNode<T>;
//			pTargetTree->date = pSource->date;
//			CopyTree(pSource->leftChild, pTargetTree->leftChild);
//			CopyTree(pSource->rightChild, pTargetTree->rightChild);
//		}
//	}
//
//
//private:
//	BinaryTreeNode<T>* root;
//};
//
//
//
//
//
//
//int main()
//{
//	BinaryTree<int> B1;
//	BinaryTreeNode<int>* RootPoint = B1.CreateNode(nullptr, E_Root, 'A');
//	BinaryTreeNode<int>* SubPoint = B1.CreateNode(RootPoint, E_ChildLeft, 'B');
//	SubPoint = B1.CreateNode(SubPoint, E_ChildLeft, 'D');
//	SubPoint = B1.CreateNode(RootPoint, E_ChildRight, 'C');
//	SubPoint = B1.CreateNode(SubPoint, E_ChildRight, 'E');
//	BinaryTree<int> B2;
//	B2.CreatBT((char*)"ABD###C#E##");
//	cout << "ǰ���������Ϊ��" << endl;
//	B2.preOrder();
//	cout << endl << "��������Լ��Ƿ�Ϊ��ȫ������" << endl;
//	B2.levelOrder();
//	cout << "�������ڵ����Ϊ��" << B2.GetNum() << endl;
//	cout << "�������ĸ߶�Ϊ" << B2.GetHeight() << endl;
//	int val = 'D';
//	BinaryTreeNode<int>* p = B2.SearchElem(val);
//	if (p != nullptr)
//	{
//		cout << "�ҵ���ֵΪ��" << (char)val << "�Ľڵ�" << endl;
//	}
//	else
//	{
//		cout << "û���ҵ�ֵΪ��" << (char)val << "�Ľڵ�" << endl;
//	}
//	BinaryTreeNode<int>* pNode = B2.GetParent(p);
//	if (pNode != nullptr)
//	{
//		if (p != nullptr)
//			cout << "�ҵ���ֵΪ" << (char)p->date << "�ڵ�ĸ��ڵ�,���ڵ��ֵΪ" << (char)pNode->date << endl;
//	}
//	else
//	{
//		if (p != nullptr)
//			cout << "û�ҵ�ֵΪ" << (char)p->date << "�ڵ�ĸ��ڵ�" << endl;
//	}
//	BinaryTree<int>B3;
//	B2.CopyTree(&B3);
//
//}