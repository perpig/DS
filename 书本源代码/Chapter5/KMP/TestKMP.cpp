#include "Assistance.h"	      // 实用程序软件包
#include "KMP.h"		      // KMP算法

int main(void)
{	// 测式KMP字符串模式匹配算法
	String ob("this is a string");
	String pat("is");
	cout << KMP_find(ob, pat) << endl;

	cout << KMP_find(ob, pat, 3) << endl;

	pat="string";
	cout << KMP_find(ob, pat) << endl;
	
	pat="this";
	cout << KMP_find(ob, pat) << endl;

	cout << KMP_find(ob, pat, 1) << endl;

	pat="that";
	cout << KMP_find(ob, pat) << endl;

	pat="this is a string!";
	cout << KMP_find(ob, pat) << endl;

	pat=ob;
	cout << KMP_find(ob, pat) << endl;

	system("PAUSE");        // 调用库函数system()
	return 0;               // 返回值0, 返回操作系统
}
