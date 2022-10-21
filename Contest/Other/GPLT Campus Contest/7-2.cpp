#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n;
    double x;
    cin >> n >> x;
    printf("%d", (int)ceil(1.0 * n / x));
    return 0;
}