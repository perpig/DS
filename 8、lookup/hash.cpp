#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct location // 用来存位置
{
    int flag;
    int a;
    int b;
    int c;
};

int main()
{
    int count_a, count_b, count_c;
    vector<int> c;
    int temp;
    map<int, struct location> hash;
    cin >> count_a >> count_b >> count_c;
    c.resize(count_c);
    for (int i = 0; i < count_a; i++)
    {
        cin >> temp;
        hash[temp].a = i + 1;
        hash[temp].flag++;
    }
    for (int i = 0; i < count_b; i++)
    {
        cin >> temp;
        hash[temp].b = i + 1;
        hash[temp].flag++;
    }

    for (int i = 0; i < count_c; i++)
    {
        cin >> c[i];
    }

    for (int i = 0; i < count_c; i++)
    {
        // cout << i << " : " << hash[c[i]].a << " " << hash[c[i]].b << " " << hash[c[i]].flag << endl;
        if (hash[c[i]].a && hash[c[i]].b)
        {
            cout << c[i] << " " << hash[c[i]].a << " " << hash[c[i]].b << " " << i + 1 << endl;
            break;
        }
        if (i == count_c - 1)
            cout << "NOT FOUND" << endl;
    }
    return 0;
}