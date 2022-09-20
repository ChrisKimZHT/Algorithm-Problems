#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
char s[MAXN];
int ps[MAXN];
int n;

int main()
{
    cin >> n >> s + 1;
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1')
            ps[i] = ps[i - 1] + 1;
        else
            ps[i] = ps[i - 1] - 1;
        mp[ps[i]].push_back(i);
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        int t = ps[i];
        auto it = mp.find(t);
        if (it != mp.end() && it->second.size())
        {
            int x = it->second.back() - i;
            if (x > 0)
                ans = max(ans, x);
        }
    }
    cout << ans << endl;
    return 0;
}