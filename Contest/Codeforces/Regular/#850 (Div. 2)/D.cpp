#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int m;
    cin >> m;
    vector<int> v[6];
    vector<string> ans;
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
        {
            v[0].push_back(i);
        }
        else if (cnt_w == 2 && cnt_n == 0)
        {
            v[1].push_back(i);
        }
        else if (cnt_i == 2 && cnt_w == 0)
        {
            v[2].push_back(i);
        }
        else if (cnt_i == 2 && cnt_n == 0)
        {
            v[3].push_back(i);
        }
        else if (cnt_n == 2 && cnt_w == 0)
        {
            v[4].push_back(i);
        }
        else if (cnt_n == 2 && cnt_i == 0)
        {
            v[5].push_back(i);
        }
    }
    for (auto now : v[0])
    {
        if (v[2].size())
        {
            int swp = v[2].back();
            v[0].pop_back();
            v[2].pop_back();
            ans.push_back(to_string(now) + " w " + to_string(swp) + " i");
        }
        else
        {
            int swp = v[4].back();
            v[0].pop_back();
            v[4].pop_back();
            ans.push_back(to_string(now) + " w " + to_string(swp) + " n");
            v[5].push_back(now);
        }
    }
    for (auto now : v[1])
    {
        if (v[4].size())
        {
            int swp = v[4].back();
            v[1].pop_back();
            v[4].pop_back();
            ans.push_back(to_string(now) + " w " + to_string(swp) + " n");
        }
        else
        {
            int swp = v[2].back();
            v[1].pop_back();
            v[2].pop_back();
            ans.push_back(to_string(now) + " w " + to_string(swp) + " i");
            v[3].push_back(now);
        }
    }
    for (auto now : v[2])
    {
        if (v[0].size())
        {
            int swp = v[0].back();
            v[2].pop_back();
            v[0].pop_back();
            ans.push_back(to_string(now) + " i " + to_string(swp) + " w");
        }
    }
    for (auto now : v[3])
    {
        if (v[5].size())
        {
            int swp = v[5].back();
            v[3].pop_back();
            v[5].pop_back();
            ans.push_back(to_string(now) + " i " + to_string(swp) + " n");
        }
    }
    for (auto now : v[4])
    {
        if (v[1].size())
        {
            int swp = v[1].back();
            v[4].pop_back();
            v[1].pop_back();
            ans.push_back(to_string(now) + " n " + to_string(swp) + " w");
        }
    }
    for (auto now : v[5])
    {
        if (v[3].size())
        {
            int swp = v[3].back();
            v[5].pop_back();
            v[3].pop_back();
            ans.push_back(to_string(now) + " n " + to_string(swp) + " i");
        }
    }
    cout << ans.size() << endl;
    for (auto ele : ans)
        cout << ele << endl;
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