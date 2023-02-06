#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int m;
    cin >> m;
    vector<int> v[6];
    vector<tuple<int, char, int, char>> ans;
    for (int i = 1; i <= m; i++)
    {
        string tmp;
        cin >> tmp;
        int cnt_w = 0, cnt_i = 0, cnt_n = 0;
        for (auto c : tmp)
        {
            if (c == 'w')
                cnt_w++;
            else if (c == 'i')
                cnt_i++;
            else
                cnt_n++;
        }
        if (cnt_w == 3)
        {
            v[0].push_back(i);
            v[1].push_back(i);
        }
        else if (cnt_i == 3)
        {
            v[2].push_back(i);
            v[3].push_back(i);
        }
        else if (cnt_n == 3)
        {
            v[4].push_back(i);
            v[5].push_back(i);
        }
        else if (cnt_w == 2 && cnt_i == 0)
            v[0].push_back(i);
        else if (cnt_w == 2 && cnt_n == 0)
            v[1].push_back(i);
        else if (cnt_i == 2 && cnt_w == 0)
            v[2].push_back(i);
        else if (cnt_i == 2 && cnt_n == 0)
            v[3].push_back(i);
        else if (cnt_n == 2 && cnt_w == 0)
            v[4].push_back(i);
        else if (cnt_n == 2 && cnt_i == 0)
            v[5].push_back(i);
    }
    for (auto now : v[0])
    {
        if (v[2].size())
        {
            int swp = v[2].back();
            v[2].pop_back();
            ans.push_back({now, 'w', swp, 'i'});
        }
        else
        {
            int swp = v[4].back();
            v[4].pop_back();
            ans.push_back({now, 'w', swp, 'n'});
            v[5].push_back(now);
        }
    }
    for (auto now : v[1])
    {
        if (v[4].size())
        {
            int swp = v[4].back();
            v[4].pop_back();
            ans.push_back({now, 'w', swp, 'n'});
        }
        else
        {
            int swp = v[2].back();
            v[2].pop_back();
            ans.push_back({now, 'w', swp, 'i'});
            v[3].push_back(now);
        }
    }
    for (auto now : v[2])
    {
        int swp = v[0].back();
        v[0].pop_back();
        ans.push_back({now, 'i', swp, 'w'});
    }
    for (auto now : v[3])
    {
        int swp = v[5].back();
        v[5].pop_back();
        ans.push_back({now, 'i', swp, 'n'});
    }
    for (auto now : v[4])
    {
        int swp = v[1].back();
        v[1].pop_back();
        ans.push_back({now, 'n', swp, 'w'});
    }
    for (auto now : v[5])
    {
        int swp = v[3].back();
        v[3].pop_back();
        ans.push_back({now, 'n', swp, 'i'});
    }
    cout << ans.size() << endl;
    for (auto [a, b, c, d] : ans)
        cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
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