#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    vector<bool> st(n);
    for (int i = 0; i < n; i++)
    {
        if (i + k < n)
        {
            st[i] = true;
            st[i + k] = true;
        }
        if (i + k + 1 < n)
        {
            st[i + k + 1] = true;
        }
    }
    vector<int> cnt_s(26), cnt_t(26);
    for (int i = 0; i < n; i++)
    {
        if (st[i])
        {
            cnt_s[s[i] - 'a']++;
            cnt_t[t[i] - 'a']++;
        }
        else if (s[i] != t[i])
        {
            cout << "No" << endl;
            return;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (cnt_s[i] != cnt_t[i])
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}