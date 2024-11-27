#include "Assistance.h"					  // ������������
#include "InThreadBinaryTree.h"		  // ����������������

int main(void)
{
    try		{							  // ��try��װ���ܳ����쳣�Ĵ���
		char pre[]={'A','B','D','E','G','C','F'};		// ��������
		char in[]={'D','B','G','E','A','C','F'};		// ��������
		int n = 7;						  // ������
		BinaryTree<char> bt;
		bt = CreateBinaryTree(pre, in, n);// ���������
		cout << "��pre[]={A,B,D,E,G,C,F},in[]={D,B,G,E,A,C,F}���������:" << endl;
		DisplayBTWithTreeShape<char>(bt);
		cout << endl;
		system("PAUSE");	

		cout << "���������������������:" << endl;
		InThreadBinTree<char> thrBt1(bt);
		DisplayBTWithTreeShape<char>(thrBt1);
		system("PAUSE");		
	
		cout << "�������:" << endl;
		thrBt1.InOrder(Write<char>);
		cout<<endl;
		system("PAUSE");		

		InThreadBinTree<char> thrBt2(thrBt1);	
		cout << "���ƹ�������������:" << endl;
		DisplayBTWithTreeShape<char>(thrBt2);
		system("PAUSE");			
	
		cout << "�������:" << endl;
		thrBt2.InOrder(Write<char>);
		cout<<endl;
		system("PAUSE");			

		thrBt2 = thrBt1;
		ThreadBinTreeNode<char> *p = thrBt2.GetFirst();
		p = thrBt2.GetNext(p);
		thrBt2.InsertRightChild(p,'H');
		cout << "�����������������:" << endl;
		DisplayBTWithTreeShape<char>(thrBt2);
		system("PAUSE");			
	
		cout << "�������:" << endl;
		thrBt2.InOrder(Write<char>);
		cout<<endl;

		thrBt2.DeleteLeftChild(p);
		cout << "ɾ����������������:" << endl;
		DisplayBTWithTreeShape<char>(thrBt2);
		system("PAUSE");			
	
		cout << "�������:" << endl;
		thrBt2.InOrder(Write<char>);
		cout<<endl;
	}
	catch (Error err)	{				// ��׽�������쳣
		err.Show();						// ��ʾ�쳣��Ϣ
	}

	system("PAUSE");	
	return 0;				
}

