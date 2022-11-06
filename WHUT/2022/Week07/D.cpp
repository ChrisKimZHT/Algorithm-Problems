#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;
int prime[MAXN], idx;
bool not_prime[MAXN];
void init_prime()
{
    not_prime[0] = not_prime[1] = true;
    for (int i = 2; i < MAXN; i++)
    {
        if (!not_prime[i])
            prime[idx++] = i;
        for (int j = 0; j < idx && i * prime[j] < MAXN; j++)
        {
            not_prime[i * prime[j]] = true;
            if (!(i % prime[j]))
                break;
        }
    }
}

int main()
{
    init_prime();
    int n;
    while (cin >> n, n)
    {
        cout << n << " = ";
        for (int i = 0; i < idx; i++)
        {
            int a = prime[i], b = n - a;
            if (b < 2)
            {
                cout << "Goldbach's conjecture is wrong." << endl;
                break;
            }
            if (!not_prime[b])
            {
                cout << a << " + " << b << endl;
                break;
            }
        }
    }
    return 0;
}