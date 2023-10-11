#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    n--;
    int len = s.size(), pos = 0;
    int seg_len = len;
    while (pos + seg_len - 1 < n)
    {
        pos += seg_len;
        seg_len--;
    }
    pos = n - pos;
    int del = 0;
    vector<char> stk;
    stk.push_back(s.front());
    for (int i = 1; i < len; i++)
    {
        while (stk.size() && stk.back() > s[i])
        {
            if (len == seg_len + del)
                break;
            stk.pop_back();
            del++;
        }
        stk.push_back(s[i]);
    }
    cout << stk[pos];
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