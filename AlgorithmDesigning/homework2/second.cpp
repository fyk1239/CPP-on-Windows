#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n)
{
	vector<vector<int>> f(m, vector<int>(n));
	// ������Ӧ�Ķ�ά����
	// 1��dp˼�룬����ֵ������״̬ת�Ʒ������
	f[0][0] = 1;
	for (int i = 1; i < m; i++)
		f[i][0] = 1;
	for (int j = 1; j < n; j++)
		f[0][j] = 1;

	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			f[i][j] = f[i - 1][j] + f[i][j - 1];
		}
	}
	// 2 �����ؽ��
	return f[m - 1][n - 1];
}

int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		cout << uniquePaths(m, n) << endl;
	}
	return 0;
}
