#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int N, K, X;
    cin >> N >> K >> X;
    vector<long long> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    sort(A.begin(), A.end());
    for (int i = N - 1; i >= 0; i--)
    {
        long long k = A[i] / X;
        if (!k)
            break;
        if (K >= k)
        {
            A[i] -= k * X;
            K -= k;
        }
        else
        {
            A[i] -= K * X;
            K = 0;
            break;
        }
    }
    sort(A.begin(), A.end());
    for (int i = N - 1; i >= 0; i--)
    {
        if (!K)
            break;
        A[i] = 0;
        K--;
    }
    long long ans = accumulate(A.begin(), A.end(), 0LL);
    cout << ans << endl;
    return 0;
}