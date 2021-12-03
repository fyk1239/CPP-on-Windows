#include "shell_sort.h" // 希尔排序算法
#include "utility.h"	// 实用程序软件包

int main(void)
{
	int a[] = {8, 3, 6, 1, 68, 12, 19, 3, 1};
	int inc[] = {5, 3, 1};
	int n = 9, t = 3;
	cout << "排序前:";
	Display(a, n);			 // 显示a
	ShellSort(a, n, inc, t); // 希尔排序
	cout << "排序后:";
	Display(a, n); // 显示a

	system("PAUSE"); // 调用库函数system()
	return 0;		 // 返回值0, 返回操作系统
}