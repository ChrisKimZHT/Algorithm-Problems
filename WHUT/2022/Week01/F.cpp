#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int ans = 0, t;
        while (n--)
        {
            cin >> t;
            ans += t;
        }
        cout << ans << endl;
    }
    return 0;
}