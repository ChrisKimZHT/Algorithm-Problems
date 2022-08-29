#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int N, A[MAXN];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    sort(A, A + N);
    int mid = A[N / 2], ans = 0;
    for (int i = 0; i < N; i++)
        ans += abs(mid - A[i]);
    cout << ans << endl;
    return 0;
}