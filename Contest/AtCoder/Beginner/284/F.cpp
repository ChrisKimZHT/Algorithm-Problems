#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 2e6 + 10;
int N;
char T[MAXN], T_rev[MAXN];

// hash-1: 19260817
const unsigned long long MOD_1 = 19260817;
unsigned long long p_1[MAXN], h_1[MAXN], h_rev_1[MAXN];
void init_1()
{
    p_1[0] = 1;
    for (int i = 1; i <= 2 * N; i++)
    {
        p_1[i] = (p_1[i - 1] * 131) % MOD_1;
        h_1[i] = ((h_1[i - 1] * 131) % MOD_1 + T[i]) % MOD_1;
        h_rev_1[i] = ((h_rev_1[i - 1] * 131) % MOD_1 + T_rev[i]) % MOD_1;
    }
}

unsigned long long get_1(int l, int r)
{
    return (h_1[r] % MOD_1 + MOD_1 - (h_1[l - 1] * p_1[r - l + 1]) % MOD_1) % MOD_1;
}

unsigned long long get_rev_1(int l, int r)
{
    return (h_rev_1[r] % MOD_1 + MOD_1 - (h_rev_1[l - 1] * p_1[r - l + 1]) % MOD_1) % MOD_1;
}

// hash-2: 19660813
const unsigned long long MOD_2 = 19660813;
unsigned long long p_2[MAXN], h_2[MAXN], h_rev_2[MAXN];
void init_2()
{
    p_2[0] = 1;
    for (int i = 1; i <= 2 * N; i++)
    {
        p_2[i] = (p_2[i - 1] * 131) % MOD_2;
        h_2[i] = ((h_2[i - 1] * 131) % MOD_2 + T[i]) % MOD_2;
        h_rev_2[i] = ((h_rev_2[i - 1] * 131) % MOD_2 + T_rev[i]) % MOD_2;
    }
}

unsigned long long get_2(int l, int r)
{
    return (h_2[r] % MOD_2 + MOD_2 - (h_2[l - 1] * p_2[r - l + 1]) % MOD_2) % MOD_2;
}

unsigned long long get_rev_2(int l, int r)
{
    return (h_rev_2[r] % MOD_2 + MOD_2 - (h_rev_2[l - 1] * p_2[r - l + 1]) % MOD_2) % MOD_2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> T + 1;
    for (int i = 2 * N; i >= 1; i--)
        T_rev[2 * N - i + 1] = T[i];
    init_1();
    init_2();
    for (int i = 0; i <= N; i++)
    {
        int l = N - i + 1, r = 2 * N - i;
        unsigned long long a_1 = get_rev_1(l, r),
                           a_2 = get_rev_2(l, r),
                           b_1 = get_1(1, i),
                           b_2 = get_2(1, i),
                           c_1 = get_1(i + N + 1, 2 * N),
                           c_2 = get_2(i + N + 1, 2 * N);
        if (a_1 == ((b_1 * p_1[N - i]) % MOD_1 + c_1) % MOD_1 &&
            a_2 == ((b_2 * p_2[N - i]) % MOD_2 + c_2) % MOD_2)
        {
            for (int j = i + N; j >= i + 1; j--)
                cout << T[j];
            cout << endl;
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}