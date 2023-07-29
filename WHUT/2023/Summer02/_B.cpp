#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

constexpr int MAXN = 2e6 + 10;
bool not_prime[MAXN];
int prime[MAXN], prime_cnt[MAXN], prime_size;

void init_prime()
{
    not_prime[0] = not_prime[1] = true;
    for (int i = 2; i < MAXN; i++)
    {
        prime_cnt[i] = prime_cnt[i - 1];
        if (!not_prime[i])
        {
            prime[prime_size++] = i;
            prime_cnt[i]++;
        }
        for (int j = 0; j < prime_size && i * prime[j] < MAXN; j++)
        {
            not_prime[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}

bool check_palindromes(int x)
{
    vector<int> digit;
    while (x)
    {
        digit.push_back(x % 10);
        x /= 10;
    }
    for (int i = 0, j = digit.size() - 1; i <= j; i++, j--)
        if (digit[i] != digit[j])
            return false;
    return true;
}

int palindromes_cnt[MAXN];
void init_palindromes()
{
    for (int i = 1; i < MAXN; i++)
        palindromes_cnt[i] = palindromes_cnt[i - 1] + check_palindromes(i);
}

void solve()
{
    init_prime();
    init_palindromes();
    int p, q;
    cin >> p >> q;
    for (int i = MAXN - 1; i >= 0; i--)
    {
        if (prime_cnt[i] * q <= palindromes_cnt[i] * p)
        {
            cout << i << endl;
            return;
        }
    }
    cout << "Palindromic tree is better than splay tree" << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}