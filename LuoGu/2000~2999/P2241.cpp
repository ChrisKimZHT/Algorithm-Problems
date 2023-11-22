#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    if (m > n)
        swap(n, m);
    long long sq = 0, rc = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (i == j)
                sq += 1LL * (n + 1 - i) * (m + 1 - j);
            else
                rc += 1LL * (n + 1 - i) * (m + 1 - j);
    cout << sq << ' ' << rc << endl;
    return 0;
}