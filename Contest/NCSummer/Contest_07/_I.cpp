#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

constexpr int MOD = 998244353;

int brute_force(vector<string> &arr)
{
    int len = arr.front().length();
    int siz = arr.size();
    int res = 0;
    for (int i = 0; i < (1 << len); i++)
    {
        for (int j = 0; j < siz; j++)
        {
            bool flag = true;
            for (int k = 0; k < len; k++)
            {
                if (arr[j][k] == '?')
                    continue;
                if (arr[j][k] != (i >> k & 1) + '0')
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                res++;
                break;
            }
        }
    }
    return res;
}

int inc_exc(vector<string> &arr)
{
    int len = arr.front().length();
    int siz = arr.size();
    int res = 0;
    for (int i = 1; i < (1 << siz); i++)
    {
        bool flag = true;
        string match(len, '?');
        for (int j = 0; flag && j < siz; j++)
        {
            if ((i >> j & 1) == 0)
                continue;
            for (int k = 0; k < len; k++)
            {
                if (match[k] == '0' && arr[j][k] == '1' ||
                    match[k] == '1' && arr[j][k] == '0')
                {
                    flag = false;
                    break;
                }
                if (match[k] == '?')
                    match[k] = arr[j][k];
            }
        }
        if (!flag)
            continue;
        int tmp = 1;
        for (int j = 0; j < len; j++)
            if (match[j] == '?')
                tmp = (tmp * 2) % MOD;
        bool op = __builtin_popcount(i) & 1; // odd+ even-
        if (op)
            res = (res + tmp) % MOD;
        else
            res = (res - tmp + MOD) % MOD;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    map<int, vector<string>> mp;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        mp[s.length()].emplace_back(s);
    }
    int ans = 0;
    for (auto &[len, arr] : mp)
    {
        if (len <= 20)
            ans = (ans + brute_force(arr)) % MOD;
        else
            ans = (ans + inc_exc(arr)) % MOD;
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}