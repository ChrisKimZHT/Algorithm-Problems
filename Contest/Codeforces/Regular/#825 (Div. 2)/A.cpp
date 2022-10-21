#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        int cnt_a = 0, cnt_b = 0, diff = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i])
                cnt_a++;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            if (b[i])
                cnt_b++;
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
                diff++;
        }
        int ans = 0;
        if (diff == 0)
            ans = 0;
        else if (cnt_a == cnt_b)
            ans = 1;
        else if (abs(cnt_a - cnt_b) == diff)
            ans = abs(cnt_a - cnt_b);
        else
            ans = abs(cnt_a - cnt_b) + 1;
        cout << ans << endl;
    }
    return 0;
}