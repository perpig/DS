#include "Assistance.h"				// 实用程序软件包
#include "GenList.h"			// 广义表

int main(void)
{
	
    try								// 用try封装可能出现异常的代码
	{
		GenList<int> gList1;
		gList1.Insert(3);
		gList1.Insert(2);
		gList1.Insert(1);
		gList1.Show();
		cout << endl;
		GenList<int> gList2;
		gList2.Insert(4);
		gList1.Insert(gList2);
		gList1.Show();
		cout << endl;

		gList1.Delete(1);
		gList1.Show();
		cout << endl;

		GenList<int> gList3;
		gList3.Insert(gList1);
		gList3.Show();
		cout << endl;

		cout << "gList3深度:" << gList3.GetDepth() << endl;
		cout << "gList3长度:" << gList3.GetLength() << endl;

		GenList<int> gList4(gList3);
		gList4 = gList3;
		gList4.Show();
		cout << endl;

		GenList<int> gList;
		cout << "请输入广义表eg: (12,(34)):" << endl;
		gList.Input();
		if (!gList.IsEmpty())
		{
			gList.Show();
			cout << endl;
		}
	}
	catch (Error err)		// 捕捉并处理异常
	{
		err.Show();			// 显示异常信息
	}

	system("PAUSE");        // 调用库函数system()
	return 0;               // 返回值0, 返回操作系统
}


