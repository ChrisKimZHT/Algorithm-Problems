#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int MAXN = 1e5 + 10;
int arr[MAXN];

void rev(int l, int r)
{
    if (l == r)
        return;
    for (int i = l, j = r; i < j; i++, j--)
        swap(arr[i], arr[j]);
    int mid = (l + r) / 2;
    rev(l, mid);
    rev(mid + 1, r);
}

void solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    for (int i = 1; i <= n; i++)
        arr[i] = i;
    rev(1, n);
    int ans = 0;
    for (int i = l; i <= r; i++)
        ans += arr[i];
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}