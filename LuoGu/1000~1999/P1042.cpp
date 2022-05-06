#include <bits/stdc++.h>

using namespace std;

int main()
{
    char res;
    string oneline;
    int a_w = 0, a_l = 0;
    while (cin >> res)
    {
        if (res == 'E')
        {
            oneline += res;
            break;
        }
        oneline += res;
    }
    for (int i = 0; i < oneline.size(); i++)
    {
        if (oneline[i] == 'W')
        {
            a_w++;
            if (abs(a_w - a_l) >= 2 && (a_w >= 11 || a_l >= 11))
            {
                cout << a_w << ':' << a_l << endl;
                a_w = 0;
                a_l = 0;
            }
        }
        else if (oneline[i] == 'L')
        {
            a_l++;
            if (abs(a_w - a_l) >= 2 && (a_w >= 11 || a_l >= 11))
            {
                cout << a_w << ':' << a_l << endl;
                a_w = 0;
                a_l = 0;
            }
        }
        else
        {
            cout << a_w << ':' << a_l << endl;
            break;
        }
    }
    cout << endl;
    int b_w = 0, b_l = 0;
    for (int i = 0; i < oneline.size(); i++)
    {
        if (oneline[i] == 'W')
        {
            b_w++;
            if (abs(b_w - b_l) >= 2 && (b_w >= 21 || b_l >= 21))
            {
                cout << b_w << ':' << b_l << endl;
                b_w = 0;
                b_l = 0;
            }
        }
        else if (oneline[i] == 'L')
        {
            b_l++;
            if (abs(b_w - b_l) >= 2 && (b_w >= 21 || b_l >= 21))
            {
                cout << b_w << ':' << b_l << endl;
                b_w = 0;
                b_l = 0;
            }
        }
        else
        {
            cout << b_w << ':' << b_l << endl;
            break;
        }
    }
    return 0;
}