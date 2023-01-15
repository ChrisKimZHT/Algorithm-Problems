#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<int, int> mp;
    for (char c : s)
        mp[c - 'a']++;
    vector<pair<int, int>> cnt;
    for (auto pr : mp)
        cnt.push_back(pr);
    int char_types = cnt.size();
    sort(cnt.begin(), cnt.end(), cmp);
    int ans = INT32_MAX, ans_each_cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i || n > 26 * i)
            continue;
        int types = n / i;
        int max_same = 0;
        if (char_types > types)
        {
            for (int j = 0; j < types; j++)
                max_same += min(cnt[j].second, i);
        }
        else
        {
            for (int j = 0; j < char_types; j++)
                max_same += min(cnt[j].second, i);
        }
        if (n - max_same < ans)
        {
            ans = n - max_same;
            ans_each_cnt = i;
        }
    }
    int ans_types = n / ans_each_cnt;
    bool st[26] = {false};
    int delta = ans_types - char_types;
    if (delta > 0)
    {
        for (int i = 0; i < char_types; i++)
            st[cnt[i].first] = true;
        for (int i = 0; i < 26; i++)
        {
            if (!st[i])
            {
                st[i] = true;
                delta--;
            }
            if (!delta)
                break;
        }
    }
    else
    {
        for (int i = 0; i < ans_types; i++)
            st[cnt[i].first] = true;
    }
    int change[26] = {0};
    for (int i = 0; i < 26; i++)
    {
        if (st[i])
            change[i] = ans_each_cnt - mp[i];
        else
            change[i] = -mp[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (change[s[i] - 'a'] < 0)
        {
            change[s[i] - 'a']++;
            s[i] = '#';
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] != '#')
            continue;
        for (int j = 0; j < 26; j++)
        {
            if (change[j] <= 0)
                continue;
            s[i] = 'a' + j;
            change[j]--;
            break;
        }
    }
    cout << ans << endl
         << s << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}