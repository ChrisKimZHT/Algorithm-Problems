#include <bits/stdc++.h>

using namespace std;

int diff(string &a, string &b)
{
    int ans = 0;
    for (int i = 0; i < a.size(); i++)
        ans += abs(a[i] - b[i]);
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<string> str(n);
        for (int i = 0; i < n; i++)
            cin >> str[i];
        int ans = INT32_MAX;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                ans = min(ans, diff(str[i], str[j]));
        cout << ans << endl;
    }
    return 0;
}