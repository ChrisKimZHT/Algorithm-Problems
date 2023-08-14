#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

typedef unsigned long long ull;
constexpr ull base = 449;
constexpr ull mod = 436522843;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int same_pos = -1;
    for (int i = 0, j = n - 1; i < j && s[i] == s[j]; i++, j--)
        same_pos = i;
    string pre = s.substr(0, same_pos + 1);
    string suf = s.substr(n - same_pos - 1);
    // awa = s remove prefix and suffix
    // bwb = reversed awa
    string awa = s.substr(same_pos + 1, n - 2 * (same_pos + 1));
    string bwb = awa;
    reverse(bwb.begin(), bwb.end());
    int cn = awa.size();
    vector<ull> p(cn + 10), ha(cn + 10), hb(cn + 10);
    p[0] = 1;
    for (int i = 1; i <= cn; i++)
    {
        p[i] = p[i - 1] * base % mod;
        ha[i] = (ha[i - 1] * base % mod + awa[i - 1]) % mod;
        hb[i] = (hb[i - 1] * base % mod + bwb[i - 1]) % mod;
    }
    auto get_a = [&](int l, int r) -> ull
    {
        return (ha[r + 1] - ha[l] * p[r - l + 1] % mod + mod) % mod;
    };
    auto get_b = [&](int l, int r) -> ull
    {
        return (hb[r + 1] - hb[l] * p[r - l + 1] % mod + mod) % mod;
    };
    // from left
    int cnt_a = 0;
    for (int i = 0; i < cn; i++)
        if (get_a(0, i) == get_b(cn - 1 - i, cn - 1))
            cnt_a = i + 1;
    // from right
    int cnt_b = 0;
    for (int i = 0; i < cn; i++)
        if (get_a(cn - 1 - i, cn - 1) == get_b(0, i))
            cnt_b = i + 1;
    string mid = "";
    if (cnt_a > cnt_b)
        mid = awa.substr(0, cnt_a);
    else
        mid = awa.substr(cn - cnt_b);
    cout << pre + mid + suf << endl;
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