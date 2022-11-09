#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int first, temp;
    cin >> first;
    for (int i = 1; i < n; i++)
        cin >> temp;
    if (first == 1)
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