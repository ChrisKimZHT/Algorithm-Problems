#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 1e6 + 10;
int ans[MAXN];
void init()
{
    ans[1] = 1;
    int now_dig = 1;
    for (int i = 2; i <= MAXN; i++)
    {
        if (i >= now_dig * 10)
            now_dig *= 10;
        if (!(i % now_dig))
            ans[i] = ans[i - 1] + 1;
        else
            ans[i] = ans[i - 1];
    }
}

void solve()
{
    int n;
    cin >> n;
    cout << ans[n] << endl;
}

int main()
{
    init();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}