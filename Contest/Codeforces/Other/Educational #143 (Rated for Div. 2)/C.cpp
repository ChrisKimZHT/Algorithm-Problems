#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n + 10), b(n + 10);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    vector<ll> pb(n + 10);
    for (int i = 1; i <= n; i++)
        pb[i] = pb[i - 1] + b[i];
    vector<ll> remain(n + 10);
    vector<int> cnt(n + 10);
    for (int i = 1; i <= n; i++)
    {
        int pos = upper_bound(pb.begin() + 1, pb.begin() + 1 + n, a[i] + pb[i - 1]) - pb.begin();
        cnt[i] += 1;
        cnt[pos] -= 1;
        remain[pos] += a[i] + pb[i - 1] - pb[pos - 1];
    }
    for (int i = 1; i <= n; i++)
        cnt[i] += cnt[i - 1];
    for (int i = 1; i <= n; i++)
        cout << b[i] * cnt[i] + remain[i] << ' ';
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