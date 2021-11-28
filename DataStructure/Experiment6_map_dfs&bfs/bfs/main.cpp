#include "utility.h"					// ʵ�ó��������
#include "adj_list_dir_graph.h"			// �ڽӱ�����ͼ
#include "bfs.h"						// ͼ�Ĺ�����ȱ���

int main(void)
{
    try									// ��try��װ���ܳ����쳣�Ĵ���
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
		{	// �����ڽӾ������
			for (int v = 0; v < n; v++)
			{	// �����ڽӾ���Ԫ�ص�ֵ
				if (m[u][v] == 1) g.InsertEdge(u, v);
			}
		}

		cout << "ԭ��ͼ:" << endl;
		Display(g);						// ��ʾͼg
		cout << endl;
		system("PAUSE");				// ���ÿ⺯��system()

		cout << "������ȱ���:";
		BFSTraverse<char>(g, Write);	// <char>����ȷ������ģ�����
		cout << endl;
	}
	catch (Error err)					// ��׽�������쳣
	{
		err.Show();						// ��ʾ�쳣��Ϣ
	}

	system("PAUSE");					// ���ÿ⺯��system()
	return 0;							// ����ֵ0, ���ز���ϵͳ
}

