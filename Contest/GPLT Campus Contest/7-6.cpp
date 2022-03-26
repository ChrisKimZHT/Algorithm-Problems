#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[10010];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int s;
    cin >> s;
    double ans = 0;
    while (s)
    {
        ans += 1.0 / a[0];
        a[0]++;
        s--;
        sort(a, a + n);
    }
    printf("%.3lf", ans);
    return 0;
}