#include "utility.h"		// 实用程序软件包
#include "kmpmatch.h"		// KMP算法

int main()
{	// 测式KMP字符串模式匹配算法
	String T("this is a string");
	String P("is");

	cout << KMPIndex(T, P) << endl;
	cout << KMPIndex(T, P, 3) << endl;
	cout << KMPIndex(T, P, 6) << endl;
	T=P;
	cout << KMPIndex(T, P) << endl;

	system("PAUSE");        // 调用库函数system()
	return 0;               // 返回值0, 返回操作系统
}