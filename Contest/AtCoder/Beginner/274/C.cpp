#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4e5 + 20;
int N, A[MAXN];
int dist[MAXN];

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= N; i++)
        dist[2 * i] = dist[2 * i + 1] = dist[A[i]] + 1;
    for (int i = 1; i <= 2 * N + 1; i++)
        cout << dist[i] << endl;
    return 0;
}