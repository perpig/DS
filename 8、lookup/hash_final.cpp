#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct location // 用来存元素位置
{
    int a;
    int b;
};

int main()
{
    int count_a, count_b, count_c; // 每个数组的个数
    vector<int> c;                 // c数组
    int temp;
    map<int, struct location> hash; // hash表 键：元素 值：位置
    cin >> count_a >> count_b >> count_c;
    c.resize(count_c);                // 为c数组调整大小
    for (int i = 0; i < count_a; i++) // a数组
    {
        cin >> temp;
        hash[temp].a = i + 1; // 将位置存入hash表
    }
    for (int i = 0; i < count_b; i++) // b数组
    {
        cin >> temp;
        hash[temp].b = i + 1; // 将位置存入hash表
    }

    for (int i = 0; i < count_c; i++) // 存c数组
    {
        cin >> c[i];
    }

    for (int i = 0; i < count_c; i++) // 遍历c数组
    {
        if (hash[c[i]].a && hash[c[i]].b) // 如果此时的元素在hash表中a，b都存过
        {
            cout << c[i] << " " << hash[c[i]].a << " " << hash[c[i]].b << " " << i + 1 << endl;
            break; // 此时找到共同最小元素 跳出循环
        }
        if (i == count_c - 1) // 遍历到最后，说明没找到 输出NOT FOUND
            cout << "NOT FOUND" << endl;
    }
    return 0;
}