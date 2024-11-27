#include "Assistance.h"
#include "MineHeap.h"

int main()
{
	int a[12]={80,57,99,35,23,11,74,29,62,16};
	MinHeap<int> ha(a,20,10);
	int e;
	cout<<endl;
	
	cout << "最小堆序列为：" << endl;
	ha.Traverse(Write<int>);
	cout << endl << endl;	
	
	cout << "插入元素 14 后的最小堆序列为：" << endl;
	ha.Insert(14);
	ha.Traverse(Write<int>);
	cout << endl << endl;
	
	ha.DeleteTop(e);
	cout<<"删除的堆顶元素为:"<<e<<endl;
	ha.Traverse(Write<int>);
	cout<<endl;
	
	system("pause");
	return 0;
}
