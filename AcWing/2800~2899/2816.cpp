#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int n, m;
int a[MAXN], b[MAXN];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    int pa = 0, pb = 0;
    bool flag = true;
    while (true)
    {
        while (b[pb] != a[pa] && pb < m)
            pb++;
        if (pb < m && b[pb] == a[pa])
        {
            pa++;
            pb++;
        }
        else
        {
            flag = false;
            break;
        }
        if (pa == n)
            break;
    }
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}