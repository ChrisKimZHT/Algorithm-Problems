#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

// 必须有序！
bool cmp(vector<int> a, vector<int> b)
{
    int pa, pb;
    set<int> sa, sb;
    for (auto ele : a)
        sa.insert(ele);
    for (auto ele : b)
        sb.insert(ele);
    //////////////////////////////////////
    if (a.front() == a.back())
    {
        pa = 8;
    }
    else if (a[0] == a[3] ||
             a[1] == a[4])
    {
        pa = 7;
    }
    else if (a[0] == a[1] && a[2] == a[4] ||
             a[0] == a[2] && a[3] == a[4])
    {
        pa = 6;
    }
    else if (a[0] == 2 && a[1] == 3 && a[2] == 4 && a[3] == 5 && a[4] == 6)
    {
        pa = 5;
    }
    else if (a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4 && a[4] == 5)
    {
        pa = 4;
    }
    else if (a[0] == a[2] || a[1] == a[3] || a[2] == a[4])
    {
        pa = 3;
    }
    else if (sa.size() == 3)
    {
        pa = 2;
    }
    else if (sa.size() == 4)
    {
        pa = 1;
    }
    else
    {
        pa = 0;
    }
    //////////////////////////////////////
    if (b.front() == b.back())
    {
        pb = 8;
    }
    else if (b[0] == b[3] ||
             b[1] == b[4])
    {
        pb = 7;
    }
    else if (b[0] == b[1] && b[2] == b[4] ||
             b[0] == b[2] && b[3] == b[4])
    {
        pb = 6;
    }
    else if (b[0] == 2 && b[1] == 3 && b[2] == 4 && b[3] == 5 && b[4] == 6)
    {
        pb = 5;
    }
    else if (b[0] == 1 && b[1] == 2 && b[2] == 3 && b[3] == 4 && b[4] == 5)
    {
        pb = 4;
    }
    else if (b[0] == b[2] || b[1] == b[3] || b[2] == b[4])
    {
        pb = 3;
    }
    else if (sb.size() == 3)
    {
        pb = 2;
    }
    else if (sb.size() == 4)
    {
        pb = 1;
    }
    else
    {
        pb = 0;
    }
    //////////////////////////////////////
    return pa > pb;
}

vector<int> dice(5), tmp;
int all, cnt;

void dfs(int t, int dep)
{
    if (dep == 5)
    {
        all++;
        sort(tmp.begin(), tmp.end());
        if (cmp(tmp, dice))
            cnt++;
        tmp = dice;
        return;
    }
    if ((t >> dep & 1) == 0)
    {
        dfs(t, dep + 1);
    }
    else
    {
        for (int i = 1; i <= 6; i++)
        {
            tmp[dep] = i;
            dfs(t, dep + 1);
        }
    }
}

void solve()
{
    for (int i = 0; i < 5; i++)
        cin >> dice[i];
    sort(dice.begin(), dice.end());
    int ra = 0, rb = 1, pc = 0;
    for (int i = 0; i < 1 << 6; i++)
    {
        all = cnt = 0;
        tmp = dice;
        dfs(i, 0);
        int gcd = __gcd(all, cnt);
        all /= gcd;
        cnt /= gcd;
        if (cnt == ra && all == rb)
        {
            int npc = 0;
            for (int j = 0; j < 5; j++)
                if (i >> j & 1)
                    npc++;
            pc = min(npc, pc);
        }
        else if (1.0 * ra / rb < 1.0 * cnt / all)
        {
            int gcd = __gcd(cnt, all);
            ra = cnt;
            rb = all;
            pc = 0;
            for (int j = 0; j < 5; j++)
                if (i >> j & 1)
                    pc++;
        }
    }
    cout << pc << ' ' << ra << ' ' << rb << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}