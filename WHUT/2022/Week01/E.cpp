#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int k;
        cin >> k;
        int ans = 0, t;
        while (k--)
        {
            cin >> t;
            ans += t;
        }
        cout << ans << endl;
    }
    return 0;
}