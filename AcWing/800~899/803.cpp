#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int n;
vector<pair<int, int>> area;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        area.push_back({l, r});
    }
    sort(area.begin(), area.end());
    int ans = 0, l = INT32_MIN, r = INT32_MIN;
    for (auto item : area)
    {
        if (item.first <= r)
        {
            r = max(r, item.second);
        }
        else
        {
            l = item.first;
            r = item.second;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}