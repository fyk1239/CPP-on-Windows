#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int> &nums)
{
	/* 思路：选择本次可跳跃的位置中，
	下次可跳跃的最大长度最大的位置。 */
	int jumps = 0; // 跳的次数
	int i = 0;	   // 遍历起点
	while (i < nums.size() - 1)
	{
		int wide = i + nums[i]; // 范围
		int setp = 0;			// 每一个点的范围
		int position = 0;		// 用来保存贪心选择的那一个点
		i++;
		while (i <= wide && i < nums.size()) // 开始在当前点的范围里找下一个跳点
		{
			if (nums[i] + i >= setp || i == nums.size() - 1)
			// 前面一个是贪心选择范围大且更远的，后面那个是贪心选择可以直接到达终点的
			{
				setp = nums[i] + i;
				position = i;
			}
			i++;
		}
		jumps++;	  // 步数加一
		i = position; // i换成新的跳点
	}
	return jumps; // 返回结果
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
		cout << jump(nums) << endl;
	}
	return 0;
}
