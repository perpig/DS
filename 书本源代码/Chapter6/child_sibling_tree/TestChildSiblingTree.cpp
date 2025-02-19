#include "Assistance.h"		  // 实用程序软件包
#include "ChildSiblingTree.h" // 孩子兄弟表示树类

int main(void)
{
	try // 用try封装可能出现异常的代码
	{
		char items[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
		int parents[] = {-1, 0, 0, 0, 1, 1, 3, 3};
		int n = 8;
		ChildSiblingTree<char> t(items, parents, n);
		cout << "树:" << endl;
		DisplayTWithConcaveShape(t);
		cout << endl;
		getchar();
		// system("PAUSE"); // 调用库函数system()

		cout << "先根序遍历树:";
		t.PreRootOrder(Write);
		cout << endl;
		cout << "后根序遍历树:";
		t.PostRootOrder(Write);
		cout << endl;
		cout << "层次遍历树:";
		t.LevelOrder(Write);
		cout << endl;
		cout << "树高:";
		cout << t.Height();
		cout << endl;
		cout << "树的度:";
		cout << t.Degree();
		cout << endl;
		char e;
		t.GetElem(t.GetRoot(), e);
		cout << "结点" << e << "的度:" << t.NodeDegree(t.GetRoot());
		cout << endl;
		getchar();
		//system("PAUSE"); // 调用库函数system()

		ChildSiblingTree<char> t1(t);
		cout << "复制构造树:" << endl;
		//		DisplayTWithConcaveShape<char>(t1);
		DisplayTWithConcaveShape(t1);
		cout << endl;
		getchar();
		//system("PAUSE"); // 调用库函数system()

		t1 = t;
		cout << "赋值语句重载构造树:" << endl;
		//		DisplayTWithConcaveShape<char>(t1);
		DisplayTWithConcaveShape(t1);
		cout << endl;
		getchar();
		//system("PAUSE"); // 调用库函数system()

		e = 'A';
		ChildSiblingTree<char> t2(e); // 生成以e为根的树

		ChildSiblingTreeNode<char> *cur = t2.GetRoot();
		e = 'B';
		t2.InsertChild(cur, 1, e);

		e = 'C';
		t2.InsertChild(cur, 2, e);

		cout << "树:" << endl;
		DisplayTWithConcaveShape(t2);
		cout << endl;
		ChildSiblingTreeNode<char> *f, *c;
		f = t2.GetRoot();
		c = t2.FirstChild(f);
		f = t2.Parent(c);
		cout << c->data << "双亲是:" << f->data;
		cout << endl;
		getchar();
		//system("PAUSE"); // 调用库函数system()

		cur = t2.GetRoot();
		t2.DeleteChild(cur, 2);
		cout << "删除根第二棵子树后:" << endl;
		DisplayTWithConcaveShape(t2);
		cout << endl;
	}
	catch (Error err) // 捕捉并处理异常
	{
		err.Show(); // 显示异常信息
	}
	
	getchar();
	//system("PAUSE"); // 调用库函数system()
	return 0;		 // 返回值0, 返回操作系统
}
