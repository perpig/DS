#include "Assistance.h"	    // 辅助软件包
#include "Brute-Force.h"	// 算法

int main(void)
{	// 测式简单字符串模式匹配算法
	String ob("this is a string");
	String pat("is");
	cout << BF_find(ob, pat) << endl;

	cout << BF_find(ob, pat, 3) << endl;

	pat="string";
	cout << BF_find(ob, pat) << endl;
	
	pat="this";
	cout << BF_find(ob, pat) << endl;

	cout << BF_find(ob, pat, 3) << endl;

	pat="that";
	cout << BF_find(ob, pat) << endl;

	pat="this is a string!";
	cout << BF_find(ob, pat) << endl;

	pat=ob;
	cout << BF_find(ob, pat) << endl;

	system("PAUSE");        // 调用库函数system()
	return 0;               // 返回值0, 返回操作系统
}
