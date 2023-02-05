#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int alice = 0, bob = 0;
    int now = 0, cnt = 1;
    for (int i = 1;; i++)
    {
        if (n < i)
        {
            if (now == 0)
                alice += n;
            else
                bob += n;
            break;
        }
        if (now == 0)
            alice += i;
        else
            bob += i;
        n -= i;
        cnt++;
        if (cnt == 2)
        {
            now = 1 - now;
            cnt = 0;
        }
    }
    cout << alice << ' ' << bob << endl;
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