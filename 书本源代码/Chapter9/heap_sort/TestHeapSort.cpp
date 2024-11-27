#include "Assistance.h"				// ¸¨ÖúÈí¼ş°ü
#include "HeapSort.h"				// ¶ÑÅÅĞòËã·¨

int main(void)
{
	int a[] = {55, 63, 38, 21, 63, 92, 16, 46, 87, 72};
	int n = 10;
	cout << "ÅÅĞòÇ°:";
	Display(a, n);					 
	HeapSort(a, n);					// ¶ÑÅÅĞò
	cout << "ÅÅĞòºó:";
	Display(a, n);					

	system("PAUSE");				
	return 0;						
}
