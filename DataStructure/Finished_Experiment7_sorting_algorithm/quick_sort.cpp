#include "quick_sort.h" // 快速排序算法
#include "utility.h"	// 实用程序软件包

int main()
{
	int a[11];
	for (int i = 0; i < 11; i++)
	{
		cin >> a[i];
	}
	
	cout << "排序前:";
	Display(a, 11);	 // 显示a
	QuickSort(a, 11); // 快速排序
	cout << "排序后:";
	Display(a, 11); // 显示a

	system("PAUSE"); // 调用库函数system()
	return 0;		 // 返回值0, 返回操作系统
}
