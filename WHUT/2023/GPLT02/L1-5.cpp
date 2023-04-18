#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int A, B;
    cin >> A >> B;
    int ans = A * B;
    string out = to_string(ans);
    reverse(out.begin(), out.end());
    int out_int = stoi(out);
    cout << out_int << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}