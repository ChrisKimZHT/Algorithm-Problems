#include <bits/stdc++.h>

using namespace std;

string read()
{
    string res;
    char ch;
    while (cin >> ch)
    {
        if (ch == '[')
        {
            int t;
            cin >> t;
            string tmp = read();
            while (t--)
                res.append(tmp);
        }
        else if (ch == ']')
        {
            return res;
        }
        else
        {
            res.append(1, ch);
        }
    }
    return res;
}

int main()
{
    cout << read() << endl;
    return 0;
}