#include "String.h"
#include <iostream>

int frequency(char *sStr,char arrChar[],int arrTimes[])
{
    //arrChar 记录字符串中所有不同的字符
    //arrtimes记录出现次数
    int count = 0;  //记录字符的个数
    int len = strlen(sStr);
    if(len == 0)  return count;//字符串为空
    for(int i = 0; i < len; i++)
        arrTimes[i] = 0;
    for(int i = 0; i < len; i++)
    {
        int flag = 0;
        for(int j = 0; j < count; j++)
        {
            if(arrChar[j]==sStr[i])
            {
                arrTimes[j]++;
                flag++;
                break;
            }
        }
        if(!flag)
        {
            arrChar[count] = sStr[i];
            arrTimes[count++]++;
        }
    }
    return count;
}

int main()
{
    char* cStr = new char[100];
    char arrChar[100];
    int arrTimes[100];
    cout << "输入cStr:" ;
    cin >> cStr;
    int count = frequency(cStr,arrChar,arrTimes); 
    cout << "频度：" << count << endl;
    cout << "字符：个数，如下：" << endl;
    for(int i = 0; i < count; i++)
    cout << arrChar[i] << ":"<<arrTimes[i]<<endl;
    delete[] cStr; // 释放内存
    return 0;
}