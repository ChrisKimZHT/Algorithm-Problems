#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 5e5 + 10;
int N;
int a[MAXN];

signed main()
{
    cin >> N;
    int same = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
        if (a[i] == i)
            same++;
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (a[i] != i && a[a[i]] == i)
            ans++;
    }
    ans /= 2;
    ans += same * (same - 1) / 2;
    cout << ans << endl;
    return 0;
}