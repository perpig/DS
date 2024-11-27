#include "Assistance.h"		// 辅助软件包
#include "BinaryTree.h"		// 二叉链表类
#include<iostream>
int main()
{
	BinTreeNode<char>* p;
	char e;
	e = 'A';
	BinaryTree<char> bt(e);		// 建立二叉树
	e = 'B';
	p = bt.GetRoot();
	bt.InsertLeftChild(p, e);	// 插入左孩子
	e = 'C';
	bt.InsertRightChild(p, e);	// 插入右孩子
	p = bt.LeftChild(p);
	e = 'D';
	bt.InsertLeftChild(p, e);	// 插入右孩子
	p = bt.GetRoot();
	p = bt.RightChild(p);
	e = 'E';
	bt.InsertLeftChild(p, e);	// 插入左孩子
	e = 'F';
	bt.InsertRightChild(p, e);	// 插入右孩子
	// 显示原始二叉树
	cout << "原树:" << endl;
	DisplayBTWithTreeShape(bt);
	BinTreeNode<char>* newRoot = bt.Revolute(bt.GetRoot());// 调用Revolute函数进行左右子树交换
	BinaryTree<char> newTree(newRoot);// 构造一个新的二叉树对象，以新的根结点为根
	cout << "\n交换后的树:" << endl;// 显示交换左右子树后的二叉树
	DisplayBTWithTreeShape(newTree);

	int n, a, b, i;
	cout << "输入计算行数："<<endl;
	cin >> n;
	int left[100], right[100];//构建数组储存每一组计算结果
	for (i = 0; i < n; i++)
		left[i] = 0, right[i] = 0;//初始化数组
	cout << "请输入数据：" << endl;
	for (i = 0; i < n; i++)
	{
		cin >> a >> b;
		while (1)
		{
			if (a > b)
			{
				a = a - b;
				left[i]++;//如果a>b，说明该结点为左子树
			}
			if (a < b)
			{
				b = b - a;
				right[i]++; //如果a<b，说明该结点为右子树
			}
			if (a == b) break;
		}
	}
	cout << "结果为：" << endl;
	for (i = 0; i < n; i++)
	{
		cout << left[i] << " " << right[i] << endl;
	}
	return 0;
}
