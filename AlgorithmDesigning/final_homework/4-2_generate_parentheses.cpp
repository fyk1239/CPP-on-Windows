#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define MAX 100005
using namespace std;
// usedLeft是已使用的左括号数，usedRight是已使用的右括号数
// s是其中一个括号序列，result是全部括号序列组成的数组，num是括号总对数
void generate(int usedLeft, int usedRight, string s, vector<string> &result, int num)
{
    // 当左右括号数均等于num
    if (usedLeft == num && usedRight == num)
    {
        result.push_back(s);
        return;
    }
    // 若左括号数 < num，先加左括号
    if (usedLeft < num)
        generate(usedLeft + 1, usedRight, s + "(", result, num);
    // 若当前左括号个数 > 右括号个数，可加右括号
    if (usedRight < num && usedLeft > usedRight)
        generate(usedLeft, usedRight + 1, s + ")", result, num);
}

int main()
{
    int num;
    vector<string> result;
    // 输入数据
    while (cin >> num)
    {
        generate(0, 0, "", result, num);
        // 输出结果
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl << result.size() << endl;
        result.clear(); // 清空result向量，准备接收下一次样例
        cout << endl;
    }
    system("pause");
    return 0;
}