#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e4 + 10;
int N;
pair<int, int> WS[MAXN];

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first + a.second < b.first + b.second;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> WS[i].first >> WS[i].second;
    sort(WS, WS + N, cmp);
    long long sumw = 0, ans = INT32_MIN;
    for (int i = 0; i < N; i++)
    {
        ans = max(ans, sumw - WS[i].second);
        sumw += WS[i].first;
    }
    cout << ans << endl;
    return 0;
}