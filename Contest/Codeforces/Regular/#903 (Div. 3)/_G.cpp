#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

constexpr int MAXN = 2e5 + 10, MOD = 26;
int bit[MAXN];

int query(int pos)
{
    int ans = 0;
    for (int i = pos; i; i -= i & -i)
        ans = (ans + bit[i]) % MOD;
    return ans;
}

void update(int pos, int val)
{
    for (int i = pos; i < MAXN; i += i & -i)
        bit[i] = ((bit[i] + val) % MOD + MOD) % MOD;
}

void solve()
{
    memset(bit, 0, sizeof(bit));
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    update(1, s[0] - 'a');
    for (int i = 1; i < s.size(); i++)
        update(i + 1, s[i] - s[i - 1]);
    set<int> st2, st3;
    for (int i = 0; i < s.size(); i++)
    {
        if (i + 1 < s.size() && s[i] == s[i + 1])
            st2.insert(i + 1);
        if (i + 2 < s.size() && s[i] == s[i + 2])
            st3.insert(i + 1);
    }
    auto check = [&](int pos) -> void {
        for (int i = max(1ll, pos - 5); i <= min(n, pos + 5) - 1; i++)
        {
            if (query(i) == query(i + 1))
                st2.insert(i);
            else
                st2.erase(i);
        }
        for (int i = max(1ll, pos - 5); i <= min(n, pos + 5) - 2; i++)
        {
            if (query(i) == query(i + 2))
                st3.insert(i);
            else
                st3.erase(i);
        }
    };
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, r, x;
            cin >> l >> r >> x;
            update(l, x);
            update(r + 1, -x);
            check(l);
            check(r);
        }
        else // if (op == 2)
        {
            int l, r;
            cin >> l >> r;
            bool flag = true;
            auto pos = st2.lower_bound(l);
            if (pos != st2.end() && *pos + 1 <= r)
                flag = false;
            pos = st3.lower_bound(l);
            if (pos != st3.end() && *pos + 2 <= r)
                flag = false;
            if (flag)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
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