#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int x2 = 2, x3 = 1;
    for (int i = 0; i < n; i++)
    {
        if (h > a[i])
        {
            h += a[i] / 2;
        }
        else
        {
            if (x2 > 0)
            {
                h *= 2;
                x2--;
            }
            if (h > a[i])
            {
                h += a[i] / 2;
                continue;
            }
            if (x3 > 0)
            {
                h *= 3;
                x3--;
            }
            if (h > a[i])
            {
                h += a[i] / 2;
                continue;
            }
            if (x2 > 0)
            {
                h *= 2;
                x2--;
            }
            if (h > a[i])
            {
                h += a[i] / 2;
                continue;
            }
            cout << i << endl;
            return;
        }
    }
    cout << n << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}