#ifndef __SEQQUEUE_H__
#define __SEQQUEUE_H__
//队列
#include "Assistance.h"

template<class ElemType>
class SeqQueue
{
protected:
    int front,rear;
    int maxSize;
    ElemType *elems;

public:
    SeqQueue(int size = DEFAULT_SIZE);
    virtual ~SeqQueue();
    int GetLength() const;
    bool IsEmpty() const;
    void Clear();
    void Traverse(void(*visit)(const ElemType &)) const;
    Status DelQueue(ElemType &e);
    Status GetHead(ElemType &e) const;
    Status EnQueue(const ElemType &e); // 入队操作
    SeqQueue(const SeqQueue<ElemType> &q);
    SeqQueue<ElemType>& operator = (const SeqQueue<ElemType> &q);
};

template<class ElemType>
SeqQueue<ElemType>::SeqQueue(int size)
{
    maxSize = size;
    elems = new ElemType[maxSize];
    rear = front = 0;
}

template<class ElemType>
SeqQueue<ElemType>::~SeqQueue()
{
    delete [] elems;
}

template<class ElemType>
int SeqQueue<ElemType>::GetLength() const
{
    return (rear - front + maxSize) % maxSize;
}

template<class ElemType>
bool SeqQueue<ElemType>::IsEmpty() const
{
    return rear == front;
}

template<class ElemType>
void SeqQueue<ElemType>::Clear()
{
    rear = front = 0;
}

template<class ElemType>
void SeqQueue<ElemType>::Traverse(void(*visit)(const ElemType &)) const
{
    for(int i = front;i != rear; i = (i+1) % maxSize)
        (*visit)(elems[i]);
}

template<class ElemType>
Status SeqQueue<ElemType>::DelQueue(ElemType &e)
{
    if(IsEmpty()) return UNDER_FLOW;
    e = elems[front];
    front = (front + 1) % maxSize;
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
    if((rear+1) % maxSize == front) return OVER_FLOW;
    elems[rear] = e;
    rear = (rear + 1) % maxSize;
    return SUCCESS;
}

template<class ElemType>
SeqQueue<ElemType>::SeqQueue(const SeqQueue<ElemType> &q)
{
    maxSize = q.maxSize;
    if(elems != NULL && elems != q.elems) delete []elems;
    elems = new ElemType[maxSize];
    front = q.front;
    rear = q.rear;
    for(int i = front; i != rear; i = (i + 1) % maxSize)
        elems[i] = q.elems[i];
}

template<class ElemType>
SeqQueue<ElemType>& SeqQueue<ElemType>::operator = (const SeqQueue<ElemType> &q)
{
    if(&q == this) return *this;
    maxSize = q.maxSize;
    if(elems != NULL && elems != q.elems) delete []elems;
    elems = new ElemType[maxSize];
    front = q.front;
    rear = q.rear;
    for(int i = front; i != rear; i = (i + 1) % maxSize)
        elems[i] = q.elems[i];
    return *this;
}

#endif // !__SEQQUEUEH___