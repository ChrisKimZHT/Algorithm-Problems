#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

bool cmp(pair<vector<int>, int> a, pair<vector<int>, int> b)
{
    if (a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}

void solve()
{
    int N, M;
    cin >> N >> M;
    map<vector<int>, int> cnt;
    for (int i = 0; i < N; i++)
    {
        vector<int> v;
        for (int j = 0; j < M; j++)
        {
            int t;
            cin >> t;
            v.push_back(t);
        }
        cnt[v]++;
    }
    vector<pair<vector<int>, int>> data;
    for (auto ele : cnt)
        data.push_back(ele);
    sort(data.begin(), data.end(), cmp);
    cout << data.size() << endl;
    for (auto ele : data)
    {
        cout << ele.second << ' ';
        for (int i = 0; i < ele.first.size(); i++)
            cout << ele.first[i] << " \n"[i == ele.first.size() - 1];
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