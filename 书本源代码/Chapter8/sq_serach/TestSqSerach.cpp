#include "Assistance.h"		// ���������
#include "SqSerach.h"		// ˳�����ͷ�ļ�

int main(void)
{
	int elem[] = {8, 11, 23, 34, 46, 57, 61, 72, 98};
	int n =9;
	int k = 57;
	int p = SqSerach(elem, n, k);
	if (p >= 0)	// ���ҳɹ�
		cout << "���ҳɹ�,Ԫ��" << k << "��λ��Ϊ:" << p << endl;
	else		// ����ʧ��
		cout << "����ʧ��!" << endl;

	system("PAUSE");
	return 0;
}
