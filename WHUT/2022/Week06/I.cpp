#include <bits/stdc++.h>

using namespace std;

int t, n;
string str;
vector<int> mp(26);
vector<bool> st(26);

int find(int x)
{
    return mp[x] == x ? x : find(mp[x]);
}

int main()
{
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 26; i++)
        {
            mp[i] = i;
            st[i] = false;
        }
        cin >> n >> str;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int c = str[i] - 'a';
            if (mp[c] == c)
            {
                cnt++;
                for (int j = 0; j < 26; j++)
                {
                    if ((find(j) != find(c) || cnt == 26) && !st[j])
                    {
                        st[j] = true;
                        mp[c] = j;
                        break;
                    }
                }
            }
            cout << char('a' + mp[c]);
        }
        cout << endl;
    }
    return 0;
}