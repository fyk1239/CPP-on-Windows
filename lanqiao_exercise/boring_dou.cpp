#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 蓝桥杯练习 无聊的逗 借鉴版
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    vector<int> v2((1 << n));
    for (int i = 0; i < (1 << n); i++)
    { //(1<<n)即2^n
        for (int j = 0; j < n; j++)
        { //有n根木棒
            if (i & (1 << j))
            { //说明这个状态有这根木棒
                v2[i] += v[j];
            }
        }
    }
    int result = 0;
    //组合之间进行比较
    for (int i = 0; i < (1 << n); i++)
    { //(1<<n)即2^n
        for (int j = 0; j < (1 << n); j++)
        { //(1<<n)即2^n
            if (!(i & j) && v2[i] == v2[j])
            { //状态不同但是值相同 !(i&j)是为了判断两个组合中是否包含相同的木棒，如果包含相同的木棒，那么值不会是0
                result = max(result, v2[i]);
            }
        }
    }
    cout << result;
    return 0;
}