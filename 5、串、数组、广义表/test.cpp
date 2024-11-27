#include <string>
#include<iostream>
using namespace std;
int main()
{
    int i = 0;
    rewind(stdin);
    cout << "请输入要查找的单词，输入#表示结束" << endl;
    while(true)
    {
        string buffer;
        char ch;
        while (true)
        {
            ch = getchar();
            if(ch == '#' || ch == ' ')
                break;
            buffer += ch;
        }
        //search.push_back({buffer, -1, 0, true});
        //cout << i++ << ":" << buffer << " push_back" << "\n";
        if(ch == '#')
            break;
    }
    return 0;
}