#include <bits/stdc++.h>

using namespace std;

int main()
{
    const int MAXN = 3e5 + 10;
    int n, m;
    cin >> n >> m;
    vector<int> alls;
    vector<pair<int, int>> ins, qry;
    vector<int> ori(MAXN, 0), ps(MAXN, 0);
    for (int i = 0; i < n; i++)
    {
        int x, c;
        cin >> x >> c;
        ins.push_back({x, c});
        alls.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        qry.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    for (auto item : ins)
        ori[lower_bound(alls.begin(), alls.end(), item.first) - alls.begin()] += item.second;
    ps[0] = ori[0];
    for (int i = 1; i < alls.size(); i++)
        ps[i] = ori[i] + ps[i - 1];
    for (auto item : qry)
        cout << ps[lower_bound(alls.begin(), alls.end(), item.second) - alls.begin()] - ps[lower_bound(alls.begin(), alls.end(), item.first) - alls.begin() - 1] << endl;
    return 0;
}