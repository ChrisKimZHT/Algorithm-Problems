#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 10);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int pre = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] == i)
            pre++;
    int gap = 0, pos = -1;
    vector<int> pg;
    for (int i = 1, now = 1; i <= n; i++)
    {
        if (a[i] != now)
        {
            gap++;
            pg.push_back(i);
            if (gap == pre)
                pos = i;
            i--;
        }
        now++;
    }
    // coFut << pre << ' ' << gap << endl;
    if (pre == gap)
        cout << pre + 1 + (a[n] - pre) * (k - 1) << endl;
    else if (pre > gap)
        cout << pre + 1 + (a[n] - pre + (pre - gap)) * (k - 1) << endl;
    else
    {
        if (pre * k < gap)
        {
            if (pg[pre * k + 1] - pg[pre * k] == 1)
                cout << pg[pre * k] << endl;
            else
                cout << pg[pre * k + 1] << endl;
        }
        else if (pre * k == gap)
        {
            cout << a[n] + 1 << endl;
        }
        else
        {
            int cnt = gap / pre;
            cout << "fuck" << endl;
        }
    }
}

signed main()
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