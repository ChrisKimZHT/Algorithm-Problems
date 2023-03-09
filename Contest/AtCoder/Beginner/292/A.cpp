#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string S;
    cin >> S;
    for (auto c : S)
        cout << char(toupper(c));
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}