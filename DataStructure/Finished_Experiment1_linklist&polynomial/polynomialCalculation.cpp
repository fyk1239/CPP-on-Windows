#include "polynomial.h" // 简单线性链表类
#include "utility.h"    // 实用程序软件包
using namespace std;

int main()
{
     char code = '0';
     Polynomial polynow, polya, polyb, polyresult;
     Item tmpItem;
     int position;

     while (code != '6')
     {
          cout << endl
               << "1. 生成多项式.";
          cout << endl
               << "2. 显示多项式.";
          cout << endl
               << "3. 多项式加法.";
          cout << endl
               << "4. 多项式减法.";
          cout << endl
               << "5. 多项式乘法.";
          cout << endl
               << "6. 退出";
          cout << endl
               << "选择功能(1~6):";
          cin >> code;
          switch (code)
          {
          case '1':
               cout << endl
                    << "输入系数和指数(用空格分割，系数为-1时退出):";
               cin >> tmpItem.coe >> tmpItem.exp;
               while (tmpItem.coe != -1)
               {
                    polynow.InsertItem(tmpItem);
                    cin >> tmpItem.coe >> tmpItem.exp;
               }
               break;
          case '2':
               polya = polynow;
               polya.Display();
               break;
          case '3':
               // 输入两个待计算的多项式
               polya.SetZero();
               cout << endl
                    << "输入第一个多项式的系数和指数(用空格分割，系数为-1时退出):";
               cin >> tmpItem.coe >> tmpItem.exp;
               while (tmpItem.coe != -1)
               {
                    polya.InsertItem(tmpItem);
                    cin >> tmpItem.coe >> tmpItem.exp;
               }

               polyb.SetZero();
               cout << endl
                    << "输入第二个多项式的系数和指数(用空格分割，系数为-1时退出):";
               cin >> tmpItem.coe >> tmpItem.exp;
               while (tmpItem.coe != -1)
               {
                    polyb.InsertItem(tmpItem);
                    cin >> tmpItem.coe >> tmpItem.exp;
               }
               // 执行相加操作
               polyresult = polya + polyb;
               // 显示这三个多项式
               cout << endl
                    << "第一个多项式：";
               polya.Display();
               cout << endl
                    << "第二个多项式：";
               polyb.Display();
               cout << endl
                    << "上两个多项式之和：";
               polyresult.Display();
               break;
          case '4':
               // 输入被减多项式
               polya.SetZero();
               cout << endl
                    << "输入第一个多项式的系数和指数(用空格分割，系数为-1时退出):";
               cin >> tmpItem.coe >> tmpItem.exp;
               while (tmpItem.coe != -1)
               {
                    polya.InsertItem(tmpItem);
                    cin >> tmpItem.coe >> tmpItem.exp;
               }
               // 输入减数多项式
               polyb.SetZero();
               cout << endl
                    << "输入第二个多项式的系数和指数(用空格分割，系数为-1时退出):";
               cin >> tmpItem.coe >> tmpItem.exp;
               while (tmpItem.coe != -1)
               {
                    tmpItem.coe = -tmpItem.coe; // 将减数多项式设置为其相反数
                    polyb.InsertItem(tmpItem);
                    cin >> tmpItem.coe >> tmpItem.exp;
               }
               // 执行相减操作（以加相反数的形式执行）
               polyresult = polya + polyb;
               // 显示这三个多项式
               cout << endl
                    << "第一个多项式：";
               polya.Display();
               cout << endl
                    << "第二个多项式：";
               polyb.Display();
               cout << endl
                    << "上两个多项式之差：";
               polyresult.Display();
               break;
          case '5':
               // 输入两个待乘的多项式
               polya.SetZero();
               cout << endl
                    << "输入第一个多项式的系数和指数(用空格分割，系数为-1时退出):";
               cin >> tmpItem.coe >> tmpItem.exp;
               while (tmpItem.coe != -1)
               {
                    polya.InsertItem(tmpItem);
                    cin >> tmpItem.coe >> tmpItem.exp;
               }

               polyb.SetZero();
               cout << endl
                    << "输入第二个多项式的系数和指数(用空格分割，系数为-1时退出):";
               cin >> tmpItem.coe >> tmpItem.exp;
               while (tmpItem.coe != -1)
               {
                    polyb.InsertItem(tmpItem);
                    cin >> tmpItem.coe >> tmpItem.exp;
               }
               // 执行相乘操作
               polyresult = polya * polyb;
               // 显示这三个多项式
               cout << endl
                    << "第一个多项式：";
               polya.Display();
               cout << endl
                    << "第二个多项式：";
               polyb.Display();
               cout << endl
                    << "上两个多项式之积：";
               polyresult.Display();
               break;
          case '6':;
          }
     }

     system("PAUSE"); // 调用库函数system()
     return 0;        // 返回值0, 返回操作系统
}