#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 2022;
int t, n;
int a[MAXN];

bool check(int len)
{
    for (int i = 1; i <= len; i++)
    {
        ll base_sum = 0;
        for (int j = 0; j < i; j++)
            base_sum += a[j];
        ll sum = 0;
        int cnt = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            cnt++;
            if (sum > base_sum || cnt > len)
            {
                sum = -1;
                break;
            }
            if (sum == base_sum)
                sum = cnt = 0;
        }
        if (!sum)
            return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int l = 1, r = n;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (check(mid))
                r = mid;
            else
                l = mid + 1;
        }
        cout << l << endl;
    }
    return 0;
}
/*
1
7
1 2 3 6 3 2 1
*/