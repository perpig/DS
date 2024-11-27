#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 计算逆序数
int inversionCount(string s)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i + 1; j < s.length(); j++)
        {
            if (s[i] > s[j])
            {
                count++;
            }
        }
    }
    return count;
}

// 自定义比较函数
bool cmp(string a, string b)
{
    int count_a = inversionCount(a);
    int count_b = inversionCount(b);
    if (count_a != count_b) // 如果逆序数不相同就可以直接返回大小关系
        return count_a > count_b;
    return a < b; // 逆序用字典顺序比较 string有自己比较的功能的
}

// 通用冒泡排序
void bubbleSort(vector<string> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (cmp(arr[j], arr[j + 1])) // 这里的比较用我们自己定义的比较
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> dna_list(n);

    for (int i = 0; i < n; i++)
    {
        cin >> dna_list[i];
    }

    // 使用冒泡排序
    bubbleSort(dna_list);

    for (int i = 0; i < n; i++)
    {
        // cout << inversionCount(dna_list[i]) << " ";
        cout << dna_list[i] << endl;
    }

    return 0;
}
