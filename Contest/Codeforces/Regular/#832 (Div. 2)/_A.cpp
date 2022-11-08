#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        long long t;
        cin >> t;
        ans += t;
    }
    cout << abs(ans) << endl;
}

int main()
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