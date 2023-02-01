#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n, s, r;
    cin >> n >> s >> r;
    int vmax = s - r;
    cout << vmax << ' ';
    int base = r / (n - 1), extra = r - base * (n - 1);
    for (int i = 0; i < extra; i++)
        cout << base + 1 << ' ';
    for (int i = 0; i < n - 1 - extra; i++)
        cout << base << ' ';
    cout << endl;
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