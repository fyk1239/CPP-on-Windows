#include "utility.h"				// ʵ�ó��������
#include "gen_list.h"				// �����

int main(void)
{
	
    try								// ��try��װ���ܳ����쳣�Ĵ���
	{
		GenList<int> gList1;
		gList1.Push(3);
		gList1.Push(2);
		gList1.Push(1);
		gList1.Show();
		cout << endl;
		GenList<int> gList2;
		gList2.Push(4);
		gList1.Push(gList2);
		gList1.Show();
		cout << endl;

		GenList<int> gList3;
		gList3.Push(gList1);
		gList3.Show();
		cout << endl;

		cout << "gList3���:" << gList3.Depth() << endl;

		GenList<int> gList4(gList3);
		gList4 = gList3;
		gList4.Show();
		cout << endl;

		GenList<int> gList;
		cout << "����������eg: (12,(34)):" << endl;
		gList.Input();
		if (!gList.Empty())
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


