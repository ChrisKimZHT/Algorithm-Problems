#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        int n;
        cin >> n;
        double ans = 1.0;
        for (int i = 2; i <= n; i++)
        {
            if (i % 2)
                ans += 1.0 / i;
            else
                ans -= 1.0 / i;
        }
        cout << fixed << setprecision(2) << ans << endl;
    }
    return 0;
}