#include <bits/stdc++.h>

using namespace std;

int main()
{
    int array[101];
    int num, max = 0, min = 0;

    cin >> num;
    cin >> array[0];
    max += array[0];
    min += array[0];
    for (int i = 1; i < num; i++)
    {
        cin >> array[i];
        max += array[i];
        if (array[i] > array[i - 1])
        {
            min += array[i];
        }
    }

    cout << max << endl;
    cout << min;

    return 0;
}