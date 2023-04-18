#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 10;
int a[MAXN];
bool st[MAXN][MAXN];

void solve()
{
    for (int i = 0; i < 6; i++)
    {
        cin >> a[i];
        st[i][a[i]] = true;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            for (int k = 6; k >= 1; k--)
            {
                if (!st[j][k])
                {
                    st[j][k] = true;
                    a[j] = k;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < 6; i++)
    {
        cout << a[i] << " \n"[i + 1 == 6];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
