x = int(input())

num = 0

for i in range(1, 10000000):
    num *= 10
    num += 1
    if num % x == 0:
        print(f"{int(num // x)} {i}")
        break
