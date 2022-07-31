#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110;
int N, M;
bool edge[MAXN][MAXN];
int ans = 0;

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int U, V;
        cin >> U >> V;
        edge[U][V] = edge[V][U] = true;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            for (int k = j + 1; k <= N; k++)
            {
                if (edge[i][j] && edge[i][k] && edge[j][k])
                    ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}