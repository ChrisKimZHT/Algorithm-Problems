#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

long long A, B;
inline long double f(long double x)
{
    return (long double)A / sqrt(x + 1) + x * B;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> A >> B;
    long double root = pow(1.0 * A / (2 * B), 2.0 / 3) - 1;
    long long iroot = root;
    long double ans = A;
    for (long long i = iroot - 10; i <= iroot + 10; i++)
        ans = min(ans, f(i));
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}