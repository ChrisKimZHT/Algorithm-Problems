def hs():
    L = [0]
    S = set()
    A = [int(a) for a in input().split()]
    s = 0
    for i, a in enumerate(A):
        if a not in S:
            S.add(a)
            s = (s + a * (a + 1346) * (a + 9185)) % P
        L.append(s)
    return L


P = 8128812800000059
N = int(input())
X, Y = hs(), hs()
Q = int(input())
for _ in range(Q):
    x, y = map(int, input().split())
    print("Yes" if X[x] == Y[y] else "No")
