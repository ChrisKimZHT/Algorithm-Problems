#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int num[3];

void solve()
{
    cin >> num[0] >> num[1] >> num[2];
    sort(num, num + 3);
    cout << num[1] << endl;
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