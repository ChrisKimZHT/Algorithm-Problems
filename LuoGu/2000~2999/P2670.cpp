#include <bits/stdc++.h>

using namespace std;

int n, m;
int mp[110][110];

int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        string t;
        cin >> t;
        for (int j = 0; j < n; j++)
        {
            if (t[j] == '*')
            {
                mp[i][j] = -10;
                if (i - 1 >= 0 && j - 1 >= 0 && i - 1 < m && j - 1 < n)
                    mp[i - 1][j - 1]++;
                if (i + 1 >= 0 && j - 1 >= 0 && i + 1 < m && j - 1 < n)
                    mp[i + 1][j - 1]++;
                if (i - 1 >= 0 && j + 1 >= 0 && i - 1 < m && j + 1 < n)
                    mp[i - 1][j + 1]++;
                if (i + 1 >= 0 && j + 1 >= 0 && i + 1 < m && j + 1 < n)
                    mp[i + 1][j + 1]++;
                if (i - 1 >= 0 && j >= 0 && i - 1 < m && j < n)
                    mp[i - 1][j]++;
                if (i >= 0 && j - 1 >= 0 && i < m && j - 1 < n)
                    mp[i][j - 1]++;
                if (i + 1 >= 0 && j >= 0 && i + 1 < m && j < n)
                    mp[i + 1][j]++;
                if (i >= 0 && j + 1 >= 0 && i < m && j + 1 < n)
                    mp[i][j + 1]++;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mp[i][j] < 0)
            {
                cout << "*";
            }
            else
            {
                cout << mp[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}