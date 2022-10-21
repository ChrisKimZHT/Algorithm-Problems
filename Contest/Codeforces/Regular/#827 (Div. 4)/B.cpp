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
        map<int, int> mp;
        while (n--)
        {
            int t;
            cin >> t;
            mp[t]++;
        }
        bool flag = true;
        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            if (it->second >= 2)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}