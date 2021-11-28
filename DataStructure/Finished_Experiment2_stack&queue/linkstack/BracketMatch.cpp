#include "BracketMatch.h"   // 中括号匹配算法
#include "utility.h"        // 实用程序软件包

int main()
{
    char str[100];
    cout << "输入一个字符串:";
    cin >> str;

    if (Match(str))
    { // 返回true,表示匹配
        cout << "括号匹配" << endl;
    }
    else
    { // 返回false,表示不匹配
        cout << "括号不匹配" << endl;
    }

    system("PAUSE"); // 调用库函数system()
    return 0;        // 返回值0, 返回操作系统
}