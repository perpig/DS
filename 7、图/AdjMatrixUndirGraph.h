#ifndef __ADJ_MAXTRIX_UNDIR_GRAPH_H__
#define __ADJ_MAXTRIX_UNDIR_GRAPH_H__

#include "Assistance.h"

template <class ElemType>
class AdjMatrixUndirGraph
{
protected:
    int vexNum;          // 顶点数目
    int vexMaxNum;       // 允许最大顶点数目
    int arcNum;          // 边数
    int **arcs;          // 存放边的信息
    ElemType *vertexes;  // 存放信息数组
    mutable Status *tag; // 标志数组

public:
    AdjMatrixUndirGraph(ElemType es[], int vertexNum, int vertexMaxNum = DEFAULT_SIZE);
    AdjMatrixUndirGraph(int vertexMaxNum = DEFAULT_SIZE);
    ~AdjMatrixUndirGraph();
    void Clear();
    bool Isempty();
    Status GetElem(int v, ElemType &d) const;
};

template <class ElemType>
AdjMatrixUndirGraph<ElemType>::AdjMatrixUndirGraph(ElemType es[], int vertexNum, int vertexMaxNum)
{
    if (vertexMaxNum < 0)
        throw Error("允许的顶点最大数目不能为负！");
    if (vertexMaxNum < vertexNum)
        throw Error("顶点数目不能大雨允许的顶点最大数目！");

    vexNum = vertexNum;
    vexMaxNum = vertexMaxNum;
    arcNum = 0;

    vertexes = new ElemType[vexMaxNum];
    tag = new Status[vexMaxNum];
    arcs = (int **)new int *[vexMaxNum];
    for (int i = 0; i < vexNum; i++)
        arcs[i] = new int[vexMaxNum];

    for (int i = 0; i < vexNum; i++)
    {
        vertexes[i] = es[i];
        tag[i] = UNVISITED;
        for (int j = 0; j < vexNum; j++)
            arcs[i][j] = 0;
    }
}

template <class ElemType>
AdjMatrixUndirGraph<ElemType>::AdjMatrixUndirGraph(int vertexMaxNum)
{
    if (vertexMaxNum < 0)
        throw Error("允许的顶点最大数目不能为负！");

    vexNum = 0;
    vexMaxNum = vertexMaxNum;
    arcNum = 0;

    vertexes = new ElemType[vexMaxNum];
    tag = new Status[vexMaxNum];
    arcs = (int **)new int *[vexMaxNum];
    for (int i = 0; i < vexNum; i++)
        arcs[i] = new int[vexMaxNum];
}

template <class ElemType>
void AdjMatrixUndirGraph<ElemType>::Clear()
{
    vexNum = 0;
    arcNum = 0;
}

template <class ElemType>
bool AdjMatrixUndirGraph<ElemType>::Isempty()
{
    return vexNum == 0;
}

template <class ElemType>
AdjMatrixUndirGraph<ElemType>::~AdjMatrixUndirGraph()
{
    delete[] vertexes;
    delete[] tag;

    for (int i = 0; i < vexNum; i++)
    {
        delete[] arcs[i];
    }
    delete[] arcs;
}

template <class ElemType>
Status AdjMatrixUndirGraph<ElemType>::GetElem(int v, ElemType &d) const
{
    if (v < 0 || v >= vexNum)
        return NOT_PRESENT;
    else
    {
        d = vertexes[v];
        return ENTRY_FOUND;
    }
}

#endif // !__ADJ_MAXTRIX_UNDIR_GRAPH_H__
