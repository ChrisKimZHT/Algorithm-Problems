#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const string PI = "31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";

void solve(int t)
{
    int ans = 1;
    for (int i = 0; i < (PI[t] - '0'); i++)
    {
        int n;
        cin >> n;
        ans *= n;
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve(i);
    return 0;
}