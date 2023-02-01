#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

string ans = "314159265358979323846264338327";

int solve()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        if (ans[i] != s[i])
            return i;
    return s.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        cout << solve() << endl;
    return 0;
}