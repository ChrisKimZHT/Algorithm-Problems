#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    else if (n == 2)
    {
        int a, b;
        cin >> a >> b;
        cout << a << ' ' << b << endl;
        return;
    }
    else if (n == 3)
    {
        vector<int> a(2), b(2), c(3);
        for (int i = 0; i < 2; i++)
            cin >> a[i];
        for (int i = 0; i < 2; i++)
            cin >> b[i];
        for (int i = 0; i < 2; i++)
            cin >> c[i];
        if (a[0] == b[0])
            cout << a[0] << ' ' << c[0] << ' ' << c[1] << endl;
        else if (a[0] == c[0])
            cout << a[0] << ' ' << b[0] << ' ' << b[1] << endl;
        else
            cout << b[0] << ' ' << a[0] << ' ' << a[1] << endl;
        return;
    }
    vector<int> ans(n - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> ans[i];
    vector<int> tmp(n - 1);
    int diff = 0;
    bool flag = false;
    for (int i = 0; i < n - 1; i++)
    {
        if (flag)
        {
            int _;
            for (int j = 0; j < n - 1; j++)
                cin >> _;
            continue;
        }
        for (int j = 0; j < n - 1; j++)
            cin >> tmp[j];
        for (int j = 0; j < n - 1; j++)
        {
            if (tmp[j] != ans[j])
            {
                diff = j;
                break;
            }
        }
        if (diff + 1 < n - 1 && tmp[diff + 1] != ans[diff + 1])
            flag = true;
    }
    if (tmp[diff] == ans[diff + 1])
        swap(tmp, ans);
    ans.insert(ans.begin() + diff, tmp[diff]);
    for (auto ele : ans)
        cout << ele << ' ';
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}