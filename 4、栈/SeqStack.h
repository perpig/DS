//SeqStack.h
//顺序栈
#ifndef __SEASTACK_H__
#define __SEASTACK_H__

#include"Assistance.h"

template<typename ElemType>
class SeqStack
{
protected:
    int top;
    int maxSize;
    ElemType *elems;
public:
    SeqStack(int size = DEFALT_SIZE);  //有参构造函数
    virtual ~SeqStack();               //析构函数
    int GetLength() const;             //栈长度
    bool IsEmpty() const;              //判断是否为空
    void Clear();                      //清空栈
    void Traverse(void(*Visit)(const ElemType &)) const;  //遍历z栈
    Status Push(const ElemType e);  //入栈
    Status Top(ElemType &e) const;  //取栈顶元素
    Status pop(ElemType &e);  //出栈
    SeqStack(const SeqStack<ElemType> &s);  //拷贝构造函数
    SeqStack<ElemType>& operator=(const SeqStack<ElemType> &s);  //重载赋值运算符 
};

//有参构造函数
template<typename ElemType>
SeqStack<ElemType>::SeqStack(int size)  
{
    top = -1;
    maxSize = size;
    if(elems != NULL) delete []elems;  //释放已有的存储空间
    elems = new ElemType[maxSize];
}

//析构函数
template<typename ElemType>
SeqStack<ElemType>::~SeqStack()
{
    delete []elems;
}       

//栈长度      
template<typename ElemType>
int SeqStack<ElemType>::GetLength() const
{
    return top+1;
}
             
//判断是否为空
template<typename ElemType>
bool SeqStack<ElemType>::IsEmpty() const
{
    return top == -1;
}

//清空栈
template<typename ElemType>
void SeqStack<ElemType>::Clear()
{
    top = -1;
}                   
    
//遍历z栈    
template<typename ElemType>
void SeqStack<ElemType>::Traverse(void(*Visit)(const ElemType &)) const
{
    for(int i = top; i >= 0; i--)
        (*visit)(elems[i]);
}

//入栈
template<typename ElemType>
Status SeqStack<ElemType>::Push(const ElemType e)
{
    if(top == maxSize - 1) return OVER_FLOW;
    elems[++top] = e;
    return SUCCESS;
}

//取栈顶元素
template<typename ElemType>
Status SeqStack<ElemType>::Top(ElemType &e) const
{
    if(IsEmpty()) return UNDER_FLOW;
    e = elems[top];
    return SUCCESS;
}

//出栈
template<typename ElemType>
Status SeqStack<ElemType>::pop(ElemType &e)
{
    if(IsEmpty()) return UNDER_FLOW;
    e = elems[top--];
    return SUCCESS;
}
    
//拷贝构造函数
template<typename ElemType>
SeqStack<ElemType>::SeqStack(const SeqStack<ElemType> &s)
{
    maxSize = s.maxSize;
    top = s.top;
    if(elems != NULL && elems != s.elems) delete []elems;
    elems = new ElemType[maxSize];
    for(int i = 0; i<=top; i++)
        elems[i] = s.elems[i];
}

//重载赋值运算符 
template<typename ElemType>
SeqStack<ElemType>& SeqStack<ElemType>::operator=(const SeqStack<ElemType> &s)
{
    if(&s == this) return *this;
    maxSize = s.maxSize;
    top = s.top;
    if(elems != NULL && elems != s.elems) delete []elems;
    elems = new ElemType[maxSize];
    for(int i = 0; i<= top; i++)
        elems[i] = s.elems[i];
    return *this;
}

#endif // !__SEASTACK_H__