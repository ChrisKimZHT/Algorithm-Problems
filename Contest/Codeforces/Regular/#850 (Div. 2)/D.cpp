#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int m;
    cin >> m;
    map<pair<char, char>, vector<int>> mp;
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
            mp[{'w', 'i'}].push_back(i);
            mp[{'w', 'n'}].push_back(i);
        }
        else if (cnt_i == 3)
        {
            mp[{'i', 'w'}].push_back(i);
            mp[{'i', 'n'}].push_back(i);
        }
        else if (cnt_n == 3)
        {
            mp[{'n', 'w'}].push_back(i);
            mp[{'n', 'i'}].push_back(i);
        }
        else if (cnt_w == 2 && cnt_i == 0)
        {
            mp[{'w', 'i'}].push_back(i);
        }
        else if (cnt_w == 2 && cnt_n == 0)
        {
            mp[{'w', 'n'}].push_back(i);
        }
        else if (cnt_i == 2 && cnt_w == 0)
        {
            mp[{'i', 'w'}].push_back(i);
        }
        else if (cnt_i == 2 && cnt_n == 0)
        {
            mp[{'i', 'n'}].push_back(i);
        }
        else if (cnt_n == 2 && cnt_w == 0)
        {
            mp[{'n', 'w'}].push_back(i);
        }
        else if (cnt_n == 2 && cnt_i == 0)
        {
            mp[{'n', 'i'}].push_back(i);
        }
    }
    for (auto now : mp[{'w', 'i'}])
    {
        if (mp[{'i', 'w'}].size())
        {
            int swp = mp[{'i', 'w'}].back();
            mp[{'w', 'i'}].pop_back();
            mp[{'i', 'w'}].pop_back();
            ans.push_back(to_string(now) + " w " + to_string(swp) + " i");
        }
        else
        {
            int swp = mp[{'n', 'w'}].back();
            mp[{'w', 'i'}].pop_back();
            mp[{'n', 'w'}].pop_back();
            ans.push_back(to_string(now) + " w " + to_string(swp) + " n");
            mp[{'n', 'i'}].push_back(now);
        }
    }
    for (auto now : mp[{'w', 'n'}])
    {
        if (mp[{'n', 'w'}].size())
        {
            int swp = mp[{'n', 'w'}].back();
            mp[{'w', 'n'}].pop_back();
            mp[{'n', 'w'}].pop_back();
            ans.push_back(to_string(now) + " w " + to_string(swp) + " n");
        }
        else
        {
            int swp = mp[{'i', 'w'}].back();
            mp[{'w', 'n'}].pop_back();
            mp[{'i', 'w'}].pop_back();
            ans.push_back(to_string(now) + " w " + to_string(swp) + " i");
            mp[{'i', 'n'}].push_back(now);
        }
    }
    for (auto now : mp[{'i', 'w'}])
    {
        if (mp[{'w', 'i'}].size())
        {
            int swp = mp[{'w', 'i'}].back();
            mp[{'i', 'w'}].pop_back();
            mp[{'w', 'i'}].pop_back();
            ans.push_back(to_string(now) + " i " + to_string(swp) + " w");
        }
    }
    for (auto now : mp[{'i', 'n'}])
    {
        if (mp[{'n', 'i'}].size())
        {
            int swp = mp[{'n', 'i'}].back();
            mp[{'i', 'n'}].pop_back();
            mp[{'n', 'i'}].pop_back();
            ans.push_back(to_string(now) + " i " + to_string(swp) + " n");
        }
    }
    for (auto now : mp[{'n', 'w'}])
    {
        if (mp[{'w', 'n'}].size())
        {
            int swp = mp[{'w', 'n'}].back();
            mp[{'n', 'w'}].pop_back();
            mp[{'w', 'n'}].pop_back();
            ans.push_back(to_string(now) + " n " + to_string(swp) + " w");
        }
    }
    for (auto now : mp[{'n', 'i'}])
    {
        if (mp[{'i', 'n'}].size())
        {
            int swp = mp[{'i', 'n'}].back();
            mp[{'n', 'i'}].pop_back();
            mp[{'i', 'n'}].pop_back();
            ans.push_back(to_string(now) + " n " + to_string(swp) + " i");
        }
    }
    cout << ans.size() << endl;
    for(auto ele:ans)
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