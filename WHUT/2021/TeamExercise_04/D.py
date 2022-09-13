import functools


def cmp(a, b):
    if a[0] == b[0]:
        if a[1] < b[1]:
            return -1
        elif a[1] == b[1]:
            return 0
        else:
            return 1
    elif a[0] > b[0]:
        return 1
    else:
        return -1


T = int(input())
for cse in range(1, T + 1):
    n = int(input())
    point = []
    for i in range(0, n):
        xy = input().split()
        point.append([int(xy[0]), int(xy[1])])
    mid = []
    for i in range(0, n - 1):
        for j in range(i + 1, n):
            mid.append([point[i][0] + point[j][0], point[i][1] + point[j][1]])
    mid = sorted(mid, key=functools.cmp_to_key(cmp))
    ans = 0
    for i in range(0, len(mid)):
        for j in range(i + 1, len(mid)):
            if mid[i] == mid[j]:
                ans += 1
            else:
                break
    print(f"Case {cse}: {ans}")
