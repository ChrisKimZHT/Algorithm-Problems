#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> tme;
int n;

int main()
{
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        tme.push_back({a, b});
    }
    sort(tme.begin(), tme.end());
    int ans = 0, l = 0, r = 0;
    for (int i = 0; i < tme.size(); i++)
    {
        if (r <= tme[i].first)
        {
            l = tme[i].first;
            r = tme[i].second;
            ans++;
        }
        else
        {
            r = min(r, tme[i].second);
        }
    }
    cout << ans << endl;
    return 0;
}