#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

string oper(string str)
{
    string ans = "";
    for (int i = 1; i < str.size(); i++)
    {
        if (str[i] % 2 == str[i - 1] % 2)
        {
            ans += max(str[i], str[i - 1]);
        }
    }
    return ans;
}

void solve()
{
    string a, b;
    cin >> a >> b;
    string aa = oper(a), bb = oper(b);
    if (aa == bb)
        cout << aa << endl;
    else
        cout << aa << endl
             << bb << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
