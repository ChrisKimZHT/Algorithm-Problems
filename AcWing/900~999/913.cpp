#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pque;

signed main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        pque.push(t);
    }
    int ans = 0;
    while (pque.size())
    {
        ans += pque.top() * (pque.size() - 1);
        pque.pop();
    }
    cout << ans << endl;
    return 0;
}