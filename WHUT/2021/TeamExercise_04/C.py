T = int(input())
for i in range(1, T + 1):
    nk = input().split()
    n = int(nk[0])
    k = int(nk[1])
    ans = 1
    if n >= k:
        for j in range(0, k):
            ans *= (n - j) * (n - j)
        for p in range(2, k + 1):
            ans //= p
    else:
        ans = 0
    print(f"Case {i}: {ans}")
