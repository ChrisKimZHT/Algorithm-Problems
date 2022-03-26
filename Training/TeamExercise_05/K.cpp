#include <bits/stdc++.h>
#define eps 1e-6

using namespace std;

int n, k;
vector<double> a(10010);

bool judge(double x)
{
    double transfer = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > x)
            transfer += (a[i] - x) * (1.0 - 1.0 * k / 100);
        else if (a[i] < x)
            transfer -= x - a[i];
    }
    if (transfer >= 0)
        return true;
    else
        return false;
}

int main(void)
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    double l = 0, r = 1.0 * accumulate(a.begin(), a.end(), (double)0) / n;
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (judge(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%.9lf\n", l);
    return 0;
}