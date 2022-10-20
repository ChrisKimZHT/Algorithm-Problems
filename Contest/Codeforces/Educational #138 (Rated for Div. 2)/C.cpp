#include <bits/stdc++.h>

using namespace std;

bool check(int x, vector<int> q)
{
    for (int i = x; i > 0; i--)
    {
        while (q.size() && q.back() > i)
            q.pop_back();
        if (!q.size())
            return false;
        q.pop_back();
        if (q.size())
            q.erase(q.begin());
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int l = 0, r = 100;
    while (l < r)
    {
        int mid = (l + r + 1) / 2;
        if (check(mid, a))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}