#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int x = 0;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        if (i % 2)
            x ^= t;
    }
    if (x)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}