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
        int ans = a;
        for (int i = 2; i <= a / i; i++)
        {
            if (!(a % i))
            {
                ans = ans / i * (i - 1);
                while (!(a % i))
                    a /= i;
            }
        }
        if (a > 1)
            ans = ans / a * (a - 1);
        cout << ans << endl;
    }
    return 0;
}