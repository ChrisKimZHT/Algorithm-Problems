#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        int cnt[3]{};
        for (int i = 0; i < str.size(); i++)
            cnt[str[i] - 'A']++;
        if (cnt[0] + cnt[2] == cnt[1])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}