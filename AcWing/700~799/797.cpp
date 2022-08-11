#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int n, m;
int ls[MAXN], dfls[MAXN];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> ls[i];
    for (int i = 1; i <= n; i++)
        dfls[i] = ls[i] - ls[i - 1];
    while (m--)
    {
        int l, r, c;
        cin >> l >> r >> c;
        dfls[l] += c;
        dfls[r + 1] -= c;
    }
    int tmp = dfls[0];
    for (int i = 1; i <= n; i++)
    {
        tmp += dfls[i];
        cout << tmp << ' ';
    }
    cout << endl;
    return 0;
}