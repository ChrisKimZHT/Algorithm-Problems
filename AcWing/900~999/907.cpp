#include <bits/stdc++.h>

using namespace std;

int main()
{
    int s, t, N;
    cin >> s >> t;
    cin >> N;
    vector<pair<int, int>> area;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        area.push_back({a, b});
    }
    sort(area.begin(), area.end());
    int ans = 0;
    bool flag = false;
    for (int i = 0; i < area.size(); i++)
    {
        int j = i, r = INT32_MIN;
        while (j < N && area[j].first <= s)
        {
            r = max(area[j].second, r);
            j++;
        }
        if (r < s)
            break;
        ans++;
        if (r >= t)
        {
            flag = true;
            break;
        }
        i = j - 1;
        s = r;
    }
    if (flag)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}