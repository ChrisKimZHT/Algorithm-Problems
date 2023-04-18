#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int N, M;
    cin >> N >> M;
    while (N--)
    {
        double p;
        cin >> p;
        if (p < M)
            cout << "On Sale! " << fixed << setprecision(1) << p << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}