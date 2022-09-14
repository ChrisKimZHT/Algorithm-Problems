#include <iostream>

using namespace std;

int f(char c)
{
    if (isupper(c))
        return c - 'A' + 1;
    else
        return -(c - 'a' + 1);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        char c;
        int n;
        cin >> c >> n;
        getchar();
        cout << n + f(c) << endl;
    }
    return 0;
}