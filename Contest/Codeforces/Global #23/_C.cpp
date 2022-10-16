#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> inv;
    for (int i = 1; i < n; i++)
        if (a[i] > a[i + 1])
            inv.push({a[i] - a[i + 1], i + 1});
    for (int i = 1; i <= n; i++)
    {
        if (!inv.size())
        {
            cout << '1' << ' ';
            continue;
        }
        pair<int, int> t = inv.top();
        if (t.first > i)
        {
            inv.pop();
            cout << t.second << ' ';
            inv.push({t.first - i, t.second});
        }
        else
        {
            inv.pop();
            cout << t.second << ' ';
        }
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}