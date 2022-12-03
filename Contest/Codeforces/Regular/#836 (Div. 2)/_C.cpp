#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    if (n % x)
    {
        cout << -1 << endl;
        return;
    }
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
        p[i] = i;
    p[1] = x;
    p[n] = 1;
    while (x < n)
    {
        for (int i = x * 2; i <= n; i += x)
        {
            if (n % i == 0)
            {
                p[x] = i;
                x = i;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << p[i] << ' ';
    cout << endl;
    return;
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