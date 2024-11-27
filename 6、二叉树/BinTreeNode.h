#ifndef __BIN_TREE_NODE_H__
#define __BIN_TREE_NODE_H__

#include "Assistance.h"

template <class ELemType>
struct BinTreeNode {
    ELemType data;
    BinTreeNode<ELemType>* leftChild;
    BinTreeNode<ELemType>* rightChild;

    BinTreeNode();
    BinTreeNode(const ELemType & d,
        BinTreeNode<ELemType>* lChild = NULL,
        BinTreeNode<ELemType>* rChild = NULL);
};

template <class ELemType>
BinTreeNode<ELemType>::BinTreeNode() {
    leftChild = rightChild = NULL;
}

template <class ELemType>
BinTreeNode<ELemType>::BinTreeNode(const ELemType & d,
        BinTreeNode<ELemType>* lChild,
        BinTreeNode<ELemType>* rChild) {
    data = d;
    leftChild = lChild;
    rightChild = rChild;
}

#endif // !__BIN_TREE_NODE_H__