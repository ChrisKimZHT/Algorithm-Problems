#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef long long ll;

void solve()
{
    ll N;
    cin >> N;
    for (ll i = 2; i * i * i <= N; i++)
    {
        if (N % i)
            continue;
        if (!((N / i) % i))
        {
            cout << i << ' ' << N / i / i << endl;
            return;
        }
        else
        {
            cout << (ll)round(sqrt(N / i)) << ' ' << i << endl;
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}