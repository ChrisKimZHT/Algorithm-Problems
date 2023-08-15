#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

void solve()
{
    int q;
    cin >> q;
    while (q--)
    {
        string op;
        cin >> op;
        map<int, int> m, mb;
        vector<int> v, vb;
        if (op == "+")
        {
            int x;
            cin >> x;
            vb = v;
            mb = m;
            m[x]++;
            v.push_back(x);
        }
        else if (op == "-")
        {
            int x;
            cin >> x;
            vb = v;
            mb = m;
            for (int i = 0; i < x; i++)
            {
                int num = v.back();
                v.pop_back();
                m[num]--;
                if (m[num] == 0)
                    m.erase(num);
            }
        }
        else if (op == "!")
        {
            m = mb;
            v = vb;
        }
        else // if (op == "?")
        {
            cout << m.size() << endl;
        }
    }
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