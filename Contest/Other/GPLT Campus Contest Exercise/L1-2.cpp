#include <iostream>

using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    printf("%d/%.1lf=%d", A, 1.0 * A / B, B);
    return 0;
}