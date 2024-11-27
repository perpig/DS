#include "SeqStack.h"	// 循环队列类

void test1() 
{
    SeqStack<int> qa;
    int n, x, d, No;
 
    cout << "输入车厢数："; 
    cin >> n;
    No = 1;        // No表示排在主轨道左边最前面的车厢编号，初始值为1. 
    cout << "输入 " << n << " 节车厢的出站顺序："; 
    for (int i = 1; i <= n ; i++)
    {//一共输入n个数据，以表示车厢编号
        cin >> d;
        if(qa.Top(x) == SUCCESS && x == d) 
        {
           //看栈内（副轨道）是否有元素，如果有并且和输入的车厢编号相等，则出栈
           cout << "第 " << x << " 号车厢从辅轨道进入主轨道右边." << endl;
           qa.Pop(x);
        }
        if (No <= d) 
        {
           while (No <= n && No < d) 
           {
              //输入的编号大于当前主轨道上第一个车厢对应的编号，则No号车厢入栈
              cout << "第 " << No << " 号车厢从主轨道左边进入辅轨道." << endl;
              qa.Push(No++);
           }
           if (No == d) 
           {
              //输入的编号恰好等于主轨道上第一个对应的编号，则直接输出
              cout << "第 " << No << " 号车厢从主轨道左边进入主轨道右边." << endl;
              No++;
           }
        }
        else 
           break;
    }
    if (qa.IsEmpty())
        cout << "调度完成." << endl;
    else
        cout << "调度无法完成." << endl;

	//system("PAUSE");
	//return; 
}

void test2()
{
    SeqStack<int> qa;
    int n, x, d, No[100], j = 0;//使用j遍历顺序数组No[j]
    cout << "输入车厢数：";
    cin >> n;
    for (j = 0; j < n; j++)
        No[j] = j+1;//No作为预设好右边主轨道的顺序
    cout << "输入 " << n << " 节车厢的顺序：";
    for (int i = 1; i <= n; i++) 
    {//一共输入n个数据，以表示车厢编号
        cin >> d;
        while (qa.Top(x) == SUCCESS && x == No[j]) 
        {
            //看栈内（副轨道）是否有元素，如果有并且和对应顺序排列的车厢编号相等，则出栈
            cout << "第 " << x << " 号车厢从辅轨道进入主轨道右边." << endl;
            qa.Pop(x);
            j++;
        }
        if (No[j] <= d) 
        {
            while (No[j] <= n && No[j] < d) 
            {//输入的编号大于当前主轨道上第一个车厢对应的编号，则d号车厢入栈
                cout << "第 " << d << " 号车厢从主轨道左边进入辅轨道." << endl;
                qa.Push(d);
                break;
            }
            if (No[j] == d) 
            {//输入的编号等于当前主轨道上第一个车厢对应的编号，则直接输出
                cout << "第 " << d << " 号车厢从主轨道左边进入主轨道右边." << endl;
                j++;
            }
        }
        if (i == n && !qa.IsEmpty()) 
        {
            //防止上述出现最后一位已输出完毕但栈内仍有剩余车厢的情况
            while(qa.Top(x) == SUCCESS && x == No[j])
            {
            cout << "第 " << x << " 号车厢从辅轨道进入主轨道右边." << endl;
            qa.Pop(x);
            j++;
            }
        }
    }
    if (qa.IsEmpty())
        cout << "调度完成." << endl;
    else
        cout << "调度无法完成." << endl;
    //system("PAUSE");
    return;
}

int main()
{
    //test1();
    test2();
    return 0;
}