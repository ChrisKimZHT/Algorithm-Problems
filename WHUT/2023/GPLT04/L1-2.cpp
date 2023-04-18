#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int N, K, M;
    cin >> N >> K >> M;
    cout << max(0, N - K * M) << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}