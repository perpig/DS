#include "Assistance.h"			// ����������
#include "QuickSort.h"			// ���������㷨

int main(void)
{
	int a[] = {55, 63, 38, 21, 63, 92, 16, 46, 87, 72};
	int n = 10;
	cout << "����ǰ:";
	Display(a, n);				 
	QuickSort(a, 0, n - 1, n);	
	cout << "�����:";
	Display(a, n);				

	system("PAUSE");			
	return 0;					
}
