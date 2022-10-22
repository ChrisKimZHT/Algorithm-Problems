#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
int H, W;
int cnt[MAXN];

int main()
{
    cin >> H >> W;
    for (int i = 0; i < H; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < W; j++)
            if (s[j] == '#')
                cnt[j]++;
    }
    for (int i = 0; i < W; i++)
        cout << cnt[i] << ' ';
    cout << endl;
    return 0;
}