#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
bool dupl[MAXN];
int n, num[MAXN];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    int l = 1, r = 1;
    int ans = 1;
    while (r < n)
    {
        while (!dupl[num[r]] && r <= n)
        {
            dupl[num[r]] = true;
            r++;
        }
        ans = max(ans, r - l);
        while (dupl[num[r]])
        {
            dupl[num[l]] = false;
            l++;
        }
    }
    cout << ans << endl;
    return 0;
}