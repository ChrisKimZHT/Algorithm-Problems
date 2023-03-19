#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const string msg[5] = {"Kill", "Double Kill", "Triple Kill", "Quadra Kill", "Penta Kill"};

void solve()
{
    int n;
    cin >> n;
    vector<pair<pair<int, int>, char>> v(n);
    char _;
    for (int i = 0; i < n; i++)
        cin >> v[i].first.first >> _ >> v[i].first.second >> v[i].second;
    sort(v.begin(), v.end());
    int last = -100, strike = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i].second == 'D' || v[i].second == 'A')
            continue;
        int now = v[i].first.first * 60 + v[i].first.second;
        if (now - last <= 10)
            strike++;
        else
            strike = 0;
        if (v[i].first.first < 10)
            cout << 0;
        cout << v[i].first.first;
        cout << ':';
        if (v[i].first.second < 10)
            cout << 0;
        cout << v[i].first.second;
        cout << ' ';
        cout << msg[min(strike, 4)] << endl;
        last = now;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}