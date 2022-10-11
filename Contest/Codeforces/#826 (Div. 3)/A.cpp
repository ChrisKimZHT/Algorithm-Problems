#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<char, int> mp{{'S', 0}, {'M', 1}, {'L', 2}};
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        if (mp[a.back()] < mp[b.back()])
            cout << "<" << endl;
        else if (mp[a.back()] > mp[b.back()])
            cout << ">" << endl;
        else if (a.back() == 'S')
        {
            if (a.size() < b.size())
                cout << ">" << endl;
            else if (a.size() > b.size())
                cout << "<" << endl;
            else
                cout << "=" << endl;
        }
        else
        {
            if (a.size() < b.size())
                cout << "<" << endl;
            else if (a.size() > b.size())
                cout << ">" << endl;
            else
                cout << "=" << endl;
        }
    }
    return 0;
}