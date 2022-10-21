#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), s(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    string str;
    cin >> str;
    for (int i = 0; i < n; i++)
    {
        if (!s[i])
        {
            s[i] = str[i];
            for (int j = i + 1; j < n; j++)
            {
                if (a[j] == a[i])
                {
                    s[j] = str[i];
                }
            }
        }
    }
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != str[i])
        {
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}