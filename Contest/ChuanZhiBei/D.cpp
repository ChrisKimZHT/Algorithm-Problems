#include <bits/stdc++.h>
#define int long long

using namespace std;

const int SIZE = 1e6 + 10;

int n, k;
int a[SIZE];

int need_day(int x)
{
    int lim = x, ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (lim < a[i] * a[i])
        {
            lim = x;
            lim -= a[i] * a[i];
            ans++;
        }
        else
        {
            lim -= a[i] * a[i];
        }
    }
    return ans;
}

signed main(void)
{
    cin >> n >> k;
    int sum = 0, maxa = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i] * a[i];
        maxa = max(maxa, a[i]);
    }
    int l = maxa * maxa, r = sum;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (need_day(mid) > k)
            l = mid + 1;
        else
            r = mid;
    }
    cout << l << endl;
    // while (1)
    // {
    //     int x;
    //     cin >> x;
    //     cout << need_day(x) << endl;
    // }

    return 0;
}