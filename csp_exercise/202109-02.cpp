#include <bits/stdc++.h>
using namespace std;

#define MAX 500001
int get_not_zero_block(int a[], int num);
void all_minus(int a[], int num, int c);

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num, array[MAX], p, count;

    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> array[i];
    }

    count = get_not_zero_block(array, num);

    cout << count;

    /* if (count == 0)
        cout << "0";
    else
    {
        if
    } */
    return 0;
}

int get_not_zero_block(int a[], int num)
{
    int count = 0;
    for (int i = 0; i < num; i++)
    {
        if (a[i] != 0)
        {
            int j = i + 1;
            while (a[j++] != 0)
                ;
            count++;
            i = j;
        }
    }
    return count;
}

void all_minus(int a[], int num, int c)
{
    for (int i = 0; i < num; i++)
    {
        if (a[i] < c)
            a[i] = 0;
    }
}
