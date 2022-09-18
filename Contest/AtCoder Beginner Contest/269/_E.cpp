#include <bits/stdc++.h>

using namespace std;

int query(int a, int b, int c, int d)
{
    cout << "? " << a << ' ' << b << ' ' << c << ' ' << d << endl;
    int resp;
    cin >> resp;
    return resp;
}

int main()
{
    int N;
    cin >> N;
    int xl = 1, xr = N;
    while (xl < xr)
    {
        int mid = (xl + xr) / 2;
        int resp = query(xl, mid, 1, N);
        if (resp == -1)
            return 0;
        if (resp <= mid - xl)
            xr = mid;
        else
            xl = mid + 1;
    }
    int yl = 1, yr = N;
    while (yl < yr)
    {
        int mid = (yl + yr) / 2;
        int resp = query(1, N, yl, mid);
        if (resp == -1)
            return 0;
        if (resp <= mid - yl)
            yr = mid;
        else
            yl = mid + 1;
    }
    cout << "! " << xl << ' ' << yl << endl;
    return 0;
}