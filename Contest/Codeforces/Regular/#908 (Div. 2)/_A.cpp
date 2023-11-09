// Problem: A. Secret Sport
// Contest: Codeforces - Codeforces Round 908 (Div. 2)
// URL: https://codeforces.com/contest/1894/problem/A
// Memory Limit: 512 MB
// Time Limit: 3000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ca = 0, cb = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; i * j <= n; j++)
        {
            int a = 0, b = 0;
            int aa = 0, bb = 0;
            for (int k = 0; k < n; k++)
            {
                if (s[k] == 'A')
                    a++;
                else
                    b++;
                if (a == i)
                {
                    a = b = 0;
                    aa++;
                }
                if (b == i)
                {
                    a = b = 0;
                    bb++;
                }
                if (aa == j)
                {
                    if (k == n - 1)
                        ca++;
                    break;
                }
                if (bb == j)
                {
                	if (k == n - 1)
                		cb++;
                	break;
                }
            }
        }
    }
    if (ca && !cb)
    	cout << 'A' << endl;
    else if (!ca && cb)
    	cout << 'B' << endl;
    else
    	cout << '?' << endl;
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