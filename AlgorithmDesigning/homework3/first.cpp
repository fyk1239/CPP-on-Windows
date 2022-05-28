#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arrayPairSum(vector<int> &nums)
{
	// 思路：使用贪心算法，每次选择可选择的最大值，
	// 即数组中第二大的元素。
	int sum = 0;
	sort(nums.begin(), nums.end());
	vector<int>::iterator it = nums.begin();
	while (it != nums.end())
	{
		sum += *it;
		it += 2;
	}
	return sum;
}

int main()
{
	int len;
	while (cin >> len)
	{
		int *a = new int[len];
		for (int i = 0; i < len; i++)
		{
			cin >> a[i];
		}
		vector<int> nums(a, a + len);
		cout << arrayPairSum(nums) << endl;
	}
	return 0;
}
