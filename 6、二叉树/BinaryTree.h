//考完有空看看CreateBinaryTree
#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include "LinkQueue.h"
#include "LinkStack.h"
#include "BinTreeNode.h"
#include "Assistance.h"

template <class ElemType>
class BinaryTree
{
protected:
    BinTreeNode<ElemType>* root; //根节点
    //拷贝树
    BinTreeNode<ElemType>* CopyTree(BinTreeNode<ElemType> *t);
    //删除以r为根的树
    void Destroy(BinTreeNode<ElemType>* &r);
    // 先序遍历以r为根的二叉树
    void PreOrder(BinTreeNode<ElemType>*r,void(*Visit)(const ElemType &)) const;
    // 中序遍历以r为根的二叉树
    void InOrder(BinTreeNode<ElemType>*r,void(*Visit)(const ElemType &)) const;
    // 后序遍历以r为根的二叉树
    void PostOrder(BinTreeNode<ElemType>*r,void(*Visit)(const ElemType &)) const;
    //求高
    int Height(const BinTreeNode<ElemType>* r) const;
    //求节点个数
    int NodeCount(const BinTreeNode<ElemType>* r) const;
    //求最端点的节点数
    int LeafCount(const BinTreeNode<ElemType>* r) const;
    //求双亲
    BinTreeNode<ElemType>* Parent(BinTreeNode<ElemType>* r, const BinTreeNode<ElemType>* p) const;

public:
    //无参构造函数
    BinaryTree();
    //以e为根的构造函数
    BinaryTree(const ElemType &e);
    virtual ~BinaryTree();
    //返回根
    BinTreeNode<ElemType>* GetRoot() const;
    bool IsEmpty() const;
    Status GetElem(BinTreeNode<ElemType> *p, ElemType &e) const;
    Status SetElem(BinTreeNode<ElemType>* p, const ElemType &e);
    void PreOrder(void (*Visit)(const ElemType &)) const;
    void InOrder(void (*Visit)(const ElemType &)) const;
    void PostOrder(void (*Visit)(const ElemType &)) const;
    //Recursion 递归
    void PreOrderWithoutRecursion(void (*Visit)(const ElemType &)) const;	
    void InOrderWithoutRecursion(void (*Visit)(const ElemType &)) const;	
    //层序遍历
    void LevelOrder(void (*Vist)(const ElemType &)) const;
    //求高
    int	Height() const;		
    //节点数
    int NodeCount() const;
    //端点数
    int LeafCount() const;
    //翻转函数
    BinTreeNode<ElemType>* Revolute(const BinTreeNode<ElemType>* r)const;

    //  求结点p的左孩子
	BinTreeNode<ElemType> *LeftChild(const BinTreeNode<ElemType> *p) const;
	// 求结点p的右孩子
	BinTreeNode<ElemType> *RightChild(const BinTreeNode<ElemType> *p) const;
	// 求结点p的左兄弟 
	BinTreeNode<ElemType> *LeftSibling(const BinTreeNode<ElemType> *p) const;
	// 求结点p的右兄弟
	BinTreeNode<ElemType>*RightSibling(const BinTreeNode<ElemType>*p) const;
	// 求结点p的双亲
	BinTreeNode<ElemType> *Parent(const BinTreeNode<ElemType> *p) const;
    // 插入一个结点e作为p的左孩子
	void InsertLeftChild(BinTreeNode<ElemType> *p, const ElemType &e);
    // 插入一个结点e作为p的右孩子
	void InsertRightChild(BinTreeNode<ElemType> *p, const ElemType &e);
    // 删除p的左子树
	void DeleteLeftChild(BinTreeNode<ElemType> *p);	
    // 删除p的右子树
	void DeleteRightChild(BinTreeNode<ElemType> *p);

	//"完全二叉树"（complete binary tree）每一层填满
	bool IsComBiTree ( ) const;
    // 复制构造函数
	BinaryTree(const BinaryTree<ElemType> &t);	
    // 建立以r为根的二叉树
	BinaryTree(BinTreeNode<ElemType> *r);	
    // 赋值运算符重载		
	BinaryTree<ElemType> &operator=(const BinaryTree<ElemType>& t);
};

//其他的函数：

template <class ElemType>
//	按树状形式显示以r为根的二叉树，level为层次数，可设根结点的层次数为1
void DisplayBTWithTreeShape(BinTreeNode<ElemType> *r, int level);

template <class ElemType>
//	对外接口：树状形式显示二叉树 
void DisplayBTWithTreeShape(BinaryTree<ElemType> &bt);


template <class ElemType>
// 已知二叉树的先序序列pre[preLeft..preRight]和中序序列in[inLeft..inRight]构造以r为根的二叉树
void CreateBinaryTree(BinTreeNode<ElemType> *&r, ElemType pre[], ElemType in[], 
	int preLeft, int preRight, int inLeft, int inRight);	
		
template <class ElemType>
// 已知先序和中序序列构造二叉树
BinaryTree<ElemType> &CreateBinaryTree(ElemType pre[], ElemType in[], int n);



template <class ElemType>
//无参构造函数
BinaryTree<ElemType>::BinaryTree()
{
    root = NULL;
}

template <class ElemType>
//以e为根的构造函数
BinaryTree<ElemType>::BinaryTree(const ElemType &e)
{
    root = new BinTreeNode<ElemType>(e,NULL,NULL);
}

template <class ElemType>
BinaryTree<ElemType>::~BinaryTree()
{
    Destroy(root);
}

template <class ElemType>
BinTreeNode<ElemType>* BinaryTree<ElemType>::CopyTree(BinTreeNode<ElemType> *t)
{
    if(r == NULL) return NULL;
    BinTreeNode<ElemType>* lChild = CopyTree(t->leftChild);
    BinTreeNode<ElemType>* rChild = CopyTree(t->rightChild);
    BinTreeNode<ElemType>* r = new BinTreeNode(t->data,lChild,rChild);
    return r;
}

template <class ElemType>
void BinaryTree<ElemType>::Destroy(BinTreeNode<ElemType>* &r)
{
    if(r==NULL) return;
    Destroy(r->leftChild);
    Destroy(r->rightChild);
    delete r;
}

template <class ElemType>
//返回根
BinTreeNode<ElemType>* BinaryTree<ElemType>::GetRoot() const
{
    return root;
}
    
template <class ElemType>
bool BinaryTree<ElemType>::IsEmpty() const
{
    return root == NULL;
}

template <class ElemType>
Status BinaryTree<ElemType>::GetElem(BinTreeNode<ElemType> *p, ElemType &e) const
// 操作结果：用e返回结点p元素值,如果不存在结点p,函数返回NOT_PRESENT,否则返回ENTRY_FOUND
{
    if(p == NULL) return NOT_PRESENT;
    e = p->data;
    return ENTRY_FOUND;
}
    
template <class ElemType>
Status BinaryTree<ElemType>::SetElem(BinTreeNode<ElemType>* p, const ElemType &e)
// 操作结果：如果不存在结点p,则返回FAIL,否则返回SUCCESS,并将结点p的值设置为e
{
    if(p == NULL) return FAIL;
    p->data = e;
    return SUCCESS;
}

template <class ElemType>
// 先序遍历以r为根的二叉树
void BinaryTree<ElemType>::PreOrder(BinTreeNode<ElemType>*r,void(*Visit)(const ElemType &)) const
{
    if(r == NULL) return;
    (*Visit)(r->data);
    PreOrder(r->leftChild);
    PreOrder(r->rightChild);
}

template <class ElemType>
void BinaryTree<ElemType>::PreOrder(void (*Visit)(const ElemType &)) const
{
    PreOrder(root,Visit);
}

template <class ElemType>
void BinaryTree<ElemType>::PreOrderWithoutRecursion(void (*Visit)(const ElemType &)) const
{
    if(root == NULL) return;
    BinTreeNode<ElemType> * p = root;
    LinkStack<BinTreeNode<ElemType> * > s;
    while(p != NULL || !s.IsEmpty())
    {
        while(p != NULL)
        {
            (*Visit)(p->data);
            s.Push(p);
            p = p->leftChild;
        }
        if(!s.IsEmpty())
        {
            s.Pop(p);
            p = p->rightChild;
        }
    }
}

template <class ElemType>
// 中序遍历以r为根的二叉树
void BinaryTree<ElemType>::InOrder(BinTreeNode<ElemType>*r,void(*Visit)(const ElemType &)) const
{
    if(r == NULL) return;
    InOrder(r->leftChild);
    (*Visit)(r->data);
    InOrder(r->rightChild);
}

template <class ElemType>
void BinaryTree<ElemType>::InOrder(void (*Visit)(const ElemType &)) const
{
    InOrder(root,Visit);
}

template <class ElemType>
void BinaryTree<ElemType>::InOrderWithoutRecursion(void (*Visit)(const ElemType &)) const
{
    if(root == NULL) return;
    BinTreeNode<ElemType> * p = root;
	LinkStack<BinTreeNode<ElemType> *> s;
    while(p != NULL || !s.IsEmpty())
    {
        while(p)
        {
            s.Push(p);
            p = p->leftChild;
        }
        if(!s.IsEmpty())
        {
            s.Pop(p);
            (*Visit)(p->data);
            p = p->rightChild;
        }
    }

}

template <class ElemType>
// 后序遍历以r为根的二叉树
void BinaryTree<ElemType>::PostOrder(BinTreeNode<ElemType>*r,void(*Visit)(const ElemType &)) const
{
    if(r == NULL) return;
    PreOrder(r->leftChild);
    PreOrder(r->rightChild);
    (*Visit)(r->data);
}

template <class ElemType>
void BinaryTree<ElemType>::PostOrder(void (*Visit)(const ElemType &)) const
{
    PostOrder(root,Visit);
}

template <class ElemType>
//层序遍历
void BinaryTree<ElemType>::LevelOrder(void (*Vist)(const ElemType &)) const
{
    BinTreeNode<ElemType>* p;
    LinkQueue<BinTreeNode<ElemType> * > q;
    if(root) q.EnQueue(root);
    while(!q.IsEmpty())
    {
        //这一层按顺序遍历
        q.DelQueue(p);
        (*Visit)(p->data);
        //把下一层入队列
        if(p->leftChild != NULL)
        q.EnQueue(p->leftChild);
        if(p->rightChild != NULL)
        q.EnQueue(p->rightChild);
    }
}

template <class ElemType>
//求高
int BinaryTree<ElemType>::Height(const BinTreeNode<ElemType>* r) const
{
    if(r == NULL) return 0;
    int lHeight = Height(r->leftChild);
    int rHeight = Height(r->rightChild);
    return (lHeight > rHeight ? lHeight : rHeight) + 1;
}

template <class ElemType>
//求高
int BinaryTree<ElemType>::Height() const
{
    return Height(root);
}

template <class ElemType>
//求节点个数
int BinaryTree<ElemType>::NodeCount(const BinTreeNode<ElemType>* r) const
{
    if(r == NULL) return 0;
    return NodeCount(r->leftChild) + NodeCount (r->rightChild)+1;
}

template <class ElemType>
//节点数
int BinaryTree<ElemType>::NodeCount() const
{
    NodeCount(root);
}

template <class ElemType>
//求最端点的节点数
int BinaryTree<ElemType>::LeafCount(const BinTreeNode<ElemType>* r) const
{
    if(r == NULL) return 0;
    if(r->leftChild == NULL && r->rightChil == NULL)
    return 1;
    return LeafCount(r->leftChild) + LeafCount(r->rightChild);
}

template <class ElemType>
//端点数
int BinaryTree<ElemType>::LeafCount() const
{
    LeafCount(root);
}

template <class ElemType>
BinTreeNode<ElemType>* BinaryTree<ElemType>::Revolute(const BinTreeNode<ElemType>* r) const
{
	if (r == NULL) return NULL;
    Revolute(r->leftChild);
    Revolute(r->rightChild);

    // 交换左右子节点
    BinTreeNode<ElemType>* temp = r->leftChild;
    r->leftChild = r->rightChild;
    r->rightChild = temp;
}

// template <class ElemType>
// BinTreeNode<ElemType>* BinaryTree<ElemType>::Revolute(const BinTreeNode<ElemType>* r) const
// {
// 	if (r == NULL)
// 		return NULL;
// 	BinTreeNode<ElemType>* newRoot = new BinTreeNode<ElemType>(r->data);
// 	newRoot->leftChild = Revolute(r->rightChild);
// 	newRoot->rightChild = Revolute(r->leftChild);
// 	return newRoot;
// }

template <class ElemType>
//求双亲
BinTreeNode<ElemType>* BinaryTree<ElemType>::Parent(BinTreeNode<ElemType>* r, const BinTreeNode<ElemType>* p) const
{
    if(r == NULL) return NULL;
    if(r -> leftChild == p || r -> rightChild == p) 
    return r;
    BinTreeNode<ElemType>* tmp;
    tmp = Parent(r->leftChild , p);
    if(tmp != NULL) return tmp;
    tmp = Parent(r->rightChild , p);
    if(tmp != NULL) return tmp;
    return NULL;
}
    
template <class ElemType>
BinTreeNode<ElemType> *BinaryTree<ElemType>::Parent(const BinTreeNode<ElemType> *p) const
// 操作结果：返回二叉树结点p的双亲
{
	return Parent(root, p);
}

template <class ElemType>
BinTreeNode<ElemType> *BinaryTree<ElemType>::LeftChild(const BinTreeNode<ElemType> *p) const
// 操作结果：返回二叉树结点p的左孩子
{
	return p->leftChild;
}

template <class ElemType>
BinTreeNode<ElemType> *BinaryTree<ElemType>::RightChild(const BinTreeNode<ElemType> *p) const
// 操作结果：返回二叉树结点p的右孩子
{
	return p->rightChild;
}

template <class ElemType>
BinTreeNode<ElemType> *BinaryTree<ElemType>::LeftSibling(const BinTreeNode<ElemType> *p) const
// 操作结果：返回二叉树结点p的左兄弟 
{
    BinTreeNode<ElemType> *r = Parent(root, p);
    if (r == NULL)
       return NULL;
    if (r->rightChild == p)
	   return r->leftChild; 
    return NULL;
}

template <class ElemType>
BinTreeNode<ElemType> *BinaryTree<ElemType>::RightSibling(const BinTreeNode<ElemType> *p) const
// 操作结果：返回二叉树结点p的左兄弟
{
    BinTreeNode<ElemType> *r = Parent(root, p);
    if (r == NULL)
       return NULL;
    if (r->leftChild == p)
	   return r->rightChild;
    return NULL;
}

template <class ElemType>
void BinaryTree<ElemType>::InsertLeftChild(BinTreeNode<ElemType> *p, const ElemType &e)
// 初始条件：p非空，
// 操作结果：插入元素值为e的结点为p的左孩子，如果p的左孩子非空，则p原有左子树成为e的左子树
{
	if (p == NULL)	// p空，返回
		return;
    BinTreeNode<ElemType>* Child = new BinTreeNode<ElemType>(e);
    if(p->leftChild != NULL)
    Child->leftChild = p->leftChild;
    p->leftChild = Child;
}

template <class ElemType>
void BinaryTree<ElemType>::InsertRightChild(BinTreeNode<ElemType> *p, const ElemType &e)
// 初始条件：p非空
// 操作结果：插入元素值为e的结点为p的右孩子，如果p的右孩子非空，则p原有右子树成为e的右子树
{
	if (p == NULL)	// p为空，返回
		return;
    BinTreeNode<ElemType>* Child = new BinTreeNode<ElemType>(e);
    if(p->rightChild != NULL)
    Child->rightChild = p->rightChild;
    p->rightChild = Child;
}

template <class ElemType>
void BinaryTree<ElemType>::DeleteLeftChild(BinTreeNode<ElemType> *p)
// 初始条件：p非空
// 操作结果：删除p左子树
{
	if (p == NULL)	
		return;
	Destroy(p->leftChild);	// 删除p左子树
}

template <class ElemType>
void BinaryTree<ElemType>::DeleteRightChild(BinTreeNode<ElemType> *p)
// 初始条件：p非空
// 操作结果：删除p右子树
{
	if (p == NULL)	// p为空
		return;
	// p非空
	Destroy(p->rightChild);	// 删除p右子树
}

template <class ElemType>
//"完全二叉树"（complete binary tree）每一层填满
bool BinaryTree<ElemType>::IsComBiTree ( ) const
{
    if(root == NULL) return true;
    BinTreeNode<ElemType>* p = root;
    LinkStack<BinTreeNode<ELemType>*> s;
    while(p != NULL || !s.IsEmpty())
    {
        if(p == NULL) //到最末尾了，出栈判断
        {
            s.Pop(p);
        }
        if(p -> leftChild == NULL && p -> rightChild != NULL
        || p -> leftChild != NULL && p -> rightChild == NULL)
        return false;
        s.Push(p->rightChild);
        p = p->leftChild;
        if(p -> leftChild == NULL && p -> rightChild != NULL
        || p -> leftChild != NULL && p -> rightChild == NULL)
        return false;
    }
    return true;
}

template <class ElemType>
// 复制构造函数
BinaryTree<ElemType>::BinaryTree(const BinaryTree<ElemType> &t)
{
    root = CopyTree(t.root);
}

template <class ElemType>
// 建立以r为根的二叉树
BinaryTree<ElemType>::BinaryTree(BinTreeNode<ElemType> *r)	
{
    root = r;
}	

template <class ElemType>
// 赋值运算符重载
BinaryTree<ElemType>& BinaryTree<ElemType>::operator=(const BinaryTree<ElemType>& t)
{
    if(&t == this) return *this;
    Destroy(root);
    root = CopyTree(t.root);
    return this;
}

//其他的函数：

template <class ElemType>
//	按树状形式显示以r为根的二叉树，level为层次数，可设根结点的层次数为1
void DisplayBTWithTreeShape(BinTreeNode<ElemType> *r, int level)
{
    if(r == NULL) return;
    DisplayBTWithTreeShape(r->leftChild, level + 1);
    cout << endl;
    for(int i = 0;i < level; i++)
    cout << " ";
    cout << r->data;
    DisplayBTWithTreeShape(r->leftChild, level + 1);
}

//对外接口：
template <class ElemType>
//	树状形式显示二叉树 
void DisplayBTWithTreeShape(BinaryTree<ElemType> &bt)
{
    DisplayBTWithTreeShape(bt.GetRoot(), 1);
    cout << endl;
}


// template <class ElemType>
// // 已知二叉树的先序序列pre[preLeft..preRight]和中序序列in[inLeft..inRight]构造以r为根的二叉树
// void CreateBinaryTree(BinTreeNode<ElemType> *&r, ElemType pre[], ElemType in[], 
// 	int preLeft, int preRight, int inLeft, int inRight)
// {

// }

// template <class ElemType>
// // 已知先序和中序序列构造二叉树
// BinaryTree<ElemType> &CreateBinaryTree(ElemType pre[], ElemType in[], int n)
// {}

template <class ElemType>
void CreateBinaryTree(BinTreeNode<ElemType> *&r, ElemType pre[], ElemType in[], 
							int preLeft, int preRight, int inLeft, int inRight)	
// 操作结果：已知二叉树的先序序列pre[preLeft..preRight]和中序序列in[inLeft..inRight]构造以r为根的二叉树
{
	if (inLeft > inRight)	// 二叉树无结点,空二叉树
		r = NULL;			// 空二叉树根为空
	else	{	// 二叉树有结点,非空二叉树
		r = new BinTreeNode<ElemType>(pre[preLeft]);// 生成根结点
		int mid = inLeft;
		while (in[mid] != pre[preLeft]) 	// 查找pre[preLeft]在in[]中的位置,也就是中序序列中根的位置
			mid++;
		CreateBinaryTree(r->leftChild, pre, in, preLeft+1, preLeft + mid - inLeft, inLeft, mid - 1);
			// 生成左子树
		CreateBinaryTree(r->rightChild, pre, in, preLeft + mid - inLeft + 1, preRight, mid + 1, 
			inRight);								// 生成右子树
	}
} 

template <class ElemType>
BinaryTree<ElemType> &CreateBinaryTree(ElemType pre[], ElemType in[], int n)
// 操作结果：已知先序和中序序列构造二叉树
{
	BinTreeNode<ElemType> *r;						// 二叉树的根
	CreateBinaryTree<ElemType>(r, pre, in, 0, n - 1, 0, n - 1);
		// 由先序和中序序列构造以r为根的二叉树 
	BinaryTree<ElemType> *bt = new BinaryTree<ElemType>(r);	// 生成二叉树
	return *bt;
}

#endif // !__BINARY_TREE_H__