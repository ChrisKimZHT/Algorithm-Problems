/* 
 * 典型错解 
 * Typical Wrong Solution
 */

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
    int pos = 0;
    while (pos < n && a[pos] == 1)
        pos++;
    int x2 = 2, x3 = 1;
    for (int i = pos; i < n; i++)
    {
        if (h > a[i])
        {
            h += a[i] / 2;
            continue;
        }
        if (x2 > 0 && h * 2 > a[i])
        {
            x2--;
            h = h * 2 + a[i] / 2;
            continue;
        }
        if (x3 > 0 && h * 3 > a[i])
        {
            x3--;
            h = h * 3 + a[i] / 2;
            continue;
        }
        if (x2 > 1 && h * 4 > a[i])
        {
            x2 -= 2;
            h = h * 4 + a[i] / 2;
            continue;
        }
        if (x2 > 0 && x3 > 0 && h * 6 > a[i])
        {
            x2--;
            x3--;
            h = h * 6 + a[i] / 2;
            continue;
        }
        if (x2 > 1 && x3 > 0 && h * 12 > a[i])
        {
            x2 -= 2;
            x3--;
            h = h * 12 + a[i] / 2;
            continue;
        }
        cout << i << endl;
        return;
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