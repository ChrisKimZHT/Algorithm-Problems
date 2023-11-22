#include <bits/stdc++.h>

using namespace std;

int k, x, y;

void solve(int px, int py, int tx, int ty, int len)
{
    if (len == 1)
        return;
    int hlen = len / 2;
    int lux = px, luy = py;
    int ldx = px, ldy = py + hlen;
    int rux = px + hlen, ruy = py;
    int rdx = px + hlen, rdy = py + hlen;
    int luxt = px + hlen - 1, luyt = py + hlen - 1;
    int ldxt = px + hlen - 1, ldyt = py + hlen;
    int ruxt = px + hlen, ruyt = py + hlen - 1;
    int rdxt = px + hlen, rdyt = py + hlen;
    if (tx >= rdx && ty >= rdy) // RD
    {
        cout << luyt << ' ' << luxt << ' ' << 4 << endl;
        solve(rdx, rdy, tx, ty, hlen);     // RD
        solve(ldx, ldy, ldxt, ldyt, hlen); // LD
        solve(rux, ruy, ruxt, ruyt, hlen); // RU
        solve(lux, luy, luxt, luyt, hlen); // LU
    }
    else if (ty >= ldy) // LD
    {
        cout << ruyt << ' ' << ruxt << ' ' << 3 << endl;
        solve(rdx, rdy, rdxt, rdyt, hlen); // RD
        solve(ldx, ldy, tx, ty, hlen);     // LD
        solve(rux, ruy, ruxt, ruyt, hlen); // RU
        solve(lux, luy, luxt, luyt, hlen); // LU
    }
    else if (tx >= rux) // RU
    {
        cout << ldyt << ' ' << ldxt << ' ' << 2 << endl;
        solve(rdx, rdy, rdxt, rdyt, hlen); // RD
        solve(ldx, ldy, ldxt, ldyt, hlen); // LD
        solve(rux, ruy, tx, ty, hlen);     // RU
        solve(lux, luy, luxt, luyt, hlen); // LU
    }
    else // LU
    {
        cout << rdyt << ' ' << rdxt << ' ' << 1 << endl;
        solve(rdx, rdy, rdxt, rdyt, hlen); // RD
        solve(ldx, ldy, ldxt, ldyt, hlen); // LD
        solve(rux, ruy, ruxt, ruyt, hlen); // RU
        solve(lux, luy, tx, ty, hlen);     // LU
    }
}

int main()
{
    cin >> k >> x >> y;
    solve(1, 1, y, x, 1 << k);
    return 0;
}