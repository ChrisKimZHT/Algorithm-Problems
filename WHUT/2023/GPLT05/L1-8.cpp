#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int N, K, S;
    cin >> N >> K >> S;
    vector<pair<int, int>> v;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a >= 175)
            v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    int cnt = 0, last = -1, same = 1;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].first == last)
        {
            same++;
            if (same <= K)
            {
                cnt++;
            }
            else if (v[i].second >= S)
            {
                cnt++;
            }
        }
        else
        {
            last = v[i].first;
            same = 1;
            cnt++;
        }
    }
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
