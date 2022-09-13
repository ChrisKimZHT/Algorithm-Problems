#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10000;
int prime[MAXN], idx;
bool is_prime[MAXN];

void init_prime()
{
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < MAXN; i++)
    {
        if (is_prime[i])
            prime[idx++] = i;
        for (int j = 0; j < idx && i * prime[j] < MAXN; j++)
        {
            is_prime[i * prime[j]] = false;
            if (!(i % prime[j]))
                break;
        }
    }
}

inline int f(int x)
{
    return x * x + x + 41;
}

int main()
{
    init_prime();
    int x, y;
    while (cin >> x >> y, x || y)
    {
        bool flag = true;
        for (int i = x; i <= y; i++)
        {
            if (!is_prime[f(i)])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "OK" << endl;
        else
            cout << "Sorry" << endl;
    }
    return 0;
}