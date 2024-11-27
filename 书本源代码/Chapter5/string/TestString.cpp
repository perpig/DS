#include "Assistance.h"		// 辅助软件包
#include "String.h"			// 串类

int main(void)
{
	// 测试构造函数
	String s1("测试构造函数");
	Write(s1);
	String s2(s1);
	Write(s2);
	
	// 测试Copy()
	s2 = "This is a string.";
	Copy(s1 ,s2);
	Write(s1);
	Copyn(s1 ,s2, 4);
	Write(s1);

	// 测试Insert()
	s1 = "bcdefg.";
	s2 = "xy";
	Insert(s1, s2, 5);
	Write(s1);
	cout << endl;

	// 测试Delete()
	s1 = "abcdefghijkl.";
	Delete(s1, 2, 4);
	Write(s1);

	// 测试关系运算符 
	s1 = "This is a string.";
	s2 = "This is a string.";
	if (s1 == s2) 
       cout << "s1和s1相等。"<< endl;
    else 
       cout << "s1和s1不相等。"<< endl;
 
	// 测试SubString()
	String strTmp = SubString(s1, 2, 8);
	Write(strTmp);

	// 测式下标运算符
	cout << s1[1] << endl;
	
	// 测试+运算符 
 	s1 = "This is a";
	s2 = " string.";
	s1 = s1 + s2;
	Write(s1);
	cout << endl;

	system("PAUSE");        // 调用库函数system()
	return 0;               // 返回值0, 返回操作系统
}
