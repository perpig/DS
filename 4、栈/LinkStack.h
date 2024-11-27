#ifndef __LINKSTACK_H__
#define __LINKSTACK_H__

#include "Node.h"
#include "Assistance.h"

//链表栈类
template<class ElemType>
class LinkStack
{
protected:
    Node<ElemType> *top;

public:
    LinkStack();
    ~LinkStack();
    int GetLength() const;
    bool IsEmpty() const;
    void Clear();
    void Traverse(void(*visit)(const ElemType &)) const;
    Status Push(const ElemType e);
    Status Top(ElemType &e) const;
    Status Pop(ElemType &e);
    LinkStack(const LinkStack<ElemType> &s);
    LinkStack<ElemType>& operator=(const LinkStack<ElemType> &s);
};

template<typename ElemType>
LinkStack<ElemType>::LinkStack()
{
    top = NULL;
}

template<typename ElemType>
LinkStack<ElemType>::~LinkStack()
{
    Clear();
}
template<typename ElemType>
int LinkStack<ElemType>::GetLength() const
{
    int count = 0;
    Node<ElemType> *p;
    for(p = top; p != NULL; p = p->next)
        count++;
    return count;
}

template<typename ElemType>
bool LinkStack<ElemType>::IsEmpty() const
{
    return top == NULL;
}

template<typename ElemType>
void LinkStack<ElemType>::Clear()
{
    Node<ElemType> *p;
    for(p = top; top != NULL;top = top->next)
        delete p;
}

template<typename ElemType>
void LinkStack<ElemType>::Traverse(void(*visit)(const ElemType &)) const
{
    Node<ElemType> *p;
    for(p = top; p != NULL;p = p->next)
        (*visit)(p->data);
}

template<typename ElemType>
Status LinkStack<ElemType>::Push(const ElemType e)
{
    Node<ElemType> *p = new Node<ElemType>(e,top);
    if(p == NULL) return OVER_FLOW; //动态内存耗尽
    top = p;
    return SUCCESS;
}

template<typename ElemType>
Status LinkStack<ElemType>::Top(ElemType &e) const
{
    if(IsEmpty()) return UNDER_FLOW;  //栈空
    e = top->data;
    return SUCCESS;
}

template<typename ElemType>
Status LinkStack<ElemType>::Pop(ElemType &e)
{
    if(IsEmpty()) return UNDER_FLOW;  //栈空
    e = top->data;
    Node<ElemType> *p = top;
    top = top->next;
    delete p;
    return SUCCESS;
}

template<typename ElemType>
LinkStack<ElemType>::LinkStack(const LinkStack<ElemType> &s)
{
    if(s.IsEmpty()) top = NULL;
    else
    {
        top = new Node<ElemType>(s.top->data);  
        Node<ElemType> *p = top; 
        Node<ElemType> *q = s.top->next;
        for(;q != NULL; p = p->next, q = q->next)
            p->next = new Node<ElemType>(q->data);
    }
}

template<typename ElemType>
LinkStack<ElemType>& LinkStack<ElemType>::operator=(const LinkStack<ElemType> &s)
{
    if(&s == this) return *this;
    Clear();
    if(s.IsEmpty()) return *this;
    top = new Node<ElemType>(s.top->data);
    Node<ElemType> *p = top;
    Node<ElemType> *q = s.top->next;
    for(;q != NULL; p = p->next, q = q->next )
        p->next = new Node<ElemType>(q->data);
    return *this;
}

#endif 