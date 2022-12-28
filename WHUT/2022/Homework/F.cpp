#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int N, M;
    cin >> N >> M;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    int awa = a.front();
    sort(a.begin(), a.end());
    int awa_pos;
    for (int i = 0; i < N; i++)
    {
        if (a[i] == awa)
        {
            awa_pos = i;
            break;
        }
    }
    if (N == 1)
    {
        cout << 1 << endl;
        return;
    }
    int ans = min(awa, M - awa + 1);
    if (awa_pos == 0)
        ans = min(ans, M - a[1] + 2);
    else if (awa_pos == N - 1)
        ans = min(ans, a[N - 2] + 1);
    else
        ans = min(ans, max(a[awa_pos - 1], M - a[awa_pos + 1] + 1) + 1);
    int l = awa_pos, r = awa_pos;
    while (l > 0 && a[l - 1] == a[l] - 1)
        l--;
    while (r < N - 1 && a[r + 1] == a[r] + 1)
        r++;
    ans = min(ans, max(a[l], M - a[r] + 1));
    cout << ans << endl;
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