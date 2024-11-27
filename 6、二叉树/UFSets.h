#ifndef __ELEM_NODE_H__
#define __ELEM_NODE_H__

#include "Assistance.h"
#include <vector>
#include <algorithm>

template <typename ElemType>
struct ElemNode
{
    ElemType data;
    int parent;
};

#endif // !__ELEM_NODE_H__

#ifndef __UFESTS_H__
#define __UFSETS_H__

template <typename ElemType>
class UFSets
{
protected:
    vector<ElemNode<ElemType> > sets;

    // help fuction
    int Find(ElemType e) const;
    // 带压缩路径
    int CollapsingFind(ElemType e) const;

public:
    UFSets(ElemType es[], int n);
    virtual ~UFSets();
    int Size() const;
    ElemType GetElem(int p) const;
    int GetOrder(ElemType e) const;
    void Union(ElemType a, ElemType b);
    //////////////////////////////////////////
    void WeightedUnion(ElemType a, ElemType b); // 根据结点多少合并a与b所在的等价类
    bool Differ(ElemType a, ElemType b);        // 判断元素a、b是否在同一个等价类
    UFSets(const UFSets &copy);                 // 复制构造函数
    UFSets &operator=(const UFSets &copy);      // 赋值运算符
};

template <typename ElemType>
UFSets<ElemType>::UFSets(ElemType es[], int n)
{
    // 在开始之前先把容器滞空
    // sets.resize(0);
    // for (auto &e : es)
    // {
    //     ElemNode<ElemType> temp;
    //     temp.data = e;
    //     temp.parent = -1;
    //     sets.push_back(temp);
    // }
    sets.resize(n);
    for (int i = 0; i < n;i++)
    {
        sets[i].parent = -1;
        sets[i].data = es[i];
    }
}

template <typename ElemType>
UFSets<ElemType>::~UFSets()
{
    sets.resize(0);
}

template <typename ElemType>
int UFSets<ElemType>::Size() const
{
    return sets.size();
}

template <typename ElemType>
int UFSets<ElemType>::Find(ElemType e) const
// 找根
{
    //vector<ElemType>::iterator it;
    // 运用algorithm的find函数
    // auto it = find(sets.begin(), sets.end(), e);
    // // not find
    // if (it == sets.end())
    //     return -1;
    int p = 0;
    //find e
    while(p <Size()&& sets[p].data!=e)
        p++;
    if(p == Size())
        return -1;
    while (sets[p].parent > -1)
        p = sets[p].parent;
    return p;
}


////////////////////////////////////////////////////////////
template <class ElemType>
void UFSets<ElemType>::Union(ElemType a, ElemType b)
// 操作结果：合并a与b所在的等价类
{
    int r1 = Find(a); // 查找a所在等价类的根
    int r2 = Find(b); // 查找b所在等价类的根
    if (r1 != r2 && r1 != -1)
    {
        sets[r1].parent += sets[r2].parent;
        sets[r2].parent = r1; // 合并等价类
    }
}

template <class ElemType>
void UFSets<ElemType>::WeightedUnion(ElemType a, ElemType b)
// 操作结果：根据结点多少合并a与b所在的等价类
{
    int r1 = Find(a); // 查找a所在等价类的根
    int r2 = Find(b); // 查找b所在等价类的根
    if (r1 != r2 && r1 != -1)
    {
        int temp = sets[r1].parent + sets[r2].parent;
        if (sets[r1].parent <= sets[r2].parent)
        {
            sets[r2].parent = r1;
            sets[r1].parent = temp;
        }
        else
        {
            sets[r1].parent = r2; // r1中的结点个数少，r1指向r2
            sets[r2].parent = temp;
        }
    }
}

template <class ElemType>
bool UFSets<ElemType>::Differ(ElemType a, ElemType b)
// 操作结果：如果a与b不在同一等价类上，返回true，否则返回false
{
    int r1 = Find(a); // 查找a所在等价类的根
    int r2 = Find(b); // 查找b所在等价类的根
    return r1 != r2;
}

template <class ElemType>
UFSets<ElemType>::UFSets(const UFSets &copy)
// 操作结果：由copy构造新对象——复制构造函数
{
    sets.resize(Size());                    // 设置容量
    for (int i = 0; i < Size(); i++)
        sets[i] = copy.sets[i]; // 复制每个元素
}

template <class ElemType>
UFSets<ElemType> &UFSets<ElemType>::operator=(const UFSets<ElemType> &copy)
// 操作结果：将copy赋值给当前对象——赋值运算符
{
    if (&copy != this)
    {
        sets.resize(copy.Size());                 // 设置容量
        for (int i = 0; i < Size(); i++)
            sets[i] = copy.sets[i]; // 复制每个元素
    }
    return *this;
}

#endif // !__UFESTS_H__
