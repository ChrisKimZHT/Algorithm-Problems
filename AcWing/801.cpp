#include <bits/stdc++.h>

using namespace std;

// 直接使用内置函数的解法
/* int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int t;
        cin >> t;
        cout << __builtin_popcount(t) << ' ';
    }
    cout << endl;
    return 0;
} */

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int t;
        cin >> t;
        int ans = 0;
        while (t)
        {
            t -= t & -t;
            ans++;
        }
        cout << ans << ' ';
    }
    cout << endl;
    return 0;
}