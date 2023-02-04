#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int calc(int num, int times)
{
    int last = num;
    for (int i = 0; i < times; i++)
    {
        int now = 0;
        while (last)
        {
            now += last % 10;
            last /= 10;
        }
        if (now < 10)
            return now;
        last = now;
    }
    return last;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 10);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> ftree(n + 10);
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, r;
            cin >> l >> r;
            for (int i = l; i <= n; i += i & -i)
                ftree[i] += 1;
            for (int i = r + 1; i <= n; i += i & -i)
                ftree[i] -= 1;
        }
        else
        {
            int x;
            cin >> x;
            int ans = 0;
            for (int i = x; i; i -= i & -i)
                ans += ftree[i];
            cout << calc(a[x], ans) << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}