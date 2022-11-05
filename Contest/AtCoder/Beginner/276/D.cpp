#include <bits/stdc++.h>
#define int long long

using namespace std;

struct node
{
    int cnt_2, cnt_3;
    int remain;
};

signed main()
{
    int N;
    cin >> N;
    vector<node> a(N);
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        while (!(t % 2))
        {
            a[i].cnt_2++;
            t /= 2;
        }
        while (!(t % 3))
        {
            a[i].cnt_3++;
            t /= 3;
        }
        a[i].remain = t;
    }
    for (int i = 1; i < N; i++)
    {
        if (a[i - 1].remain != a[i].remain)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    int min_cnt2 = INT32_MAX, min_cnt3 = INT32_MAX;
    for (int i = 0; i < N; i++)
    {
        min_cnt2 = min(min_cnt2, a[i].cnt_2);
        min_cnt3 = min(min_cnt3, a[i].cnt_3);
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans += a[i].cnt_2 - min_cnt2;
        ans += a[i].cnt_3 - min_cnt3;
    }
    cout << ans << endl;
    return 0;
}