#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> p(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i].first >> p[i].second;
    sort(p.begin() + 1, p.end(), cmp);
    int k = m * 3 / 2, t = p[k].second;
    while (p[k + 1].second >= t)
        k++;
    cout << t << ' ' << k << endl;
    for (int i = 1; i <= k; i++)
        cout << p[i].first << ' ' << p[i].second << endl;
    return 0;
}