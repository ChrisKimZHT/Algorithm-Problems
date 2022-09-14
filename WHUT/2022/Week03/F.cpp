#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    bool flag = false;
    for (int i = sqrt(2 * N); i > 1; i--)
    {
        if (2 * N - i * (i - 1) > 0 && !((2 * N - i * (i - 1)) % (2 * i)))
        {
            flag = true;
            cout << (2 * N - i * (i - 1)) / (2 * i) << endl;
        }
    }
    if (!flag)
        cout << "No Solution" << endl;
    return 0;
}