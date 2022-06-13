#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
// 动态规划算法，grid[i][j]表示从grid[0][0]到grid[i][j]的最小路径和
void least_sum_of_route(vector<vector<int>> &grid, int m, int n)
{
    // 处理边界元素，左边界与上边界元素均只有一种方式到达，选取上一个位置的数字与原有的数字相加作为当前路径和
    for (int j = 1; j < n; ++j)
        grid[0][j] += grid[0][j - 1];
    for (int i = 1; i < m; ++i)
        grid[i][0] += grid[i - 1][0];
    // 处理其余元素，中间的元素可由左边与上边的元素到达，需选取两者中较小的数字与原有的数字相加作为当前路径和
    for (int i = 1; i < m; ++i)
        for (int j = 1; j < n; ++j)
            grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
    // 输出最终结果
    cout << grid[m - 1][n - 1] << endl;
}
int main()
{
    // 输入数据
    int m, n;
    while (cin >> m >> n)
    {
        vector<vector<int>> grid(m, vector<int>(n));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                cin >> grid[i][j];
        // 输出结果
        least_sum_of_route(grid, m, n);
        // 清空数组
        grid.clear();
    }
    system("pause");
    return 0;
}