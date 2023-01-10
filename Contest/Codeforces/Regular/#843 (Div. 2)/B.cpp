#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> bit(n);
    map<int, int> cnt_bit;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int t;
            cin >> t;
            bit[i].push_back(t);
            cnt_bit[t]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int j = 0; j < bit[i].size(); j++)
        {
            if (cnt_bit[bit[i][j]] == 1)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}