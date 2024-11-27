#ifndef __ASSISTANCE_H__				// 如果没有定义__ASSISTANCE_H__
#define __ASSISTANCE_H__				// 那么定义__ASSISTANCE_H__

// 辅助软件包

// ANSI C++标准库头文件
#include <cstring>					// 标准串操作
#include <iostream>					// 标准流操作
#include <limits>					// 极限
#include <cmath>					// 数据函数
#include <fstream>					// 文件输入输出
#include <cctype>					// 字符处理
#include <ctime>       				// 日期和时间函数
#include <cstdlib>					// 标准库
#include <cstdio>       			// 标准输入输出
#include <iomanip>					// 输入输出流格式设置	
#include <cstdarg> 					// 支持变长函数参数	
#include <cassert>					// 支持断言
using namespace std;				// 标准库包含在命名空间std中

// 自定义类型
enum Status {SUCCESS, FAIL, UNDER_FLOW, OVER_FLOW,RANGE_ERROR, DUPLICATE_ERROR,
	NOT_PRESENT, ENTRY_INSERTED, ENTRY_FOUND, VISITED, UNVISITED};

// 宏定义
#define DEFAULT_SIZE 1000			// 缺省元素个数
#define DEFAULT_INFINITY 1000000	// 缺省无穷大


// 辅助函数声明

char GetChar(istream &inStream = cin); // 从输入流inStream中跳过空格及制表符获取一字符
/*bool UserSaysYes();		// 当用户肯定回答(yes)时, 返回true, 用户否定回答(no)时,返回false
void SetRandSeed();		// 设置当前时间为随机数种子
int GetRand(int n);		// 生成0 ~ n-1之间的随机数
int GetRand();			// 生成随机数
int GetPoissionRand(double expectValue);// 生成期望值为expectValue泊松随机数 
*/
template <class ElemType >
void Swap(ElemType &e1, ElemType &e2);	// 交换e1, e2之值
template<class ElemType>
void Display(ElemType elem[], int n);	// 显示数组elem的各数据元素值
template <class ElemType>
void Write(const ElemType &e);			// 显示数据元素

// 实用类
//class Timer;			// 定时器类Timer
class Error;			// 通用异常类
char GetChar(istream &inStream)
// 操作结果：从输入流inStream中跳过空格及制表符获取一字符
{
	char ch;								// 临时变量
	while ((ch = (inStream).peek()) != EOF	// 文件结束符(peek()函数从输入流中接受1
											// 字符,流的当前位置不变)
		&& ((ch = (inStream).get()) == ' '	// 空格(get()函数从输入流中接受1字符,流
											// 的当前位置向后移1个位置)
		|| ch == '\t'));					// 制表符
	
	return ch;								// 返回字符
}
/*
bool UserSaysYes()
// 操作结果: 当用户肯定回答(yes)时, 返回true, 用户否定回答(no)时,返回false
{
	char ch;							// 用户回答字符
	bool initialResponse = true;		// 初始回答

	do
	{	// 循环直到用户输入恰当的回答为止
		if (initialResponse)
		{	// 初始回答
			cout << "(y, n)?"; 
		}
		else
		{	// 非初始回答
			cout << "用y或n回答:";
		}
		
		while ((ch = GetChar()) == '\n');	// 跳过空格,制表符及换行符获取一字符
		initialResponse = false;
	} while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N');
	while (GetChar() != '\n');		// 跳过当前行后面的字符
	
	if (ch == 'y' || ch == 'Y') return true;
	else return false;
}

// 定时器类Timer
class Timer
{
private:
// 数据成员
	clock_t startTime;

public:
//  方法声明
	Timer();				// 构造函数
	~Timer(void) {};		// 析构函数	
	double ElapsedTime();	// 返回已过的时间
	void Reset();			// 重置开始时间
};

// 定时器类Timer的实现部分
Timer::Timer()							
// 操作结果：由当前时间作为开始时间构造对象
{	 
	startTime = clock();
}

double Timer::ElapsedTime()
// 操作结果：返回从Timer对象启动或最后一次调用reset()后所使用的CPU时间
{
	clock_t endTime = clock();
	return (double)(endTime - startTime) / (double)CLK_TCK;
}

void Timer::Reset()
// 操作结果：重置开始时间
{
	startTime = clock();
}
*/
// 通用异常类                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
#define MAX_ERROR_MESSAGE_LEN 100
class Error
{
private:
// 数据成员
	char message[MAX_ERROR_MESSAGE_LEN];// 异常信息

public:
//  方法声明
	Error(const char *mes = "一般性异常!");	// 构造函数 
	~Error(void) {};					// 析构函数	
	void Show() const;					// 显示异常信息
};

// 通用异常类的实现部分
Error::Error(const char *mes)
// 操作结果：由mes构构通用异常对象
{
	strcpy(message, mes);				// 复制异常信息
}

void Error::Show()const
// 操作结果：显示异常信息
{
	cout << message << endl;			// 显示异常信息	
}
/*
void SetRandSeed()
// 操作结果：设置当前时间为随机数种子
{ 
	srand((unsigned)time(NULL)); 
}

int GetRand(int n)
// 操作结果：生成0 ~ n-1之间的随机数
{ 
	return rand() % (n); 
}

int GetRand()
// 操作结果：生成随机数
{ 
	return rand(); 
}

int GetPoissionRand(double expectValue)
// 操作结果：生成期望值为expectValue泊松随机数 
{
	double x = rand() / (double)(RAND_MAX + 1);	// x均匀分布于[0, 1)
	int k = 0;
	double p = exp(-expectValue);			// pk为泊松分布值
	double s = 0;							// sk用于求和p0+p1+...+pk-1

	while (s <= x)
	{	// 当sk <= x时循环, 循环结束后sk-1 <= x < sk
		s += p;								// 求和
		k++;
		p = p * expectValue / k;			// 求下一项pk
	}
	return k - 1;							// k-1的值服从期希值为expectValue的泊松分布
}
*/
template <class ElemType >
void Swap(ElemType &e1, ElemType &e2)
// 操作结果: 交换e1, e2之值
{
	ElemType temp;		// 临时变量
	// 循环赋值实现交换e1, e2
	temp = e1;	e1 = e2;  e2 = temp;
}

template<class ElemType>
void Display(ElemType elem[], int n)
// 操作结果: 显示数组elem的各数据元素值
{
	for (int i = 0; i < n; i++)
	{	// 显示数组elem
		cout << elem[i] << "  ";
	}
	cout << endl; 
}

template <class ElemType>
void Write(const ElemType &e)
// 操作结果: 显示数据元素
{
    cout << e << "  ";
}

#endif
