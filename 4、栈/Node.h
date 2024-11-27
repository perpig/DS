#ifndef __NODE_H__
#define __NODE_H__
//链表栈----结点类

template<typename ElemType>
struct Node
{
    ElemType data;
    Node<ElemType> *next;

    Node();   //无参默认构造函数
    Node(ElemType item, Node<ElemType>* link = NULL);
};

template<typename ElemType>
Node<ElemType>::Node()
{
    next = NULL;
}

template<typename ElemType>
Node<ElemType>::Node(ElemType item, Node<ElemType>* link)
{
    data = item;
    next = link;
}

#endif 