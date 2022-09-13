#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110;
int n, f[MAXN];

int sg(int x)
{
    if (f[x] != -1)
        return f[x];
    unordered_set<int> us;
    for (int i = 0; i < x; i++)
        for (int j = 0; j <= i; j++)
            us.insert(sg(i) ^ sg(j));
    for (int i = 0;; i++)
        if (!us.count(i))
            return f[x] = i;
}

int main()
{
    memset(f, -1, sizeof(f));
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