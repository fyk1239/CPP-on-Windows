#ifndef __ITEMS_H__
#define __ITEMS_H__

// 项类模板
struct Item
{
    // 数据成员:
    double coe;         // 系数
    int exp;         // 指数

    // 构造函数模板:
    Item();                                // 无参数的构造函数模板
    Item(double coe0, int exp0);    // 已知数据元素值和指针建立结构
};

// 结点类模板的实现部分
Item::Item()
// 操作结果：构造指数域为-1的结点
{
    exp = -1;
}

Item::Item(double coe0, int exp0)
// 操作结果：构造一个数据域为item和指针域为link的结点
{
    coe = coe0;
    exp = exp0;
}

#endif