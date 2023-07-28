#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string t;
    cin >> t;
    string all0(n, '0'), all1(n, '1');
    string try0 = t + all0 + t;
    if (try0.find(t, 1) == try0.size() - t.size())
    {
        cout << all0 << endl;
        return;
    }
    string try1 = t + all1 + t;
    if (try1.find(t, 1) == try1.size() - t.size())
    {
        cout << all1 << endl;
        return;
    }
    cout << -1 << endl;
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