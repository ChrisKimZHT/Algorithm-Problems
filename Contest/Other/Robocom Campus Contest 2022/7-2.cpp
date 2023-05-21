#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int n;
int a[MAXN];

int energy(int inc)
{
    int ans = a[0] + inc;
    for (int i = 1; i < n; i++)
        ans = __gcd(ans, a[i] + inc);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans, anse = 0;
    for (int n = 0; n < 1000; n++)
    {
        if (energy(n) > anse)
        {
            ans = n;
            anse = energy(n);
        }
    }
    cout << energy(ans) << ' ' << ans << endl;
    return 0;
}