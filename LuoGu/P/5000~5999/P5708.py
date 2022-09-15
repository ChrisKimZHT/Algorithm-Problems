l = input().split()
a, b, c = float(l[0]), float(l[1]), float(l[2])
p = (a + b + c) / 2
print(format((p * (p - a) * (p - b) * (p - c)) ** 0.5, '.1f'))
