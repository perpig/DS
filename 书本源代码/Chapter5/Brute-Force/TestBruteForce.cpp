#include "Assistance.h"	    // ���������
#include "Brute-Force.h"	// �㷨

int main(void)
{	// ��ʽ���ַ���ģʽƥ���㷨
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

	system("PAUSE");        // ���ÿ⺯��system()
	return 0;               // ����ֵ0, ���ز���ϵͳ
}
