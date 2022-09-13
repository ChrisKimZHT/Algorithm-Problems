#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    while (cin >> t)
    {
        if (90 <= t && t <= 100)
            cout << "A" << endl;
        else if (80 <= t && t <= 89)
            cout << "B" << endl;
        else if (70 <= t && t <= 79)
            cout << "C" << endl;
        else if (60 <= t && t <= 69)
            cout << "D" << endl;
        else if (0 <= t && t <= 59)
            cout << "E" << endl;
        else
            cout << "Score is error!" << endl;
    }

    return 0;
}