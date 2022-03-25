//�����е�K������

#include <iostream>
using namespace std;

/*
 * 1�����ÿ��������㷨�Ļ���˼�룬���ػ��ֺ�����λ�á�
	  ÿ��ѡ��arr[left]��Ϊ��׼��
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
 * ���ö��ַ�˼��ʵ��
 */
void findKthLargest(int arr[], int len, int k)
{
	/*
	 *2����ȡ��׼ֵ��ȷ����һ����ѯ�Ļ������������黹����������
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
