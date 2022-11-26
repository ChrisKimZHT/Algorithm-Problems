#include <bits/stdc++.h>
#define int long long

using namespace std;

int fun(int a, int b)
{
    if (b > 0)
        return abs(a);
    else
        return -abs(a);
}

signed main()
{
    int a, b;
    cin >> a >> b;
    cout << fun(a, b) << endl;
    return 0;
}