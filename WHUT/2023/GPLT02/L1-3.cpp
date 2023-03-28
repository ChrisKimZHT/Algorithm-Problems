#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int D;
    cin>>D;
    cout << (D - 1 + 2) % 7 + 1 << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}