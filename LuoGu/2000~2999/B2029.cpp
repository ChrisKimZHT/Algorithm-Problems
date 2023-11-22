#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1.0);

int main()
{
    int h, r;
    cin >> h >> r;
    double v = PI * r * r * h;
    cout << ceil(20000 / v) << endl;
    return 0;
}