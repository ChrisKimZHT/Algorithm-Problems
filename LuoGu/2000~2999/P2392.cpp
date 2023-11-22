#include <bits/stdc++.h>

using namespace std;

int main()
{
    int s[4];
    cin >> s[0] >> s[1] >> s[2] >> s[3];
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        vector<int> a(s[i]);
        for (int j = 0; j < s[i]; j++)
            cin >> a[j];
        int res = INT32_MAX, sum = accumulate(a.begin(), a.end(), 0);
        for (int j = 0; j < 1 << s[i]; j++)
        {
            int tmp = 0;
            for (int k = 0; k < s[i]; k++)
                if (j >> k & 1)
                    tmp += a[k];
            res = min(res, max(tmp, sum - tmp));
        }
        ans += res;
    }
    cout << ans << endl;
    return 0;
}