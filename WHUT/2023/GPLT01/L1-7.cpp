#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int pa, pb;
    cin >> pa >> pb;
    int cnt = 0;
    for (int i = 0; i < 3; i++)
    {
        int t;
        cin >> t;
        cnt += t;
    }
    if (pa > pb && 3 - cnt > 0)
        cout << "The winner is a: " << pa << " + " << 3 - cnt << endl;
    else if (pb > pa && cnt > 0)
        cout << "The winner is b: " << pb << " + " << cnt << endl;
    else if (3 - cnt == 3)
        cout << "The winner is a: " << pa << " + " << 3 - cnt << endl;
    else if (cnt == 3)
        cout << "The winner is b: " << pb << " + " << cnt << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}