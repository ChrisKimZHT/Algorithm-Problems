#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int N;
    cin >> N;
    vector<int> h(N + 10);
    for (int i = 1; i <= N; i++)
        cin >> h[i];
    h[0] = h[N + 1] = INT32_MIN;
    vector<int> pre(N + 10), suf(N + 10);
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < i; j++)
            if (h[j] < h[i])
                pre[i] = max(pre[i], pre[j] + 1);
    for (int i = N; i >= 1; i--)
        for (int j = N; j >= i; j--)
            if (h[j] < h[i])
                suf[i] = max(suf[i], suf[j] + 1);
    int ans = 0;
    for (int i = 1; i <= N; i++)
        ans = max(ans, pre[i] + suf[i]);
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}