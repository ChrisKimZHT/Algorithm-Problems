#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    for (int i = 1; i <= N; i++)
    {
        if (K % i || N % i)
            continue;
        string part = S.substr(0, i);
        string rev = part;
        reverse(rev.begin(), rev.end());
        if (part != rev && ((N + K) / i) % 2)
            continue;
        bool flag = true;
        for (int j = 0; j < N / i; j++)
        {
            if (j % 2 == 0 && S.substr(j * i, i) != part)
            {
                flag = false;
                break;
            }
            else if (j % 2 == 1 && S.substr(j * i, i) != rev)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}

signed main()
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