#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#include "items.h"          // 项类模板
#include "simple_lk_list.h" // 简单链表类模板
#include "utility.h"        // 实用程序软件包

// 简单线性链表类模板
template <class ElemType>
class Polynomial
{
protected:
    //  链表实现的数据成员:
    SimpleLinkList<ElemType> Polylist; // 多项式组成的线性表

public:
    //  抽象数据类型方法声明及重载编译系统默认方法声明:
    Polynomial();                                                   // 无参构造函数
    virtual ~Polynomial();                                          // 析构函数模板
    int Length() const;                                             // 求多项式长度
    bool IsZero() const;                                            // 判断多项式是否为0
    void Clear();                                                   // 将多项式清空
    void Show();                                                    // 显示多项式
    void InsertItem(const Node<Item<ElemType>> &it);                            // 插入项
    Polynomial(const Polynomial &copy);                             // 复制构造函数
    Polynomial(const SimpleLinkList<Item<ElemType>> &copyLinklist); // 由多项式组成的线性表构造多项式
    //运算符重载
    Polynomial &operator=(const Polynomial &copy);                             // 重载赋值运算符版本一
    Polynomial &operator=(const SimpleLinkList<Item<ElemType>> &copyLinklist); // 重载赋值运算符版本二
    Polynomial &operator+(const Polynomial &p) const;                          // 加法运算符重载
    Polynomial &operator-(const Polynomial &p) const;                          // 减法运算符重载
    Polynomial &operator*(const Polynomial &p) const;                          // 乘法运算符重载

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
int Polynomial<ElemType>::Length() const
// 操作结果：求多项式项数
{
    Node<Item<ElemType>> *tmp = Polylist->head;
    int count = 0;
    while (tmp->next != nullptr)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}

template <class ElemType>
bool Polynomial<ElemType>::IsZero() const
// 操作结果：如多项式为空，则返回true，否则返回false
{
    return Length() == 0;
}

template <class ElemType>
void Polynomial<ElemType>::Clear()
// 操作结果：清空多项式
{
    Node<Item<ElemType>> *tmpPtr = Polylist->head;
    while (Length() > 0)
    { // 表性表非空，则删除第1个项
        // Delete(tmpPtr->exp, tmpcoe);
    }
}

template <class ElemType>
void Polynomial<ElemType>::Show()
// 操作结果：显示多项式中项
{
    for (Node<Item<ElemType>> *tmpPtr = Polylist.head->next; tmpPtr != NULL; tmpPtr = tmpPtr->next)
    { // 用tmpPtr依次指向每个项
        cout << tmpPtr->coe << "x^" << tmpPtr->exp;
        if (tmpPtr->next != NULL)
            cout << " + ";
        else
            cout << endl;
    }
}

template <class ElemType>
Polynomial<ElemType>::Polynomial(const SimpleLinkList<Item<ElemType>> &copy)
// 操作结果：由多项式copy构造新多项式——复制构造函数模板
{
    int copyLength = copy.Length(); // copy的长度
    ElemType coe0, exp0;
    Polylist.Init(); // 初始化多项式

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
void Polynomial<ElemType>::InsertItem(const Node<Item<ElemType>> &item)
// 按照升序插入项
{
    Node<Item<ElemType>> *tmpItem1 = Polylist->head->next;
    while (tmpItem1->next != NULL)
    {
        if (tmpItem1->exp < item->exp && tmpItem1->next->exp > item.exp)
        {
            item.next = tmpItem1->next;
            tmpItem1->next = item;
            delete tmpItem1;
            return;
        }
        else 
        {
            tmpItem1 = tmpItem1->next;
        }
    }
}

// 运算符重载的实现
template<class Elemtype>
Polynomial Polynomial::operator+(const Polynomial &copy) const // 重载赋值运算符版本一
{
    SimpleLinkList<Item> la = 
}


#endif