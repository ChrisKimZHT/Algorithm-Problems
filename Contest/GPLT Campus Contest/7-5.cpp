#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        if (tolower(s[i]) != 'b')
            cout << s[i];
        else
        {
            if (i + 2 < n)
            {
                if (tolower(s[i + 1]) == 'a' && tolower(s[i + 2]) == 'd')
                {
                    cout << "good";
                    i += 2;
                }
                else
                    cout << s[i];
            }
            else
            {
                cout << s[i];
                continue;
            }
        }
    }
    return 0;
}