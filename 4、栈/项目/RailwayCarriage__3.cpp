#include "Assistance.h"	// 辅助软件包
#include "SeqStack.h"	// 循环队列类

int main(void)
{
   SeqStack<int> qa;
int n, x, d;

cout << "输入车厢数：";
cin >> n;
cout << "输入 " << n << " 节车厢的入站顺序：";
for (int i = 1; i <= n;) {
    cin >> d;

    while (qa.Top(x) == SUCCESS && x == i) {
        cout << "第 " << x << " 号车厢从辅轨道进入主轨道右边." << endl;
        qa.Pop(x);
        i++;
    }
    if (d > i) {
        cout << "第 " << d << " 号车厢从主轨道左边进入辅轨道." << endl;
        qa.Push(d);
        continue;
    } else if (d == i) {
        cout << "第 " << d << " 号车厢从主轨道左边进入主轨道右边." << endl;
        while (qa.Top(x) == SUCCESS && x == i + 1) {
            cout << "第 " << x << " 号车厢从辅轨道进入主轨道右边." << endl;
            qa.Pop(x);
            i++;
        }
        i++;
    } else {
        break;
    }
}
if (qa.IsEmpty())
    cout << "调度完成." << endl;
else
    cout << "调度无法完成." << endl;

//system("PAUSE");
return 0;
}


