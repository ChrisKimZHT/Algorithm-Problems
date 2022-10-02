#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110;
int n, m;
multiset<int> s;

int main()
{
    cin >> n >> m;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        mx = max(mx, t);
        s.insert(t);
    }
    mx += m;
    while (m--)
    {
        int t = *s.begin();
        s.extract(t);
        s.insert(t + 1);
    }
    cout << *s.rbegin() << ' ' << mx << endl;
    return 0;
}