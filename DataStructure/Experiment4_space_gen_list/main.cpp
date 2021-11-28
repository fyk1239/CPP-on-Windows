#include "gen_list.h" // 广义表
#include "utility.h"  // 实用程序软件包

int main(void)
{

	try // 用try封装可能出现异常的代码
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

		cout << "广义表3深度:" << gList3.Depth() << endl;

		GenList<int> gList4(gList3);
		gList4 = gList3;
		gList4.Show();
		cout << endl;

		GenList<int> gList;
		cout << "请输入广义表，例如: (12,(34)):" << endl;
		gList.Input();
		if (!gList.Empty())
		{
			gList.Show();
			cout << endl;
		}
	}
	catch (Error err) // 捕捉并处理异常
	{
		err.Show(); // 显示异常信息
	}

	system("PAUSE"); // 调用库函数system()
	return 0;		 // 返回值0, 返回操作系统
}
