#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef long long ll;

const int SIZE = 1e6 + 10;
int prime[SIZE], primesize = 0;
bool not_prime[SIZE];
void init_prime()
{
    not_prime[0] = not_prime[1] = true;
    for (int i = 2; i < SIZE; i++)
    {
        if (!not_prime[i])
            prime[primesize++] = i;
        for (int j = 0; j < primesize && i * prime[j] < SIZE; j++)
        {
            not_prime[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init_prime();
    ll K;
    cin >> K;
    if (K == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    map<int, int> mp;
    for (int i = 0; i < primesize; i++)
    {
        if (K == 1)
            break;
        while (!(K % prime[i]))
        {
            K /= prime[i];
            mp[prime[i]]++;
        }
    }
    if (K != 1)
    {
        cout << K << endl;
        return 0;
    }
    if (mp.rbegin()->first > 1e5)
    {
        cout << mp.rbegin()->first * mp.rbegin()->second << endl;
        return 0;
    }
    for (int i = 1;; i++)
    {
        if (mp.empty())
        {
            cout << i - 1 << endl;
            return 0;
        }
        int t = i;
        for (int j = 0; j < primesize; j++)
        {
            if (t == 1 || t < j)
                break;
            while (!(t % prime[j]))
            {
                t /= prime[j];
                if (mp.find(prime[j]) != mp.end())
                {
                    mp[prime[j]]--;
                    if (mp[prime[j]] == 0)
                        mp.erase(prime[j]);
                }
            }
        }
    }
    return 0;
}