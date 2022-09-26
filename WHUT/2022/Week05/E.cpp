#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s;
        vector<int> ele;
        for (int i = 0; i < n; i++)
        {
            int t;
            cin >> t;
            if (t)
                ele.push_back(i);
        }
        if (ele.size() < s)
        {
            cout << -1 << endl;
            continue;
        }
        int res = INT32_MAX;
        for (int i = 0; i < ele.size(); i++)
        {
            int tmp = 0;
            if (i >= 1)
                tmp += ele[i - 1] + 1;
            if (i + s - 1 <= (int)ele.size() - 2)
                tmp += n - ele[i + s];
            res = min(res, tmp);
        }
        cout << res << endl;
    }
    return 0;
}