#include <bits/stdc++.h>
#define F(i, n, m) for (int i = n; i <= m; i++)
using namespace std;
int n, a[1000001];
void mysort(int l, int r) //自己写的快排
{
    int mid = a[(l + r) / 2]; //找中间的数进行2分
    int i = l, j = r;
    do
    {
        while (a[i] < mid)
            i++; //找左半部分大于中间数的
        while (a[j] > mid)
            j--; //找右半部分小于中间数的
        if (i <= j)
        {
            swap(a[i], a[j]); //换位
            i++;              //左指针右移
            j--;              //右指针左移
        }
    } while (i <= j);
    if (l < j)
        mysort(l, j);
    if (i < r)
        mysort(i, r);
}
int main()
{
    cin >> n;
    F(i, 1, n)
    cin >> a[i];
    random_shuffle(a + 1, a + n + 1); //打乱它
    mysort(1, n);                     //快排
    F(i, 1, n)
    cout << a[i] << ' '; //输出
    return 0;
}