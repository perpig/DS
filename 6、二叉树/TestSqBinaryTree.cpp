#include "Assistance.h"					// 辅助软件包
#include "SqBinaryTree.h"				// 顺序存储二叉树类

void system_PAUSE()
{
	cout << "Press any key to continue . . ." ;
	cin.get();
}

int main(void)
{
	int p, c, l, r;
	char e, cElem, pElem, lElem, rElem;
	
	e = 'A';
	SqBinaryTree<char> bt(e,20);		// 建立二叉树
	
	e = 'B';
	p = bt.GetRoot();
	bt.InsertLeftChild(p, e);		// 插入左孩子

	e = 'C';
	bt.InsertRightChild(p, e);	// 插入右孩子
		
	p = bt.LeftChild(p);
	e = 'D';
	bt.InsertLeftChild(p, e);	// 插入右孩子

	p = bt.GetRoot();
	p = bt.RightChild(p);
	e = 'E';
	bt.InsertLeftChild(p, e);		// 插入左孩子
	e = 'F';
	bt.InsertRightChild(p, e);	// 插入右孩子

	c = bt.LeftChild(p);
	bt.GetElem(p, pElem);
	bt.GetElem(c, cElem);
	cout << cElem << "双亲是" << pElem << endl;
	p = bt.GetRoot();	// 根
	bt.GetElem(p, pElem);
	l = bt.LeftChild(p);			// 左孩子
	bt.GetElem(l, lElem);
	r = bt.RightSibling(l);		    // 右孩子
	bt.GetElem(r, rElem);

	cout << pElem << "左孩子是" << lElem;
	cout << ", 右孩子是" << rElem << endl;
	cout << "二叉树的高是" << bt.Height() << endl;

	cout << "原树:" << endl;
	DisplayBTWithTreeShape<char>(bt);
	cout << endl;
	system_PAUSE();			

	// cout << "叶子结点个数：" ;
	// cout << "3";
	// cout << endl;
	// system_PAUSE();					
		
	SqBinaryTree<char> btNew(bt);	// 复制构造新树
	cout << "复制构造新树:" << endl;
	DisplayBTWithTreeShape<char>(btNew);
	cout << endl;
	system_PAUSE();			

	btNew = bt;						// 赋值生成新树
	cout << "赋值生成新树:" << endl;
	DisplayBTWithTreeShape<char>(btNew);
	cout << endl;
	system_PAUSE();	

	cout << "结点数:" << bt.NodeCount();
	cout << endl;
	system_PAUSE();		

	cout << "先序遍历:" << endl;
	bt.PreOrder(Write<char>);
	cout<<endl;
	system_PAUSE();		

	cout << "中序遍历:" << endl;
	bt.InOrder(Write<char>);
	cout<<endl;
	system_PAUSE();	

	cout << "后序遍历:" << endl;
	bt.PostOrder(Write<char>);
	cout<<endl;
	system_PAUSE();	

	cout << "层次遍历:" << endl;
	bt.LevelOrder(Write<char>);
	cout<<endl;
	system_PAUSE();	

	p = bt.GetRoot();
	bt.DeleteRightChild(p);					
	cout << "删除根的右子树后:" << endl;
	DisplayBTWithTreeShape<char>(bt);
	cout << endl;
	system_PAUSE();				// 调用库函数system()

	char pre[]={'A','B','D','E','G','H','C','F','I'};		// 先序序列
	char in[]={'D','B','G','E','H','A','C','F','I'};		// 中序序列
	int n = 9, size=15;						// 结点个数
	SqBinaryTree<char> preInbt;
	preInbt = CreateBinaryTree(pre, in, n, size);// 构造二叉树
		
	cout << "由pre[]={'A','B','D','E','G','H','C','F','I'},in[]={'D','B','G','E','H','A','C','F','I'}构造二叉树:" << endl;
	DisplayBTWithTreeShape<char>(preInbt);
	cout << endl;

	system_PAUSE();

    cout << "作业题：" << endl;
	char pre1[] = {'B','E','F','C','G','D','H'};
	char in1[] = {'F','E','B','G','C','H','D'};
	int n1 = 7;					// 结点个数
	SqBinaryTree<char> preInbt1;
	preInbt1 = CreateBinaryTree(pre1, in1, n);// 构造二叉树
	DisplayBTWithTreeShape<char>(preInbt1);
	cout << endl;


	system_PAUSE();
	return 0;
}
