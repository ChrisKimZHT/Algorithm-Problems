#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long x, y, a, b;
        cin >> x >> y >> a >> b;
        long long gcdxy = __gcd(x, y);
        x /= gcdxy;
        y /= gcdxy;
        long long tmp = x + y;
        long long cnt = 0;
        bool flag = true;
        while (true)
        {
            if (!(tmp % 2))
            {
                tmp /= 2;
                cnt++;
            }
            else if (tmp == 1)
            {
                break;
            }
            else
            {
                flag = false;
                break;
            }
        }
        if (!flag)
        {
            cout << "-1" << endl;
            continue;
        }
        cout << cnt + 1 << endl;
    }
    return 0;
}