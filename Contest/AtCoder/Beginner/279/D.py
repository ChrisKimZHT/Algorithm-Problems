from decimal import *
getcontext().prec = 50

[A, B] = map(lambda x: int(x), input().split(' '))


def f(x: Decimal) -> Decimal:
    return Decimal(A) / (x + Decimal(1)).sqrt() + Decimal(B) * x


l = 0
r = A
while l < r:
    m1 = l + (r - l) // 3
    m2 = r - (r - l) // 3
    if f(Decimal(m1)) > f(Decimal(m2)):
        l = m1 + 1
    else:
        r = m2 - 1

print(round(f(Decimal(l)), 10))
