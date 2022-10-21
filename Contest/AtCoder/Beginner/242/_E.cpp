#include <bits/stdc++.h>
#define MOD 998244353

using namespace std;

int main(void)
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        string S;
        cin >> N >> S;
        long long ans = 0, p = 1;
        for (int i = (N - 1) / 2; i >= 0; i--)
        {
            ans += p * (S[i] - 'A');
            ans %= MOD;
            p *= 26;
            p %= MOD;
        }
        string palindrome = S;
        for (int i = 0, j = N - 1; i <= j; i++, j--)
            palindrome[j] = palindrome[i];
        if (palindrome <= S)
        {
            ans++;
            ans %= MOD;
        }
        cout << ans << endl;
    }
    return 0;
}