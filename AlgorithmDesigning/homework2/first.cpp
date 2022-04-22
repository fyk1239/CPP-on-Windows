#include <iostream>
#include <vector>
using namespace std;

int robRange(vector<int> &values, int start, int end)
{
	int maxvalue;
	int prevalue = 0, curvalue = 0; // curvalue为当前房子中的金额， prevalue为后面房子中可以得到的金额之和
	for (int i = end; i >= start; i--)
	{
		maxvalue = max(prevalue, values[i] + curvalue);
		curvalue = prevalue;
		prevalue = maxvalue;
	}
	// 1、dp思路解决【start,end】子问题的解

	return maxvalue; // 最大的values
}

int rob(vector<int> &values)
{
	// 2、处理初始状态
	if (values.size() == 1)
		return values[0];
	else if (values.size() == 2)
		return max(values[0], values[1]);
	// 3、返回较大的结果
	return max(robRange(values, 0, values.size() - 2), robRange(values, 1, values.size() - 1));
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
		vector<int> values(a, a + len);
		cout << rob(values) << endl;
	}
	return 0;
}
