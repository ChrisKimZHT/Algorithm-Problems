#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin >> n;
    long long ans = 1;
    for (int i = 0;i<7;i++)
        ans = ans * n % 14;
    cout << ans << endl;
    return 0;
}