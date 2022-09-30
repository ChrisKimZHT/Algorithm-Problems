#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110;
int N, T;
vector<pair<int, int>> coin;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return 1.0 * a.second / a.first > 1.0 * b.second / b.first;
}

int main()
{
    cin >> N >> T;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        coin.push_back({a, b});
    }
    sort(coin.begin(), coin.end(), cmp);
    // for (auto i : coin)
    //     cout << i.first << ' ' << i.second << endl;
    int remain = T;
    double ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (remain - coin[i].first >= 0)
        {
            ans += coin[i].second;
            remain -= coin[i].first;
        }
        else
        {
            ans += 1.0 * coin[i].second * remain / coin[i].first;
            break;
        }
    }
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}