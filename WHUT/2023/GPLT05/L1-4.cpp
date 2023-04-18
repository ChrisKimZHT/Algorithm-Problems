#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;
    int c = a + b;
    long long ans = 1LL;
    for (int i = 2; i <= c; i++)
        ans *= i;
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
