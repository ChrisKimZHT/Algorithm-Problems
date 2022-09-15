#include <bits/stdc++.h>

using namespace std;

int t;
int x, y;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> x >> y;
        if (y % x)
        {
            cout << "0 0" << endl;
            continue;
        }
        int t = y / x;
        bool flag = false;
        for (int i = 1; i <= 100; i++)
        {
            for (int j = 1; j <= 100; j++)
            {
                int k = pow(i, j);
                if (k > 100)
                    break;
                if (t == k)
                {
                    cout << j << ' ' << i << endl;
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }
        if (!flag)
            cout << "0 0" << endl;
    }
    return 0;
}