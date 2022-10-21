#include <bits/stdc++.h>
#define mod 998244353

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc > 0)
    {
        tc--;
        int n;
        string s;
        cin >> n >> s;
        long long cres = 0;
        string target = s;
        int p = 0, q = n - 1;
        while (p < q)
        {
            target[q] = target[p];
            p++;
            q--;
        }
        int last = (n - 1) / 2;
        for (int i = 0; i <= last; i++)
        {
            cres *= 26;
            cres %= mod;
            cres += (s[i] - 'A');
            cres %= mod;
        }
        cres++;
        cres %= mod;
        if (s < target)
        {
            cres += (mod - 1);
            cres %= mod;
        }
        cout << cres << '\n';
    }
    return 0;
}
