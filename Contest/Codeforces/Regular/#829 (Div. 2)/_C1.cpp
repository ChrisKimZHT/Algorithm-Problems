#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt_p1 = 0, cnt_n1 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
            cnt_p1++;
        else
            cnt_n1++;
    }
    if (n % 2)
    {
        cout << -1 << endl;
        return;
    }
    int delta = (cnt_p1 - cnt_n1) / 2;
    vector<pair<int, int>> ans;
    if (delta > 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (!delta)
            {
                ans.push_back({i, i});
                continue;
            }
            if (i < n - 1 && a[i] == 1 && a[i + 1] == 1)
            {
                ans.push_back({i, i + 1});
                delta--;
                i++;
            }
            else if (i < n - 1 && a[i] == -1 && a[i + 1] == 1)
            {
                ans.push_back({i, i + 1});
                delta--;
                i++;
            }
            else
            {
                ans.push_back({i, i});
            }
        }
    }
    else if (delta < 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (!delta)
            {
                ans.push_back({i, i});
                continue;
            }
            if (i < n - 1 && a[i] == -1 && a[i + 1] == -1)
            {
                ans.push_back({i, i + 1});
                delta++;
                i++;
            }
            else if (i < n - 1 && a[i] == 1 && a[i + 1] == -1)
            {
                ans.push_back({i, i + 1});
                delta++;
                i++;
            }
            else
            {
                ans.push_back({i, i});
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
            ans.push_back({i, i});
    }
    if (delta)
    {
        cout << -1 << endl;
        return;
    }
    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i.first + 1 << ' ' << i.second + 1 << endl;
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