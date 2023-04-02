#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return 1.0 * a.second / a.first > 1.0 * b.second / b.first;
}

void solve()
{
    int N, D;
    cin >> N >> D;
    vector<pair<double, double>> vw(N);
    for (int i = 0; i < N; i++)
        cin >> vw[i].first;
    for (int i = 0; i < N; i++)
        cin >> vw[i].second;
    sort(vw.begin(), vw.end(), cmp);
    double val = 0;
    for (int i = 0; i < N; i++)
    {
        if (D >= vw[i].first)
        {
            val += vw[i].second;
            D -= vw[i].first;
        }
        else
        {
            val += 1.0 * vw[i].second / vw[i].first * D;
            break;
        }
    }
    cout << fixed << setprecision(2) << val << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}