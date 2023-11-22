#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int t;
    cin >> t;
    if (n == 0)
    {
        cout << t << endl;
        return 0;
    }
    if (t == -1)
        cout << '-';
    else if (t != 1)
        cout << t;
    if (n != 1)
        cout << "x^" << n;
    else
        cout << "x";
    while (--n >= 0)
    {
        cin >> t;
        if (n)
        {
            if (t == 1)
                cout << '+';
            else if (t == -1)
                cout << '-';
            else if (t == 0)
                continue;
            else if (t > 0)
                cout << '+' << t;
            else if (t < 0)
                cout << t;
            if (n != 1)
                cout << "x^" << n;
            else
                cout << "x";
        }
        else
        {
            if (t > 0)
                cout << '+';
            else if (t == 0)
                continue;
            cout << t << endl;
        }
    }

    return 0;
}