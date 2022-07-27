#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int n, m;
int ls[MAXN], psls[MAXN];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> ls[i];
    for (int i = 1; i <= n; i++)
        psls[i] = psls[i - 1] + ls[i];
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cout << psls[r] - psls[l - 1] << endl;
    }
    return 0;
}