#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (cnt < 0)
        {
            cout << "No" << endl;
            return;
        }
        if (s[i] == 'A')
            cnt++;
        else if (s[i] == 'Q')
            cnt--;
    }
    if (cnt < 0)
    {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}