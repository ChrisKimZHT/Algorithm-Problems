#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int A, B;
    cin >> A >> B;
    double C = sqrt(A * A + B * B);
    double cosC = A / C;
    cout << cosC << ' ' << sqrt(1 - cosC * cosC);
    return 0;
}