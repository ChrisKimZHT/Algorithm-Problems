#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        for (int i = 2; i <= a / i; i++)
        {
            int cnt = 0;
            while (!(a % i))
            {
                cnt++;
                a /= i;
            }
            if (cnt)
                cout << i << ' ' << cnt << endl;
        }
        if (a != 1)
            cout << a << ' ' << 1 << endl;
        cout << endl;
    }
    return 0;
}