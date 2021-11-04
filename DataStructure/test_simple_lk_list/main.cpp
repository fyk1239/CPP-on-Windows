#include "utility.h"		// 实用程序软件包
#include "simple_lk_list.h"	// 简单线性链表类

int main(void)
{
	char c = '0';
    SimpleLinkList<double> la,lb;
    double e;
	int position;

    while (c != '8')
	{
        cout << endl << "1. 生成线性表.";
        cout << endl << "2. 显示线性表.";
        cout << endl << "3. 检索元素.";
        cout << endl << "4. 设置元素值.";
        cout << endl << "5. 删除元素.";
        cout << endl << "6. 插入元素.";
		cout << endl << "7. 清空线性表";
		cout << endl << "8. 退出"; 
		cout << endl << "选择功能(1~8):";
		cin >> c;
		switch (c) 
		{
			case '1':
				cout << endl << "输入e(e = 0时退出):";
				cin >> e;
				while (e != 0)
				{
					la.Insert(la.Length() + 1, e);
					cin >> e;
				}
				break;
			case '2':
			    lb = la;
			    lb.Traverse(Write<double>);
				break;
			case '3':
			    cout << endl << "输入元素位置:";
			    cin >> position;
			    if (la.GetElem(position, e) == NOT_PRESENT) 
					cout << "元素不存储." << endl;
				else
					cout << "元素:" << e << endl;
			    break;
			case '4':
			    cout << endl << "输入位置:";
			    cin >> position;
			    cout << endl << "输入元素值:";
			    cin >> e;
				if (la.SetElem(position, e) == RANGE_ERROR)
					cout << "位置范围错." << endl;
				else
					cout << "设置成功." << endl;
			    break;
			case '5':
			    cout << endl << "输入位置:";
			    cin >> position;
			    if (la.Delete(position, e) == RANGE_ERROR) 
					cout << "位置范围错." << endl;
				else
					cout << "被删除元素值:" << e << endl;
			    break;
			case '6':
			    cout << endl << "输入位置:";
			    cin >> position;
			    cout << endl << "输入元素值:";
			    cin >> e;
			    if (la.Insert(position, e) == RANGE_ERROR) 
					cout << "位置范围错." << endl;
				else
					cout << "插入元素成功:" << e << endl;
			    break;
			case '7':
				la.Clear();
				break;
		}
	}
	cout << "您已成功退出" << endl;
	system("PAUSE");        // 调用库函数system()
	return 0;               // 返回值0, 返回操作系统
}