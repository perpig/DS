#include "Assistance.h"					// ���������
#include "BinSerach.h"					// ˳�����ͷ�ļ�

int main(void)
{
	int elem[] = {8, 11, 23, 34, 39, 46, 68, 71, 86};
	int n =9;
	int k = 71;
	int p = BinSerach(elem, n, k);		// �������۰���� 
	if (p >= 0)	// ���ҳɹ�
		cout << "���ҳɹ�,Ԫ��" << k << "��λ��Ϊ:" << p << endl;
	else	// ����ʧ��
		cout << "����ʧ��!" << endl;
  
    int low = 0, high = n-1;
    k = 23;
	p = BinSerach(elem, low, high, k);	// �ݹ���۰���� 
	if (p >= 0)	// ���ҳɹ�
		cout << "���ҳɹ�,Ԫ��" << k << "��λ��Ϊ:" << p << endl;
	else	// ����ʧ��
		cout << "����ʧ��!" << endl;
    
	system("PAUSE");
	return 0;

}
