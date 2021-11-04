#include <iostream>
using namespace std;
#define MAX 20
int arr[MAX][MAX];
int num_of_method(int a[][MAX], int row, int rol);

int main()  
{
    int row0, col0, rhorse, chorse;
    cin >> row0 >> col0 >> rhorse >> chorse;
    for (int i = 0; i < row0; i ++)
    {
        for (int j = 0; j < col0; j++)
        {
            if (i == rhorse && j == chorse)
                arr[i][j] = -1;
            else if ((rhorse - i) * (rhorse - i) + (chorse - j) * (chorse - j) == 10)
                arr[i][j] = -1;
            else
                arr[i][j] = 0;
        }
    }
    cout << num_of_method(arr, row0, col0);
    return 0;
}

int num_of_method(int a[][MAX], int row, int col)
{
    if (row == 0 && col == 0)
        return 1;
    else if (a[row][col] == 0 && row == 0)
        return num_of_method(a, row, col - 1);
    else if (a[row][col] == 0 && col == 0)
        return num_of_method(a, row - 1, col);
    else
        return num_of_method(a, row, col - 1) + num_of_method(a, row - 1, col);
}