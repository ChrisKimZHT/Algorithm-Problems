#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> area;
    priority_queue<int, vector<int>, greater<int>> lft;
    while (N--)
    {
        int a, b;
        cin >> a >> b;
        area.push_back({a, b});
    }
    sort(area.begin(), area.end());
    lft.push(INT32_MIN);
    int ans = 1;
    for (auto p : area)
    {
        if (lft.top() < p.first)
        {
            lft.pop();
            lft.push(p.second);
        }
        else
        {
            ans++;
            lft.push(p.second);
        }
    }
    cout << ans << endl;
    return 0;
}