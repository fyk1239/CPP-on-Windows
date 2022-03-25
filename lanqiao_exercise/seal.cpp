#include <cmath>
#include <iostream>
using namespace std;

// 蓝桥杯训练 印章
double dp[25][25], p;
int main()
{
    int n, m;
    cin >> n >> m;
    p = 1.0 / n; //每种出现的概率

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i < j)
                dp[i][j] = 0;
            if (j == 1)
            {
                dp[i][j] = pow(p, i - 1); //p^(i-1)
            }
            else
            {
                dp[i][j] = dp[i - 1][j] * (j * 1.0 / n) + dp[i - 1][j - 1] * ((n - j + 1) * 1.0 / n);
            }
        }
    }
    //	cout << "dp\n";
    //		for ( int i = 1; i <= m; ++i ) {
    //		for ( int j = 1; j <= n; ++j ) {
    //			printf("%.2lf  ",dp[i][j]);
    //		}
    //		cout << endl;
    //	}

    printf("%.4lf  ", dp[m][n]);
    return 0;
}