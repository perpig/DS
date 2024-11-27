#ifndef  __STRING_H__
#define __STRING_H__

#include "LinkList.h"

class String
{
protected:
    char *sVal;
    int length;

public:
    String();
    virtual ~String();
    String(const String &s);
    String(const char *s);
    String(LinkList<char> &s);
    int GetLength() const;
    bool IsEmpty() const;
    String& operator=(const String &s);
    const char* CStr() const;  //将串转换成字符数组
    char& operator[](int p) const;
};

// -----------------------串相关操作----------------------
// 输出串
void Write(const String &s);
// 将串s2复制到串s1
void Copy(String &s1, const String &s2);
// 将串s2复制n个字符到串s1 
void Copyn(String &s1, const String &s2, int n);
 // 将字符串s2插入到s1的p位置 
Status Insert(String &s1, const String &s2, int p);
// 删除字符串s中从p位置开始长度为n的字符串 
Status Delete(String &s1, int p, int n);
// 求串s的第p个字符开始的长度为n的子串
String SubString(const String &s, int p, int n);
// 重载关系运算符+
String operator+(const String &s1,const String &s2);
// 重载关系运算符==
bool operator==(const String &s1, const String &s2);
// 重载关系运算符<
bool operator<(const String &s1, const String &s2);
// 重载关系运算符>
bool operator>(const String &s1, const String &s2);
// 重载关系运算符<=
bool operator<=(const String &s1, const String &s2);
// 重载关系运算符>=
bool operator>=(const String &s1, const String &s2);
// 重载关系运算符!=
bool operator!=(const String &s1, const String &s2);

String::String() {
    length = 0;
    sVal = NULL;
}

String::~String() {
    if(sVal != NULL)
    delete [] sVal;
}

String::String(const String &s) {
    //length = s.length; //不能及时对串长进行更新
    length = strlen(s.CStr());  // 设置串长
    //if(sVal != NULL) delete [] sVal;
    //静态数组：静态数组的内存分配是在编译时完成的，数组的大小和内存布局在编译阶段就已经确定。
    //只有部分情况的内存提前分配，这里不会提前分配
    sVal = new char[length + 1];
    strcpy(sVal, s.CStr());
}

String::String(const char *s) {
    length = strlen(s);
    sVal = new char[length + 1];
    strcpy(sVal,s);
}

String::String(LinkList<char> &s) {
    length = s.GetLength();
    sVal = new char[length + 1];
    for(int i = 0; i < length; i++)
        s.GetElem(i+1,sVal[i]);
    sVal[length] = '\0';
}

int String::GetLength() const {
    return length;
}

bool String::IsEmpty() const {
    return length == 0;
}

String& String::operator=(const String &s) {
    if(&s == this) return *this;
    delete []sVal;
    length = s.length;
    sVal = new char[length + 1];
    strcpy(sVal, s.CStr());
    return *this;
}

//将串转换成字符数组
const char* String::CStr() const {
    return (const char *) sVal;
}
char& String::operator[](int p) const {
    return sVal[p];
}

// 输出串
void Write(const String &s){
    cout << s.CStr() << endl;
}//cout不能直接输出String对象，因为cout是C++标准库中的输出流对象，而String是一个自定义的类对象。

// 将串s2复制到串s1
void Copy(String &s1, const String &s2){
    s1 = s2;
}

// 将串s2复制n个字符到串s1 
void Copyn(String &s1, const String &s2, int n) {
    const char * cs2 = s2.CStr();
    int len = strlen(cs2) < n ? strlen(cs2) : n;
    char *cs1 = new char[len + 1];
    strncpy(cs1,cs2,n);
    cs1[len] = '\0';
    s1 = cs1;
}

// 将字符串s2插入到s1的p位置 
Status Insert(String &s1, const String &s2, int p) {
    const char *cs1 = s1.CStr();
    const char *cs2 = s2.CStr();
    if(p < 0 || p > strlen(cs1)) return RANGE_ERROR;
    int len = strlen(cs1) + strlen(cs2);
    char * cs = new  char[len + 1];
    strncpy(cs, cs1, p);
    cs[p] = '\0';  //strcat的函数原型两个字符串相连
    strcat(cs, cs2);
    for(int i = p; i < strlen(cs1); i++)
        cs[i + strlen(cs2)] = cs1[i];
    cs[len] = '\0';
    s1 =cs;
    return SUCCESS;
}

// 删除字符串s中从p位置开始长度为n的字符串 
Status Delete(String &s, int p, int n)
{
    const char* cs = s.CStr();
    if(p > strlen(cs) || p < 0 || p + n >= strlen(cs))
    return RANGE_ERROR;
    int len = strlen(cs) - n;
    char *news = new char[len +1 ];
    strncpy(news , cs, p);
    for(int i = p; i < len ; i++)
    news[i] = cs[i + n];
    news[len] = '\0';
    s = news;    //赋值
    delete [] news;   //释放空间
    return SUCCESS;
}

// 求串s的第p个字符开始的长度为n的子串
String SubString(const String &s, int p, int n)
{
    if(p < 0 || p + n > s.GetLength() || n < 0) {
        String cs("");
        return cs;
    }
    const char *cs = s.CStr();
    char* sub = new char[n + 1];
    strncpy(sub, cs + p, n);
    sub[n] = '\0';
    String new_cs(sub);// 生成串对象
    delete []sub;
    return new_cs;
}

// 重载关系运算符+
String operator+(const String &s1,const String &s2)
{
    const char* cs1 = s1.CStr();
    const char* cs2 = s2.CStr(); 
    char *cs = new char[strlen(cs1) + strlen(cs2) + 1];
    strcpy(cs, cs1);
    strcat(cs, cs2);
    String s(cs);
    delete []cs;
    return s;
}
// 重载关系运算符==
bool operator==(const String &s1, const String &s2)
{
    return strcmp(s1.CStr(), s2.CStr()) == 0;
}

// 重载关系运算符<
bool operator<(const String &s1, const String &s2){
    return strcmp(s1.CStr(), s2.CStr()) < 0;
}

// 重载关系运算符>
bool operator>(const String &s1, const String &s2){
    return strcmp(s1.CStr(), s2.CStr()) > 0;
}

// 重载关系运算符<=
bool operator<=(const String &s1, const String &s2) {
    return strcmp(s1.CStr(), s2.CStr()) <= 0;
}

// 重载关系运算符>=
bool operator>=(const String &s1, const String &s2) {
    return strcmp(s1.CStr(), s2.CStr()) >= 0;
}

// 重载关系运算符!=
bool operator!=(const String &s1, const String &s2)
{
    return strcmp(s1.CStr(), s2.CStr()) != 0;
}

#endif // ! __STRING_H__