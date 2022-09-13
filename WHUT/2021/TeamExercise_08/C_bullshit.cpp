#include <iostream>
#include <map>
#include <queue>
#include <utility>

using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    int num[30];
    for (int i = 0; i < n; i++)
        cin >> num[i];
    map<int, int> mp;
    mp[0] = 1;
    queue<pair<int, int>> que;
    for (int i = 0; i < n; i++)
    {
        for (auto it = mp.begin(); it != mp.end(); ++it)
            que.push({it->first, it->second});
        while (!que.empty())
        {
            mp[que.front().first + num[i]] += que.front().second;
            que.pop();
        }
    }
    cout << mp[t] << endl;
}