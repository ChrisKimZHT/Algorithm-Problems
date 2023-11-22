#include <bits/stdc++.h>

using namespace std;

const int MAXM = 5010;
int n, m;
vector<pair<int, int>> milk;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int p, a;
        cin >> p >> a;
        milk.push_back({p, a});
    }
    sort(milk.begin(), milk.end());
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        if (n >= milk[i].second)
        {
            n -= milk[i].second;
            ans += milk[i].first * milk[i].second;
        }
        else
        {
            ans += n * milk[i].first;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}