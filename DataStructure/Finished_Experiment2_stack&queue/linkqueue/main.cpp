#include "linkqueue.h" // 链队列类
#include "utility.h"  // 实用程序软件包

int main(void)
{
	char code = '0';
	LinkQueue<double> qa, qb;
	double x;

	while (code != '6')
	{
		cout << endl
			 << "1. 生成队列.";
		cout << endl
			 << "2. 显示队列.";
		cout << endl
			 << "3. 入队列.";
		cout << endl
			 << "4. 出队列.";
		cout << endl
			 << "5. 取队列头.";
		cout << endl
			 << "6. 退出";
		cout << endl
			 << "选择功能(1~6):";
		cin >> code;
		switch (code)
		{
		case '1':
			cout << endl
				 << "输入e(e = 0时退出)";
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
			cout << endl
				 << "输入元素值:";
			cin >> x;
			qa.InQueue(x);
			break;
		case '4':
			qa.OutQueue(x);
			cout << endl
				 << "队头元素值为 " << x << " ." << endl;
			break;
		case '5':
			qa.GetHead(x);
			cout << endl
				 << "队头元素值为 " << x << " ." << endl;
			break;
		case '6':;
		}
	}

	system("PAUSE"); // 调用库函数system()
	return 0;		 // 返回值0, 返回操作系统
}