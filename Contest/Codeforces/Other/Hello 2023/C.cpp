#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int MAXN = 2e5 + 10;
int n, m;
int a[MAXN], ps[MAXN];

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        ps[i] = ps[i - 1] + a[i];
    int psm = ps[m], cnt = 0, offset = 0;
    priority_queue<int> big_heap;
    for (int i = m; i >= 1; i--)
    {
        while (ps[i] < psm + offset)
        {
            cnt++;
            offset -= big_heap.top() * 2;
            big_heap.pop();
        }
        if (a[i] > 0)
            big_heap.push(a[i]);
    }
    priority_queue<int, vector<int>, greater<int>> small_heap;
    offset = 0;
    for (int i = m + 1; i <= n; i++)
    {
        if (a[i] < 0)
            small_heap.push(a[i]);
        while (ps[i] + offset < psm)
        {
            cnt++;
            offset -= small_heap.top() * 2;
            small_heap.pop();
        }
    }
    cout << cnt << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}