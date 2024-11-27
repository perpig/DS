#ifndef __CHILD_SIBLING_FOREST_NODE_H__
#define __CHILD_SIBLING_FOREST_NODE_H__

#include "Assistance.h"
#include "Node.h"

template <typename ElemType>
struct ChildSiblingTreeNode
{
    ElemType data;
    ChildSiblingTreeNode<ElemType> *firstChild;
    ChildSiblingTreeNode<ElemType> *nextSibling;

    ChildSiblingTreeNode();
    ChildSiblingTreeNode(ElemType val,
                         ChildSiblingTreeNode<ElemType> *firstChild = NULL,
                         ChildSiblingTreeNode<ElemType> *nextSibling = NULL);
};

template <typename ElemType>
ChildSiblingTreeNode<ElemType>::ChildSiblingTreeNode()
{
    firstChild = nextSibling = NULL;
}

template <typename ElemType>
ChildSiblingTreeNode<ElemType>::ChildSiblingTreeNode(ElemType val,
            ChildSiblingTreeNode<ElemType> *f,
            ChildSiblingTreeNode<ElemType> *n)
{
    data = val;
    firstChild = f;
    nextSibling = n;
}
#endif //__CHILD_SIBLING_FOREST_NODE_H__