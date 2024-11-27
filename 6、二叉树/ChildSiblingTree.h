#ifndef __CHILD_SIBLING_TREE2_H__
#define __CHILD_SIBLING_TREE2_H__

#include "ChildSiblingTreeNode.h"
#include "LinkQueue.h"

template <typename ElemType>
class ChildSiblingTree
{
protected:
    ChildSiblingTreeNode<ElemType> *root;

    // 辅助函数
    void Destory(ChildSiblingTreeNode<ElemType> *&r);
    void PreRootOrder(ChildSiblingTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const;
    void PostRootOrder(ChildSiblingTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const;
    int NodeCount(ChildSiblingTreeNode<ElemType> *r) const;
    // 求deepth
    int LeafCount(ChildSiblingTreeNode<ElemType> *r) const;
    int Height(ChildSiblingTreeNode<ElemType> *r) const;
    // 求度
    int Degree(ChildSiblingTreeNode<ElemType> *r) const;
    ///////
    // void Delete(ChildSiblingTreeNode<ElemType> *r);		// 删除以r为根的树
    ChildSiblingTreeNode<ElemType> *Parent(ChildSiblingTreeNode<ElemType> *r,
                                           const ChildSiblingTreeNode<ElemType> *cur) const;
    ChildSiblingTreeNode<ElemType> *CopyTree(ChildSiblingTreeNode<ElemType> *copy);
    ChildSiblingTreeNode<ElemType> *CreatTreeGhelp(ElemType items[], int parents[], int r, int n);
    // 数据元素items，节点双亲，根结点r，节点个数n

public:
    ChildSiblingTree();
    virtual ~ChildSiblingTree();
    ChildSiblingTreeNode<ElemType> *GetRoot() const;
    bool IsEmpty() const;
    Status GetElem(ChildSiblingTreeNode<ElemType> *cur, ElemType &e) const;
    Status SetElem(ChildSiblingTreeNode<ElemType> *cur, const ElemType &e);
    void PreRootOrder(void (*Visit)(const ElemType &)) const;
    void PostRootOrder(void (*Visit)(const ElemType &)) const;
    void LevelOrder(void (*Visit)(const ElemType &)) const;
    int NodeCount() const;
    int LeafCount() const;
    int NodeDegree(ChildSiblingTreeNode<ElemType> *cur) const;
    int Degree() const;
    int Height() const;
    ChildSiblingTreeNode<ElemType> *FirstChild(ChildSiblingTreeNode<ElemType> *cur) const;
    ChildSiblingTreeNode<ElemType> *NextSibling(ChildSiblingTreeNode<ElemType> *cur) const;
    ChildSiblingTreeNode<ElemType> *Parent(ChildSiblingTreeNode<ElemType> *cur) const;
    // 将e变成cur的第i个孩子
    Status InsertChild(ChildSiblingTreeNode<ElemType> *cur, int i, const ElemType &e);
    // 删除cur的第i个孩子
    Status DeleteChild(ChildSiblingTreeNode<ElemType> *cur, int i);
    ChildSiblingTree(const ElemType &e);
    ChildSiblingTree(const ChildSiblingTree<ElemType> &copy);
    ChildSiblingTree(ElemType items[], int parents[], int n);
    ChildSiblingTree(ChildSiblingTreeNode<ElemType> *r);
    ChildSiblingTree<ElemType> &operator=(const ChildSiblingTree<ElemType> &copy);
};

// 其他一些功能------------------------------------------------------------------
template <typename ELemType>
// 凹入法  level层次 设根节点层次为1
void DisplayTWithConcaveShape(const ChildSiblingTree<ELemType> &t, ChildSiblingTreeNode<ELemType> *r, int level);

template <typename ElemType>
void DisplayTWithConcaveShape(const ChildSiblingTree<ElemType> &t);

// 函数定义-----------------------------------------------------------------------
template <typename ElemType>
ChildSiblingTree<ElemType>::ChildSiblingTree()
{
    root = NULL;
}

template <typename ElemType>
void ChildSiblingTree<ElemType>::Destory(ChildSiblingTreeNode<ElemType> *&r)
{
    ChildSiblingTreeNode<ElemType> *p;
    if (!r)
        return;
    for (p = FirstChild(r); p; p = NextSibling(p))
        Destory(p);
    delete r;
    r = NULL;
}

template <typename ElemType>
ChildSiblingTree<ElemType>::~ChildSiblingTree()
{
    Destory(root);
}

template <typename ElemType>
ChildSiblingTreeNode<ElemType> *ChildSiblingTree<ElemType>::GetRoot() const
{
    return root;
}

template <typename ElemType>
bool ChildSiblingTree<ElemType>::IsEmpty() const
{
    return !root;
}

template <typename ElemType>
Status ChildSiblingTree<ElemType>::GetElem(ChildSiblingTreeNode<ElemType> *cur, ElemType &e) const
{
    if (!cur)
        return NOT_PRESENT;
    e = cur->data;
    return ENTRY_FOUND;
}

template <typename ElemType>
Status ChildSiblingTree<ElemType>::SetElem(ChildSiblingTreeNode<ElemType> *cur, const ElemType &e)
{
    if (!cur)
        return FAIL;
    cur->data = e;
    return SUCCESS;
}

// void PreRootOreder(ChildSiblingTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const;

template <typename ElemType>
void ChildSiblingTree<ElemType>::PreRootOrder(ChildSiblingTreeNode<ElemType> *r,
                                              void (*Visit)(const ElemType &)) const
{
    ChildSiblingTreeNode<ElemType> *p;
    if (!r)
        return;
    (*Visit)(r->data);
    for (p = FirstChild(r); p; p = NextSibling(p))
        PreRootOrder(p, Visit);
}

template <typename ElemType>
void ChildSiblingTree<ElemType>::PreRootOrder(void (*Visit)(const ElemType &)) const
{
    PreRootOrder(GetRoot(), Visit);
}

template <typename ElemType>
void ChildSiblingTree<ElemType>::PostRootOrder(ChildSiblingTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const
{
    ChildSiblingTreeNode<ElemType> *p;
    if (!r)
        return;
    for (p = FirstChild(r); p; p = p->nextSibling)
    {
        PostRootOrder(p, Visit);
    }
    (*Visit)(r->data);
}

template <typename ElemType>
void ChildSiblingTree<ElemType>::PostRootOrder(void (*Visit)(const ElemType &)) const
{
    PostRootOrder(GetRoot(), Visit);
}

template <typename ElemType>
void ChildSiblingTree<ElemType>::LevelOrder(void (*Visit)(const ElemType &)) const
{
    LinkQueue<ChildSiblingTreeNode<ElemType> *> q;
    ChildSiblingTreeNode<ElemType> *cur, *p;
    if (!root)
        return;
    q.EnQueue(root);
    while (!q.IsEmpty())
    {
        q.DelQueue(cur);
        (*Visit)(cur->data);
        for (p = FirstChild(cur); p; p = p->nextSibling)
        {
            q.EnQueue(p);
        }
    }
}

template <typename ElemType>
int ChildSiblingTree<ElemType>::NodeCount(ChildSiblingTreeNode<ElemType> *r) const
{
    ChildSiblingTreeNode<ElemType> *p;
    if (!r)
        return 0;
    int count = 0;
    for (p = FirstChild(r); p; p = NextSibling(p))
        count += NodeCount(p);
    return count + 1;
}

template <typename ElemType>
int ChildSiblingTree<ElemType>::NodeCount() const
{
    return NodeCount(root);
}

template <typename ElemType>
int ChildSiblingTree<ElemType>::LeafCount(ChildSiblingTreeNode<ElemType> *r) const
{
    ChildSiblingTreeNode<ElemType> *p;
    if (!r)
        return 0;
    int count = 0;
    if (FirstChild(r))
    {
        for (p = FirstChild(r); p; p = NextSibling(p))
            count += LeafCount(p);
    }
    else
        count++;
    return count;
}

template <typename ElemType>
int ChildSiblingTree<ElemType>::LeafCount() const
{
    return LeafCount(root);
}

template <typename ElemType>
int ChildSiblingTree<ElemType>::Height(ChildSiblingTreeNode<ElemType> *r) const
{
    if (!r)
        return 0;
    ChildSiblingTreeNode<ElemType> *p;
    int MAX_HEIGHT = 0;
    for (p = FirstChild(r); p; p = NextSibling(p))
    {
        int h = Height(p);
        MAX_HEIGHT = (h > MAX_HEIGHT) ? h : MAX_HEIGHT;
    }
    return MAX_HEIGHT + 1;
}

template <typename ElemType>
int ChildSiblingTree<ElemType>::Height() const
{
    return Height(root);
}

template <typename ElemType>
int ChildSiblingTree<ElemType>::NodeDegree(ChildSiblingTreeNode<ElemType> *r) const
// 结点的毒
{
    ChildSiblingTreeNode<ElemType> *p;
    int count = 0;
    for (p = FirstChild(r); p; p = NextSibling(p))
    {
        count++;
    }
    return count;
}

template <typename ElemType>
int ChildSiblingTree<ElemType>::Degree(ChildSiblingTreeNode<ElemType> *r) const
{
    ChildSiblingTreeNode<ElemType> *p;
    int max_count = 0;
    for (p = FirstChild(r); p; p = NextSibling(p))
    {
        int count = Degree(p);
        max_count = (count > max_count) ? count : max_count;
    }
    int cur_Degree = NodeDegree(r);
    return (max_count > cur_Degree) ? max_count : cur_Degree;
}

template <typename ElemType>
int ChildSiblingTree<ElemType>::Degree() const
{
    return Degree(root);
}

template <typename ElemType>
ChildSiblingTreeNode<ElemType> *ChildSiblingTree<ElemType>::FirstChild(ChildSiblingTreeNode<ElemType> *cur) const
{
    if (!cur)
        return NULL;
    return cur->firstChild;
}

template <typename ElemType>
ChildSiblingTreeNode<ElemType> *ChildSiblingTree<ElemType>::NextSibling(ChildSiblingTreeNode<ElemType> *cur) const
{
    if (!cur)
        return NULL;
    return cur->nextSibling;
}

template <typename ElemType>
ChildSiblingTreeNode<ElemType> *ChildSiblingTree<ElemType>::Parent(ChildSiblingTreeNode<ElemType> *r,
                                                                   const ChildSiblingTreeNode<ElemType> *cur) const
{
    // 空二叉树
    if (!r)
        return NULL;
    ChildSiblingTreeNode<ElemType> *p;
    for (p = FirstChild(r); p; p = NextSibling(p))
    {
        if (p == cur)
            return r;
    }
    for (p = FirstChild(r); p; p = NextSibling(p))
    {
        ChildSiblingTreeNode<ElemType> *q = Parent(p, cur);
        if (!q)
            return q;
    }
    return NULL;
}

template <typename ElemType>
ChildSiblingTreeNode<ElemType> *ChildSiblingTree<ElemType>::Parent(ChildSiblingTreeNode<ElemType> *cur) const
{
    return Parent(root, cur);
}

template <typename ElemType>
Status ChildSiblingTree<ElemType>::InsertChild(ChildSiblingTreeNode<ElemType> *cur, int i, const ElemType &e)
// 将e变成cur的第i个孩子
{
    if (!cur)
        return FAIL;
    if (i < 1 || i > NodeDegree(cur) + 1)
        return FAIL;
    ChildSiblingTreeNode<ElemType> *newNode = new ChildSiblingTreeNode<ElemType>(e);
    if (i == 1) // 在第一个
    {
        newNode->nextSibling = cur->firstChild;
        cur->firstChild = newNode;
    }
    else
    {
        ChildSiblingTreeNode<ElemType> *p = FirstChild(cur);
        for (int j = 1; j < i - 1; j++)
        {
            p = NextSibling(p);
        }
        newNode->nextSibling = p->nextSibling;
        p->nextSibling = newNode;
    }
    return SUCCESS;
}

template <typename ElemType>
Status ChildSiblingTree<ElemType>::DeleteChild(ChildSiblingTreeNode<ElemType> *cur, int i)
// 将e变成cur的第i个孩子
{
    // if (!cur)
    //     return FAIL;
    if (i < 0 || i > NodeDegree(cur))
        return FAIL;

    ChildSiblingTreeNode<ElemType> *p = FirstChild(cur), *q;
    if (i == 1) // 在第一个
    {
        cur->firstChild = cur->firstChild->nextSibling;
    }
    else
    {
        for (int j = 1; j < i - 1; j++)
        {
            p = NextSibling(p);
        }
        q = p->nextSibling;
        p->nextSibling = p->nextSibling->nextSibling;
    }
    Destory(q);
    return SUCCESS;
}

template <typename ElemType>
ChildSiblingTree<ElemType>::ChildSiblingTree(const ElemType &e)
{
    root = new ChildSiblingTreeNode<ElemType>(e);
}

template <typename ElemType>
ChildSiblingTreeNode<ElemType> *ChildSiblingTree<ElemType>::CopyTree(ChildSiblingTreeNode<ElemType> *troot)
{
    if (!troot)
        return NULL;
    ChildSiblingTreeNode<ElemType> *r = new ChildSiblingTreeNode<ElemType>(troot->data);
    ChildSiblingTreeNode<ElemType> *p, *q, *cur;
    for (p = FirstChild(troot); p; p = NextSibling(p))
    {
        q = CopyTree(p);
        if (!r->firstChild)
        {
            r->firstChild = q;
            cur = q;
        }
        else
        {
            cur->nextSibling = q;
            cur = q;
        }
    }

    return r;
}
///////////////////////////////////////////////////////
template <typename ElemType>
ChildSiblingTree<ElemType>::ChildSiblingTree(const ChildSiblingTree<ElemType> &copy)
{
    root = CopyTree(copy.GetRoot());
}

template <typename ElemType>
ChildSiblingTreeNode<ElemType> *ChildSiblingTree<ElemType>::CreatTreeGhelp(ElemType items[], int parents[], int r, int n)
// items,双亲为parents,根结点位置r,个数n
// 利用递归 只专注本层 递归边界+本次子树构建后接到新r上
{
    if (r < 0 || r >= n) // 非法返回空树
        return NULL;
    ChildSiblingTreeNode<ElemType> *new_r = new ChildSiblingTreeNode<ElemType>(items[r]);
    ChildSiblingTreeNode<ElemType> *p, *cur;
    // cur记录最新构建的子树的根
    for (int i = 0; i < n; i++)
    // 遍历找到r的子树
    {
        if (parents[i] == r)
        {
            p = CreatTreeGhelp(items, parents, i, n);
            if (new_r->firstChild)
            {
                cur->nextSibling = p;
                cur = p;
            }
            else
            {
                new_r->firstChild = p;
                cur = p;
            }
        }
    }
    return new_r;
}

template <typename ElemType>
ChildSiblingTree<ElemType>::ChildSiblingTree(ElemType items[], int parents[], int n)
{
    root = CreatTreeGhelp(items, parents, 0, n);
}

template <typename ElemType>
ChildSiblingTree<ElemType>::ChildSiblingTree(ChildSiblingTreeNode<ElemType> *r)
{
    root = r;
}

template <typename ElemType>
ChildSiblingTree<ElemType> &ChildSiblingTree<ElemType>::operator=(const ChildSiblingTree<ElemType> &copy)
{
    if (&copy == this)
        return *this;
    Destory(root);
    root = CopyTree(copy.GetRoot());
    return *this;
}

// 其他一些功能
template <typename ELemType>
// 凹入法  level层次 设根节点层次为0
void DisplayTWithConcaveShape(const ChildSiblingTree<ELemType> &t, ChildSiblingTreeNode<ELemType> *r, int level)
{
    if (!r)
        return;
    cout << endl;
    for (int i = 0; i < level; i++)
        cout << "  ";
    ChildSiblingTreeNode<ELemType> *p;
    ELemType e;
    t.GetElem(r, e);
    cout << e;
    for (p = t.FirstChild(r); p; p = t.NextSibling(p))
        DisplayTWithConcaveShape(t, p, level + 1);
}

template <typename ElemType>
void DisplayTWithConcaveShape(const ChildSiblingTree<ElemType> &t)
{
    DisplayTWithConcaveShape(t, t.GetRoot(), 0);
    cout << endl;
}

#endif // ! __CHILD_SIBLING_TREE_H__
