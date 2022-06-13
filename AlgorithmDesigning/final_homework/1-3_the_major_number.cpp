#include <iostream>
#include <vector>
using namespace std;
// 在数组vec中递归寻找多数元素，beginSearch是开始寻找的下标，size是数组的大小
// 思路：数组中删除两个不同元素之后，剩余数组的多数元素仍然是原数组的多数元素
int major_number(vector<int> &vec, int beginSearch, int size)
{
    // 递归出口1，beginSearch已经是数组的最后一个元素
    if (beginSearch == size - 1)
        return vec.at(beginSearch);
    else
    {
        for (int next = beginSearch + 1; next < size; ++next)
        {
            if (vec.at(beginSearch) != vec.at(next)) // 找到两个不同元素
            {
                vec.erase(vec.begin() + next);
                vec.erase(vec.begin() + beginSearch);         // 将其删除
                return major_number(vec, next + 1, size - 2); // 继续递归寻找剩余数组的多数元素
            }
        }
        // 递归出口2，搜索到最后仍没有发现不同的元素
        return vec.at(beginSearch);
    }
}

int main()
{
    // 输入数据
    int length, tmp;
    vector<int> numbers;
    while (cin >> length)
    {
        for (int i = 0; i < length; ++i)
        {
            cin >> tmp;
            numbers.push_back(tmp);
        }
        // 输出结果
        cout << major_number(numbers, 0, length) << endl;
        // 清空数组
        numbers.clear();
    }
    system("pause");
    return 0;
}