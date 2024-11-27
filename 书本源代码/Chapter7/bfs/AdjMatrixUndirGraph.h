#ifndef __ADJ_MATRIX_UNDIR_GRAPH_H__
#define __ADJ_MATRIX_UNDIR_GRAPH_H__

// ����ͼ���ڽӾ�����
template <class ElemType>
class AdjMatrixUndirGraph 
{
protected:
// �ڽӾ�������ݳ�Ա:
	int vexNum, vexMaxNum, arcNum;	// ������Ŀ������Ķ��������Ŀ�ͱ���
	int **Arcs;							        // ��ű���Ϣ�ڽӾ���
	ElemType *Vertexes;						  // ��Ŷ�����Ϣ������ 
	mutable Status *tag;					  // ��־����

public:
// �ڽӾ������͵ķ�������:
	AdjMatrixUndirGraph(ElemType es[], int vertexNum, int vertexMaxNum = DEFAULT_SIZE);	
		// ������es[]Ϊ����,�������ΪvertexNum,����Ķ��������ĿΪvertexMaxNum,����Ϊ0������ͼ
	AdjMatrixUndirGraph(int vertexMaxNum = DEFAULT_SIZE);	
		// ��������Ķ��������ĿΪvertexMaxNum,����Ϊ0������ͼ
	~AdjMatrixUndirGraph();					// ��������
	void Clear();			              // ���ͼ			 
	bool IsEmpty();                 // �ж�����ͼ�Ƿ�Ϊ�� 
	int GetOrder(ElemType &e) const;// �󶥵�����	
	Status GetElem(int v, ElemType &e) const;// �󶥵��Ԫ��ֵ	
	Status SetElem(int v, const ElemType &e);// ���ö����Ԫ��ֵ
	int GetVexNum() const;					// ���ض������			 
	int GetArcNum() const;					// ���ر���			 
	int FirstAdjVex(int v) const;		// ���ض���v�ĵ�һ���ڽӵ�			 
	int NextAdjVex(int v1, int v2) const;		 // ���ض���v1�������v2����һ���ڽӵ�			 
	void InsertVex(const ElemType &e);			 // ����Ԫ��ֵΪe�Ķ���		 
	void InsertArc(int v1, int v2);			     // ���붥��Ϊv1��v2�ı�			 
	void DeleteVex(const ElemType &e);			 // ɾ��Ԫ��ֵΪe�Ķ���			 
	void DeleteArc(int v1, int v2);			     // ɾ������Ϊv1��v2�ı�			 
	Status GetTag(int v) const;			         // ���ض���v�ı�־		 
	void SetTag(int v, Status val) const;	   // ���ö���v�ı�־Ϊval		 
	AdjMatrixUndirGraph(const AdjMatrixUndirGraph<ElemType> &g);	// ���ƹ��캯��
	AdjMatrixUndirGraph<ElemType> &operator =(const AdjMatrixUndirGraph<ElemType> &g); 
		// ��ֵ�������
  void Display();	                         // ��ʾ�ڽӾ�������ͼ
};

// ����ͼ���ڽӾ������ʵ�ֲ���
template <class ElemType>
AdjMatrixUndirGraph<ElemType>::AdjMatrixUndirGraph(ElemType es[], int vertexNum, int vertexMaxNum)
// �����������������Ԫ��Ϊes[],�������ΪvertexNum,����Ķ��������ĿΪvertexMaxNum,����Ϊ0������ͼ

{
	if (vertexMaxNum < 0)
    	throw Error("����Ķ��������Ŀ����Ϊ��!");        // �׳��쳣

	if (vertexMaxNum < vertexNum)
    	throw Error("������Ŀ���ܴ�������Ķ��������Ŀ!");// �׳��쳣

	vexNum = vertexNum;			
	vexMaxNum = vertexMaxNum; 
	arcNum = 0;	

	Vertexes = new ElemType[vexMaxNum];      // �������ɶ�����Ϣ����
	tag = new Status[vexMaxNum];			       // ���ɱ�־����
	Arcs = (int **)new int *[vexMaxNum];     // �����ڽӾ���
	for (int v = 0; v < vexMaxNum; v++) 
		Arcs[v] = new int[vexMaxNum];	

	for (int v = 0; v < vexNum; v++) {
		Vertexes[v] = es[v];
		tag[v] = UNVISITED;
		for (int u = 0; u < vexNum; u++)
			Arcs[v][u] = 0;
	}
}

template <class ElemType>
AdjMatrixUndirGraph<ElemType>::AdjMatrixUndirGraph(int vertexMaxNum)
// �������������������������ĿΪvertexMaxNum�Ŀ�����ͼ
{
	if (vertexMaxNum < 0)
    	throw Error("����Ķ��������Ŀ����Ϊ��!");// �׳��쳣

	vexNum = 0;			
	vexMaxNum = vertexMaxNum;
	arcNum = 0;	

	Vertexes = new ElemType[vexMaxNum];     // �������ɶ�����Ϣ����
	tag = new Status[vexMaxNum];			      // ���ɱ�־����
	Arcs = (int **)new int *[vexMaxNum];    // �����ڽӾ���
	for (int v = 0; v < vexMaxNum; v++) 
		Arcs[v] = new int[vexMaxNum];	
 }

template <class ElemType>
void AdjMatrixUndirGraph<ElemType>::Clear()
// ���������������ͼ�Ķ������ͱ�������Ϊ0.			 
{
    vexNum = 0;
	arcNum = 0;	
}

template <class ElemType>
bool AdjMatrixUndirGraph<ElemType>::IsEmpty()
// ����������������ͼΪ�շ���true,���򷵻�false.
{
	return vexNum == 0;
}

template <class ElemType>
AdjMatrixUndirGraph<ElemType>::~AdjMatrixUndirGraph()
// ����������ͷŶ�����ռ�õĿռ�
{
	delete []Vertexes;					// �ͷŶ�������
	delete []tag;						    // �ͷű�־

	for (int v = 0; v < vexMaxNum; v++)	// �ͷ��ڽӾ������
		delete []Arcs[v];
	delete []Arcs;					    // �ͷ��ڽӾ���
}

template <class ElemType>
int AdjMatrixUndirGraph<ElemType>::GetOrder(ElemType &e) const
// ����������󶥵�e�����.�������Ŵ�0��ʼ��ͼ�в����ڶ���eʱ������-1. 
{
    for (int v = 0; v < vexNum; v++)
        if (Vertexes[v] == e)
		   return v;	    // ����e����,����������� 
	return -1;	        // ����e������,����-1
}	

template <class ElemType>
Status AdjMatrixUndirGraph<ElemType>::GetElem(int v, ElemType &e) const
// ��������������Ϊv�Ķ���ֵ, v��ȡֵ��ΧΪ0 �� v �� vexNum, v�Ϸ�ʱ����
// ͨ��eȡ�ö���ֵ��������ENTRY_FOUND������������NOT_PRESENT
{
	if (v < 0 || v >= vexNum)
		return NOT_PRESENT;	// v��Χ��,����Ԫ�ز�����
	else	{
		e = Vertexes[v];	  // ������v��Ԫ��ֵ����e
		return ENTRY_FOUND;	// ����Ԫ�ش���
	}
}	

template <class ElemType>
Status AdjMatrixUndirGraph<ElemType>::SetElem(int v, const ElemType &e)
// ������������ö����Ԫ��ֵv��ȡֵ��ΧΪ0 �� v �� vexNum, v�Ϸ�ʱ��������
//	SUCCESS, ����������RANGE_ERROR
{
	if (v < 0 || v >= vexNum)
		return RANGE_ERROR;	// v��Χ��,����λ�ô�
	else	{
		Vertexes[v] = e;		// ������Ԫ�ص�ֵ��Ϊe 
		return SUCCESS;		  // �����޸ĳɹ�
	}
}

template <class ElemType>
int AdjMatrixUndirGraph<ElemType>::GetVexNum() const
// ������������ض������			 
{
	return vexNum;
}

template <class ElemType>
int AdjMatrixUndirGraph<ElemType>::GetArcNum() const
// ������������ر���
{
	return arcNum;
}		 

template <class ElemType>
int AdjMatrixUndirGraph<ElemType>::FirstAdjVex(int v) const
// ������������ض���v�ĵ�1���ڽӵ�����		 
{
	if (v < 0 || v >= vexNum)
       throw Error("v���Ϸ�!");// �׳��쳣

	for (int u = 0; u < vexNum; u++)
		if (Arcs[v][u] != 0)
       return u;

	return -1;					// ����-1��ʾ���ڽӵ�
}

template <class ElemType>
int AdjMatrixUndirGraph<ElemType>::NextAdjVex(int v1, int v2) const
// ������������ض���v1�������v2����һ���ڽӵ�			 
{
	if (v1 < 0 || v1 >= vexNum)
       throw Error("v1���Ϸ�!");	// �׳��쳣
	if (v2 < 0 || v2 >= vexNum)
       throw Error("v2���Ϸ�!");	// �׳��쳣
	if (v1 == v2) throw
       Error("v1���ܵ���v2!");		// �׳��쳣

	for (int u = v2 + 1; u < vexNum; u++)
		if (Arcs[v1][u] != 0)
       return u;

	return -1;						// ����-1��ʾ����һ���ڽӵ�
}

template <class ElemType>
void AdjMatrixUndirGraph<ElemType>::InsertVex(const ElemType &e)
// ������������붥��e			 
{
	if (vexNum == vexMaxNum)
    throw Error("ͼ�Ķ��������ܳ�������������!");	// �׳��쳣

	Vertexes[vexNum] = e;
	tag[vexNum] = UNVISITED;
	for (int v = 0; v <= vexNum; v++) {
		Arcs[vexNum][v] = 0;
		Arcs[v][vexNum] = 0;
  }
  vexNum++;
}

template <class ElemType>
void AdjMatrixUndirGraph<ElemType>::InsertArc(int v1, int v2)
// ���������������������v1��v2�ı�			 
{
	if (v1 < 0 || v1 >= vexNum)
    throw Error("v1���Ϸ�!");	// �׳��쳣
	if (v2 < 0 || v2 >= vexNum)
    throw Error("v2���Ϸ�!");	// �׳��쳣
	if (v1 == v2)
    throw Error("v1���ܵ���v2!");// �׳��쳣

	if (Arcs[v1][v2] == 0)	{	  // ԭ����ͼ��û�б�(v1, v2) 
	   arcNum++;
	   Arcs[v1][v2] = 1;	
       Arcs[v2][v1] = 1;
    }
}

template <class ElemType>
void AdjMatrixUndirGraph<ElemType>::DeleteVex(const ElemType &e)
// ���������ɾ��Ԫ��Ϊe�Ķ���			 
{
   int v;
   for (v = 0; v < vexNum; v++)
     if	(Vertexes[v] == e)
        break;
   if (v == vexNum)
      throw Error("ͼ�в�����Ҫɾ���Ķ���!");	// �׳��쳣

   for (int u = 0; u < vexNum; u++) 
	  if (Arcs[v][u] == 1)
	     arcNum--;
	      
   vexNum--; 
   if (v < vexNum) {
      Vertexes[v] = Vertexes[vexNum];
	  tag[v] = tag[vexNum];
	  for (int u = 0; u <= vexNum; u++) 
		 Arcs[v][u] = Arcs[vexNum][u];
	  for (int u = 0; u <= vexNum; u++) 
         Arcs[u][v] = Arcs[u][vexNum];
   } 
}

template <class ElemType>
void AdjMatrixUndirGraph<ElemType>::DeleteArc(int v1, int v2)
// ���������ɾ����������v1��v2�ı�			 
{
	if (v1 < 0 || v1 >= vexNum)
    throw Error("v1���Ϸ�!");	// �׳��쳣
	if (v2 < 0 || v2 >= vexNum)
    throw Error("v2���Ϸ�!");	// �׳��쳣
	if (v1 == v2)
    throw Error("v1���ܵ���v2!");// �׳��쳣

	if (Arcs[v1][v2] != 0)	{	// ԭ����ͼ���ڱ�(v1, v2)
		arcNum--;
	  Arcs[v1][v2] = 0;	
    Arcs[v2][v1] = 0;	
  } 
}

template <class ElemType>
Status AdjMatrixUndirGraph<ElemType>::GetTag(int v) const
// ������������ض���v�ı�־		 
{
	if (v < 0 || v >= vexNum)
    throw Error("v���Ϸ�!");	// �׳��쳣

	return tag[v];
}

template <class ElemType>
void AdjMatrixUndirGraph<ElemType>::SetTag(int v, Status val) const 
// ������������ö���v�ı�־Ϊval		 
{
	if (v < 0 || v >= vexNum)
    throw Error("v���Ϸ�!");	// �׳��쳣

	tag[v] = val;
}

template <class ElemType>
AdjMatrixUndirGraph<ElemType>::AdjMatrixUndirGraph(const AdjMatrixUndirGraph<ElemType> &g)
// ���������������ͼ���ڽӾ���g����������ͼ���ڽӾ���g�������ƹ��캯��
{
	vexNum = g.vexNum;	
	vexMaxNum = g.vexMaxNum;
	arcNum = g.arcNum;	
	
	Vertexes = new ElemType[vexMaxNum];		// ���ɶ�����������
	tag = new Status[vexMaxNum];			// ���ɱ�־����
	Arcs = (int **)new int *[vexMaxNum];	// �����ڽӾ���
	for (int v = 0; v < vexMaxNum; v++) 
		Arcs[v] = new int[vexMaxNum];	

	for (int v = 0; v < vexNum; v++)	{	// ���ƶ�����������
		Vertexes[v] = g.Vertexes[v];
		tag[v] = g.tag[v];
		for (int u = 0; u < vexNum; u++)
			Arcs[v][u] = g.Arcs[v][u];
	}
}

template <class ElemType>
AdjMatrixUndirGraph<ElemType> &AdjMatrixUndirGraph<ElemType>::operator =(const AdjMatrixUndirGraph<ElemType> &g)
// ���������������ͼ���ڽӾ���g��ֵ����ǰ����ͼ���ڽӾ��󡪡���ֵ�������
{
	if (&g != this)	{
	  delete []Vertexes;				// �ͷŶ�������
	  delete []tag;						  // �ͷű�־

	  for (int v = 0; v < vexMaxNum; v++)	// �ͷ��ڽӾ������
       delete []Arcs[v];
    delete []Arcs;					  // �ͷ��ڽӾ���
	  vexNum = g.vexNum;	
    vexMaxNum = g.vexMaxNum;
	  arcNum = g.arcNum;	
	
	  Vertexes = new ElemType[vexMaxNum];	 // ���ɶ�����������
	  tag = new Status[vexMaxNum];			   // ���ɱ�־����
	  Arcs = (int **)new int *[vexMaxNum]; // �����ڽӾ���
	  for (int v = 0; v < vexMaxNum; v++) 
		  Arcs[v] = new int[vexMaxNum];	

	  for (int v = 0; v < vexNum; v++)	{	 // ���ƶ�����������
		  Vertexes[v] = g.Vertexes[v];
		  tag[v] = g.tag[v];
		  for (int u = 0; u < vexNum; u++)
		    Arcs[v][u] = g.Arcs[v][u];
	  }
	}
	return *this;
}

template <class ElemType>
void AdjMatrixUndirGraph<ElemType>::Display()
// �������: ��ʾ�ڽӾ�������ͼ
{
              
	for (int v = 0; v < vexNum; v++)
 		cout << "\t" << Vertexes[v];
	cout << endl;

	for (int v = 0; v < vexNum; v++)	{
		cout << Vertexes[v];
		for (int u = 0; u < vexNum; u++)
 			cout << "\t" << Arcs[v][u];
		cout << endl;
	}
}

#endif
