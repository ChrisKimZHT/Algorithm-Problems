#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m;
vector<int> a;

bool check(int x)
{
    int l = 0, r = 0, len = 1, ans = INT32_MAX;
    while (r < n)
    {
        if (a[r] - a[l] <= x)
        {
            int rr = n - r - 1, ll = l;
            ans = min(ans, rr + ll + min(rr, ll));
            r++;
        }
        else
        {
            l++;
        }
    }
    return ans <= m;
}

signed main()
{
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int l = 0, r = a.back() - a.front();
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
    return 0;
}