#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        double e[3];
        cin >> e[0] >> e[1] >> e[2];
        sort(e, e + 3);
        if (e[0] + e[1] - e[2] > 1e-6)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}