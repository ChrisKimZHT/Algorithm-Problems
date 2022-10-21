#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    bool have_one = false;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        if (t)
            have_one = true;
    }
    if (have_one)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}