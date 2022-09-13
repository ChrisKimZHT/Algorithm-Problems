#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110, MAXM = 10010;
int k, n;
int s[MAXN], f[MAXM];

int sg(int x)
{
    if (f[x] != -1)
        return f[x];
    unordered_set<int> us;
    for (int i = 0; i < k; i++)
    {
        int t = x - s[i];
        if (t >= 0)
            us.insert(sg(t));
    }
    for (int i = 0;; i++)
        if (!us.count(i))
            return f[x] = i;
}

int main()
{
    memset(f, -1, sizeof(f));
    cin >> k;
    for (int i = 0; i < k; i++)
        cin >> s[i];
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        ans ^= sg(t);
    }
    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}