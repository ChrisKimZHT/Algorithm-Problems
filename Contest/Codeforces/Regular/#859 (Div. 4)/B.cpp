#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> odd, even;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if (t & 1)
            odd.push_back(t);
        else
            even.push_back(t);
    }
    int sum_odd = accumulate(odd.begin(), odd.end(), 0);
    int sum_even = accumulate(even.begin(), even.end(), 0);
    if (sum_even <= sum_odd)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}