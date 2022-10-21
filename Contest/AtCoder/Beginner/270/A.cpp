#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    int x = 0, y = 0, z = 0;
    if (A == 1)
    {
        x++;
    }
    else if (A == 2)
    {
        y++;
    }
    else if (A == 4)
    {
        z++;
    }
    else if (A == 3)
    {
        x++;
        y++;
    }
    else if (A == 5)
    {
        x++;
        z++;
    }
    else if (A == 6)
    {
        y++;
        z++;
    }
    else if (A == 7)
    {
        x++;
        y++;
        z++;
    }
    if (B == 1)
    {
        x++;
    }
    else if (B == 2)
    {
        y++;
    }
    else if (B == 4)
    {
        z++;
    }
    else if (B == 3)
    {
        x++;
        y++;
    }
    else if (B == 5)
    {
        x++;
        z++;
    }
    else if (B == 6)
    {
        y++;
        z++;
    }
    else if (B == 7)
    {
        x++;
        y++;
        z++;
    }
    int ans = 0;
    if (x)
        ans += 1;
    if (y)
        ans += 2;
    if (z)
        ans += 4;
    cout << ans << endl;
    return 0;
}