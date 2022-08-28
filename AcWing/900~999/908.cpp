#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> area;
    while (N--)
    {
        int a, b;
        cin >> a >> b;
        area.push_back({a, b});
    }
    sort(area.begin(), area.end());
    int ans = 0, l = INT32_MIN, r = INT32_MIN;
    for (auto p : area)
    {
        if (p.first > r)
        {
            ans++;
            l = p.first;
            r = p.second;
        }
        else
            r = min(r, p.second);
    }
    cout << ans << endl;
    return 0;
}