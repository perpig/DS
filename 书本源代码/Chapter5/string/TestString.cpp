#include "Assistance.h"		// ���������
#include "String.h"			// ����

int main(void)
{
	// ���Թ��캯��
	String s1("���Թ��캯��");
	Write(s1);
	String s2(s1);
	Write(s2);
	
	// ����Copy()
	s2 = "This is a string.";
	Copy(s1 ,s2);
	Write(s1);
	Copyn(s1 ,s2, 4);
	Write(s1);

	// ����Insert()
	s1 = "bcdefg.";
	s2 = "xy";
	Insert(s1, s2, 5);
	Write(s1);
	cout << endl;

	// ����Delete()
	s1 = "abcdefghijkl.";
	Delete(s1, 2, 4);
	Write(s1);

	// ���Թ�ϵ����� 
	s1 = "This is a string.";
	s2 = "This is a string.";
	if (s1 == s2) 
       cout << "s1��s1��ȡ�"<< endl;
    else 
       cout << "s1��s1����ȡ�"<< endl;
 
	// ����SubString()
	String strTmp = SubString(s1, 2, 8);
	Write(strTmp);

	// ��ʽ�±������
	cout << s1[1] << endl;
	
	// ����+����� 
 	s1 = "This is a";
	s2 = " string.";
	s1 = s1 + s2;
	Write(s1);
	cout << endl;

	system("PAUSE");        // ���ÿ⺯��system()
	return 0;               // ����ֵ0, ���ز���ϵͳ
}
