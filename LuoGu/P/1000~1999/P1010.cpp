#include <bits/stdc++.h>

using namespace std;

void dfs(int x)
{
    if (x == 0 || x == 2)
    {
        cout << x;
        return;
    }
    int p = 0, t = x;
    while (x >= 1 << p)
        p++;
    bool flag = false;
    for (int i = p - 1; i >= 0; i--)
    {
        if (t >= 1 << i)
        {
            t -= 1 << i;
            if (flag)
                cout << '+';
            flag = true;
            cout << '2';
            if (i != 1)
            {
                cout << '(';
                dfs(i);
                cout << ')';
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    dfs(n);
    return 0;
}