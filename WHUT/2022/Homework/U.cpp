#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    long double tmp = sqrt(n) + sqrt(m);
    long double res = 1.0;
    for (int i = 0; i < 6; i++)
        res *= tmp;
    cout << fixed << setprecision(0) << res << endl;
    return 0;
}