#include <bits/stdc++.h>

using namespace std;

string ans = "AAAAAAAAAA";

int query(string s)
{
    cout << s << endl;
    int t;
    cin >> t;
    return t;
}

void solve()
{
    for (int i = 0; i < 10; i++)
    {
        int init = query(ans);
        for (int j = 1; j < 4; j++)
        {
            string tmp = ans;
            tmp[i] += j;
            int res = query(tmp);
            if (res == 10)
            {
                return;
            }
            if (res < init)
            {
                break;
            }
            else if (res > init)
            {
                ans[i] += j;
                break;
            }
        }
    }
}

int main()
{
    solve();
}