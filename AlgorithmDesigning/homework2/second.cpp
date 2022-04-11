#include <iostream>
using namespace std;

int uniquePaths(int m, int n)
{
	vector<vector<int>> f(m, vector<int>(n));/ //创建对应的二维数组
	// 1、dp思想，赋初值并利用状态转移方程求解

	// 2 、返回结果
	return f......;
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
