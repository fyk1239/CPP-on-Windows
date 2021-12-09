#include "calculator.h" // 计算器类
#include "linkstack.h"	// 顺序栈类
#include "utility.h"	// 实用程序软件包

int main()
{
	do
	{
		try // 用try封装可能出现异常的代码
		{
			cout << "输入一个表达式:" << endl;
			Calculator::Run(); // 表达式求值
			cout << "是否继续(y, n)?";
		}
		catch (Error err) // 捕捉并处理异常
		{
			err.Show(); // 显示异常信息
			cout << "是否继续(y, n)?";
		}
	} while (UserSaysYes());
	
	system("PAUSE"); // 调用库函数system()
	return 0;		 // 返回值0, 返回操作系统
}