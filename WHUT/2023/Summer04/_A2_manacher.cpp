#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

string pre_process(string &s)
{
    string ans = "^";
    for (auto &c : s)
    {
        ans += '#';
        ans += c;
    }
    ans += '#';
    ans += '$';
    return ans;
}

void manacher(string &s, vector<int> &p)
{
    int r = 0, mid = 0;
    for (int i = 1; i < s.size() - 1; i++)
    {
        p[i] = r > i ? min(p[2 * mid - i], r - i) : 1;
        while (s[i + p[i]] == s[i - p[i]])
            p[i]++;
        if (i + p[i] > r)
        {
            r = i + p[i];
            mid = i;
        }
    }
}

string filter_str(string s)
{
    string ans;
    for (int i = 0; i < s.size(); i++)
        if (s[i] != '#' && s[i] != '^' && s[i] != '$')
            ans += s[i];
    return ans;
}

void solve()
{
    string s;
    cin >> s;
    int l = 0, r = s.size() - 1;
    for (; l < r; l++, r--)
        if (s[l] != s[r])
            break;
    string pre = s.substr(0, l);
    string suf = s.substr(r + 1);
    string str = s.substr(l, r - l + 1);
    string strnew = pre_process(str);
    vector<int> p(strnew.size() + 10);
    manacher(strnew, p);
    int pos_a = 0;
    for (int i = 1; i < strnew.size() - 1; i++)
        if (i - p[i] + 1 == 1)
            pos_a = i;
    string mid_a = filter_str(strnew.substr(0, 2 * pos_a));
    int pos_b = 0;
    for (int i = strnew.size() - 2; i >= 1; i--)
        if (i + p[i] == strnew.size() - 1)
            pos_b = i;
    string mid_b = filter_str(strnew.substr(pos_b - p[pos_b] + 1));
    cout << pre << (mid_a.size() > mid_b.size() ? mid_a : mid_b) << suf << endl;
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