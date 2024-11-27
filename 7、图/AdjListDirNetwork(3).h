#ifndef __ADJ_LIST_GRAPH_H__
#define __ADJ_LIST_GRAPH_H__

#include "AdjListDirNetworkArc.h"			// 网络邻接表的边结点类
#include "AdjListDirNetworkVex.h"			// 网络邻接表的顶点结点类
#include<vector>
#include <numeric>
// 无向网的邻接表类

template <class ElemType, class WeightType>
class AdjListDirNetwork
{
protected:
// 邻接表的数据成员:
	int vexNum, vexMaxNum, arcNum;					// 顶点数目、允许的顶点最大数目和边数
	AdjListNetWorkVex<ElemType, WeightType> *vexTable;	// 顶点表
	mutable Status *tag;					        // 标志数组				
	WeightType infinity;							// 无穷大的值 

public:
// 抽象数据类型方法声明及重载编译系统默认方法声明:
	AdjListDirNetwork(ElemType es[], int vertexNum, int vertexMaxNum = DEFAULT_SIZE, 
		WeightType infinit = (WeightType)DEFAULT_INFINITY);
		// 以数组es[]为顶点数据,顶点个数为vertexNum,允许的顶点最大数目为vertexMaxNum,
        // infinit表示无穷大,边数为0构造无向网
	AdjListDirNetwork(int vertexMaxNum = DEFAULT_SIZE, 
		WeightType infinit = (WeightType)DEFAULT_INFINITY);
		// 构造允许的顶点最大数目为vertexMaxNum,infinit表示无穷大,边数为0的无向网
	~AdjListDirNetwork();						 // 析构函数
	void Clear();			                     // 清空无向网			 
	bool IsEmpty();                              // 判断无向网是否为空 
	int GetOrder(ElemType &d) const;             // 求顶点的序号	
	Status GetElem(int v, ElemType &d) const;    // 求顶点的元素值	
	Status SetElem(int v, const ElemType &d);    // 设置顶点的元素值
	WeightType GetInfinity() const;				 // 取无穷大的值			 
	int GetVexNum() const;						 // 求无向网的顶点个数			 
	int GetArcNum() const;						 // 求无向网的边数个数			 
	int FirstAdjVex(int v) const;				 // 求无向网中顶点v的第一个邻接点			 
	int NextAdjVex(int v1, int v2) const;		 // 求无向网中顶点v1的相对于v2的下一个邻接点			 
	void InsertVex(const ElemType &d);			 // 插入元素值为d的顶点		 
	void InsertArc(int v1, int v2, WeightType w);// 插入从顶点为v1和v2、权为w的边			 
	void DeleteVex(const ElemType &d);			 // 删除元素值为d的顶点			 
	void DeleteArc(int v1, int v2);			     // 删除从顶点为v1和v2的边			 
	WeightType GetWeight(int v1, int v2) const;	 // 求从顶点为v1和v2的边的权值
	void SetWeight(int v1, int v2, WeightType w);// 设置从顶点为v1和v2的边的权值
	Status GetTag(int v) const;				     // 求顶点v的标志		 
	void SetTag(int v, Status tag) const;	     // 设置顶点v的标志为tag	 
	AdjListDirNetwork(const AdjListDirNetwork<ElemType, WeightType> &copy);	// 复制构造函数
	AdjListDirNetwork<ElemType, WeightType> &operator =
		(const AdjListDirNetwork<ElemType, WeightType> &copy); // 重载赋值运算符 
    void Display();	// 显示无向网邻接表 
	void SollinAlgorithm(vector<Edge<WeightType>>& mstEdges);
	bool IsUniqueMST();
};
//Solin算法求最小生成树
template <class ElemType, class WeightType>
void AdjListDirNetwork<ElemType, WeightType>::SollinAlgorithm(vector<Edge<WeightType>>& mstEdges) {
	// 初始化组件（每个顶点是一个组件）
	vector<int> parent(vexNum);
	iota(parent.begin(), parent.end(), 0); // 用0至vexNum-1的连续整数填充parent

	auto findParent = [&parent](int v) {
		while (parent[v] != v) {
			v = parent[v];
		}
		return v;
		};
	int numComponents = vexNum;
	while (numComponents > 1) {
		// 每个组件选择连接到其他组件的最小边
		vector<Edge<WeightType>> cheapest(vexNum, Edge<WeightType>(-1, -1, (WeightType)DEFAULT_INFINITY));
		for (int v = 0; v < vexNum; ++v) {
			for (int w = FirstAdjVex(v); w >= 0; w = NextAdjVex(v, w)) {
				int rootV = findParent(v);
				int rootW = findParent(w);
				if (rootV != rootW) {
					WeightType weight = GetWeight(v, w);
					if (weight < cheapest[rootV].weight) {
						cheapest[rootV] = Edge<WeightType>(v, w, weight);
					}
				}
			}
		}
		// 合并组件并添加边到MST
		for (int i = 0; i < vexNum; ++i) {
			if (cheapest[i].v1 != -1) {
				int rootV1 = findParent(cheapest[i].v1);
				int rootV2 = findParent(cheapest[i].v2);
				if (rootV1 != rootV2) {
					mstEdges.push_back(cheapest[i]);
					parent[rootV1] = rootV2;
					--numComponents;
				}
			}
		}
	}
}
template <class ElemType, class WeightType>
bool AdjListDirNetwork<ElemType, WeightType>::IsUniqueMST() {
	// Step 1: 标记具有相同权值的边
	vector<bool> markedArcs(arcNum, false); // 用于标记是否已经扫描过的边
	for (int i = 0; i < vexNum; ++i) {
		for (int j = FirstAdjVex(i); j >= 0; j = NextAdjVex(i, j)) {
			WeightType weight = GetWeight(i, j);
			for (int k = 0; k < vexNum; ++k) {
				if (k != i) {
					for (int l = FirstAdjVex(k); l >= 0; l = NextAdjVex(k, l)) {
						if (GetWeight(k, l) == weight) {
							markedArcs[j] = true;
							break;
						}
					}
				}
			}
		}
	}
	// Step 2: 使用 Sollin 算法求出最小生成树
	vector<Edge<WeightType>> mstEdges;
	SollinAlgorithm(mstEdges);
	// Step 3: 检查是否包含了被标记的边
	for (const auto& edge : mstEdges) {
		if (markedArcs[edge.from]) {
			// 如果包含了被标记的边，则依次去掉这些边，再求最小生成树
			vector<Edge<WeightType>> mstEdgesWithoutMarked;
			for (const auto& e : mstEdges) {
				if (e.from != edge.from || e.to != edge.to || e.weight != edge.weight) {
					mstEdgesWithoutMarked.push_back(e);
				}
			}
			// 再次求最小生成树
			vector<Edge<WeightType>> newMSTEdges;
			SollinAlgorithm(newMSTEdges);
			// 检查新的最小生成树的权值是否和原来的最小生成树的权值相同
			WeightType totalWeight1 = 0, totalWeight2 = 0;
			for (const auto& e : mstEdgesWithoutMarked) {
				totalWeight1 += e.weight;
			}
			for (const auto& e : newMSTEdges) {
				totalWeight2 += e.weight;
			}
			if (totalWeight1 == totalWeight2) {
				return false; // 最小生成树不唯一
			}
		}
	}
	return true; // 最小生成树唯一
}
// 无向网的邻接表类的实现部分
template <class ElemType, class WeightType>
AdjListDirNetwork<ElemType, WeightType>::AdjListDirNetwork(ElemType es[],
       int vertexNum, int vertexMaxNum, WeightType infinit)
// 操作结果：构造顶点数据为es[],顶点数为numVex,顶点个数为vertexNum,infinit表示无穷大,边数为0的无向网
{
	if (vertexMaxNum < 0)
    	throw Error("允许的顶点最大数目不能为负!");        // 抛出异常

	if (vertexMaxNum < vertexNum)
    	throw Error("顶点数目不能大于允许的顶点最大数目!");// 抛出异常

	vexNum = vertexNum;			
	vexMaxNum = vertexMaxNum; 
	arcNum = 0;
	infinity = infinit;
	
	tag = new Status[vexMaxNum];
	vexTable = new AdjListNetWorkVex<ElemType, WeightType>[vexMaxNum];
 
	for (int v = 0; v < vexNum; v++)  {
		tag[v] = UNVISITED;
		vexTable[v].data = es[v];
		vexTable[v].firstarc = NULL;
	}
}

template <class ElemType, class WeightType>
AdjListDirNetwork<ElemType, WeightType>::AdjListDirNetwork(int vertexMaxNum, WeightType infinit)
// 操作结果：构造顶点最大数目为vertexMaxNum,infinit表示无穷大的空无向网
{
	if (vertexMaxNum < 0)
    	throw Error("允许的顶点最大数目不能为负!");// 抛出异常

	vexNum = 0;			
	vexMaxNum = vertexMaxNum;
	arcNum = 0;
	infinity = infinit;

	tag = new Status[vexMaxNum];
	vexTable = new AdjListNetWorkVex<ElemType, WeightType>[vexMaxNum];
}

template <class ElemType, class WeightType>
AdjListDirNetwork<ElemType, WeightType>::~AdjListDirNetwork()
// 操作结果：释放邻接表无向网所占用空间
{
    Clear();                                // 释放边结点
	delete []tag;							// 释放标志
	delete []vexTable;						// 释放邻接表
}

template <class ElemType, class WeightType>
void AdjListDirNetwork<ElemType, WeightType>::Clear()
// 操作结果：释放所有的边结点，并把无向网的顶点数和边数设置为0.			 
{
	AdjListNetworkArc<WeightType> *p;
	for (int v = 0; v < vexNum; v++)	{	// 释放边结点
	    p = vexTable[v].firstarc;
	    while (p != NULL) {
			vexTable[v].firstarc = p->nextarc;
			delete p;
			p = vexTable[v].firstarc;
        }	
	}
    vexNum = 0;
	arcNum = 0;	
}

template <class ElemType, class WeightType>
bool AdjListDirNetwork<ElemType, WeightType>::IsEmpty()
// 操作结果：如果无向网为空返回true,否则返回false.
{
	return vexNum == 0;
}

template <class ElemType, class WeightType>
int AdjListDirNetwork<ElemType, WeightType>::GetOrder(ElemType &d) const
// 操作结果：求顶点d的序号.顶点的序号从0开始，图中不存在顶点d时返回-1. 
{
    int v;
    for (v = 0; v < vexNum; v++)
        if (d == vexTable[v].data)
           break;
           
	if (v < 0 || v >= vexNum)
		return -1;	// 顶点d不存在,返回-1
	else
		return v;	// 顶点d不存在,返回它的序号 
}	

template <class ElemType, class WeightType>
Status AdjListDirNetwork<ElemType, WeightType>::GetElem(int v, ElemType &d) const
// 操作结果：求序号为v的顶点值, v的取值范围为0 ≤ v ＜ vexNum, v合法时函数
//	通过d取得顶点值，并返回ENTRY_FOUND；否则函数返回NOT_PRESENT
{
	if (v < 0 || v >= vexNum)
		return NOT_PRESENT;			// 元素不存在
	else	{
		d = vexTable[v].data;		// 将顶点v的元素值赋给d
		return ENTRY_FOUND;			// 元素存在
	}
}	

template <class ElemType, class WeightType>
Status AdjListDirNetwork<ElemType, WeightType>::SetElem(int v, const ElemType &d)
// 操作结果：设置顶点的元素值v的取值范围为0 ≤ v ＜ vexNum, v合法时函数返回
//	SUCCESS, 否则函数返回RANGE_ERROR
{
	if (v < 0 || v >= vexNum)
		return RANGE_ERROR;			// 位置错
	else	{
		vexTable[v].data = d;		// 顶点元素
		return SUCCESS;				// 成功
	}
}

template <class ElemType, class WeightType>
WeightType AdjListDirNetwork<ElemType, WeightType>::GetInfinity() const
// 操作结果：返回无穷大的值 
{
	return infinity;
}

template <class ElemType, class WeightType>
int AdjListDirNetwork<ElemType, WeightType>::GetVexNum() const
// 操作结果：返回顶点个数			 
{
	return vexNum;
}

template <class ElemType, class WeightType>
int AdjListDirNetwork<ElemType, WeightType>::GetArcNum() const
// 操作结果：返回边数个数
{
	return arcNum;
}		 

template <class ElemType, class WeightType>
int AdjListDirNetwork<ElemType, WeightType>::FirstAdjVex(int v) const
// 操作结果：返回顶点v的第一个邻接点			 
{
	if (v < 0 || v >= vexNum)
       throw Error("v不合法!");// 抛出异常

	if (vexTable[v].firstarc == NULL)
	   return -1;              // 不存在邻接点
	else
	   return vexTable[v].firstarc->adjVex;
}

template <class ElemType, class WeightType>
int AdjListDirNetwork<ElemType, WeightType>::NextAdjVex(int v1, int v2) const
// 操作结果：返回顶点v1的相对于v2的下一个邻接点			 
{
	AdjListNetworkArc<WeightType> *p;
	if (v1 < 0 || v1 >= vexNum)
       throw Error("v1不合法!");	// 抛出异常
	if (v2 < 0 || v2 >= vexNum)
       throw Error("v2不合法!");	// 抛出异常
	if (v1 == v2)
       throw Error("v1不能等于v2!");// 抛出异常
	
	p = vexTable[v1].firstarc;
	while (p != NULL && p->adjVex != v2)
	    p = p->nextarc;

	if (p == NULL || p->nextarc == NULL)
		return -1;                   // 不存在下一个邻接点
	else
		return p->nextarc->adjVex;
}

template <class ElemType, class WeightType>
void AdjListDirNetwork<ElemType, WeightType>::InsertVex(const ElemType &d)
// 操作结果：在顶点表的表尾插入元素值为d的顶点。			 
{
	if (vexNum == vexMaxNum)
       throw Error("图的顶点数不能超过允许的最大数!");	// 抛出异常

	vexTable[vexNum].data = d;
	vexTable[vexNum].firstarc = NULL;
	tag[vexNum] = UNVISITED;
    vexNum++;
}

template <class ElemType, class WeightType>
void AdjListDirNetwork<ElemType, WeightType>::InsertArc(int v1, int v2, WeightType w)
// 操作结果：插入顶点为v1和v2,权为w的边			 
{
	if (v1 < 0 || v1 >= vexNum)
       throw Error("v1不合法!");	// 抛出异常
	if (v2 < 0 || v2 >= vexNum)
       throw Error("v2不合法!");	// 抛出异常
	if (v1 == v2)
       throw Error("v1不能等于v2!");// 抛出异常
	if (w == infinity)
       throw Error("w不能为无空大!");// 抛出异常

	AdjListNetworkArc<WeightType> *p, *q;
	p = vexTable[v1].firstarc;
    vexTable[v1].firstarc = new AdjListNetworkArc<WeightType>(v2, w, p);
	//这里从v1，v2链表各自添加对应边
	q = vexTable[v2].firstarc;
	vexTable[v2].firstarc = new AdjListNetworkArc<WeightType>(v1,w,q);
	arcNum+=2;
}

template <class ElemType, class WeightType>
void AdjListDirNetwork<ElemType, WeightType>::DeleteVex(const ElemType &d)
// 操作结果：删除元素值为d的顶点			 
{
    int v;
    AdjListNetworkArc<WeightType> *p, *q;
    for (v = 0; v < vexNum; v++)
       if	(vexTable[v].data == d)
           break;
	if (v == vexNum)
       throw Error("图中不存在要删除的顶点!");	// 抛出异常

    for (int u = 0; u < vexNum; u++)           // 删除与d有关的弧 
       if (u != v) 
          DeleteArc(u, v); 

          
	p = vexTable[v].firstarc;                  // 删除从d出发的弧 
	while (p != NULL) {
        vexTable[v].firstarc = p->nextarc;
        delete p;    
	    p = vexTable[v].firstarc;
		arcNum--;
	}

    vexNum--;
    vexTable[v].data = vexTable[vexNum].data;
    vexTable[v].firstarc = vexTable[vexNum].firstarc;
    vexTable[vexNum].firstarc = NULL;
    tag[v] = tag[vexNum];

    for (int u = 0; u < vexNum; u++)         
       if (u != v) {
	      p = vexTable[u].firstarc;
	      while (p != NULL) {
             if (p->adjVex == vexNum)
                p->adjVex = v;
             p = p->nextarc;
          }
       }   
}

template <class ElemType, class WeightType>
void AdjListDirNetwork<ElemType, WeightType>::DeleteArc(int v1, int v2)
// 操作结果：删除顶点为v1和v2的边			 
{
	if (v1 < 0 || v1 >= vexNum)
       throw Error("v1不合法!");	// 抛出异常
	if (v2 < 0 || v2 >= vexNum)
       throw Error("v2不合法!");	// 抛出异常
	if (v1 == v2) throw
       Error("v1不能等于v2!");		// 抛出异常

	AdjListNetworkArc<WeightType> *p, *q=NULL;
	p = vexTable[v1].firstarc;
	while (p != NULL && p->adjVex != v2) {
        q = p;
        p = p->nextarc;
    }
    if (p != NULL) {
	    if (vexTable[v1].firstarc == p)
            vexTable[v1].firstarc = p->nextarc;
        else
            q->nextarc = p->nextarc;
        delete p;    
		arcNum--;
	}
	//对称删除边
	p = vexTable[v2].firstarc;
	while (p != NULL && p->adjVex != v1) {
        q = p;
        p = p->nextarc;
    }
    if (p != NULL) {
	    if (vexTable[v2].firstarc == p)
            vexTable[v2].firstarc = p->nextarc;
        else
            q->nextarc = p->nextarc;
        delete p;    
		arcNum--;
	}
}

template <class ElemType, class WeightType>
WeightType AdjListDirNetwork<ElemType, WeightType>::GetWeight(int v1, int v2) const
// 操作结果：返回顶点为v1和v2的边的权值
{
	if (v1 < 0 || v1 >= vexNum)
       throw Error("v1不合法!");	// 抛出异常
	if (v2 < 0 || v2 >= vexNum)
       throw Error("v2不合法!");	// 抛出异常

	AdjListNetworkArc<WeightType> *p;
	p = vexTable[v1].firstarc;
	while (p != NULL && p->adjVex != v2) 
       p = p->nextarc;
    if (p != NULL)
	   return p->weight;			// 返回权值
	else
	   return infinity;				// 返回权值为infinity，表示边不存在
}

template <class ElemType, class WeightType>
void AdjListDirNetwork<ElemType, WeightType>::SetWeight(int v1, int v2, WeightType w)
// 操作结果：设置顶点为v1和v2的边的权值
{
	if (v1 < 0 || v1 >= vexNum)
       throw Error("v1不合法!");        // 抛出异常
	if (v2 < 0 || v2 >= vexNum)
       throw Error("v2不合法!");	    // 抛出异常
	if (v1 == v2)
       throw Error("v1不能等于v2!");    // 抛出异常
	if (w == infinity)
       throw Error("w不能为无空大!");   // 抛出异常

	AdjListNetworkArc<WeightType> *p;
	p = vexTable[v1].firstarc;
	while (p != NULL && p->adjVex != v2)
       p = p->nextarc;
    if (p != NULL)
	   p->weight = w;		            // 修改权值
	p = vexTable[v2].firstarc;
	while (p != NULL && p->adjVex != v1)
       p = p->nextarc;
    if (p != NULL)
	   p->weight = w;		            // 对称修改权值
}

template <class ElemType, class WeightType>
Status AdjListDirNetwork<ElemType, WeightType>::GetTag(int v) const
// 操作结果：返回顶点v的标志		 
{
	if (v < 0 || v >= vexNum)
       throw Error("v不合法!");		// 抛出异常

	return tag[v];
}

template <class ElemType, class WeightType>
void AdjListDirNetwork<ElemType, WeightType>::SetTag(int v, Status val) const
// 操作结果：设置顶点v的标志为val		 
{
	if (v < 0 || v >= vexNum)
       throw Error("v不合法!");		// 抛出异常

	tag[v] = val;
}

template <class ElemType, class WeightType>
AdjListDirNetwork<ElemType, WeightType>::AdjListDirNetwork(const AdjListDirNetwork<ElemType, WeightType> &copy)
// 操作结果：由无向网的邻接矩阵copy构造新无向网的邻接矩阵copy——复制构造函数
{
	AdjListNetworkArc<WeightType> *p, *q;
	infinity =copy.infinity;
	vexNum = copy.vexNum;
	vexMaxNum = copy.vexMaxNum;	
	arcNum = copy.arcNum;

	tag = new Status[vexMaxNum];
	vexTable = new AdjListNetWorkVex<ElemType, WeightType>[vexMaxNum];
	for (int v = 0; v < vexNum; v++)	{
		tag[v] = copy.tag[v];
		vexTable[v].data = copy.vexTable[v].data;
		vexTable[v].firstarc = NULL;
		p = copy.vexTable[v].firstarc;
		while (p != NULL) 
           if (vexTable[v].firstarc == NULL) {
              vexTable[v].firstarc = new AdjListNetworkArc<WeightType>(p->adjVex, p->weigth);	
              q = vexTable[v].firstarc;
              p = p->nextarc;
           }
           else {   
              q->nextarc = new AdjListNetworkArc<WeightType>(p->adjVex, p->weigth);	
              q = q->nextarc;
              p = p->nextarc;
           }   
	}
}

template <class ElemType, class WeightType>
AdjListDirNetwork<ElemType, WeightType> &AdjListDirNetwork<ElemType, WeightType>::operator =(const AdjListDirNetwork<ElemType, WeightType> &copy)
// 操作结果：将无向网的邻接矩阵copy赋值给当前无向网的邻接矩阵——赋值语句重载
{
	if (&copy != this)
	{
        Clear();                                    // 释放当前无向网边结点
	    delete []tag;								// 释放当前无向网标志数组 
	    delete []vexTable;							// 释放当前无向网顶点表 

	    AdjListNetworkArc<WeightType> *p, *q;
	    infinity =copy.infinity;
	    vexNum = copy.vexNum;
	    vexMaxNum = copy.vexMaxNum;	
	    arcNum = copy.arcNum;

	    tag = new Status[vexMaxNum];
	    vexTable = new AdjListNetWorkVex<ElemType, WeightType>[vexMaxNum];
	    for (int v = 0; v < vexNum; v++)	{
		   tag[v] = copy.tag[v];
		   vexTable[v].data = copy.vexTable[v].data;
		   vexTable[v].firstarc = NULL;
		   p = copy.vexTable[v].firstarc;
		   while (p != NULL) 
               if (vexTable[v].firstarc == NULL) {
                  vexTable[v].firstarc = new AdjListNetworkArc<WeightType>(p->adjVex, p->weigth);	
                  q = vexTable[v].firstarc;
                  p = p->nextarc;
               }
               else {   
                  q->nextarc = new AdjListNetworkArc<WeightType>(p->adjVex, p->weigth);	
                  q = q->nextarc;
                  p = p->nextarc;
               }   
	   }
    }
	return *this;
}

template <class ElemType, class WeightType>
void AdjListDirNetwork<ElemType, WeightType>::Display()
// 操作结果: 显示邻接矩阵无向网
{
	AdjListNetworkArc<WeightType> *p;
    cout << "无向网共有" << vexNum << "个顶点，" << arcNum << "条边。" << endl; 
	for (int v = 0; v < vexNum; v++)	{	// 显示第v个邻接链表
		cout << v << ":\t" << vexTable[v].data;				// 显示顶点号
	    p = vexTable[v].firstarc;
	    while (p != NULL) {
        	cout << "-->(" << p->adjVex << "," << p->weight << ")";
            p = p->nextarc; 
		}
		cout << endl; 
	}
}

#endif
