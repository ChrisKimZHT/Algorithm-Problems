#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int A, B, C, X;
    cin >> A >> B >> C >> X;
    double p;
    if (X <= A)
        p = 1;
    else if (A < X && X <= B)
        p = 1.0 * C / (B - A);
    else
        p = 0;
    printf("%.9lf", p);
    return 0;
}