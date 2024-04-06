//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//#define MaxSize 100
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
//	bool isValid;
//};
//template <typename T>
//class BinaryTree
//{
//public:
//	BinaryTree()
//	{
//		for (int i = 0; i <= MaxSize; i++)
//		{
//			SqBiTree[i].isValid = false;
//		}
//	}
//	~BinaryTree(){}
//	int CreateNode(int parindex, ChildSigh pointSign, const T& e)
//	{
//		if (pointSign != E_Root)
//		{
//			if (!isValidRangIndex(parindex))
//			{
//				return -1;
//			}
//			if (SqBiTree[parindex].isValid == false)
//			{
//				return -1;
//			}
//		}
//		int index = -1;
//		if (pointSign == E_Root)
//		{
//			index = 1;
//		}
//		else if (pointSign == E_ChildLeft)
//		{
//			index = 2 * parindex;
//			if (isValidRangIndex(index) == false)
//			{
//				return -1;
//			}
//		}
//		else
//		{
//			index = 2 * parindex+1;
//			if (isValidRangIndex(index) == false)
//			{
//				return -1;
//			}
//		}
//		SqBiTree[index].date = e;
//		SqBiTree[index].isValid = true;
//		return index;
//
//	}
//	//获取父节点的下标
//	int GetParentIndex(int sonIndex)
//	{
//		if (!isValidRangIndex(sonIndex))
//		{
//			return -1;
//		}
//		if (SqBiTree[sonIndex].isValid == false)
//		{
//			return -1;
//		}
//		return int(sonIndex / 2);
//	}
//	//下标是否合法
//	bool isValidRangIndex(int index)      
//	{
//		if (index<1 || index>MaxSize)
//		{
//			return false;
//		}
//		return true;
//	}
//	//获取某个节点所在的高度
//	int GetOnesHeight(int index)
//	{
//		if (!isValidRangIndex(index))
//		{
//			return -1;
//		}
//		if (SqBiTree[index].isValid == false)
//		{
//			return -1;
//		}
//		int height = int(log(index) / log(2) + 1);
//		return height;
//	}
//	//计算二叉树的高度
//	int GetHeight()
//	{
//		if (SqBiTree[1].isValid == false)
//		{
//			return 0;
//		}
//		int i;
//		for (i = MaxSize; i >= 1; i--)
//		{
//			if (SqBiTree[i].isValid == true)
//			{
//				break;
//			}
//		}
//		return GetOnesHeight(i);
//	}
//	//判断是否为完全二叉树
//	bool isComlateBT()
//	{
//		if (SqBiTree[1].isValid == false)
//		{ return false; }
//		int i=0;
//		for ( i = MaxSize; i >= 1; i--)
//		{
//			if (SqBiTree[i].isValid == true)
//				break;
//		}
//		for (int k = 1; k <= i; k++)
//		{
//			if (SqBiTree[k].isValid == false)
//			{
//				return false;
//			}
//		}
//		return true;
//	}
//	//前序遍历二叉树
//	void preOrder()
//	{
//		if (SqBiTree[1].isValid == false) { return; }
//		preOrder(1);
//	}
//	void preOrder(int index)
//	{
//		if (!isValidRangIndex(index))
//		{
//			return ;
//		}
//		if (SqBiTree[index].isValid == false)
//		{
//			return ;
//		}
//		cout << (char)SqBiTree[index].date << " ";
//		preOrder(2 * index);
//		preOrder(2 * index+1);
//	}
//private:
//	BinaryTreeNode<T> SqBiTree[MaxSize + 1];// 下表为0的空间不使用
//};
//
//int main()
//{
//	BinaryTree<int> myTree;
//	int indexRoot = myTree.CreateNode(-1, E_Root, 'A');
//	int indexNodeB = myTree.CreateNode(indexRoot, E_ChildLeft, 'B');
//	int indexNodeC = myTree.CreateNode(indexRoot, E_ChildRight, 'C');
//	int indexNodeD = myTree.CreateNode(indexNodeB, E_ChildLeft, 'D');
//	int indexNodeE = myTree.CreateNode(indexNodeC, E_ChildLeft, 'E');
//	int iParentIndex = myTree.GetParentIndex(indexNodeE);
//	cout << "E的父亲节点下标为" << iParentIndex << endl;
//	int iHeight = myTree.GetOnesHeight(indexNodeD);
//	cout << "D所在的高度为" << iHeight << endl;
//	cout << "二叉树的高度为" << myTree.GetHeight() << endl;
//	cout << "该二叉树是否为完全二叉树：" << myTree.isComlateBT() << endl;
//	cout << "前序遍历结果为：" << endl;
//	myTree.preOrder();
//}
