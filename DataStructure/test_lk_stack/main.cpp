#include "utility.h"	// ʵ�ó��������
#include "lk_stack.h"	// ��ջ��

int main(void)
{
	char c = '0';
    LinkStack<double> sa,sb;
    double x;
    while (c != '6')
	{
        cout << endl << "1. ����ջ.";
        cout << endl << "2. ��ʾջ.";
        cout << endl << "3. ��ջ.";
        cout << endl << "4. ��ջ.";
        cout << endl << "5. ȡջ��.";
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
						sa.Push(x);
				}
				break;
	       case '2':
			    sb = sa;
				cout << endl;
			    sb.Traverse(Write<double>);
				break;
		   case '3':
			    cout << endl << "����Ԫ��ֵ:";
			    cin >> x;
			    sa.Push(x);
			    break;
           case '4':
			    sa.Pop(x);
			    cout << endl << "ջ��Ԫ��ֵΪ " << x << " ." << endl;
			    break;
           case '5':
			    sa.Top(x);
			    cout << endl << "ջ��Ԫ��ֵΪ " << x << " ." << endl;
			    break;
		   case '6':;
		}
	}

	system("PAUSE");        // ���ÿ⺯��system()
	return 0;               // ����ֵ0, ���ز���ϵͳ
}


