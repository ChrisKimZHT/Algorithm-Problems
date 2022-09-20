#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        int ans = 0;
        if (m > 30)
            m = 30;
        for (int i = m; i >= 0; i--)
        {
            int p = 1 << i;
            if (n >= p)
            {
                int t = n / p;
                n -= t * p;
                ans += t;
            }
        }
        cout << ans << endl;
    }
    return 0;
}