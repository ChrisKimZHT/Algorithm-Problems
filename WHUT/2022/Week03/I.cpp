#include <bits/stdc++.h>

using namespace std;

const int MAXN = 210;
int t;
int n, m;
int mat[MAXN][MAXN];

int get_val(int a, int b)
{
    int ans = mat[a][b];
    for (int i = 1; a + i < n && b + i < m; i++)
        ans += mat[a + i][b + i];
    for (int i = 1; 0 <= a - i && b + i < m; i++)
        ans += mat[a - i][b + i];
    for (int i = 1; a + i < n && 0 <= b - i; i++)
        ans += mat[a + i][b - i];
    for (int i = 1; 0 <= a - i && 0 <= b - i; i++)
        ans += mat[a - i][b - i];
    return ans;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ans = max(ans, get_val(i, j));
        cout << ans << endl;
    }
    return 0;
}