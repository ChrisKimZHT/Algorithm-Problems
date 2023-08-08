#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> b(n + 10), pxor(n + 10);
    for (int i = 1; i < n; i++)
    {
        cin >> b[i];
        pxor[i] = pxor[i - 1] ^ b[i];
    }
    vector<int> a1_digit(30, -1);
    for (int i = 1; i < n; i++)
    {
        for (int j = 29; j >= 0; j--)
        {
            int digit_1 = pxor[i - 1] >> j & 1;
            int digit_2 = pxor[i] >> j & 1;
            if (digit_1 != digit_2)
            {
                if (a1_digit[j] == -1)
                {
                    a1_digit[j] = digit_1;
                }
                else if (a1_digit[j] != digit_1)
                {
                    cout << -1 << endl;
                    return;
                }
                break;
            }
        }
    }
    k--;
    for (int i = 0; i <= 29; i++)
    {
        if (a1_digit[i] == -1)
        {
            a1_digit[i] = k & 1;
            k >>= 1;
        }
    }
    if (k)
    {
        cout << -1 << endl;
        return;
    }
    int a1 = 0;
    for (int i = 29; i >= 0; i--)
    {
        a1 = (a1 << 1) + a1_digit[i];
    }
    cout << a1 << ' ';
    for (int i = 1; i < n; i++)
    {
        a1 ^= b[i];
        cout << a1 << ' ';
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}