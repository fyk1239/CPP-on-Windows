#include <algorithm>
#include <cmath>
#include <iostream>
#define MAX 100005
using namespace std;

void planting_flowers(int* flowerbed, int length, int num)
{
    // available[i] = true表示flowerbed[i]可以种植，反之亦然。
    bool available[length];
    // 边界元素处理，若flowerbed[i] = 1，则其左右均不能种花，处理available[0]
    if (flowerbed[0] == 0 && flowerbed[1] == 0)
        available[0] = true;
    else
        available[0] = false;
    // 处理available[length - 1]
    if (flowerbed[length - 1] == 0 && flowerbed[length - 2] == 0)
        available[length - 1] = true;
    else
        available[length - 1] = false;
    // 处理其余数据，若flowerbed[i] = 1，则其左右均不能种花
    for (int i = 1; i < length; ++i)
    {
        if (flowerbed[i - 1] || flowerbed[i] || flowerbed[i + 1])
            available[i] = false;
        else
            available[i] = true;
    }
    // 贪心算法，选择最靠前的可种的（available[i] = true）地块
    for (int i = 0; i < length; ++i)
    {
        if (num)
        {
            if (available[i])
            {
                --num;
                available[i] = false;
                // 考虑边界情况
                if (!i)
                    available[i - 1] = false;
                if (i != length - 1)
                    available[i - 1] = false;
            }
        }
        else
            break;
    }
    // 输出最终结果
    if (num)
        cout << "false";
    else
        cout << "true";
    cout << endl;
}
int main()
{
    // 输入数据
    int length, num;
    while (cin >> length >> num)
    {
        int flowerbed[length];
        for (int i = 0; i < length; ++i)
            cin >> flowerbed[i];
        // 输出结果
        planting_flowers(flowerbed, length, num);
    }
    system("pause");
    return 0;
}