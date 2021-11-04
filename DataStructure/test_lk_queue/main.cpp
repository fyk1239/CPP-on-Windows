#include "utility.h"	// ʵ�ó��������
#include "lk_queue.h"	// ��������

int main(void)
{
	char c = '0';
    LinkQueue<double> qa,qb;
    double x;

    while (c != '6')
	{
        cout << endl << "1. ���ɶ���.";
        cout << endl << "2. ��ʾ����.";
        cout << endl << "3. �����.";
        cout << endl << "4. ������.";
        cout << endl << "5. ȡ����ͷ.";
		cout << endl << "6. �˳�";
		cout << endl << "ѡ����(1~6):";
		cin >> c;
		switch (c) 
		{
			case '1':
				cout << endl << "����e(e = 0ʱ�˳�)";
				while (x != 0)
				{
					cin >> x;
					if (x != 0)
						qa.InQueue(x);
				}
				break;
	       case '2':
			    qb = qa;
				cout << endl;
			    qb.Traverse(Write<double>);
				break;
		   case '3':
			    cout << endl << "����Ԫ��ֵ:";
			    cin >> x;
			    qa.InQueue(x);
			    break;
           case '4':
			    qa.OutQueue(x);
			    cout << endl << "��ͷԪ��ֵΪ " << x << " ." << endl;
			    break;
           case '5':
			    qa.GetHead(x);
			    cout << endl << "��ͷԪ��ֵΪ " << x << " ." << endl;
			    break;
		   case '6':;
		}
	}

	system("PAUSE");        // ���ÿ⺯��system()
	return 0;               // ����ֵ0, ���ز���ϵͳ
}


