#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int x = 0;
    while (n--)
    {
        int t;
        cin >> t;
        x ^= t;
    }
    if (x)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}