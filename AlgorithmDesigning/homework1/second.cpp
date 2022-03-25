//数组中第K大数字

#include <iostream>
using namespace std;

/*
 * 1、利用快速排序算法的基本思想，返回划分后基点的位置。
	  每次选择arr[left]做为基准点
 */
int partition(int arr[], int left, int right)
{
	int tmp;
	while (left < right)
	{
		while (left < right && arr[left] >= arr[right])
		{
			right--;
		}
		tmp = arr[right];
		arr[right] = arr[left];
		arr[left] = tmp;

		while(left < right && arr[left] >= arr[right])
		{
			left++;
		}
		tmp = arr[right];
		arr[right] = arr[left];
		arr[left] = tmp;
	}
	return left;
}

/*
 * 利用二分法思想实现
 */
void findKthLargest(int arr[], int len, int k)
{
	/*
	 *2、获取基准值，确定下一步查询的划分是左子数组还是右子数组
	 */
	int p = partition(arr, 0, len - 1), kk = k - 1, low = 0, high = len - 1;
	while (p != kk)
	{
		if (p < kk)
			p = partition(arr, p + 1, high);
		else
			p = partition(arr, low, p - 1);
	}
	
	cout << arr[kk] << endl;
	return;
}

int main()
{
	int len, k;
	while (cin >> len)
	{
		cin >> k;
		int *arr = new int[len];
		for (int i = 0; i < len; i++)
		{
			cin >> arr[i];
		}
		findKthLargest(arr, len, k);
	}
	return 0;
}
