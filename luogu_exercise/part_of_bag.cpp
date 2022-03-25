#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
struct Thing
{
    int mass;
    double value, per;
};

bool cmp(Thing a, Thing b)
{
    return a.per > b.per;
}

// P2240 【深基12.例1】部分背包问题
int main()
{
    int num, weight;
    double result;
    Thing things[105];
    cin >> num >> weight;
    for (int i = 0; i < num; i++)
    {
        cin >> things[i].mass >> things[i].value;
        things[i].per = things[i].value / things[i].mass;
    } // 输入数据

    sort(things + 1, things + num + 1, cmp);
    for (int i = 0; i < num; i++)
    {
        if (weight - things[i].mass > 0)
        {
            weight -= things[i].mass;
            result += things[i].value;
        }
        else
        {
            result += weight * things[i].per;
            weight = 0;
            break;
        }
    }
    cout << fixed << setprecision(2) << result;

    return 0;
}

/* #include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
struct Item
{
    int c, w;
}; //定义结构体，c代表价值，w代表重量
Item item[1010];
bool cmp(Item a, Item b)
{
    return a.w * b.c > b.w * a.c;
} //排序函数，说白了就是比性价比
int main()
{
    int N, V;
    cin >> N >> V;
    for (int i = 1; i <= N; i++)
    {
        cin >> item[i].c >> item[i].w;
    }
    sort(item + 1, item + N + 1, cmp); //输入后排序
    double ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (V <= item[i].c)
        {
            ans += (double)item[i].w / item[i].c * V; //因为上面结构体定义的w是int不是double，前面一定加(double)或1.0 * 。
            V = 0;
            break; //如果背包容量不够放下所有这种金币，就把背包装满，然后break。
        }
        else
        {
            ans += item[i].w;
            V -= item[i].c;
        } //够的话全装进去
    }
    printf("%.2lf", ans); //保留2位小数输出
    return 0;
} */