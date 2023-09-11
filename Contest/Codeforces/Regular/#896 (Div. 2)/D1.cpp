#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

pair<int, int> bin_split(int x)
{
    int start = -1;
    int t = x, digit = 0;
    while (t)
    {
        digit++;
        t /= 2;
    }
    for (int i = 0; i < digit; i++)
    {
        if (start == -1 && (x >> i & 1) == 1)
            start = i;
        else if (start != -1 && (x >> i & 1) == 0)
            return {-1, -1};
    }
    return {start, digit};
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 10);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int sum = accumulate(a.begin() + 1, a.begin() + 1 + n, 0LL);
    if (sum % n)
    {
        cout << "No" << endl;
        return;
    }
    int mean = sum / n;
    vector<int> remain(40);
    int same = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] == mean)
            same++;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == mean)
            continue;
        int delta = abs(a[i] - mean);
        auto splt = bin_split(delta);
        if (splt.first == -1)
        {
            cout << "No" << endl;
            return;
        }
        if (a[i] > mean)
        {
            remain[splt.first]--;
            remain[splt.second]++;
        }
        else
        {
            remain[splt.first]++;
            remain[splt.second]--;
        }
    }
    for (int i = 0; i < remain.size(); i++)
    {
        if (remain[i])
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
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