#include <fstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct SearchItem   // 表示某单词当前被搜索的状态
{
    string word;    // 被搜索的单词
    int pt;         // 表示当前已经匹配到的位置
    int cnt;        // 表示已经出现过多少次该单词
    bool valid;     // 表示该单词与文本中当前单词是否还可能匹配
};

int main()
{
    vector<string> lines;//定义一个空的vector
    vector<SearchItem> search;
    string filename;
    fstream fs;
    // 打开文本文件
    while (fs.is_open() == false)
    {
        cout << "请输入文件名：" << endl;
        cin >> filename;
        fs.open(filename, fstream::in | fstream::out);
        if (fs.is_open())
            break;
        cout << "无法打开文件" << endl;
    }
    // 读取文本
    while (!fs.eof())
    {
        char buffer[7000] = "";
        fs.getline(buffer, 7000);//读取整行文本
        lines.push_back(buffer);
    }
    fs.close();
    // 读取要查找的单词
    rewind(stdin);
    cout << "请输入要查找的单词，输入#表示结束" << endl;
    while (true)
    {
        string buffer;
        char ch;
        while (true)
        {
            ch = getchar();
            if (ch == '#' || ch == ' ')
                break;
            buffer += ch;
        }
        search.push_back({buffer, -1, 0, true});
        if (ch == '#')
            break;
    }
    // 查找单词
    // 遍历每一行
    for (int line = 0; line < lines.size(); line++)
    {
        // 从前往后扫描，article_pt表示当前文本被扫描到的位置
        for (int article_pt = 0; article_pt < lines[line].length(); article_pt++)
        {
            // 文本中当前位置字符
            char ch = lines[line][article_pt];
            // 如果在单词中
            if (isalpha(ch) || ch == '\'')
            {
                // 大写字母应当转成小写
                if (isupper(ch))//如果ch是大写字母，则返回true
                    ch = tolower(ch);//如果ch是大写字母，则返回其小写字母的形式，否则直接返回ch
                // 逐个检查每个需要被匹配的单词
                for (int i = 0; i < search.size(); i++)
                {
                    // 如果该单词已经不可能匹配成功（之前某一位字母不同），直接跳出
                    if (search[i].valid == false)
                        continue;
                    // 准备好要检查的这个单词的下一个字符
                    int pt = search[i].pt + 1;
                    // 如果文本中的单词比要检查的单词长，肯定不能匹配
                    if (pt >= search[i].word.length())
                        search[i].valid = false;    // 让它以后也不能匹配
                    // 检查两边的当前字符是否相等
                    else if (search[i].word[pt] == ch)
                        search[i].pt = pt;          // 匹配成功，准备匹配下一位
                    else
                        search[i].valid = false;    // 匹配失败，后面放弃匹配
                }
            }
            else// 如果是逗号空格等分隔符
            {
                for (int i = 0; i < search.size(); i++)
                {
                    // 检查前一个字母是否匹配成功
                    if (search[i].valid == true && search[i].pt == search[i].word.length() - 1)
                    {
                        search[i].cnt++;
                        cout << "单词" << search[i].word << "第" << search[i].cnt << "次出现在第" << line + 1 << "行" << endl;
                    }
                    // 重新激活每一个待检查的单词，让它尝试匹配文本中的新单词
                    search[i].pt = -1;
                    search[i].valid = true;
                }
            }
        }
    }
    for (int i = 0; i < search.size(); i++)
        cout << "单词" << search[i].word << "共出现" << search[i].cnt << "次" << endl;
    return 0;
}