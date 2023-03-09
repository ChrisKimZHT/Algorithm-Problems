#include <bits/stdc++.h>

using namespace std;

const long double eps = 1e-9;
long double A, B;

bool check(long double x)
{
    long double l = sqrt(A * A + x * x);
    long double ll = l / 2.0L * sqrt(3.0L);
    long double mx = x / 2.0L, my = A / 2.0L;
    long double rx = mx + ll / l * A, ry = my + ll / l * x;
    return rx <= B && ry <= A;
}

void solve()
{
    cin >> A >> B;
    if (A > B) // A <= B
        swap(A, B);
    double l = 0, r = B;
    while (abs(l - r) > eps)
    {
        double mid = (l + r) / 2.0L;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << fixed << setprecision(20) << sqrt(A * A + l * l) << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}