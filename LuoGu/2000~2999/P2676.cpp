#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e4 + 10;
int N, B;
int H[MAXN];

signed main()
{
    cin >> N >> B;
    for (int i = 0; i < N; i++)
        cin >> H[i];
    sort(H, H + N);
    int ans = 1;
    while (true)
    {
        if (B > H[N - ans])
        {
            B -= H[N - ans];
            ans++;
        }
        else
        {
            ans++;
            break;
        }
    }
    cout << ans - 1 << endl;
    return 0;
}