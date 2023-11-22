#include <bits/stdc++.h>

using namespace std;

const double lg2 = log10(2);

int main()
{
    int P;
    cin >> P;
    cout << int(lg2 * P) + 1 << endl;
    vector<unsigned long long> num(500);
    num[0] = 1;
    for (; P > 0; P -= 60)
    {
        unsigned long long r = 0;
        for (int i = 0; i < 500; i++)
        {
            if (P >= 60)
                r += num[i] << 60;
            else
                r += num[i] << P;
            num[i] = r % 10;
            r /= 10;
        }
    }
    num[0] -= 1;
    for (int i = 499; i >= 0; i--)
    {
        cout << char('0' + num[i]);
        if (!(i % 50))
            cout << endl;
    }
    return 0;
}