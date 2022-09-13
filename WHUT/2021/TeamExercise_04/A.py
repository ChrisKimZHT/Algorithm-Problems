T = int(input())
for i in range(1, T + 1):
    nk = input().split()
    n = int(nk[0])
    k = int(nk[1])
    ans = 0
    for j in range(2, n + 1):
        ans += k
        ans %= j
    print(f"Case {i}: {ans + 1}")
