#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e4 + 10;
int N;
int ps[MAXN];

int main()
{
    cin >> N;
    vector<int> p[7];
    for (int i = 1; i <= N; i++)
    {
        cin >> ps[i];
        ps[i] += ps[i - 1];
        ps[i] %= 7;
        p[ps[i]].push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < 7; i++)
    {
        if (p[i].empty())
            continue;
        int a = p[i].front(), b = p[i].back();
        ans = max(ans, b - a);
    }
    cout << ans << endl;
    return 0;
}