#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b)
{
    if (a.first != b.first)
        return a.first > b.first;
    return a.second < b.second;
}

void solve()
{
    int N, G, K;
    cin >> N >> G >> K;
    vector<pair<int, string>> data(N);
    for (int i = 0; i < N; i++)
        cin >> data[i].second >> data[i].first;
    sort(data.begin(), data.end(), cmp);
    int value = 0;
    for (int i = 0; i < N; i++)
    {
        if (G <= data[i].first &&
            data[i].first <= 100)
            value += 50;
        else if (60 <= data[i].first &&
                 data[i].first < G)
            value += 20;
    }
    cout << value << endl;
    int last = -1, num = -1;
    for (int i = 0; i < N; i++)
    {
        int id;
        if (last == data[i].first)
            id = num;
        else
            id = num = i + 1;
        if (id > K)
            break;
        last = data[i].first;
        cout << id << ' ' << data[i].second << ' ' << data[i].first << endl;
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