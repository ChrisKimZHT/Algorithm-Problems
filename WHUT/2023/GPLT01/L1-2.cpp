#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int L, N;
    cin >> L >> N;
    N--;
    vector<int> ans;
    while (N)
    {
        ans.push_back(N % 26);
        N /= 26;
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < L - ans.size(); i++)
        cout << 'z';
    for (int i = 0; i < ans.size(); i++)
        cout << char('z' - ans[i]);
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