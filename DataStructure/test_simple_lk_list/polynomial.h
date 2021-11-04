#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#include "utility.h" // 实用程序软件包
#include "items.h" // 项类模板

// 简单线性链表类模板
template <class ElemType>
class SimpleLinkList
{
protected:
    //  链表实现的数据成员:
    Item<ElemType> *head; // 头结点指针

    // 辅助函数模板:
    Item<ElemType> *GetElemPtr(int position) const; // 返回指向第position个结点的指针
    void Init();                                    // 初始化线性表

public:
    //  抽象数据类型方法声明及重载编译系统默认方法声明:
    SimpleLinkList();                                                          // 无参数的构造函数模板
    virtual ~SimpleLinkList();                                                 // 析构函数模板
    int Length() const;                                                        // 求线性表长度
    bool Empty() const;                                                        // 判断线性表是否为空
    void Clear();                                                              // 将线性表清空
    void Show();                                                               // 显示线性表元素
    // void Traverse(void (*visit)(const ElemType &)) const;                   // 遍历线性表
    StatusCode GetElem(int position, ElemType &coe, ElemType &exp) const;      // 求指定位置的元素
    StatusCode SetElem(int position, ElemType &coe, ElemType &exp);            // 设置指定位置的元素值
    StatusCode Delete(int position, ElemType &coe, ElemType &exp);             // 删除元素
    StatusCode Insert(int position, const ElemType &coe, const ElemType &exp); // 插入元素
    SimpleLinkList(const SimpleLinkList<ElemType> &copy);                      // 复制构造函数模板
    SimpleLinkList<ElemType> &operator=(const SimpleLinkList<ElemType> &copy); // 重载赋值运算符

#ifdef __FRIEND_VOID_DECOMPOSE__
    // 定义成友员,使用protected成员
    friend void Decompose(const SimpleLinkList<char> &la,
                          SimpleCircLinkList<char> &letter,
                          SimpleCircLinkList<char> &digit,
                          SimpleCircLinkList<char> &other);
#endif
};

// 简单线性链表类模板的实现部分
template <class ElemType>
Item<ElemType> *SimpleLinkList<ElemType>::GetElemPtr(int position) const
// 操作结果：返回指向第position个结点的指针
{
    Item<ElemType> *tmpPtr = head; // 用tmpPtr遍历线性表以查找第position个结点
    int curPosition = 0;           // tmpPtr所指结点的位置

    while (tmpPtr != NULL && curPosition < position)
    // 顺指针向后查找，直到tmpPtr指向第position个结点
    {
        tmpPtr = tmpPtr->next;
        curPosition++;
    }

    if (tmpPtr != NULL && curPosition == position)
    { // 查找成功
        return tmpPtr;
    }
    else
    { // 查找失败
        return NULL;
    }
}

template <class ElemType>
void SimpleLinkList<ElemType>::Init()
// 操作结果：初始化线性表
{
    head = new Item<ElemType>; // 构造头指针
}

template <class ElemType>
SimpleLinkList<ElemType>::SimpleLinkList()
// 操作结果：构造一个空链表
{
    Init();
}

template <class ElemType>
SimpleLinkList<ElemType>::~SimpleLinkList()
// 操作结果：销毁线性表
{
    Clear();     // 清空线性表
    delete head; // 释放头结点所点空间
}

template <class ElemType>
int SimpleLinkList<ElemType>::Length() const
// 操作结果：返回线性表元素个数
{
    int count = 0; // 计数器
    for (Item<ElemType> *tmpPtr = head->next; tmpPtr != NULL; tmpPtr = tmpPtr->next)
    {            // 用tmpPtr依次指向每个元素
        count++; // 对线性表的每个元素进行计数
    }
    return count;
}

template <class ElemType>
bool SimpleLinkList<ElemType>::Empty() const
// 操作结果：如线性表为空，则返回true，否则返回false
{
    return head->next == NULL;
}

template <class ElemType>
void SimpleLinkList<ElemType>::Clear()
// 操作结果：清空线性表
{

    ElemType tmpexp, tmpcoe; // 临时元素值
    while (Length() > 0)
    { // 表性表非空，则删除第1个元素
        Delete(1, tmpexp, tmpcoe);
    }
}

template <class ElemType>
void SimpleLinkList<ElemType>::Show()
// 操作结果：显示线性表中元素
{
    for (Item<ElemType> *tmpPtr = head->next; tmpPtr != NULL; tmpPtr = tmpPtr->next)
    {                     // 用tmpPtr依次指向每个元素
        cout << tmpPtr->coe << "x^" << tmpPtr->exp;
        if (tmpPtr->next != NULL)
            cout << " + ";
        else
            cout << endl;
    }
}
/* template <class ElemType>
void SimpleLinkList<ElemType>::Traverse(void (*visit)(Item<ElemType> &)) const
// 操作结果：依次对线性表的每个元素调用函数(*visit)
{
    for (Item<ElemType> *tmpPtr = head->next; tmpPtr != NULL; tmpPtr = tmpPtr->next)
    {                           // 用tmpPtr依次指向每个元素
        (*visit)(tmpPtr); // 对线性表的每个元素调用函数(*visit)
        if (tmpPtr->next != NULL)
            cout << " + ";
        else
            cout << endl;
    }
} */

template <class ElemType>
StatusCode SimpleLinkList<ElemType>::GetElem(int position, ElemType &coe, ElemType &exp) const
// 操作结果：当线性表存在第position个元素时，返回其系数与指数，返回ENTRY_FOUND,
//	否则返回NOT_PRESENT
{
    if (position < 1 || position > Length())
    {                       // position范围错
        return NOT_PRESENT; // 元素不存在
    }
    else
    { // position合法
        Item<ElemType> *tmpPtr;
        tmpPtr = GetElemPtr(position); // 取出指向第position个结点的指针
        exp = tmpPtr->exp;          //返回指数
        coe = tmpPtr->coe;          //返回系数
        return ENTRY_FOUND;
    }
}

template <class ElemType>
StatusCode SimpleLinkList<ElemType>::SetElem(int position, ElemType &coe, ElemType &exp)
//  操作结果：将线性表的第position个位置的指数赋值为exp,系数赋值为coe
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
        tmpPtr = GetElemPtr(position); // 取出指向第position个结点的指针
        tmpPtr->exp = exp;              // 设置第position个元素的系数与指数
        tmpPtr->coe = coe;
        return SUCCESS;
    }
}

template <class ElemType>
StatusCode SimpleLinkList<ElemType>::Delete(int position, ElemType &coe, ElemType &exp)
// 操作结果：删除线性表的第position个位置的元素, 并用e返回其值,
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
StatusCode SimpleLinkList<ElemType>::Insert(int position, const ElemType &coe, const ElemType &exp)
// 操作结果：在线性表的第position个位置前插入元素
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
        tmpPtr->next = newPtr;                        // 将tmpPtr插入到链表中
        return SUCCESS;
    }
}

template <class ElemType>
SimpleLinkList<ElemType>::SimpleLinkList(const SimpleLinkList<ElemType> &copy)
// 操作结果：由线性表copy构造新线性表——复制构造函数模板
{
    int copyLength = copy.Length(); // copy的长度
    ElemType coe0, exp0;
    Init(); // 初始化线性表

    for (int curPosition = 1; curPosition <= copyLength; curPosition++)
    {                                 // 复制数据元素
        copy.GetElem(curPosition, coe0, exp0); // 取出第curPosition个元素
        Insert(Length() + 1, coe0, exp0);      // 将e插入到当前线性表
    }
}

template <class ElemType>
SimpleLinkList<ElemType> &SimpleLinkList<ElemType>::operator=(const SimpleLinkList<ElemType> &copy)
// 操作结果：将线性表copy赋值给当前线性表——重载赋值运算符
{
    if (&copy != this)
    {
        int copyLength = copy.Length(); // copy的长度
        ElemType coe, exp;
        Clear(); // 清空当前线性表

        for (int curPosition = 1; curPosition <= copyLength; curPosition++)
        {                                 // 复制数据元素
            copy.GetElem(curPosition, coe, exp); // 取出第curPosition个元素
            Insert(Length() + 1, coe, exp);      // 将e插入到当前线性表
        }
    }
    return *this;
}

/* template <class ElemType>
void Write(Item<ElemType> *tmpPtr)
// 操作结果: 显示数据元素
{
    cout << tmpPtr->coe << "x^" << tmpPtr->exp;
} */

#endif