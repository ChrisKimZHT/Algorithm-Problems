#include <iostream>

using namespace std;

int main()
{
    char c;
    int cnt = 0;
    while (scanf("%c", &c) != EOF)
    {
        if (c != '6')
        {
            if (cnt > 9)
            {
                cout << "27";
            }
            else if (cnt > 3)
            {
                cout << "9";
            }
            else
            {
                for (int i = 0; i < cnt; i++)
                    cout << '6';
            }
            cnt = 0;
            cout << c;
        }
        else
        {
            cnt++;
        }
    }
    return 0;
}