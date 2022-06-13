#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define MAX 100005
using namespace std;
struct node
{
    int x;    // 横坐标
    int y;    // 纵坐标
    int time; // 腐烂时间
};

int orangesRotting(vector<vector<int>> &grid, int m, int n)
{
    queue<node> Q;                            // 烂橘子队列
    int g[4][2] = {0, 1, 0, -1, 1, 0, -1, 0}; // 初始化四个方向
    int min_time = 0;                         // 橘子全部腐烂的最小时间
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2) // 是已经腐烂了的橘子
            {
                node first;
                first.x = i;
                first.y = j;
                first.time = 0; // 初始化一个烂橘子结点
                Q.push(first);  // 把这个烂橘子进入烂橘子队列
            }
        }
    }
    while (!Q.empty()) // 当还有烂橘子在队列中
    {
        node now = Q.front(); // 将最先进队列的烂橘子出列
        Q.pop();
        min_time = now.time;
        for (int i = 0; i < 4; i++)
        {
            if ((now.x + g[i][0]) >= 0 && (now.x + g[i][0]) < n && (now.y + g[i][1]) >= 0 && (now.y + g[i][1]) < m)
            {
                if (grid[now.x + g[i][0]][now.y + g[i][1]] == 1) // 如果是新鲜的橘子
                {
                    node new_node; // 新建烂橘子结点
                    new_node.x = now.x + g[i][0];
                    new_node.y = now.y + g[i][1];
                    new_node.time = now.time + 1;
                    Q.push(new_node);                 // 进入烂橘子队列
                    grid[new_node.x][new_node.y] = 2; // 开始腐烂
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 1) // 如果还有未腐烂的橘子
                return -1;       // 返回-1
    return min_time;             // 返回橘子全部腐烂的最小时间
}
int main()
{
    int m, n;
    // 输入数据
    while (cin >> m >> n)
    {
        vector<vector<int>> grid(m, vector<int>(n));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                cin >> grid[i][j];
        // 输出结果
        cout << orangesRotting(grid, m, n) << endl;
    }
    system("pause");
    return 0;
}