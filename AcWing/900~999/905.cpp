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
        area.push_back({b, a});
    }
    sort(area.begin(), area.end());
    int ans = 0, r = INT32_MIN;
    for (auto p : area)
    {
        if (p.second > r)
        {
            ans++;
            r = p.first;
        }
    }
    cout << ans << endl;
    return 0;
}