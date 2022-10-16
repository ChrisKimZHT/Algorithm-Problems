#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    int sum, odd_cnt, even_cnt, odd_add, even_add;
    sum = odd_cnt = even_cnt = odd_add = even_add = 0;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        sum += num;
        if (num % 2)
            odd_cnt++;
        else
            even_cnt++;
    }
    for (int i = 0; i < q; i++)
    {
        int t, x;
        cin >> t >> x;
        if (t) // odd
        {
            sum += x * odd_cnt;
            if (x % 2) // odd
            {
                even_cnt += odd_cnt;
                odd_cnt = 0;
            }
        }
        else // even
        {
            sum += x * even_cnt;
            if (x % 2) // odd
            {
                odd_cnt += even_cnt;
                even_cnt = 0;
            }
        }
        cout << sum << endl;
    }
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}