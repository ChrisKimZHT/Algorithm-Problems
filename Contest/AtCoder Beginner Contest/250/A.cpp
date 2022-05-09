#include <bits/stdc++.h>

using namespace std;

int main()
{
    int H, W, R, C;
    cin >> H >> W >> R >> C;
    int ans = 0;
    if (0 < R + 1 && R + 1 <= H)
        ans++;
    if (0 < R - 1 && R - 1 <= H)
        ans++;
    if (0 < C + 1 && C + 1 <= W)
        ans++;
    if (0 < C - 1 && C - 1 <= W)
        ans++;
    cout << ans << endl;
    return 0;
}