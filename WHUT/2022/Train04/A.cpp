#include <iostream>
#define endl '\n'

using namespace std;

const int MAXN = 110;
int mat[MAXN][MAXN], dp[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            cin >> mat[i][j];
    for (int i = 0; i < N; i++)
        dp[N - 1][i] = mat[N - 1][i];
    for (int i = N - 2; i >= 0; i--)
        for (int j = 0; j <= i; j++)
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + mat[i][j];
    cout << dp[0][0] << endl;
    return 0;
}