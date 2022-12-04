#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> e(n);
    for (int i = 0; i < n; i++)
    {
        int x, w;
        cin >> x >> w;
        e[i] = {x - w, x + w};
    }
    sort(e.begin(), e.end());
    int ans = 0, tail = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        if (tail <= e[i].first)
        {
            tail = e[i].second;
            ans++;
        }
        else if (tail > e[i].second)
        {
            tail = e[i].second;
        }
    }
    cout << ans << endl;
    return 0;
}