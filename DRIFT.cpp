#include <bits/stdc++.h>
using namespace std;

int Akm(int m, int n)
{
    if (m == 0)
        return n + 1;
    else if (n == 0)
        return Akm(m - 1, 1);
    else
        return Akm(m - 1, Akm(m, n - 1));
}

int main()
{
    int a, b, min, x;
    printf("请输入两个整数：") ；
}