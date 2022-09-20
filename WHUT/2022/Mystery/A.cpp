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
        string s;
        cin >> s;
        if (n != 5)
        {
            cout << "NO" << endl;
            continue;
        }
        map<char, int> mp;
        for (int i = 0; i < s.size(); i++)
            mp[s[i]]++;
        if (mp['T'] == 1 &&
            mp['i'] == 1 &&
            mp['m'] == 1 &&
            mp['u'] == 1 &&
            mp['r'] == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}