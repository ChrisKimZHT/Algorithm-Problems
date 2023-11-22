#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<bool, string>> people(n);
    for (int i = 0; i < n; i++)
        cin >> people[i].first >> people[i].second;
    int pos = 0;
    for (int i = 0; i < m; i++)
    {
        bool a;
        int s;
        cin >> a >> s;
        if (!a && !people[pos].first)
            pos = (pos - s + n) % n;
        else if (!a && people[pos].first)
            pos = (pos + s + n) % n;
        else if (a && !people[pos].first)
            pos = (pos + s + n) % n;
        else if (a && people[pos].first)
            pos = (pos - s + n) % n;
    }
    // cout << pos << endl;
    cout << people[pos].second << endl;
    return 0;
}