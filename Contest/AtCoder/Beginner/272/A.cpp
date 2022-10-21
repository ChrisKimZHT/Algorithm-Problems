#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    long long ans = 0;
    while (N--)
    {
        int t;
        cin >> t;
        ans += t;
    }
    cout << ans << endl;
    return 0;
}