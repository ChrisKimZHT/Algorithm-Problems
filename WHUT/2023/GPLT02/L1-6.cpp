#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

unordered_map<char, int> mp{{'A', '1'}, {'B', '2'}, {'C', '3'}, {'D', '4'}};

void solve()
{
    int N;
    cin >> N;
    string ans;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            string s;
            cin >> s;
            if (s.back() == 'T')
                ans += mp[s.front()];
        }
    }
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