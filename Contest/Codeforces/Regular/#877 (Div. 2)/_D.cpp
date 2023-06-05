#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    set<int> st;
    for (int i = 1; i <= n; i++)
        if (i % 2 == 0 && s[i - 1] == '(' ||
            i % 2 == 1 && s[i - 1] == ')')
            st.insert(i);
    while (q--)
    {
        int i;
        cin >> i;
        if (n % 2)
        {
            cout << "No" << endl;
            continue;
        }
        if (st.count(i))
            st.erase(i);
        else
            st.insert(i);
        if (st.size() &&
            (*st.begin() % 2 == 1 ||
             *st.rbegin() % 2 == 0))
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}