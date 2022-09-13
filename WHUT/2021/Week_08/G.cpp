#include <iostream>

using namespace std;

int main(void)
{
    int T;
    cin >> T;
    while (T--)
    {
        long long N, t, x = 1;
        cin >> N;
        t = N;
        while (t != 0)
        {
            if (t % 2 == 1)
            {
                x = x * N % 10;
            }
            N = N * N % 10;
            t >>= 1;
        }
        cout << x << endl;
    }
    return 0;
}