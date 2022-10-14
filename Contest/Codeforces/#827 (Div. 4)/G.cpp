#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    multiset<int> a;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        a.insert(t);
    }
    int ans = 0, tmp = 0;
    queue<int> que;
    for (int i = 0; i < min(32, n); i++)
    {
        int num = 0;
        for (auto &nm : a)
        {
            if ((ans | nm) > tmp)
            {
                tmp = (ans | nm);
                num = nm;
            }
        }
        if (!num)
            break;
        ans = tmp;
        que.push(num);
        a.extract(num);
    }
    while (que.size())
    {
        cout << que.front() << ' ';
        que.pop();
    }
    for (auto &nm : a)
    {
        cout << nm << ' ';
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}