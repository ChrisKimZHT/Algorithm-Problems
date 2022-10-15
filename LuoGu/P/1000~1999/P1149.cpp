/* #include <bits/stdc++.h>

using namespace std;

int ns[2020]{6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int need_stick(int x)
{
    if (ns[x])
        return ns[x];
    int ans = 0, t = x;
    while (t)
    {
        ans += ns[t % 10];
        t /= 10;
    }
    return ns[x] = ans;
}

int main()
{
    int n;
    cin >> n;
    n -= 4;
    int ans = 0;
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 1000; j++)
            if (need_stick(i) + need_stick(j) + need_stick(i + j) == n)
                ans++;
    cout << ans << endl;
    return 0;
} */

#include <iostream>
using namespace std;
int ans[25] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 8, 9, 6, 9, 29, 39, 36, 61, 72, 128};
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", ans[n]);
    return 0;
}