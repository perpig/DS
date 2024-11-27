#include "Assistance.h"
#include "MineHeap.h"

int main()
{
	int a[12]={80,57,99,35,23,11,74,29,62,16};
	MinHeap<int> ha(a,20,10);
	int e;
	cout<<endl;
	
	cout << "��С������Ϊ��" << endl;
	ha.Traverse(Write<int>);
	cout << endl << endl;	
	
	cout << "����Ԫ�� 14 �����С������Ϊ��" << endl;
	ha.Insert(14);
	ha.Traverse(Write<int>);
	cout << endl << endl;
	
	ha.DeleteTop(e);
	cout<<"ɾ���ĶѶ�Ԫ��Ϊ:"<<e<<endl;
	ha.Traverse(Write<int>);
	cout<<endl;
	
	system("pause");
	return 0;
}
