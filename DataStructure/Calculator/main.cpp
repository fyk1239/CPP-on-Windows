#include "calculator.h" // 计算器类
#include "lk_stack.h"	// 顺序表类
#include "utility.h"	// 实用程序软件包

int main(void)
{
	try // 用try封装可能出现异常的代码
	{
		do
		{
			cout << "输入一个表达式:" << endl;
			Calculator::Run(); // 表达式求值

			cout << "是否继续";
		} while (UserSaysYes());
	}
	catch (Error err) // 捕捉并处理异常
	{
		err.Show(); // 显示异常信息
	}

	system("PAUSE"); // 调用库函数system()
	return 0;		 // 返回值0, 返回操作系统
}