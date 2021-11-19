#include "polynomial.h" // 简单线性链表类
#include "utility.h"    // 实用程序软件包
using namespace std;

int main()
{
    char c = '0';
    Polynomial la, lb;
    double coe, exp;
    int position;

    while (c != '8')
    {
        cout << endl
             << "1. 生成多项式.";
        cout << endl
             << "2. 显示多项式.";
        cout << endl
             << "3. 检索指定项.";
        cout << endl
             << "4. 设置指定项系数.";
        cout << endl
             << "5. 删除指定项.";
        cout << endl
             << "6. 插入指定项.";
        cout << endl
             << "7. 清空原多项式";
        cout << endl
             << "8. 退出";
        cout << endl
             << "选择功能(1~8):";
        cin >> c;
        switch (c)
        {
        case '1':
            cout << endl
                 << "输入系数和指数(用空格分割，系数为0时退出):";
            cin >> coe >> exp;
            while (coe != 0)
            {
                Item<double> tmpItem(coe, exp);
                Node<Item<double>> tmpNode(tmpItem);
                la.InsertItem(tmpNode);
                cin >> coe >> exp;
            }
            break;
        case '2':
            lb = la;
            lb.Show();
            break;
        case '3':
            cout << endl
                 << "输入项的位置:";
            cin >> position;
            if (la.GetElem(position, coe, exp) == NOT_PRESENT)
                cout << "项不存在." << endl;
            else
                cout << "该项:" << coe << "x^" << exp << endl;
            break;
        case '4':
            cout << endl
                 << "输入位置:";
            cin >> position;
            cout << endl
                 << "依次输入该项的系数与指数:";
            cin >> coe >> exp;
            if (la.SetElem(position, coe, exp) == RANGE_ERROR)
                cout << "位置范围错." << endl;
            else
                cout << "设置成功." << endl;
            break;
        case '5':
            cout << endl
                 << "输入位置:";
            cin >> position;
            if (la.Delete(position, coe, exp) == RANGE_ERROR)
                cout << "位置范围错." << endl;
            else
                cout << "被删除项:" << coe << "x^" << exp << endl;
            break;
        case '6':
            cout << endl
                 << "输入位置:";
            cin >> position;
            cout << endl
                 << "依次输入项的系数与指数:";
            cin >> coe >> exp;
            if (la.Insert(position, coe, exp) == RANGE_ERROR)
                cout << "位置范围错." << endl;
            else
                cout << "插入项成功:" << coe << "x^" << exp << endl;
            break;
        case '7':
            la.Clear();
        }
    }

    system("PAUSE"); // 调用库函数system()
    return 0;        // 返回值0, 返回操作系统
}