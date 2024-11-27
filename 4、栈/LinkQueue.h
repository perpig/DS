#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__

//链式队列
//带头结点和尾结点
//先入后出“像排队一样”
#include "Assistance.h"
#include "Node.h"

template<class ElemType>
class LinkQueue
{
protected:
    Node<ElemType> *front,*rear;

public:
    LinkQueue();
    virtual ~LinkQueue();
    int GetLength() const;
    bool IsEmpty() const;
    void Clear();
    void Traverse(void (*visit)(const ElemType &)) const;
    Status DelQueue(ElemType &e);
    Status GetHead(const ElemType &e) const;
    Status EnQueue(const ElemType e);
    LinkQueue(const LinkQueue<ElemType> &q);
    LinkQueue<ElemType>& operator = (const LinkQueue<ElemType> &q);
};

template<class ElemType>
LinkQueue<ElemType>::LinkQueue()
{
    front = rear = new Node<ElemType>;
}

template<class ElemType>
LinkQueue<ElemType>::~LinkQueue()
{
    Clear();
    delete front;
}

template<class ElemType>
int LinkQueue<ElemType>::GetLength() const
{
    int count = 0;
    Node<ElemType>* p = front->next;
    for(;p != NULL; p = p->next)
    count++;
    return count;
}

template<class ElemType>
bool LinkQueue<ElemType>::IsEmpty() const
{
    return rear == front;
}

template<class ElemType>
void LinkQueue<ElemType>::Clear()
{
    Node<ElemType> *p = front->next;
    while(p != NULL)
    {
        front->next = p->next;
        delete p;
        p = front->next;
    }
    rear = front;
}

template<class ElemType>
void LinkQueue<ElemType>::Traverse(void (*visit)(const ElemType &)) const
{
    for(Node<ElemType> *p = front->next; p != NULL; p = p->next)
        (*visit)(p->data);
}

template<class ElemType>
Status LinkQueue<ElemType>::DelQueue(ElemType &e)
{
    if(IsEmpty()) return UNDER_FLOW;
    e = front->next->data;
    Node<ElemType> *p = front->next;
    front->next = p->next;
    //注意，当原先队列中只有一个元素时，要使队尾指针指向头结点。
    if(rear == p) rear = front;
    delete p;
    return SUCCESS;
}

template<class ElemType>
Status LinkQueue<ElemType>::GetHead(const ElemType &e) const
{
    if(IsEmpty()) return UNDER_FLOW;
    e = front->next->data;
    return SUCCESS;
}

template<class ElemType>
Status LinkQueue<ElemType>::EnQueue(const ElemType e)
{
    Node<ElemType> *p = new Node<ElemType>(e);
    if(p == NULL) return OVER_FLOW;  //动态内存已满
    rear->next = p;
    rear = rear->next;
    return SUCCESS;
}

template<class ElemType>
LinkQueue<ElemType>::LinkQueue(const LinkQueue<ElemType> &q)
{
    rear = front = new Node<ElemType>;
    for(Node<ElemType> *p = q.front->next; p != NULL; p = p->next)
        EnQueue(p->data);
} 

template<class ElemType>
LinkQueue<ElemType>& LinkQueue<ElemType>::operator = (const LinkQueue<ElemType> &q)
{
    if(&q == this) return *this;
    Clear();
    for(Node<ElemType> *p = q.front->next; p != NULL; p = p->next)
        EnQueue(p->data);
    return *this;
}

#endif // !__LINKQUEUE_H__
