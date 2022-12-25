#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

long long fastpow(long long a, long long b)
{
    long long ans = 1;
    while (b)
    {
        if (b % 2 == 1)
            ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long A, B;
    cin >> A >> B;
    cout << fastpow(A, B) << endl;
    return 0;
}