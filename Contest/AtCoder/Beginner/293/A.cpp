#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string S;
    cin >> S;
    for (int i = 0; i < S.size(); i += 2)
        swap(S[i], S[i + 1]);
    cout << S << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}