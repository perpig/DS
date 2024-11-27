#include "Assistance.h"					// ���������
#include "ChildParentTree.h"			// ����˫�ױ�ʾ����

int main(void)
{
    try									// ��try��װ���ܳ����쳣�Ĵ���
	{
		char items[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
		int parents[] = {-1, 0, 0, 0, 1, 1, 3, 3};
		int r = 0, n = 8, cur;
		ChildParentTree<char> t(items, parents, r, n);
		cout << "��:" << endl;
		DisplayTWithConcaveShape(t);
		cout << endl;
		system("PAUSE");				// ���ÿ⺯��system()

		cout << "�ȸ��������:";
		t.PreRootOrder(Write);
		cout << endl;
		cout << "����������:";
		t.PostRootOrder(Write);
		cout << endl;
		cout << "��α�����:";
		t.LevelOrder(Write);
		cout << endl;
		cout << "����:";
		cout << t.Height();
		cout << endl;
		cout << "���Ķ�:";
		cout << t.Degree();
		cout << endl;
		char e;
		t.GetElem(t.GetRoot(), e);
		cout << "���" << e << "�Ķ�:" << t.NodeDegree(t.GetRoot()); 
		cout << endl;
		system("PAUSE");				// ���ÿ⺯��system()

		cur = t.GetRoot();
		e = 'X';
		t.InsertChild(cur, 2, e);

		cur = t.FirstChild(cur);
		e = 'Y';
		t.InsertChild(cur, 1, e);

		cout << "��:" << endl;
		DisplayTWithConcaveShape(t);
		cout << endl;
		system("PAUSE");				// ���ÿ⺯��system()
		
		int p, c;
		p = t.GetRoot();
		c = t.FirstChild(p);
		p = t.Parent(c);
		char pElem, cElem;
		t.GetElem(p, pElem);
		t.GetElem(c, cElem);
		cout << cElem << "˫����:" << pElem;
		cout << endl;
	}
	catch (Error err)					// ��׽�������쳣
	{
		err.Show();						// ��ʾ�쳣��Ϣ
	}

	system("PAUSE");					// ���ÿ⺯��system()
	return 0;							// ����ֵ0, ���ز���ϵͳ
}

