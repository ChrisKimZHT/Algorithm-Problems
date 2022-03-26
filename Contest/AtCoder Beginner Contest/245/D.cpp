#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[110], B[110], C[220];
bool vis[110];

int main(void)
{
    cin >> N >> M;
    for (int i = 0; i <= N; i++)
        cin >> A[i];
    for (int i = 0; i <= N + M; i++)
        cin >> C[i];
    for (int i = N + M; i >= 0; i--)
    {
        int tmp = C[i];
        for (int j = min(M, i); j >= 0; j--)
        {
            if (!vis[j])
            {
                B[j] = tmp / A[i - j];
                vis[j] = true;
                break;
            }
            tmp -= B[j] * A[i - j];
        }
    }
    for (int i = 0; i <= M; i++)
        cout << B[i] << ' ';
    cout << endl;
    return 0;
}