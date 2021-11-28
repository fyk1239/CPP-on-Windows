#include "linkstack.h" // 链栈类
#include "utility.h"  // 实用程序软件包

int main()
{
	char code = '0';
	LinkStack<double> sa, sb;
	double x;
	while (code != '6')
	{
		cout << endl
			 << "1. 生成栈";
		cout << endl
			 << "2. 显示栈";
		cout << endl
			 << "3. 入栈";
		cout << endl
			 << "4. 出栈";
		cout << endl
			 << "5. 取栈顶";
		cout << endl
			 << "6. 退出";
		cout << endl
			 << "选择功能(1~6):";
		cin >> code;
		switch (code)
		{
		case '1':
			cout << endl
				 << "输入元素e(e = 0时退出)";
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
			cout << endl
				 << "请输入你想入栈的元素值e:";
			cin >> x;
			sa.Push(x);
			break;
		case '4':
			sa.Pop(x);
			cout << endl
				 << "原栈顶元素值为 " << x << " , 该元素已出栈。" << endl;
			break;
		case '5':
			sa.Top(x);
			cout << endl
				 << "栈顶元素值为 " << x << " 。" << endl;
			break;
		case '6':;
		}
	}

	system("PAUSE"); // 调用库函数system()
	return 0;		 // 返回值0, 返回操作系统
}
