#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int N;
    cin >> N;
    vector<int> T(N + 10);
    T[0] = INT32_MIN;
    for (int i = 1; i <= N; i++)
        cin >> T[i];
    vector<int> pre(N + 10), suf(N + 10);
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < i; j++)
            if (T[j] < T[i])
                pre[i] = max(pre[i], pre[j] + 1);
    for (int i = N; i >= 1; i--)
        for (int j = N; j >= i; j--)
            if (T[j] < T[i])
                suf[i] = max(suf[i], suf[j] + 1);
    int res = 0;
    for (int i = 1; i <= N; i++)
        res = max(res, pre[i] + suf[i]);
    cout << N - res << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}