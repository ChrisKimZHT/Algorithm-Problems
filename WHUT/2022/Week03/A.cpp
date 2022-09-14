#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 20;
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

int main()
{
    init_prime();
    int num;
    while (cin >> num, num)
    {
        int cnt = 0;
        for (int i = 0; i < idx; i++)
        {
            int t = num - prime[i];
            if (t > prime[i] && is_prime[t])
                cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}