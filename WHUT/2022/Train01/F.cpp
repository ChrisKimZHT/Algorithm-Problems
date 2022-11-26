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
        string s;
        cin >> s;
        long long ans = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'L')
                ans += i;
            else
                ans += n - i - 1;
        }
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] == 'L')
            {
                cnt++;
                ans += n - 2 * i - 1;
                cout << ans << ' ';
            }
            if (s[n - i - 1] == 'R')
            {
                cnt++;
                ans += 2 * (n - i - 1) + 1 - n;
                cout << ans << ' ';
            }
        }
        while (cnt < n)
        {
            cout << ans << ' ';
            cnt++;
        }
        cout << endl;
    }
    return 0;
}