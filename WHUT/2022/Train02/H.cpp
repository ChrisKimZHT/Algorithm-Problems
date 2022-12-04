#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if (n == 1)
        cout << -1 << endl;
    else
        cout << n << ' ' << n + 1 << ' ' << n * (n + 1) << endl;
    return 0;
}