#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(k + 1);
    for (int i = 1; i <= k; i++)
        cin >> a[i];
    reverse(a.begin() + 1, a.end());
    set<int> s;
    int now = 1;
    for (int i = 1; i <= k; i++)
    {
        for (; now <= k; now++)
        {
            if (s.find(a[i]) == s.end())
                s.insert(now);
            else
                break;
        }
        if (s.size() >= n * m - 2)
        {
            cout << "TIDAK" << endl;
            return;
        }
        s.erase(a[i]);
    }
    cout << "YA" << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}