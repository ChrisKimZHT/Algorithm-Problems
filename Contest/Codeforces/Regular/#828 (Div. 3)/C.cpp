#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    char c;
    string s;
    cin >> n >> c;
    cin >> s;
    vector<int> d(n + 1, 0);
    int fir_g = 0;
    while (fir_g < n && s[fir_g] != 'g')
        fir_g++;
    for (int i = fir_g, t = 0; i >= 0; i--, t++)
        d[i] = t;
    d[n] = d[0];
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == 'g')
            d[i] = 0;
        else
            d[i] = d[i + 1] + 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == c)
            ans = max(ans, d[i]);
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}