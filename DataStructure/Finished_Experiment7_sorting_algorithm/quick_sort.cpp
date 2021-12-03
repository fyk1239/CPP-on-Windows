#include "quick_sort.h" // 快速排序算法
#include "utility.h"	// 实用程序软件包

int main()
{
	int a[] = {8, 3, 6, 1, 68, 12};
	int n = 6;
	cout << "排序前:";
	Display(a, n);	 // 显示a
	QuickSort(a, n); // 快速排序
	cout << "排序后:";
	Display(a, n); // 显示a

	system("PAUSE"); // 调用库函数system()
	return 0;		 // 返回值0, 返回操作系统
}
