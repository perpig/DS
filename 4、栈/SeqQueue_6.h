#ifndef __SEQQUEUE_6_H__
#define __SEQQUEUE_6_H__
//队列
#include "Assistance.h"

//6. 修改本书介绍的循环队列设计，以front和length吵分别表示循环队列中的队头位置
//和队列中所含元素的个数。试完成循环队列判断队空、判断队满入队和出队函数的实现。

template<class ElemType>
class SeqQueue
{
protected:
    int front;
    int length;
    int maxSize;
    ElemType *elems;

public:
    SeqQueue(int size = DEFAULT_SIZE);
    virtual ~SeqQueue();
    int GetLength() const;
    bool IsEmpty() const;  //判断队空
    bool IsFULL() const;   //判断队满
    void Clear();
    void Traverse(void(*visit)(const ElemType &)) const;
    Status DelQueue(ElemType &e);   //出队操作
    Status GetHead(ElemType &e) const;
    Status EnQueue(const ElemType &e); // 入队操作
    SeqQueue(const SeqQueue<ElemType> &q);
    SeqQueue<ElemType>& operator = (const SeqQueue<ElemType> &q);
};

template<class ElemType>
SeqQueue<ElemType>::SeqQueue(int size)
//有参构造函数
{
    maxSize = size;
    elems = new ElemType[maxSize];
    front = length = 0;
}

template<class ElemType>
SeqQueue<ElemType>::~SeqQueue()
{
    delete [] elems;
}

template<class ElemType>
int SeqQueue<ElemType>::GetLength() const
{
    return length;
}

//队空
template<class ElemType>
bool SeqQueue<ElemType>::IsEmpty() const
{
    return length == 0;
}

//队满
template<class ElemType>
bool SeqQueue<ElemType>::IsFULL() const
{
    return length == maxSize;
}

template<class ElemType>
void SeqQueue<ElemType>::Clear()
{
    length = front = 0;
}

template<class ElemType>
void SeqQueue<ElemType>::Traverse(void(*visit)(const ElemType &)) const
{
    for(int i = 0;i < length ; i++)
        (*visit)(elems[(i + front) % maxSize]);
}

template<class ElemType>
Status SeqQueue<ElemType>::DelQueue(ElemType &e)
//出队操作
{
    if(IsEmpty()) return UNDER_FLOW;
    e = elems[front];
    front = (front + 1) % maxSize;
    length--;
    return SUCCESS;
}

template<class ElemType>
Status SeqQueue<ElemType>::GetHead(ElemType &e) const
{
    if(IsEmpty()) return UNDER_FLOW;
    e = elems[front];
    return SUCCESS;
}

template<class ElemType>
Status SeqQueue<ElemType>::EnQueue(const ElemType &e)
// 入队操作
{
    if(IsFULL()) return OVER_FLOW;
    elems[(front + length) % maxSize] = e;
    length++;
    return SUCCESS;
}

template<class ElemType>
SeqQueue<ElemType>::SeqQueue(const SeqQueue<ElemType> &q)
{
    maxSize = q.maxSize;
    if(elems != NULL && elems != q.elems) delete []elems;
    elems = new ElemType[maxSize];
    front = q.front;
    length = q.length;
    for(int i = 0; i < length; i++)
        elems[(i + front) % maxSize] = q.elems[(i + front) % maxSize];
}

template<class ElemType>
SeqQueue<ElemType>& SeqQueue<ElemType>::operator = (const SeqQueue<ElemType> &q)
{
    if(&q == this) return *this;
    maxSize = q.maxSize;
    if(elems != NULL && elems != q.elems) delete []elems;
    elems = new ElemType[maxSize];
    front = q.front;
    length = q.length;
    for(int i = 0; i < length; i++)
        elems[(i + front) % maxSize] = q.elems[(i + front) % maxSize];
    return *this;
}

#endif // !__SEQQUEUEH___