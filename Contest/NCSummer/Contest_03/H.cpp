#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            cout << "No" << endl;
            return;
        }
        for (int i = 2; i * i <= t; i++)
        {
            if (t % i == 0)
            {
                cout << "No" << endl;
                return;
            }
        }
        cout << "Yes" << endl;
        return;
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        sum += t;
    }
    if (sum & 1)
    {
        sum -= 3;
        n -= 1;
    }
    if (n == 1)
    {
        if (sum == 1)
        {
            cout << "No" << endl;
            return;
        }
        for (int i = 2; i * i <= sum; i++)
        {
            if (sum % i == 0)
            {
                cout << "No" << endl;
                return;
            }
        }
        cout << "Yes" << endl;
        return;
    }
    int rem = sum - 2 * (n - 2);
    if (rem < 4)
    {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}