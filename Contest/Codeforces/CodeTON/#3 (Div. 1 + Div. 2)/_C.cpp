#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    bool is_same = true, is_oppo = true;
    for (int i = 0; i < n && is_same; i++)
        if (a[i] != b[i])
            is_same = false;
    if (is_same)
        is_oppo = false;
    for (int i = 0; i < n && is_oppo; i++)
        if (a[i] != '0' + '1' - b[i])
            is_oppo = false;
    if (!is_same && !is_oppo)
    {
        cout << "NO" << endl;
        return;
    }
    bool st = is_oppo;
    cout << "YES" << endl;
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == '0')
        {
            int j = i;
            while (j < n && a[j] == '0')
                j++;
            j--;
            ans.push_back({i, j});
            st = !st;
            i = j;
        }
    }
    if (st)
    {
        ans.push_back({0, n - 1});
    }
    else
    {
        ans.push_back({0, 0});
        ans.push_back({1, n - 1});
    }
    cout << ans.size() << endl;
    for (auto &p : ans)
        cout << p.first + 1 << ' ' << p.second + 1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}