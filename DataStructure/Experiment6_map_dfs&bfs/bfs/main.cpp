#include "utility.h"					// 实用程序软件包
#include "adj_list_dir_graph.h"			// 邻接表有向图
#include "bfs.h"						// 图的广度优先遍历

int main(void)
{
    try									// 用try封装可能出现异常的代码
	{
		char vexs[] = {'A', 'B', 'C', 'D'};
		int m[4][4] = {
			{0, 1, 0, 1},
			{1, 0, 1, 1},
			{0, 1, 0, 1},
			{1, 1, 1, 0}
		};
		int n = 4;

		AdjListDirGraph<char> g(vexs, n);

		for (int u = 0; u < n; u++)
		{	// 生成邻接矩阵的行
			for (int v = 0; v < n; v++)
			{	// 生成邻接矩阵元素的值
				if (m[u][v] == 1) g.InsertEdge(u, v);
			}
		}

		cout << "原有图:" << endl;
		Display(g);						// 显示图g
		cout << endl;
		system("PAUSE");				// 调用库函数system()

		cout << "广度优先遍历:";
		BFSTraverse<char>(g, Write);	// <char>用于确定函数模板参数
		cout << endl;
	}
	catch (Error err)					// 捕捉并处理异常
	{
		err.Show();						// 显示异常信息
	}

	system("PAUSE");					// 调用库函数system()
	return 0;							// 返回值0, 返回操作系统
}

