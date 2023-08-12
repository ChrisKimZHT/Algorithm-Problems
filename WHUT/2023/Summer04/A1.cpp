#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int same_pos = -1;
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        if (s[i] != s[j])
            break;
        same_pos = i;
    }
    string pre = s.substr(0, same_pos + 1);
    string suf = pre;
    reverse(suf.begin(), suf.end());
    // find left
    string mid = "", tmp = "";
    int center = 0;
    bool gap = true, dot = true;
    for (int i = same_pos + 1; i < n - 1 - same_pos; i++)
    {
        if (tmp.empty())
        {
            tmp = s[i];
            gap = dot = true;
            if (tmp.size() > mid.size())
                mid = tmp;
            continue;
        }
        tmp += s[i];
        if (gap)
        {
            int len = (tmp.size() - 1) - (center + 1);
            if (center - len < 0)
                gap = false;
            else if (tmp.back() != tmp[center - len])
                gap = false;
            else if (center - len == 0 && tmp.size() > mid.size())
                mid = tmp;
        }
        if (dot)
        {
            int len = (tmp.size() - 1) - center;
            if (center - len < 0)
                dot = false;
            else if (tmp.back() != tmp[center - len])
                dot = false;
            else if (center - len == 0 && tmp.size() > mid.size())
                mid = tmp;
        }
        if (gap == false && dot == false)
        {
            gap = dot = true;
            center = tmp.size() - 1;
        }
    }
    // find right
    reverse(s.begin(), s.end());
    tmp = "";
    center = 0;
    gap = dot = true;
    for (int i = same_pos + 1; i < n - 1 - same_pos; i++)
    {
        if (tmp.empty())
        {
            tmp = s[i];
            gap = dot = true;
            if (tmp.size() > mid.size())
                mid = tmp;
            continue;
        }
        tmp += s[i];
        if (gap)
        {
            int len = (tmp.size() - 1) - (center + 1);
            if (center - len < 0)
                gap = false;
            else if (tmp.back() != tmp[center - len])
                gap = false;
            else if (center - len == 0 && tmp.size() > mid.size())
                mid = tmp;
        }
        if (dot)
        {
            int len = (tmp.size() - 1) - center;
            if (center - len < 0)
                dot = false;
            else if (tmp.back() != tmp[center - len])
                dot = false;
            else if (center - len == 0 && tmp.size() > mid.size())
                mid = tmp;
        }
        if (gap == false && dot == false)
        {
            gap = dot = true;
            center = tmp.size() - 1;
        }
    }
    cout << pre << mid << suf << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}