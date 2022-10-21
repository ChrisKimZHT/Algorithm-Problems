#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int t, n;
int a[MAXN], b[MAXN];

inline int lcm(int a, int b)
{
    return a * b / __gcd(a, b);
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        a[0] = a[n + 1] = 1;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 0; i <= n; i++)
            b[i] = lcm(a[i], a[i + 1]);
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (__gcd(b[i], b[i + 1]) != a[i + 1])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}