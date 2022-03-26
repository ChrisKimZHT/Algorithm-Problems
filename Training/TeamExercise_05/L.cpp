#include <bits/stdc++.h>
#define esp 1e-6

using namespace std;

int n, V;
vector<int> a(20), b(20);
int sum_a;

bool judge(double x)
{
    for (int i = 0; i < n; i++)
    {
        if (x * a[i] / sum_a > b[i])
            return false;
    }
    return true;
}

int main(void)
{
    cin >> n >> V;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sum_a = accumulate(a.begin(), a.end(), 0);
    double l = 0, r = V;
    while (r - l > esp)
    {
        double mid = (l + r) / 2;
        if (judge(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%.9lf", l);
    return 0;
}