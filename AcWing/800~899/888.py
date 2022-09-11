a, b = input().split(' ')
a = int(a)
b = int(b)
res = 1
for i in range(a - b + 1, a + 1):
    res *= i
for i in range(1, b + 1):
    res //= i
print(res)
