#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int len = 2 * n + 2;
    vector<int> a(len);
    for (int i = 0; i < len; i++)
        cin >> a[i];
    bool now = true;
    cout << 'a';
    for (int i = 3; i < len - 2; i += 2)
    {
        if (a[i] == 1)
        {
            now = !now;
        }
        cout << (now ? 'a' : 'b');
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}

/*
5
1 1 2 1 4 1 2 3 4 3 2 1
 */