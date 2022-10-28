#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
char s[MAXN] = {'0'};

void solve()
{
    int n;
    cin >> n;
    cin >> s + 1;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (s[i] != s[i - 1])
            cnt++;
    cout << max(0, cnt - 1) << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}