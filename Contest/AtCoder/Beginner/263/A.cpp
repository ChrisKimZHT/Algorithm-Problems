#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num[5];
    for (int i = 0; i < 5; i++)
        cin >> num[i];
    int x = 1, y = 0, t = 0;
    for (int i = 1; i < 5; i++)
    {
        if (num[i] == num[0])
            x++;
        else if (num[i] == t)
            y++;
        else if (t == 0)
        {
            t = num[i];
            y++;
        }
    }
    if (x == 2 && y == 3 || x == 3 && y == 2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}