#include "Assistance.h"					  // 辅助软件软件包
#include "InThreadBinaryTree.h"		  // 中序线索二叉树类

int main(void)
{
    try		{							  // 用try封装可能出现异常的代码
		char pre[]={'A','B','D','E','G','C','F'};		// 先序序列
		char in[]={'D','B','G','E','A','C','F'};		// 中序序列
		int n = 7;						  // 结点个数
		BinaryTree<char> bt;
		bt = CreateBinaryTree(pre, in, n);// 构造二叉树
		cout << "由pre[]={A,B,D,E,G,C,F},in[]={D,B,G,E,A,C,F}构造二叉树:" << endl;
		DisplayBTWithTreeShape<char>(bt);
		cout << endl;
		system("PAUSE");	

		cout << "中序索化后的线索二叉树:" << endl;
		InThreadBinTree<char> thrBt1(bt);
		DisplayBTWithTreeShape<char>(thrBt1);
		system("PAUSE");		
	
		cout << "中序遍历:" << endl;
		thrBt1.InOrder(Write<char>);
		cout<<endl;
		system("PAUSE");		

		InThreadBinTree<char> thrBt2(thrBt1);	
		cout << "复制构造线索二叉树:" << endl;
		DisplayBTWithTreeShape<char>(thrBt2);
		system("PAUSE");			
	
		cout << "中序遍历:" << endl;
		thrBt2.InOrder(Write<char>);
		cout<<endl;
		system("PAUSE");			

		thrBt2 = thrBt1;
		ThreadBinTreeNode<char> *p = thrBt2.GetFirst();
		p = thrBt2.GetNext(p);
		thrBt2.InsertRightChild(p,'H');
		cout << "插入结点后线索二叉树:" << endl;
		DisplayBTWithTreeShape<char>(thrBt2);
		system("PAUSE");			
	
		cout << "中序遍历:" << endl;
		thrBt2.InOrder(Write<char>);
		cout<<endl;

		thrBt2.DeleteLeftChild(p);
		cout << "删除结点后线索二叉树:" << endl;
		DisplayBTWithTreeShape<char>(thrBt2);
		system("PAUSE");			
	
		cout << "中序遍历:" << endl;
		thrBt2.InOrder(Write<char>);
		cout<<endl;
	}
	catch (Error err)	{				// 捕捉并处理异常
		err.Show();						// 显示异常信息
	}

	system("PAUSE");	
	return 0;				
}

