#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int N;
    cin >> N;
    multiset<int> a;
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        a.insert(t);
    }
    int mina = *a.begin(), maxa = *a.rbegin();
    cout << mina << ' ' << a.count(mina) << endl
         << maxa << ' ' << a.count(maxa) << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}