#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int Q, A, B;
    cin >> Q >> A >> B;
    set<int> s;
    s.insert(A + B);
    s.insert(A - B);
    while (Q--)
    {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1)
        {
            s.insert(a + b);
            s.insert(a - b);
        }
        else
        {
            auto it = s.lower_bound(a);
            if (it == s.end())
                cout << a - *s.rbegin() << endl;
            else if (*it <= b)
                cout << 0 << endl;
            else if (it == s.begin())
                cout << *it - b << endl;
            else
                cout << min(*it - b, a - *prev(it)) << endl;
        }
    }
    return 0;
}