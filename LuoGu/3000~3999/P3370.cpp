#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

typedef long long ll;
constexpr ll P = 449, MOD = 436522843;

ll get_hash(string &s)
{
    ll res = 0;
    for (int i = 0; i < s.size(); i++)
        res = (res * P % MOD + s[i]) % MOD;
    return res;
}

void solve()
{
    int n;
    cin >> n;
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        st.insert(get_hash(s));
    }
    cout << st.size() << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}