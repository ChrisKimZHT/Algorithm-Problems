#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MOD = 998244353;
long long fast_pow(long long b)
{
    long long a = 10;
    long long ans = 1;
    while (b)
    {
        if (b % 2 == 1)
            ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    string A, B;
    cin >> A >> B;
    for (int i = 0; i < N; i++)
        if (A[i] > B[i])
            swap(A[i], B[i]);
    long long a = 0, b = 0;
    for (int i = 0; i < N; i++)
    {
        a += (fast_pow(N - 1 - i) * (A[i] - '0')) % MOD;
        a %= MOD;
        b += (fast_pow(N - 1 - i) * (B[i] - '0')) % MOD;
        b %= MOD;
    }
    cout << a * b % MOD << endl;
    return 0;
}