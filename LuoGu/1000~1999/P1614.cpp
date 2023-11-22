#include <bits/stdc++.h>
#define LENGTH 3010
#define min(a, b) (a < b) ? a : b

using namespace std;

int main(void)
{
    int n, m, a[LENGTH], ans = INT32_MAX;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i <= n - m; i++)
    {
        int sum = 0;
        for (int j = i; j < i + m; j++)
        {
            sum += a[j];
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}