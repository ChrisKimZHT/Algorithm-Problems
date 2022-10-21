#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 262144 + 100;
int t, m;
int p[MAXN];

int sum(int l, int len)
{
    int ans = 0;
    for (int i = l; i < l + len; i++)
        ans += p[i];
    return ans;
}

void my_swap(int l1, int l2, int len)
{
    for (int i = 0; i < len; i++)
        swap(p[l1 + i], p[l2 + i]);
}

signed main()
{
    cin >> t;
    while (t--)
    {
        int cnt = 0;
        cin >> m;
        for (int i = 1; i <= m; i++)
            cin >> p[i];
        for (int i = 1; i < m; i <<= 1)
        {
            for (int j = 0; j < m / i; j += 2)
            {
                if (sum(i * j + 1, i) > sum(i * (j + 1) + 1, i))
                {
                    cnt++;
                    my_swap(i * j + 1, i * (j + 1) + 1, i);
                }
            }
        }
        bool flag = true;
        for (int i = 1; i <= m; i++)
        {
            if (i != p[i])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << cnt << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}