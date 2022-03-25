#include <iostream>
// P1255 数楼梯
using namespace std;

long long arr[5005] = {0};

long long recursion(int n); // 递归求楼梯数量

int main()
{
    int num;
    cin >> num;
    arr[1] = 1;
    arr[2] = 2;
    cout << recursion(num) << endl;
    return 0;
}

long long recursion(int n)
{
    if (arr[n] != 0 && n > 0)
    {
        return arr[n];
    }
    else if (n > 0)
    {
        arr[n] = recursion(n - 1) + recursion(n - 2);
        return arr[n];
    }
    else
    {
        return 0;
    }
}