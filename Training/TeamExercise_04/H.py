T = int(input())
for i in range(1, T + 1):
    n = int(input())
    ans = 0
    j = 1
    while j * j <= n:
        ans += 1
        if j * j * 2 <= n:
            ans += 1
        j += 1
    print(f"Case {i}: {n - ans}")
