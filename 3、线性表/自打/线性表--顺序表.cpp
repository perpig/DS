//线性表，本质数组，数据连续存储
//一个线性表是n(n≥0)个相同类型数据元素的有限序列。
//记为：L=(a，az，…,a。）。
//L:表名，L为空表
//下标n为表的长度

//ps：顺序表插入的最好插入是从尾部插入
#include<iostream>
using namespace std;

enum Status {
    SUCCESS, RANGE_ERROR, ENTRY_FOUND, 
    NOT_PRESENT, OVER_FLOW
};

template<typename T>
class SeqList 
{
protected:
 int length;   //
 int maxLength;  //容量capacity
 T *elems;   //元素首地址

public:
 SeqList(int size = DEFAULT_size);
 SeqList(T arr[], int n, int size= DEFAULT_size);  //根据数组内容构造顺序表
 ~SeqList();
 void Clear();//清空clear
 void Traverse(void(*visit)(const T &)) const; //遍历
 int LocateElem(const T &e) const;  //元素定位
 Status GetElem(int pos, T &e); //get pos处的元素
 Status SetElem(int pos, T &e); //set pos处的元素
 Status DeleteElem(int pos, T &e); //delete pos处的元素
 Status InsertElem(int pos,const T &e); //pos处插入元素
 Status InsertElem(const T &e); //表尾处插入元素
};

//根据size的有参构造函数
template<typename T>
SeqList<T>::SeqList(int size = DEFAULT_size) : length(0),maxLength(size)
{
    elems = new T[size];
}

//根据数组内容构造顺序表
template<typename T>
SeqList<T>::SeqList(T arr[], int n, int size= DEFAULT_size) : length(n),maxLength(size)
{
    elms= new T[size];
    for(int i=0;i<length;i++)
    elems[i] = v[i];
}

//析构函数
template<typename T>
SeqList<T>::~SeqList()
{
    delete []elems;  //手动释放
}

template<typename T>
void SeqList<T>::Clear()
{
    length = 0;
}

//遍历
template<typename T>
void SeqList<T>::Traverse(void(*visit)(const T &)) const
{
    for(int i=0;i<length ;i++)
    (*vist)(elems[i]);  //对其进行（*vist）函数的操作
}

//元素定位
template<typename T>
int SeqList<T>::LocateElem(const T &e) const 
{
    for(int =0;i<length;i++)
    {
        if(elems[i]==e)
        return i;
    }
    return 0;
}

//get pos处的元素
template<typename T>
Status SeqList<T>::GetElem(int pos, T &e) 
{
    if(pos < 0 || pos >= length)
    return NOT_PRESENT;
    e = elems[pos];
    return ENTRY_FOUND;
}

//set pos处的元素
template<typename T>
Status SeqList<T>::SetElem(int pos, T &e)
{
    if(pos < 0 || pos >= length)
    return RANGE_ERROR;
    elems[pos] = e;
    return SUCCESS;
}

//delete pos处的元素
template<typename T>
Status SeqList<T>::DeleteElem(int pos, T &e)
{
    if(pos < 0 || pos >= length)
    return RANGE_ERROR;
    e = elems[pos];
    for(int i = pos; i < length-1; i++)
    elems[i]=elems[i+1];
    length--;
    return SUCCESS;
}

//pos处插入元素
template<typename T>
Status SeqList<T>::InsertElem(int pos,const T &e)
{
    if(length == maxLength)
    return OVER_FLOW;
    if(pos < 0 || pos >= length)
    return RANGE_ERROR;
    for(int i = length-1; i >= pos; i--)
    elems[i+1]=elems[i];
    elems[pos] = e;
    length++;
    return SUCCESS;
}

//表尾处插入元素
template<typename T>
Status SeqList<T>::InsertElem(const T &e)
{
    if(length == maxLength)
    return OVER_FLOW;
    elems[length++] = e;
    return SUCCESS;
}