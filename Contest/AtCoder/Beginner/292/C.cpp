#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll get_cnt(ll x)
{
    ll cnt = 0;
    for (int i = 1; i * i <= x; i++)
    {
        if (!(x % i))
        {
            cnt += 2;
            if (i * i == x)
                cnt--;
        }
    }
    return cnt;
}

void solve()
{
    ll N;
    cin >> N;
    ll ans = 0;
    for (int i = 1; i * 2 <= N; i++)
    {
        ll tmp = get_cnt(i) * get_cnt(N - i);
        ans += 2 * tmp;
        if (i * 2 == N)
            ans -= tmp;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}