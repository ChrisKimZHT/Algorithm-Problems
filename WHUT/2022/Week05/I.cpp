#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-6;

inline double f(double x, double y)
{
    return 6.0 * x * x * x * x * x * x * x + 8.0 * x * x * x * x * x * x + 7.0 * x * x * x + 5.0 * x * x - y * x;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        double y;
        cin >> y;
        double l = 0.0, r = 100.0;
        while (r - l > eps)
        {
            double m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
            if (f(m1, y) < f(m2, y))
                r = m2;
            else
                l = m1;
        }
        cout << fixed << setprecision(4) << f(l, y) << endl;
    }
    return 0;
}