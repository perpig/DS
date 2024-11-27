#include "Assistance.h"				// ʵ�ó��������
#include "GenList.h"			// �����

int main(void)
{
	
    try								// ��try��װ���ܳ����쳣�Ĵ���
	{
		GenList<int> gList1;
		gList1.Insert(3);
		gList1.Insert(2);
		gList1.Insert(1);
		gList1.Show();
		cout << endl;
		GenList<int> gList2;
		gList2.Insert(4);
		gList1.Insert(gList2);
		gList1.Show();
		cout << endl;

		gList1.Delete(1);
		gList1.Show();
		cout << endl;

		GenList<int> gList3;
		gList3.Insert(gList1);
		gList3.Show();
		cout << endl;

		cout << "gList3���:" << gList3.GetDepth() << endl;
		cout << "gList3����:" << gList3.GetLength() << endl;

		GenList<int> gList4(gList3);
		gList4 = gList3;
		gList4.Show();
		cout << endl;

		GenList<int> gList;
		cout << "����������eg: (12,(34)):" << endl;
		gList.Input();
		if (!gList.IsEmpty())
		{
			gList.Show();
			cout << endl;
		}
	}
	catch (Error err)		// ��׽�������쳣
	{
		err.Show();			// ��ʾ�쳣��Ϣ
	}

	system("PAUSE");        // ���ÿ⺯��system()
	return 0;               // ����ֵ0, ���ز���ϵͳ
}


