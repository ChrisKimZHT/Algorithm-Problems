#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << "========================" << endl
         << "实验7  求集合的笛卡尔乘积" << endl
         << "========================" << endl;
    set<int> A, B;         // 原集合
    set<pair<int, int>> C; // 所求笛卡尔乘积
    int size_A, size_B;
    // 读入集合A
    cout << "输入集合A的元素个数：";
    cin >> size_A;
    cout << "输入集合A的元素（整型）：";
    while (size_A--)
    {
        int t;
        cin >> t;
        A.insert(t);
    }
    // 读入集合B
    cout << "输入集合B的元素个数：";
    cin >> size_B;
    cout << "输入集合B的元素（整型）：";
    while (size_B--)
    {
        int t;
        cin >> t;
        B.insert(t);
    }
    // 求笛卡尔乘积
    for (auto it = A.begin(); it != A.end(); ++it)
    {
        for (auto jt = B.begin(); jt != B.end(); ++jt)
        {
            C.insert({*it, *jt});
        }
    }
    cout << "========================" << endl;
    cout << "笛卡尔乘积：" << endl;
    for (auto it = C.begin(); it != C.end(); ++it)
    {
        cout << "<" << it->first << ", " << it->second << ">" << endl;
    }
    return 0;
}