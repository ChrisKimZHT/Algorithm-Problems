#include <bits/stdc++.h>

using namespace std;

bool StrMatch(string s1, string s2)
{
    vector<int> nxt(max(s1.size(), s2.size()) + 1); // 部分匹配表
    // 计算部分匹配表
    nxt[0] = -1;
    int i = 0, j = -1;
    int lens1 = s1.size(), lens2 = s2.size();
    while (i < lens2)
    {
        if (j == -1 || s2[i] == s2[j])
        {
            ++i;
            ++j;
            nxt[i] = j;
        }
        else
        {
            j = nxt[j];
        }
    }
    // KMP算法
    i = 0, j = 0;
    while (i < lens1 && j < lens2)
    {
        if (j == -1 || s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            j = nxt[j];
        }
    }
    if (j == lens2)
    {
        return true;
    }
    else
    {
        return false; // 没匹配到结果
    }
}

int main()
{
    string s1, s2;
    cin >> s1;
    while (1)
    {
        cin >> s2;
        if (StrMatch(s1, s2))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}