#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int count_a, count_b, count_c; // 每个数组的个数
    vector<int> c;                 // c数组
    int temp;
    multimap<int, int> hash; // multimap 键：元素 值：位置
    cin >> count_a >> count_b >> count_c;
    c.resize(count_c);                // 为c数组调整大小
    for (int i = 0; i < count_a; i++) // a数组
    {
        cin >> temp;
        hash.insert(make_pair(temp, i + 1)); // 将位置存入hash表
    }
    for (int i = 0; i < count_b; i++) // b数组
    {
        cin >> temp;
        hash.insert(make_pair(temp, i + 1)); // 将位置存入hash表
    }

    for (int i = 0; i < count_c; i++) // 存c数组
    {
        cin >> c[i];
    }

    for (int i = 0; i < count_c; i++) // 遍历c数组
    {
        auto range = hash.equal_range(c[i]); // 查找c[i]对应的所有位置
        bool found = false;
        for (auto it = range.first; it != range.second; ++it)
        {
            if (it->second <= count_a)
            { // 如果位置在a数组中
                cout << c[i] << " " << it->second << " ";
                found = true;
                break;
            }
        }
        if (!found)
        { // 如果在a数组中没找到，则在b数组中查找
            for (auto it = range.first; it != range.second; ++it)
            {
                if (it->second <= count_b)
                { // 如果位置在b数组中
                    cout << it->second - count_a << " ";
                    found = true;
                    break;
                }
            }
        }
        if (!found)
        { // 如果在a、b数组中都没找到
            cout << "NOT FOUND";
        }
        cout << endl;
    }
    return 0;
}
