#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        long long ans = 1;
        while (n--)
        {
            int t;
            cin >> t;
            if (t % 2)
                ans *= t;
        }
        cout << ans << endl;
    }
    return 0;
}