#include "Assistance.h"			// ���������
#include "BubbleSort.h"		// ���������㷨

int main(void)
{
	int a[] = {55, 63, 38, 21, 63, 92, 16, 46, 87, 72};
	int n = 10;
	cout << "����ǰ:";
	Display(a, n);				// ��ʾa
	BubbleSort(a, n);			// ��������
	cout << "�����:";
	Display(a, n);				// ��ʾa

	system("PAUSE");			// ���ÿ⺯��system()
	return 0;					// ����ֵ0, ���ز���ϵͳ
}
