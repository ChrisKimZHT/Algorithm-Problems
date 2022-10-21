#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string S;
    cin >> S;
    int Q;
    cin >> Q;
    while (Q--)
    {
        long long t, k;
        cin >> t >> k;
        k--;
        long long c = 0;
        for (long long i = t; i > 0; i--)
        {
            if (k == 0)
            {
                c += i;
                c %= 3;
                break;
            }
            if (k % 2 == 1)
            {
                c += 2;
                c %= 3;
            }
            else
            {
                c += 1;
                c %= 3;
            }
            k /= 2;
        }
        cout << char('A' + (S[k] - 'A' + c) % 3) << endl;
    }
    return 0;
}