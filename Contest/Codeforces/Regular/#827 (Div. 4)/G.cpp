#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<bool> vis(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int pre = 0, tmp = 0;
    for (int i = 0; i < n; i++)
    {
        int idx = -1;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && tmp < (pre | a[j]))
            {
                tmp = (pre | a[j]);
                idx = j;
            }
        }
        if (idx == -1)
            break;
        pre = tmp;
        cout << a[idx] << ' ';
        vis[idx] = true;
    }
    for (int i = 0; i < n; i++)
        if (!vis[i])
            cout << a[i] << ' ';
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