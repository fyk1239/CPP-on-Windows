#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#include "items.h" // 项类模板
#include "simple_lk_list.h"
#include "utility.h" // 实用程序软件包

// 简单线性链表类模板
template <class ElemType>
class Polynomial
{
protected:
    //  链表实现的数据成员:
    SimpleLinkList<ElemType> Polylist; // 多项式组成的线性表

public:
    //  抽象数据类型方法声明及重载编译系统默认方法声明:
    Polynomial();                                         // 无参构造函数
    virtual ~Polynomial();                                // 析构函数模板
    int Length() const;                                   // 求多项式长度
    bool IsZero() const;                                  // 判断多项式是否为0
    void Clear();                                         // 将多项式清空
    void Show();                                          // 显示多项式
    void InsertItem(Item<ElemType> &it);                      // 插入项
    Polynomial(const Polynomial &copy);                   // 复制构造函数
    Polynomial(const SimpleLinkList<Item> &copyLinklist); // 由多项式组成的线性表构造多项式
    //运算符重载
    Polynomial &operator=(const Polynomial &copy);                   // 重载赋值运算符版本一
    Polynomial &operator=(const SimpleLinkList<Item> &copyLinklist); // 重载赋值运算符版本二
    Polynomial &operator+(const Polynomial &p) const;                // 加法运算符重载
    Polynomial &operator-(const Polynomial &p) const;                // 减法运算符重载
    Polynomial &operator*(const Polynomial &p) const;                // 乘法运算符重载

#ifdef __FRIEND_VOID_DECOMPOSE__
        // 定义成友员,使用protected成员
    friend void Decompose(const Polynomial<char> &la,
                          SimpleCircLinkList<char> &letter,
                          SimpleCircLinkList<char> &digit,
                          SimpleCircLinkList<char> &other);
#endif
};

// 简单线性链表类模板的实现部分

template <class ElemType>
int Polynomial::Length() const
// 操作结果：返回多项式项个数
{
    int count = 0; // 计数器
    for (Item<ElemType> *tmpPtr = head->next; tmpPtr != NULL; tmpPtr = tmpPtr->next)
    {            // 用tmpPtr依次指向每个项
        count++; // 对多项式的每个项进行计数
    }
    return count;
}

template <class ElemType>
bool Polynomial<ElemType>::IsZero() const
// 操作结果：如多项式为空，则返回true，否则返回false
{
    return head->next == NULL;
}

template <class ElemType>
void Polynomial<ElemType>::Clear()
// 操作结果：清空多项式
{
    Item<ElemType> *tmpPtr = Polylist;
    while (Length() > 0)
    { // 表性表非空，则删除第1个项
        Delete(tmpPtr->exp, tmpcoe);
    }
}

template <class ElemType>
void Polynomial<ElemType>::Show()
// 操作结果：显示多项式中项
{
    for (Item<ElemType> *tmpPtr = head->next; tmpPtr != NULL; tmpPtr = tmpPtr->next)
    { // 用tmpPtr依次指向每个项
        cout << tmpPtr->coe << "x^" << tmpPtr->exp;
        if (tmpPtr->next != NULL)
            cout << " + ";
        else
            cout << endl;
    }
}

template <class ElemType>
StatusCode Polynomial<ElemType>::Delete(ElemType Exp, ElemType &coe)
// 操作结果：删除多项式的第position个位置的项, 并用e返回其值,
//	position的取值范围为1≤position≤Length(),
//	position合法时返回SUCCESS,否则返回RANGE_ERROR
{
    if (position < 1 || position > Length())
    { // position范围错
        return RANGE_ERROR;
    }
    else
    { // position合法
        Item<ElemType> *tmpPtr;
        tmpPtr = GetElemPtr(position - 1);      // 取出指向第position-1个结点的指针
        Item<ElemType> *nextPtr = tmpPtr->next; // nextPtr为tmpPtr的后继
        tmpPtr->next = nextPtr->next;           // 删除结点
        exp = nextPtr->exp;                     // 用exp返回被删结点指数
        coe = nextPtr->coe;                     // 用coe返回被删结点系数
        delete nextPtr;                         // 释放被删结点
        return SUCCESS;
    }
}

template <class ElemType>
StatusCode Polynomial<ElemType>::Insert(int position, const ElemType &coe, const ElemType &exp)
// 操作结果：在多项式的第position个位置前插入项
//	position的取值范围为1≤position≤Length()+1
//	position合法时返回SUCCESS, 否则返回RANGE_ERROR
{
    if (position < 1 || position > Length() + 1)
    {                       // position范围错
        return RANGE_ERROR; // 位置不合法
    }
    else
    { // position合法
        Item<ElemType> *tmpPtr;
        tmpPtr = GetElemPtr(position - 1); // 取出指向第position-1个结点的指针
        Item<ElemType> *newPtr;
        newPtr = new Item<ElemType>(coe, exp, tmpPtr->next); // 生成新结点
        tmpPtr->next = newPtr;                               // 将tmpPtr插入到链表中
        return SUCCESS;
    }
}

template <class ElemType>
Polynomial<ElemType>::Polynomial(const Polynomial<ElemType> &copy)
// 操作结果：由多项式copy构造新多项式——复制构造函数模板
{
    int copyLength = copy.Length(); // copy的长度
    ElemType coe0, exp0;
    Init(); // 初始化多项式

    for (int curPosition = 1; curPosition <= copyLength; curPosition++)
    {                                          // 复制数据项
        copy.GetElem(curPosition, coe0, exp0); // 取出第curPosition个项
        Insert(Length() + 1, coe0, exp0);      // 将e插入到当前多项式
    }
}

template <class ElemType>
Polynomial<ElemType> &Polynomial<ElemType>::operator=(const Polynomial<ElemType> &copy)
// 操作结果：将多项式copy赋值给当前多项式——重载赋值运算符
{
    if (&copy != this)
    {
        int copyLength = copy.Length(); // copy的长度
        ElemType coe, exp;
        Clear(); // 清空当前多项式

        for (int curPosition = 1; curPosition <= copyLength; curPosition++)
        {                                        // 复制数据项
            copy.GetElem(curPosition, coe, exp); // 取出第curPosition个项
            Insert(Length() + 1, coe, exp);      // 将e插入到当前多项式
        }
    }
    return *this;
}

template <class ElemType>
void Polynomial<ElemType>::InsertItem(const Item &item)
// 将多项式按照升序排列
{
    Item<ElemType> *tmpItem1 = head->next;
    while (tmpItem1->next != NULL)
    {
        Item<ElemType> tmpItem2 = tmpItem1;
        while (tmpItem2->next->exp < tmpItem2->exp && tmpItem2 != NULL)
        {
            Item<ElemType> tmpa;
            tmpa.exp = tmpItem2.exp;
            tmpa.coe = tmpItem2.coe;
            tmpItem2.exp = tmpItem2.next->exp;
            tmpItem2.coe = tmpItem2.next->coe;
            tmpItem2.exp = tmpa.exp;
            tmpItem2.coe = tmpa.coe;
            tmpItem2 = tmpItem2.next
        }

        tmpItem1 = tmpItem1->next;
    }
}

/* template <class ElemType>
void Write(Item<ElemType> *tmpPtr)
// 操作结果: 显示数据项
{
    cout << tmpPtr->coe << "x^" << tmpPtr->exp;
} */

#endif