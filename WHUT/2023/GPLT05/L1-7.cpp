#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<bool>> st(N, vector<bool>(M, false));
    while (Q--)
    {
        int T, C;
        cin >> T >> C;
        C--;
        if (T == 0)
        {
            for (int i = 0; i < M; i++)
                st[C][i] = true;
        }
        else
        {
            for (int i = 0; i < N; i++)
                st[i][C] = true;
        }
    }
    int cnt = 0;
    for (auto &row : st)
        for (auto col : row)
            if (col == false)
                cnt++;
    cout << cnt << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
