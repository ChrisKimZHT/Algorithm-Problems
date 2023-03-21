#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int N;
    cin >> N;
    vector<int> A(N + 1);
    vector<bool> st(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        if (!st[i])
            st[A[i]] = true;
    }
    vector<int> ans;
    for (int i = 1; i <= N; i++)
        if (!st[i])
            ans.push_back(i);
    cout << ans.size() << endl;
    for (auto ele : ans)
        cout << ele << ' ';
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}