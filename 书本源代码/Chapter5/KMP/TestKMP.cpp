#include "Assistance.h"	      // ʵ�ó��������
#include "KMP.h"		      // KMP�㷨

int main(void)
{	// ��ʽKMP�ַ���ģʽƥ���㷨
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

	system("PAUSE");        // ���ÿ⺯��system()
	return 0;               // ����ֵ0, ���ز���ϵͳ
}
