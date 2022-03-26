#include <iostream>

using namespace std;

int main(void)
{
    int n, sum, i;
    cin >> n;
    sum = (1 + n) * n / 2;
    for (i = 2;; i++)
    {
        if (sum % i == 0)
        {
            break;
        }
    }
    int ans = sum / i;
    cout << ans << endl;
    return 0;
}