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

inline int f(int x)
{
    return 3 * x * x + 3 * x + 1;
}

int main()
{
    init_prime();
    int L;
    while (cin >> L)
    {
        int ans = 0;
        for (int i = 1; f(i) <= L; i++)
            if (!not_prime[f(i)])
                ans++;
        cout << (ans ? to_string(ans) : "No Special Prime!") << endl;
    }
    return 0;
}