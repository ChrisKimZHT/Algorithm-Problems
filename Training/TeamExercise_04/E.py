MOD = 1000003
frac_res = []


def frac_init():
    frac_res.append(1)
    frac_res.append(1)
    for i in range(2, 1000001):
        frac_res.append(0)
        frac_res[i] = frac_res[i - 1] * i % MOD


def fastpow(a, b):
    a %= MOD
    ans = 1
    while b:
        if b % 2 == 1:
            ans = ans * a % MOD
        a = a * a % MOD
        b >>= 1
    return ans


def comb(n, k):
    ans = frac_res[n]
    ans *= fastpow(frac_res[k], MOD - 2) % MOD
    ans %= MOD
    ans *= fastpow(frac_res[n - k], MOD - 2) % MOD
    ans %= MOD
    return ans


frac_init()
T = int(input())
for cse in range(1, T + 1):
    nk = input().split()
    n = int(nk[0])
    k = int(nk[1])
    print(f"Case {cse}: {comb(n, k)}")
