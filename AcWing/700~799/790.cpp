#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-9;

int main()
{
    double num;
    cin >> num;
    double l, r;
    l = -10000, r = 10000;
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= num)
            r = mid;
        else
            l = mid;
    }
    cout << fixed << setprecision(6) << l << endl;
    return 0;
}