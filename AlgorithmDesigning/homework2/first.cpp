#include <iostream>
#include <vector>
using namespace std;

int robRange(vector<int> &values, int start, int end)
{
	int maxvalue;
	int prevalue = 0, curvalue = 0; // curvalueΪ��ǰ�����еĽ� prevalueΪ���淿���п��Եõ��Ľ��֮��
	for (int i = end; i >= start; i--)
	{
		maxvalue = max(prevalue, values[i] + curvalue);
		curvalue = prevalue;
		prevalue = maxvalue;
	}
	// 1��dp˼·�����start,end��������Ľ�

	return maxvalue; // ����values
}

int rob(vector<int> &values)
{
	// 2�������ʼ״̬
	if (values.size() == 1)
		return values[0];
	else if (values.size() == 2)
		return max(values[0], values[1]);
	// 3�����ؽϴ�Ľ��
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
