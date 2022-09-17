#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<pair<int, int>> vec;
    for (int i = 0; i < 10; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 10; j++)
        {
            if (s[j] == '#')
                vec.push_back({i, j});
        }
    }
    cout << vec.front().first + 1 << ' ' << vec.back().first + 1 << endl
         << vec.front().second + 1 << ' ' << vec.back().second + 1 << endl;
    return 0;
}