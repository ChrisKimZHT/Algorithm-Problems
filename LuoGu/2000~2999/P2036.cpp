#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> sb(n);
    for (int i = 0; i < n; i++)
        cin >> sb[i].first >> sb[i].second;
    int ans = INT32_MAX;
    for (int i = 1; i < 1 << n; i++)
    {
        int s = 1, b = 0;
        for (int j = 0; j < n; j++)
        {
            if (i >> j & 1)
            {
                s *= sb[j].first;
                b += sb[j].second;
            }
        }
        ans = min(ans, abs(s - b));
    }
    cout << ans << endl;
    return 0;
}