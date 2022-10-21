#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N, A, B;
    cin >> N >> A >> B;
    long long C = A * B / __gcd(A, B);
    long long N_A = N / A, N_B = N / B, N_C = N / C;
    cout << N * (N + 1) / 2 -
                N_A * (N_A + 1) / 2 * A -
                N_B * (N_B + 1) / 2 * B +
                N_C * (N_C + 1) / 2 * C
         << endl;
    return 0;
}