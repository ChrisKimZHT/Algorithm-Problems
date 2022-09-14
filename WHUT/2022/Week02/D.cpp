#include <iostream>

using namespace std;

int main()
{
    bool h = true;
    char c;
    while ((c = getchar()) != EOF)
    {
        if (isalpha(c))
        {
            if (h)
            {
                h = false;
                cout << char(toupper(c));
            }
            else
            {
                cout << c;
            }
        }
        else if (c == ' ' || c == '\n')
        {
            h = true;
            cout << c;
        }
    }
    return 0;
}