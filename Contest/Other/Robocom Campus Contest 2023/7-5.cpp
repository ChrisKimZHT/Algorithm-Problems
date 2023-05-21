#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

int n, m;
int pos = 0, color = 0;
vector<int> a, now;
vector<int> ans;

void right()
{
    pos++;
    ans.push_back(pos);
    color = (color + 1) % m;
    now[pos] = color;
}

void left()
{
    pos--;
    ans.push_back(pos);
    color = (color + 1) % m;
    now[pos] = color;
}

void solve()
{
    cin >> n >> m;
    a.resize(n);
    now.resize(n, -1);
    now[0] = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (m % 2 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 != i % 2)
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    int pos = -1;
    for (int i = 0; i < n - 1; i++)
    {
        if (abs(a[i] - a[i + 1]) == 1 || abs(a[i] - a[i + 1] == m - 1))
        {
            pos = i;
            break;
        }
    }
    if (pos == -1)
    {
        cout << "NO" << endl;
        return;
    }
    for (int i = 0; i < pos; i++)
    {
        while (a[i] != now[i])
        {
            right();
            left();
        }
        right();
    }
    for (int i = pos; i < n - 1; i++)
    {
        right();
    }
    for (int i = n - 1; i > pos + 1; i--)
    {
        while (a[i] != now[i])
        {
            left();
            right();
        }
        left();
    }
    while (a[pos] != now[pos] || a[pos + 1] != now[pos + 1])
    {
        left();
        right();
    }
    cout << ans.size() << endl;
    for (auto ele : ans)
        cout << ele + 1 << ' ';
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}