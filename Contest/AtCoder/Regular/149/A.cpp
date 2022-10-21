#include <bits/stdc++.h>

using namespace std;

int N, M;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    pair<int, int> ans = {0, 0};
    for (int i = 9; i > 0; i--)
    {
        int r = 0, len = 0;
        for (int j = 1; j <= N; j++)
        {
            r = r * 10 + i;
            r %= M;
            if (!r)
                len = max(len, j);
        }
        ans = max(ans, {len, i});
    }
    if (ans.first && ans.second)
    {
        for (int i = 0; i < ans.first; i++)
            cout << ans.second;
        cout << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}