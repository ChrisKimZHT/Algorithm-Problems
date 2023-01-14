#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long N;
    cin >> N;
    N--;
    string ans = ".........";
    ans[7] = '0' + (N % 10);
    N /= 10;
    ans[6] = ans[8] = '0' + (N % 10);
    N /= 10;
    ans[4] = ans[5] = '0' + (N % 10);
    N /= 10;
    ans[3] = '0' + (N % 10);
    N /= 10;
    ans[2] = '0' + (N % 10);
    N /= 10;
    ans[0] = ans[1] = '1' + (N % 9);
    cout << ans << endl;
    return 0;
}