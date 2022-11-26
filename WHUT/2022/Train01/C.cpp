#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 5e4 + 10;
int L, N, M;
int D[MAXN];

bool check(ll x)
{
    ll cnt = 0, now = 0, nxt = 1;
    while (nxt <= N)
    {
        if (D[nxt] - D[now] < x)
            cnt++;
        else
            now = nxt;
        nxt++;
    }
    return cnt <= M;
}

int main()
{
    cin >> L >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> D[i];
    D[0] = 0;
    D[N + 1] = L;
    ll l = 1, r = L;
    while (l < r)
    {
        ll mid = (l + r + 1) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << endl;
    return 0;
}