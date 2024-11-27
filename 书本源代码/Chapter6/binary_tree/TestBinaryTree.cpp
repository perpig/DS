#include "Assistance.h"		// ���������
#include "BinaryTree.h"		// ����������

int main(void)
{
	BinTreeNode<char> *p, *c, *f, *l, *r;
		
	char e, cElem, pElem, lElem, rElem;
	
	e = 'A';
	BinaryTree<char> bt(e);		// ����������
	cout << "A" << endl;
	if (bt.IsComBiTree ( ))
		cout << "����ȫ��������" << endl;
	else
		cout << "������ȫ��������" << endl;
	
	e = 'B';
	p = bt.GetRoot();
	bt.InsertLeftChild(p, e);	// ��������

	cout << "AB" << endl;
	if (bt.IsComBiTree ( ))
		cout << "����ȫ��������" << endl;
	else
		cout << "������ȫ��������" << endl;

	e = 'C';
	bt.InsertRightChild(p, e);	// �����Һ���
	cout << "ABC" << endl;
	if (bt.IsComBiTree ( ))
		cout << "����ȫ��������" << endl;
	else
		cout << "������ȫ��������" << endl;
		
	p = bt.LeftChild(p);
	e = 'D';
	bt.InsertLeftChild(p, e);	// �����Һ���
	cout << "ABCD" << endl;
	if (bt.IsComBiTree ( ))
		cout << "����ȫ��������" << endl;
	else
		cout << "������ȫ��������" << endl;


	p = bt.GetRoot();
	p = bt.RightChild(p);
	e = 'E';
	bt.InsertLeftChild(p, e);	// ��������
	
	cout << "ABCDE" << endl;
	if (bt.IsComBiTree ( ))
		cout << "����ȫ��������" << endl;
	else
		cout << "������ȫ��������" << endl;

	e = 'F';
	bt.InsertRightChild(p, e);	// �����Һ���

	c =  bt.LeftChild(p);
	bt.GetElem(p, pElem);
	bt.GetElem(c, cElem);
	cout << cElem << "˫����" << pElem << endl;

	p = bt.GetRoot();
	bt.GetElem(p, pElem);
	r = bt.RightChild(p);  	    // ȡ�����Һ���
	p = bt.Parent(r);
	bt.GetElem(r, rElem);
	l = bt.LeftSibling(r);		// ȡ��������
	bt.GetElem(l, lElem);

	cout << pElem << "������" << lElem;
	cout << ", �Һ�����" << rElem << endl;
	cout << "�������ĸ���" << bt.Height() << endl;

	cout << "ԭ��:" << endl;
	DisplayBTWithTreeShape<char>(bt);
	cout << endl;
	system("PAUSE");
		
	BinaryTree<char> btNew(bt);	// ���ƹ�������
	cout << "���ƹ�������:" << endl;
	DisplayBTWithTreeShape<char>(btNew);
	cout << endl;
	system("PAUSE");			

	btNew = bt;					// ��ֵ��������
	cout << "��ֵ��������:" << endl;
	DisplayBTWithTreeShape<char>(btNew);
	cout << endl;
	system("PAUSE");	

	cout << "�����:" << bt.NodeCount();
	cout << endl;
	system("PAUSE");		

	cout << "�������:" << endl;
	bt.PreOrder(Write<char>);
	cout<<endl;
	bt.PreOrderWithoutRecursion(Write<char>);
	cout<<endl;
	system("PAUSE");		

	cout << "�������:" << endl;
	bt.InOrder(Write<char>);
	cout<<endl;
	bt.InOrderWithoutRecursion(Write<char>);
	cout<<endl;
	system("PAUSE");	

	cout << "�������:" << endl;
	bt.PostOrder(Write<char>);
	cout<<endl;
	system("PAUSE");	

	cout << "��α���:" << endl;
	bt.LevelOrder(Write<char>);
	cout<<endl;
	
	if (bt.IsComBiTree ( ))
		cout << "����ȫ��������" << endl;
	else
		cout << "������ȫ��������" << endl;
	 
	system("PAUSE");	

	p = bt.GetRoot();
	bt.DeleteLeftChild(p);					
	cout << "ɾ��������������:" << endl;
	DisplayBTWithTreeShape<char>(bt);
	cout << endl;
	system("PAUSE");


	char pre[]={'A','B','D','E','G','H','C','F','I'}; // ��������
	char in[]={'D','B','G','E','H','A','C','F','I'};  // ��������
	int n = 9;						                  // ������
	BinaryTree<char> preInbt;
	preInbt = CreateBinaryTree(pre, in, n);           // ���������
		
	cout << "��pre[]={'A','B','D','E','G','H','C','F','I'},in[]={'D','B','G','E','H','A','C','F','I'}���������:" << endl;
	DisplayBTWithTreeShape<char>(preInbt);
	cout << endl;

	system("PAUSE");
	return 0;
}

