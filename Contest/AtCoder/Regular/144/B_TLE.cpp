#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 3e5 + 20;
int N, a, b;
int A[MAXN];

signed main()
{
    cin >> N >> a >> b;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    sort(A, A + N);
    while (A[N - 1] - b >= A[0])
    {
        A[0] += a;
        A[N - 1] -= b;
        sort(A, A + N);
    }
    cout << A[0] << endl;
    return 0;
}