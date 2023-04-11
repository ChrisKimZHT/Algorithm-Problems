#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int a, b, n;
    cin >> a >> b >> n;
    vector<int> v{a, b};
    int cur = 0;
    while (v.size() < n)
    {
        int t = v[cur] * v[cur + 1];
        if (t < 10)
        {
            v.push_back(t);
        }
        else
        {
            v.push_back(t / 10);
            v.push_back(t % 10);
        }
        cur++;
    }
    for (int i = 0; i < n; i++)
        cout << v[i] << " \n"[i == n - 1];
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}