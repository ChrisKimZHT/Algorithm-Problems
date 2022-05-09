#include <bits/stdc++.h>

using namespace std;

struct Point
{
    long long px, py;
};

Point operator+(const Point &a1, const Point &a2)
{
    return Point{a1.px + a2.px, a1.py + a2.py};
}

Point operator-(const Point &a1, const Point &a2)
{
    return Point{a1.px - a2.px, a1.py - a2.py};
}

bool operator<(const Point &a1, const Point &a2)
{
    if (a1.px < a2.px)
        return true;
    if (a1.px > a2.px)
        return false;
    if (a1.py < a2.py)
        return true;
    return false;
}

// Find the cross product of p1 and p2
long long crs(Point p1, Point p2)
{
    return p1.px * p2.py - p1.py * p2.px;
}

int main()
{
    int n;
    cin >> n;
    vector<Point> pts(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pts[i].px >> pts[i].py;
    }

    long long s = 0;
    for (int i = 2; i < n; i++)
    {
        s += abs(crs(pts[i - 1] - pts[0], pts[i] - pts[0]));
    }

    long long res = 8e18, e = 0;
    int q = 1;
    for (int p = 0; p < n; p++)
    {
        while (4 * e < s)
        {
            e += abs(crs(pts[q] - pts[p], pts[(q + 1) % n] - pts[p]));
            q++;
            q %= n;
            res = min(res, abs(4 * e - s));
        }
        e -= abs(crs(pts[p] - pts[q], pts[(p + 1) % n] - pts[q]));
        res = min(res, abs(4 * e - s));
    }
    cout << res << '\n';
    return 0;
}
