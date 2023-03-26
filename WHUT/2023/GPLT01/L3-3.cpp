#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<pair<long long, long long>> points(n);
    for (auto &ele : points)
        cin >> ele.first >> ele.second;
    long double ans = DBL_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                long double a = sqrt(1.0L * (points[i].first - points[j].first) * (points[i].first - points[j].first) +
                                     (points[i].second - points[j].second) * (points[i].second - points[j].second));
                long double b = sqrt(1.0L * (points[i].first - points[k].first) * (points[i].first - points[k].first) +
                                     (points[i].second - points[k].second) * (points[i].second - points[k].second));
                long double c = sqrt(1.0L * (points[j].first - points[k].first) * (points[j].first - points[k].first) +
                                     (points[j].second - points[k].second) * (points[j].second - points[k].second));
                long double p = (a + b + c) / 2;
                long double s = sqrt(p * (p - a) * (p - b) * (p - c));
                ans = min(ans, s);
            }
        }
    }
    cout << fixed << setprecision(3) << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}