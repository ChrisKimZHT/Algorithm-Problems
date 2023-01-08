#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 2e6 + 10;
const unsigned long long MOD1 = 19260817, MOD2 = 19660813;
int N;
char T[MAXN], revT[MAXN];

unsigned long long p[MAXN], h[MAXN], revh[MAXN];
void init1()
{
    p[0] = 1;
    for (int i = 1; i <= 2 * N; i++)
    {
        p[i] = (p[i - 1] * 131) % MOD1;
        h[i] = ((h[i - 1] * 131) % MOD1 + T[i]) % MOD1;
        revh[i] = ((revh[i - 1] * 131) % MOD1 + revT[i]) % MOD1;
    }
}

unsigned long long get1(int l, int r)
{
    return (h[r] % MOD1 + MOD1 - (h[l - 1] * p[r - l + 1]) % MOD1) % MOD1;
}

unsigned long long getrev1(int l, int r)
{
    return (revh[r] % MOD1 + MOD1 - (revh[l - 1] * p[r - l + 1]) % MOD1) % MOD1;
}

unsigned long long pp[MAXN], hh[MAXN], revhh[MAXN];
void init2()
{
    pp[0] = 1;
    for (int i = 1; i <= 2 * N; i++)
    {
        pp[i] = (pp[i - 1] * 131) % MOD2;
        hh[i] = ((hh[i - 1] * 131) % MOD2 + T[i]) % MOD2;
        revhh[i] = ((revhh[i - 1] * 131) % MOD2 + revT[i]) % MOD2;
    }
}

unsigned long long get2(int l, int r)
{
    return (hh[r] % MOD2 + MOD2 - (hh[l - 1] * pp[r - l + 1]) % MOD2) % MOD2;
}

unsigned long long getrev2(int l, int r)
{
    return (revhh[r] % MOD2 + MOD2 - (revhh[l - 1] * pp[r - l + 1]) % MOD2) % MOD2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> T + 1;
    for (int i = 2 * N; i >= 1; i--)
        revT[2 * N - i + 1] = T[i];
    init1();
    init2();
    for (int i = 0; i <= N; i++)
    {
        int l = N - i + 1, r = 2 * N - i;
        unsigned long long a1 = getrev1(l, r);
        unsigned long long b1 = ((1 <= i) ? get1(1, i) : 0);
        unsigned long long c1 = ((i + N + 1 <= 2 * N) ? get1(i + N + 1, 2 * N) : 0);
        unsigned long long a2 = getrev2(l, r);
        unsigned long long b2 = ((1 <= i) ? get2(1, i) : 0);
        unsigned long long c2 = ((i + N + 1 <= 2 * N) ? get2(i + N + 1, 2 * N) : 0);
        if (a1 == ((b1 * p[N - i]) % MOD1 + c1) % MOD1 &&
            a2 == ((b2 * pp[N - i]) % MOD2 + c2) % MOD2)
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