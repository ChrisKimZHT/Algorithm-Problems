#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 3e5 + 20;
int N, a, b;
int A[MAXN];

bool ok(int n)
{
    int x = 0, y = 0;
    for (int i = 0; i < N; i++)
    {
        if (A[i] >= n)
            x += (A[i] - n) / b;
        else
            y += ceil(1.0 * (n - A[i]) / a);
    }
    return x >= y;
}

signed main()
{
    cin >> N >> a >> b;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    int l = 0, r = INT32_MAX;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (ok(mid))
            l = mid + 1;
        else
            r = mid;
    }
    cout << l - 1 << endl;
    return 0;
}