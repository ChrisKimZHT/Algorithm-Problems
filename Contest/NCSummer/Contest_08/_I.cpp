#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

constexpr int MOD = 998244353;

class KMP
{
    vector<int> nxt;
    string pat;

public:
    KMP(string &s)
    {
        pat = s;
        int n = pat.length();
        int j = 0;
        nxt.resize(n);
        for (int i = 1; i < n; i++)
        {
            while (j > 0 && pat[i] != pat[j])
                j = nxt[j - 1];
            if (pat[i] == pat[j])
                j++;
            nxt[i] = j;
        }
    }
    vector<int> find(string &txt)
    {
        int n = pat.length(), m = txt.length();
        int j = 0;
        vector<int> ans;
        for (int i = 0; i < m; i++)
        {
            while (j > 0 && txt[i] != pat[j])
                j = nxt[j - 1];
            if (txt[i] == pat[j])
                j++;
            if (j == n)
            {
                ans.push_back(i - n + 1);
                j = nxt[j - 1];
            }
        }
        return ans;
    }
    set<int> get_border()
    {
        set<int> s;
        int cur = nxt.back();
        while (cur)
        {
            s.insert(cur);
            cur = nxt[cur - 1];
        }
        s.insert(0);
        return s;
    }
};

void solve()
{
    int m;
    cin >> m;
    string s, t;
    cin >> s >> t;
    int ls = s.size(), lt = t.size();
    if (ls == lt)
    {
        if (s != t)
        {
            for (int i = 1; i <= m; i++)
                cout << 0 << " \n"[i == m];
        }
        else
        {
            int ans = 1;
            for (int i = 1; i <= m; i++)
            {
                ans = ans * 26 % MOD;
                cout << ans << " \n"[i == m];
            }
        }
        return;
    }
    if ((ls + lt) % 2 == 1)
    {
        for (int i = 1; i <= m; i++)
            cout << 0 << " \n"[i == m];
        return;
    }
    if (ls > lt)
    {
        for (int i = lt - 1, j = ls - 1 - (ls - lt) / 2; i >= 0; i--, j--)
        {
            if (t[i] != s[j])
            {
                for (int i = 1; i <= m; i++)
                    cout << 0 << " \n"[i == m];
                return;
            }
        }
        int ans = 1;
        for (int i = 1; i <= m; i++)
        {
            if (i > (ls - lt) / 2)
            {
                ans = ans * 26 % MOD;
                cout << ans << " \n"[i == m];
            }
            else
            {
                KMP kmp_s(s);
                auto border_s = kmp_s.get_border();
                if (border_s.count((ls - lt) / 2 - i) == 0)
                    cout << 0 << " \n"[i == m];
                else
                    cout << 1 << " \n"[i == m];
            }
        }
    }
    else // if (ls <= lt)
    {
        for (int i = ls - 1, j = lt - 1 - (lt - ls) / 2; i >= 0; i--, j--)
        {
            if (s[i] != t[j])
            {
                for (int i = 1; i <= m; i++)
                    cout << 0 << " \n"[i == m];
                return;
            }
        }
        int ans = 1;
        for (int i = 1; i <= m; i++)
        {
            if (i > (lt - ls) / 2)
            {
                ans = ans * 26 % MOD;
                cout << ans << " \n"[i == m];
            }
            else
            {
                KMP kmp_t(t);
                auto border_t = kmp_t.get_border();
                if (border_t.count((lt - ls) / 2 - i) == 0)
                    cout << 0 << " \n"[i == m];
                else
                    cout << 1 << " \n"[i == m];
            }
        }
    }
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