#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (x * x + y * y + z * z == 3 * x * y * z)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}