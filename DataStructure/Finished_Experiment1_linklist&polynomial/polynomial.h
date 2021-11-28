#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#include "linklist.h"   // 链表类模板
#include "items.h" // 多项式项类模板

// 多项式类

class Polynomial
{
protected:
    // 多项式实现的数据成员:
    LinkList<Item> polyList; // 多项式组成的线性表

public:
    //  抽象数据类型方法声明及重载编译系统默认方法声明:
    Polynomial(){};                                  // 无参构造函数
    ~Polynomial(){};                                 // 析构函数
    int Length() const;                              // 求多项式的项数
    bool IsZero() const;                             // 判断多项式是否为0
    void SetZero();                                  // 将多项式置为0
    void Display();                                  // 显示多项式
    void InsertItem(const Item &item);               // 插入一项
    Polynomial operator+(const Polynomial &p) const; // 加法运算符重载
    Polynomial operator-(const Polynomial &p) const; // 减法运算符重载
    Polynomial operator*(const Polynomial &p) const; // 乘法运算符重载
    Polynomial(const Polynomial &copy);              // 复制构造函数
    Polynomial(const LinkList<Item> &copyLinkList);  // 由多项式组成的线性表构造多项式
    Polynomial &operator=(const Polynomial &copy);                 // 重载赋值运算符
    Polynomial &operator=(const LinkList<Item> &copyLinkList); // 重载赋值运算符
};

// 多项式类的实现部分
int Polynomial::Length() const
// 操作结果：返回多项式的项数
{
    return polyList.Length();
}

bool Polynomial::IsZero() const
// 操作结果：如多项式为0，则返回true，否则返回false
{
    return polyList.Empty();
}

void Polynomial::SetZero()
// 操作结果：将多项式置为0
{
    polyList.Clear();
}

void Polynomial::Display()
// 操作结果：显示多项式
{
    int pos = 1;
    Item it;
    StatusCode status = polyList.GetElem(pos, it);
    while (status == ENTRY_FOUND)
    // 依次显示多项式的每一项
    {
        cout << "  (" << it.coe << "x^" << it.exp << ")"; //显示多项式的一项
        status = polyList.GetElem(++pos, it);              // 取出下一项
    }
}

void Polynomial::InsertItem(const Item &item)
// 操作结果：向多项式插入一项
{
    int pos = 1;
    Item it;
    StatusCode status = polyList.GetElem(pos, it);
    while (status == ENTRY_FOUND && it.exp < item.exp)
    // 查找插入位置
    {
        status = polyList.GetElem(++pos, it); // 取出下一项
    }

    polyList.Insert(pos, item); // 向多项式插入一项
}

Polynomial Polynomial::operator+(const Polynomial &p) const
// 操作结果：返回当前多项式与p之和——加法运算符重载
{
    LinkList<Item> la = polyList;   // 当前多项式对应的线性表
    LinkList<Item> lb = p.polyList; // 多项式p对应的线性表
    LinkList<Item> lc;              // 和多项式对应的线性表
    int aPos = 1, bPos = 1;
    Item aItem, bItem;
    StatusCode aStatus, bStatus;

    aStatus = la.GetElem(aPos, aItem); // 取出la的第1项
    bStatus = lb.GetElem(bPos, bItem); // 取出lb的第1项

    while (aStatus == ENTRY_FOUND && bStatus == ENTRY_FOUND)
    {
        if (aItem.exp < bItem.exp)
        // la中的项aItem指数较小
        {
            lc.Insert(lc.Length() + 1, aItem);   // 将aItem追加到lc的后面
            aStatus = la.GetElem(++aPos, aItem); // 取出la的第下一项
        }
        else if (aItem.exp > bItem.exp)
        // lb中的项bItem指数较小
        {
            lc.Insert(lc.Length() + 1, bItem);   // 将bItem追加到lc的后面
            bStatus = lb.GetElem(++bPos, bItem); // 取出lb的第下一项
        }
        else
        // la中的项aItem和lb中的项bItem指数相等
        {
            Item sumItem(aItem.coe + bItem.coe, aItem.exp);
            if (sumItem.coe != 0)
                lc.Insert(lc.Length() + 1, sumItem); // 将bItem追加到lc的后面
            aStatus = la.GetElem(++aPos, aItem);     // 取出la的第下一项
            bStatus = lb.GetElem(++bPos, bItem);     // 取出lb的第下一项
        }
    }

    while (aStatus == ENTRY_FOUND)
    // 将la的剩余项追加到lc的后面
    {
        lc.Insert(lc.Length() + 1, aItem);   // 将aItem追加到lc的后面
        aStatus = la.GetElem(++aPos, aItem); // 取出la的第下一项
    }

    while (bStatus == ENTRY_FOUND)
    // 将lb的剩余项追加到lc的后面
    {
        lc.Insert(lc.Length() + 1, bItem);   // 将bItem追加到lc的后面
        bStatus = lb.GetElem(++bPos, bItem); // 取出lb的第下一项
    }

    Polynomial fs; // 和多项式
    fs.polyList = lc;

    return fs;
}

Polynomial Polynomial::operator-(const Polynomial &p) const
// 操作结果：返回当前多项式与p之差——减法运算符重载
{
    LinkList<Item> la = polyList;   // 当前多项式对应的线性表
    LinkList<Item> lb = p.polyList; // 多项式p对应的线性表
    int bPos = 1;
    Item bItem;
    StatusCode bStatus;

    // 将lb的各项的系数取相反数
    bStatus = lb.GetElem(bPos, bItem); // 取出lb的第1项
    while (bStatus == ENTRY_FOUND)
    {
        bItem.coe = -bItem.coe; // 将系统取反
        lb.SetElem(bPos, bItem);  // 设置项

        bStatus = lb.GetElem(++bPos, bItem); // 取出lb的下一项
    }

    Polynomial fa(la), fb(lb), fc = fa + fb;

    return fc;
}

Polynomial Polynomial::operator*(const Polynomial &p) const
// 操作结果：返回当前多项式与p之积——乘法运算符重载
{
    LinkList<Item> la = polyList;   // 当前多项式对应的线性表
    LinkList<Item> lb = p.polyList; // 多项式p对应的线性表
    LinkList<Item> lc;
    Polynomial polyMultiply; // 乘积多项式
    int aPos = 1, bPos;
    Item aItem, bItem, cItem;
    StatusCode aStatus, bStatus;

    // 用la的各项去乘lb
    aStatus = la.GetElem(aPos, aItem); // 取出la的第1项
    while (aStatus == ENTRY_FOUND)
    {
        lc.Clear(); // 清空lc
        bPos = 1;
        bStatus = lb.GetElem(bPos, bItem); // 取出lb的第1项
        while (bStatus == ENTRY_FOUND)
        {
            // 将la与lb的每一次相乘
            cItem.coe = aItem.coe * bItem.coe; // 系数相乘
            cItem.exp = aItem.exp + bItem.exp; // 指数相加

            lc.Insert(lc.Length() + 1, cItem); // lc为乘积
            
            bStatus = lb.GetElem(++bPos, bItem); // 取出lb的下一项
        }
        // 将乘积加到polyMultiply
        Polynomial tmppoly(lc);
        polyMultiply = polyMultiply + tmppoly;
        aStatus = la.GetElem(++aPos, aItem); // 取出la的下一项
    }

    return polyMultiply;
}

Polynomial::Polynomial(const Polynomial &copy)
// 操作结果：由多项式copy构造新多项式——复制构造函数
{
    polyList = copy.polyList;
}

Polynomial::Polynomial(const LinkList<Item> &copyLinkList)
// 操作结果：由多项式组成的线性表构造多项式——转换构造函数
{
    polyList = copyLinkList;
}

Polynomial &Polynomial::operator=(const Polynomial &copy)
// 操作结果：将多项式copy赋值给当前多项式——重载赋值运算符
{
    if (&copy != this)
    {
        polyList = copy.polyList;
    }
    return *this;
}

Polynomial &Polynomial::operator=(const LinkList<Item> &copyLinkList)
// 操作结果：将多项式组成的线性表copyLinkList赋值给当前多项式
//	——重载赋值运算符
{
    polyList = copyLinkList;
    return *this;
}

#endif