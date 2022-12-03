#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int H, W;
    cin >> H >> W;
    int ans = 0;
    for (int i = 0; i < H; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < W; j++)
            if (s[j] == '#')
                ans++;
    }
    cout << ans << endl;
    return 0;
}