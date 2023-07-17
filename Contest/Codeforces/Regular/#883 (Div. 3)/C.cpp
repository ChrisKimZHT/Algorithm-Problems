#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

struct Team
{
    int id;
    int point;
    int penalty;
};

bool cmp(Team a, Team b)
{
    if (a.point != b.point)
        return a.point > b.point;
    if (a.penalty != b.penalty)
        return a.penalty < b.penalty;
    return a.id < b.id;
}

void solve()
{
    int n, m, h;
    cin >> n >> m >> h;
    vector<Team> team;
    for (int i = 0; i < n; i++)
    {
        vector<int> time(m);
        for (int j = 0; j < m; j++)
            cin >> time[j];
        sort(time.begin(), time.end());
        int point = 0, pena = 0, sum = 0;
        for (int j = 0; j < m; j++)
        {
            sum += time[j];
            if (sum > h)
                break;
            pena += sum;
            point++;
        }
        team.push_back({i, point, pena});
    }
    sort(team.begin(), team.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        if (team[i].id == 0)
        {
            cout << i + 1 << endl;
            return;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}