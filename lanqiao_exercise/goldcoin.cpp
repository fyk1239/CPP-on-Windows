#include <cmath>
#include <iostream>
using namespace std;

// 蓝桥杯训练 金币 未完成
int main()
{
    int n, max = 1005, dp[max][max] = 0;
    long sum_of_right = 0, sum_of_down = 0, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> dp[i][j];
        }
    }

    for (int i = 0, j = 0; i + j < 2n - 1;)
    {
    }
}