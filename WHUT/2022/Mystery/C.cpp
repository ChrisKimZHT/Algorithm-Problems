#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> str[3];
        map<string, int> mp;
        for (int i = 0; i < n; i++)
        {
            string t;
            cin >> t;
            mp[t]++;
            str[0].push_back(t);
        }
        for (int i = 0; i < n; i++)
        {
            string t;
            cin >> t;
            mp[t]++;
            str[1].push_back(t);
        }
        for (int i = 0; i < n; i++)
        {
            string t;
            cin >> t;
            mp[t]++;
            str[2].push_back(t);
        }
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < n; i++)
        {
            if (mp[str[0][i]] == 1)
                a += 3;
            else if (mp[str[0][i]] == 2)
                a += 1;
        }
        for (int i = 0; i < n; i++)
        {
            if (mp[str[1][i]] == 1)
                b += 3;
            else if (mp[str[1][i]] == 2)
                b += 1;
        }
        for (int i = 0; i < n; i++)
        {
            if (mp[str[2][i]] == 1)
                c += 3;
            else if (mp[str[2][i]] == 2)
                c += 1;
        }
        cout << a << ' ' << b << ' ' << c << endl;
    }
    return 0;
}