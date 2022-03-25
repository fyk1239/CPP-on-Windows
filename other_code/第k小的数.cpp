#include<iostream>
using namespace std;
void quick_sort(long long arr[], int len) ; 
void quick_sort_recursive(long long arr[], int start, int end) ;
void swap(int *x, int *y) ; 
#define MAX 5000000
int main()
{
    int num , cnt , a[MAX] ; 
    cin >> num >> cnt ;
    for (int i = 0; i < num ; i++)
    {
        cin >> a[i] ; 
    }
    quick_sort(a , num) ;
    cout << a[cnt] << endl ;
    
    return 0 ;
}

void swap(long long *x, long long *y)
{
    long long t = *x;
    *x = *y;
    *y = t;
}

void quick_sort(long long arr[], int len) 
{
    quick_sort_recursive(arr, 0, len - 1);
}

void quick_sort_recursive(long long arr[], int start, int end) 
{
    if (start >= end)
        return;
    int mid = arr[end];
    int left = start, right = end - 1;
    while (left < right) {
        while (arr[left] < mid && left < right)
            left++;
        while (arr[right] >= mid && left < right)
            right--;
        swap(&arr[left], &arr[right]);
    }
    if (arr[left] >= arr[end])
        swap(&arr[left], &arr[end]);
    else
        left++;
    if (left)
        quick_sort_recursive(arr, start, left - 1);
    quick_sort_recursive(arr, left + 1, end);
}