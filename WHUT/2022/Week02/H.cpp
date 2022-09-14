#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    char c;
    string buf;
    unordered_set<string> s;
    while ((c = getchar()) != EOF)
    {
        if (isalpha(c))
        {
            buf += c;
        }
        else if (c == ' ')
        {
            if (buf.length())
                s.insert(buf);
            buf.clear();
        }
        else if (c == '\n')
        {
            if (buf.length())
                s.insert(buf);
            buf.clear();
            cout << s.size() << endl;
            s.clear();
        }
        else if (c == '#')
        {
            if (buf.length())
                s.insert(buf);
            buf.clear();
            if (s.size())
                cout << s.size() << endl;
            break;
        }
    }
    return 0;
}