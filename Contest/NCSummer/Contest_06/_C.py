n = m = int(input())
ans = 0
i = 5
while i <= n:
    j = (n - i) // (i * 2)
    k = ((n - i) % (i * 2)) // 2 + 1
    ans += i * j * (j + 1) // 2 + (j + 1) * k
    i *= 5

i = 10
while i <= n:
    j = (n - i) // i
    k = ((n - i) % i) // 2 + 1
    ans += i * j * (j + 1) // 4 + (j + 1) * k
    i *= 5

print(ans)
