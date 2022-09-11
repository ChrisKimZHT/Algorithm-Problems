#include <bits/stdc++.h>

using namespace std;

const int MAXA = 2010;
const long long MOD = 1e9 + 7;
long long ans[MAXA][MAXA];
int n;

void init()
{
    for (int i = 0; i < MAXA; i++)
        ans[i][0] = 1;
    for (int i = 1; i < MAXA; i++)
        for (int j = 1; j < MAXA; j++)
            ans[i][j] = (ans[i - 1][j] + ans[i - 1][j - 1]) % MOD;
}

int main()
{
    init();
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        cout << ans[a][b] << endl;
    }
    return 0;
}