#include <iostream>
#include <cstring>
#define endl '\n'

using namespace std;

typedef long long ll;
const int MAXN = 1e6 + 10, MOD = 1e9;
ll ans[MAXN];

int main()
{
    memset(ans, -1, sizeof(ans));
    ans[0] = ans[1] = 1;
    ans[2] = 2;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll N;
    cin >> N;
    for (int i = 3; i <= N; i++)
    {
        if (i & 1)
            ans[i] = ans[i - 1];
        else
            ans[i] = (ans[i - 2] + ans[i / 2]) % MOD;
    }
    cout << ans[N] << endl;
    return 0;
}