#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

string calc(vector<string> &vs, int cnt, string s)
{
    int n = s.size();
    string ans = "";
    string st(110, '-');
    for (int i = 1; i <= cnt; i++)
    {
        string &cur = vs[i];
        if (st[cur.size()] != '-')
        {
            if (st[cur.size()] == 'S')
                ans += 'P';
            else
                ans += 'S';
            continue;
        }
        bool pre = true, suf = true;
        for (int j = 0; j < cur.size(); j++)
        {
            if (cur[j] != s[j])
            {
                pre = false;
                break;
            }
        }
        for (int j = 0; j < cur.size(); j++)
        {
            if (cur[cur.size() - 1 - j] != s[n - 1 - j])
            {
                suf = false;
                break;
            }
        }
        if (pre == false && suf == false)
            return "-";
        if (pre)
        {
            ans += 'P';
            st[cur.size()] = 'P';
        }
        else
        {
            ans += 'S';
            st[cur.size()] = 'S';
        }
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    int cnt = 2 * n - 2;
    vector<string> vs(cnt + 10);
    string a = "", b = "";
    for (int i = 1; i <= cnt; i++)
    {
        cin >> vs[i];
        if (vs[i].size() == n - 1)
        {
            if (a == "")
                a = vs[i];
            else
                b = vs[i];
        }
    }
    if (n == 2)
    {
        cout << "PS" << endl;
        return;
    }
    // cout << a << ' ' << b << endl;
    if (a[0] == b[1])
    {
        string s = b[0] + a;
        string ans = calc(vs, cnt, s);
        // cout << s << endl;
        if (ans != "-")
        {
            cout << ans << endl;
            return;
        }
    }
    if (b[0] == a[1])
    {
        string s = a[0] + b;
        string ans = calc(vs, cnt, s);
        // cout << s << endl;
        if (ans != "-")
        {
            cout << ans << endl;
            return;
        }
    }
    // assert(0);
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