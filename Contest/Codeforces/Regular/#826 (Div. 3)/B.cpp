#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 2)
        {
            cout << "2 1" << endl;
            continue;
        }
        else if (n == 3)
        {
            cout << "-1" << endl;
            continue;
        }
        else if (n==5)
        {
            cout << "5 4 1 2 3" << endl;
            continue;
        }
        for (int i = n; i >= 1; i--)
        {
            if (i != n - i + 1)
            {
                cout << i << ' ';
            }
            else
            {
                cout << i - 1 << ' ' << i << ' ';
                i--;
            }
        }
        cout << endl;
    }
    return 0;
}