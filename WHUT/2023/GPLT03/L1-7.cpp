#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int N, M;
    cin >> N >> M;
    while (M--)
    {
        string s;
        cin >> s;
        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            if (s[i] == 'n')
                ans = ans * 2 + 1;
            else
                ans = ans * 2;
        }
        cout << ans + 1 << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}