#ifndef __SQ_LIST_H__
#define __SQ_LIST_H__

// 顺序表模板类的申明 
template <class ElemType>
class SeqList 
{
protected:
// 顺序表的数据成员
	int length;					// 顺序表的当前长度 
	int maxLength;				// 顺序表的最大容量
	ElemType *elems;			// 元素存储空间的首地址 

public:
// 顺序表的函数成员
	SeqList(int size = DEFAULT_SIZE);	// 构造一个空表 
	SeqList(ElemType v[], int n, int size = DEFAULT_SIZE);	// 根据数组v的内容构造顺序表 
	virtual ~SeqList();			// 析构函数
	int GetLength() const;		// 取顺序表长度			 
	bool IsEmpty() const;		// 判断顺序表是否为空
	void Clear();				// 将顺序表清空
	void Traverse(void (*Visit)(const ElemType &)) const;	// 遍历顺序表
	int LocateElem(const ElemType &e) const;	// 元素定位，求指定元素在顺序表中的位置
	int RestCapacity() const;  //返回剩余容量
	int RepeatElem() const;  //统计有多少个元素重复，重复元素只算一个
	Status GetElem(int i, ElemType &e) const;	// 取顺序表中第i个元素的值	
	Status SetElem(int i, const ElemType &e);	// 修改顺序表中第i个元素的值
	Status DeleteElem(int i, ElemType &e);      // 删除顺序表中第i个元素		
	Status InsertElem(int i, const ElemType &e); // 在顺序表第i个位置插入元素
 	Status InsertElem(const ElemType &e);        // 在顺序表表尾插入元素
	SeqList(const SeqList<ElemType> &sa);        // 复制构造函数
	SeqList<ElemType> &operator =(const SeqList<ElemType> &sa); // 赋值语句重载
	//1.（3）在一个顺序表中如果一个数据值有重复出现，则留下第一个这样的数据值，
	//并删除其他所有重复的元素，使表中所有元素的值均不相同。
	void DeleteRepeat();
	//3.线性表中的原地逆置
	void reverse() throw(double);
};


// 顺序表函数成员的实现部分

template <class ElemType>
SeqList<ElemType>::SeqList(int size)
// 操作结果：构造一个最大容量为size的空顺序表
{
	elems = new ElemType[size];		    // 申请存储空间
	assert(elems);                      // 申请存储空间失败，程序终止 
	maxLength = size;					// 设置顺序表的最大容量
	length = 0;							// 空线性表的长度为0
}

template <class ElemType>
SeqList<ElemType>::SeqList(ElemType v[], int n, int size)
// 操作结果：根据数组v中的内容构造顺序表
{
	elems = new ElemType[size];		    // 申请存储空间
	assert(elems);                      // 申请存储空间失败，程序终止 
	maxLength = size;					// 设置顺序表的最大容量
	length = n;							// 顺序表的当前长度为n 
	for (int i = 0; i < length; i++)	// 将数组v中的元素依次存放到elems数组中 
		elems[i] = v[i]; 
}
 
template <class ElemType>
SeqList<ElemType>::~SeqList()
// 功能：回收顺序表的存储空间 
{
	delete []elems;						// 释放存储空间
}

template <class ElemType>
int SeqList<ElemType>::GetLength() const
// 功能：返回顺序表中元素个数
{
	return length;
}

template <class ElemType>
bool SeqList<ElemType>::IsEmpty() const
// 功能：如顺序表为空，则返回true，否则返回false
{
	return length == 0;
}

template <class ElemType>
void SeqList<ElemType>::Clear()
// 功能：清空顺序表
{
	length = 0;
}

template <class ElemType>
void SeqList<ElemType>::Traverse(void (*visit)(const ElemType &)) const
// 功能：依次对顺序表的每个元素调用函数(*visit)进行访问 
{
	for (int i = 0; i < length; i++)
		(*visit)(elems[i]);
}

template <class ElemType>
int SeqList<ElemType>::LocateElem(const ElemType &e) const
// 功能：求元素e在顺序表中的序号,如果顺序表中不存在元素e则返回0
{
	int i = 0;
    while (i < length && elems[i] != e)
         i++;	
    return i < length ? i+1 : 0;
}

template <class ElemType>
int SeqList<ElemType>::RestCapacity() const  
//功能：返回剩余容量
{
	return maxLength-length;
}

template <class ElemType>
int SeqList<ElemType>::RepeatElem() const 
//功能：统计有多少个元素重复，重复元素只算一个
{
	int count=0;
	for(int i=0;i<length;i++)
	{
		for(int j=0;j<length;j++)
		{
			if(j<i&&elems[i]==elems[j])
			break;
			else if(i==j)
			continue;
			else if(elems[i]==elems[j])
			{
				count++;
				break;
			}
		}
	}
	return count;
}

template <class ElemType>
Status SeqList<ElemType>::GetElem(int i, ElemType &e) const
// 功能：当顺序表存在第i个元素时，用e返回其值，函数返回ENTRY_FOUND,否则函数返回NOT_PRESENT
{
	if(i < 1 || i > length)
		return NOT_PRESENT;	// 返回元素不存在
	else	{
		e = elems[i - 1];
		return ENTRY_FOUND;	// 元素存在
	}
}

template <class ElemType>
Status SeqList<ElemType>::SetElem(int i, const ElemType &e)
// 功能：将顺序表的第i个位置的元素赋值为e。i的取值范围为1≤i≤length,i合法时函数返回SUCCESS,否则函数返回RANGE_ERROR
{
	if (i < 1 || i > length)
		return RANGE_ERROR;	// 返回位置错
	else	{
		elems[i - 1] = e;
		return SUCCESS;		// 返回修改成功
	}
}

template <class ElemType>
Status SeqList<ElemType>::DeleteElem(int i, ElemType &e)
// 功能：删除顺序表第i个位置的元素, 并前用e返回其值。i的的取值范围为1≤i≤length,i合法时函数返回SUCCESS,否则函数返回RANGE_ERROR
{
	if (i < 1 || i > length)		
		return RANGE_ERROR;      // 返回位置错
	else	{
		e = elems[i - 1];	     // 用e返回被删除元素的值
		for (int j = i; j < length; j++)// 被删除元素之后的元素依次左移一个位置 
			elems[j-1] = elems[j]; 
		length--;				// 删除后顺序表元素个数减1
		return SUCCESS;	        // 返回删除成功
	}
}

template <class ElemType>
Status SeqList<ElemType>::InsertElem(int i, const ElemType &e)
// 功能：在顺序表的第i个位置插入元素e,i的的取值范围为1≤i≤Length()+1。 
//	如顺序表已满,则返回OVER_FLOW,
//	如i合法, 则返回SUCCESS, 否则函数返回RANGE_ERROR
{
	if (length == maxLength)
		return OVER_FLOW;	            	// 顺序表已满,返回OVER_FLOW
	else if (i < 1 || i > length + 1)		// i范围错,返回位置错
		return RANGE_ERROR;
	else	{
		for (int j = length; j >= i; j--)  // 插入位置之后的元素右移
			elems[j] = elems[j - 1]; 
		elems[i - 1] = e;	               // 将e赋值到顺序表i位置	
   		length++;				           // 插入后元素个数加1
     	return SUCCESS;			           // 返回插入成功
	}
}

template <class ElemType>
Status SeqList<ElemType>::InsertElem(const ElemType &e)
// 功能：在顺序表的表尾插入元素e,并则返回SUCCESS，如顺序表已满,则返回OVER_FLOW
{
	if (length==maxLength)		// 顺序表已满返回OVER_FLOW
		return OVER_FLOW;	
	else	{
		elems[length] = e;	    // 将元素e插入到表尾	
   		length++;				// 插入后，顺序表元素个数加1
     	return SUCCESS;			// 返回插入成功
	}
}

template <class ElemType>
SeqList<ElemType>::SeqList(const SeqList<ElemType> &sa)
// 功能：复制构造函数，由顺序表sa构造新顺序表
{
	int saLength = sa.GetLength();	// 取顺序表sa的长度
	ElemType e;

	maxLength = sa.maxLength;		// 取顺序表的最大容量
	elems = new ElemType[maxLength];// 分配存储空间
	assert(elems);                  // 分配存储空间失败 
	length = 0;					    // 空顺序表元素个数为0

	for (int i = 1; i <= saLength; i++)	{
		sa.getElem(i, e);		    // 取出顺序表sa中第i个元素
		insertElem(e);			    // 将e插入到当前顺序表的表尾 
	}
}

template <class ElemType>
SeqList<ElemType> &SeqList<ElemType>::operator =(const SeqList<ElemType> &sa)
// 功能：赋值语句重载，将顺序表sa赋值给当前顺序表
{
	if (&sa != this)	{
		int saLength = sa.GetLength();	// 取顺序表sa的长度
		ElemType e;

        maxLength = sa.maxLength;		// 取顺序表的最大容量
        delete []elems;                 // 释放顺序表原来的存储空间
        elems = new ElemType[maxLength];// 分配存储空间
	    assert(elems);                  // 分配存储空间失败 
        length = 0;						// 空顺序表元素个数为0
        for (int i = 1; i <= saLength; i++)	{
			sa.getElem(i, e);	        // 取出顺序表sa中第i个元素
			insert(e);		            // 将e插入到当前顺序表的表尾
		}
	}
	return *this;
}

//1.（3）在一个顺序表中如果一个数据值有重复出现，则留下第一个这样的数据值，
	//并删除其他所有重复的元素，使表中所有元素的值均不相同。
template <class ElemType>
void SeqList<ElemType>::DeleteRepeat() 
{
	int maxLength = 10;
	int* a = new int[maxLength]; 
	//a用于标记原数组中元素是否在后面元素中重复
	int count=length;  //表示删减后的length
	for(int i = 0; i < length; i++)
	{
		if(a[i]) //如果该元素已经是前面重复过的，那么跳过本次循环
		continue;
		for(int j = i+1; j < length; j++) //从i的下一位开始
		{
			if(elems[i] == elems[j]) 
			{
				a[j]++;   //如果重复，则标记
				count--;  //删减后的length-1
			}
		}
	}
	//为新的数组开辟区域
	ElemType *temp = new ElemType[maxLength];
	for(int i = 0, j = 0; i<length && j < count; i++)
	//将没有重复或者第一次出现的元素顺序放入新数组中
	{
		if(a[i]==0)
		temp[j++] = elems[i]; 
	}
	delete []elems;   //将原来的数组删除
	elems = temp;     //设置为删减后的数组
	delete []a;       // 释放内存
	length = count;   //length设置为删除后的length
}


//3.线性表中的原地逆置
template <class ElemType>
void SeqList<ElemType>::reverse() throw(double)
{
	if(length == 0) throw (double)-1;
	ElemType temp;
	for(int i =0;i<length/2+0.5;i++)
	{
		temp = elems[i];
		elems[i] = elems[length-i-1];
		elems[length-i-1] = temp;
	}
}


#endif
