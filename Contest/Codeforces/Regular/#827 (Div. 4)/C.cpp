#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string mat[8];
        for (int i = 0; i < 8; i++)
            cin >> mat[i];
        char ans = 'U';
        for (int i = 0; i < 8; i++)
        {
            if (mat[i] == "RRRRRRRR")
            {
                ans = 'R';
                break;
            }
        }
        if (ans != 'U')
        {
            cout << ans << endl;
            continue;
        }
        for (int i = 0; i < 8; i++)
        {
            string tmp;
            for (int j = 0; j < 8; j++)
                tmp += mat[j][i];
            if (tmp == "BBBBBBBB")
            {
                ans = 'B';
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}