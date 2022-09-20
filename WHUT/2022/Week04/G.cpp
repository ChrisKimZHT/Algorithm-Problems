#include <bits/stdc++.h>

using namespace std;

const int MAXN = 60;
int t, n;
int a[MAXN], sa[MAXN];

struct ANS
{
    int a, b, c;
};

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        memcpy(sa, a, sizeof(a));
        sort(sa, sa + n);
        vector<ANS> ans;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == sa[i])
                continue;
            for (int j = i + 1; j < n; j++)
            {
                if (a[j] == sa[i])
                {
                    ans.push_back({i + 1, j + 1, j - i});
                    int t = a[j];
                    for (int k = j; k > i; k--)
                        a[k] = a[k - 1];
                    a[i] = t;
                }
            }
        }
        cout << ans.size() << endl;
        for (auto &i : ans)
            cout << i.a << ' ' << i.b << ' ' << i.c << endl;
    }
    return 0;
}