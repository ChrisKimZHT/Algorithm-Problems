#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, l;
    cin >> n >> l;
    vector<pair<int, int>> gm;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        gm.push_back({x, y});
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int a = gm[i].first, b = gm[j].second;
            int cnt = 0;
            for (int k = 0; k < n; k++)
            {
                int x = gm[k].first, y = gm[k].second;
                if (a <= x && x <= a + l && b <= y && y <= b + l)
                    cnt++;
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
    return 0;
}