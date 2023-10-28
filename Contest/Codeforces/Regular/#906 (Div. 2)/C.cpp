// Problem: C. Qingshan Loves Strings 2
// Contest: Codeforces - Codeforces Round 906 (Div. 2)
// URL: https://codeforces.com/contest/1890/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool flag = false;
    if (n % 2)
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        if (s[i] == s[j])
        {
            flag = true;
            break;
        }
    }
    if (!flag)
    {
        cout << 0 << endl << endl;
        return;
    }
    int cnt_0 = 0;
    for (int i = 0; i < n; i++)
        cnt_0 += s[i] == '0';
    if (cnt_0 * 2 != n)
    {
        cout << -1 << endl;
        return;
    }
    vector<int> ans;
    int offset = 0;
    vector<char> l_ex, r_ex;
    for (int i = 0, j = n - 1; i < j;)
    {
        char a = s[i], b = s[j];
        bool ua = true, ub = true;
        if (l_ex.size())
        {
            a = l_ex.back();
            ua = false;
        }
        if (r_ex.size())
        {
            b = r_ex.back();
            ub = false;
        }
        if (a == b)
        {
            if (a == '0')
            {
                ans.push_back(j + 1 + offset + r_ex.size());
                r_ex.push_back('0');
                if (!ua)
                    l_ex.pop_back();
                else
                    i++;
            }
            else
            {
                ans.push_back(i + offset - l_ex.size());
                l_ex.push_back('1');
                offset += 2;
                if (!ub)
                    r_ex.pop_back();
                else
                    j--;
            }
        }
        else
        {
            if (!ua)
                l_ex.pop_back();
            else
                i++;
            if (!ub)
                r_ex.pop_back();
            else
                j--;
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " \n"[i + 1 == ans.size()];
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