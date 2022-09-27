#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;
int T, n;
char str[MAXN];

bool check(int num)
{
    int t = 0;
    for (int i = 1; i <= n; i++)
    {
        if (str[i] == '0')
        {
            t++;
        }
        else
        {
            if (t < num)
                t = -num;
            else if (t == num)
                t = -max(num - 1, 0);
            else
                return false;
        }
    }
    return t <= 0;
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        cin >> str + 1;
        int l = 0, r = n;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (check(mid))
                r = mid;
            else
                l = mid + 1;
        }
        cout << l << endl;
    }

    return 0;
}