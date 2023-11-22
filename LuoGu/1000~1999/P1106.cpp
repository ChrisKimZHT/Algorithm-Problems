#include <bits/stdc++.h>

using namespace std;

string str_n;
vector<int> n;
int k;

int main()
{
    cin >> str_n >> k;
    for (int i = 0; i < str_n.size(); i++)
        n.push_back(str_n[i] - '0');
    while (k--)
    {
        bool flag = false;
        for (auto it = n.begin(); next(it) != n.end(); ++it)
        {
            if (*it > *next(it))
            {
                n.erase(it);
                flag = true;
                break;
            }
        }
        if (!flag)
            n.erase(prev(n.end()));
    }
    while (n.size() - 1 && !n.front())
        n.erase(n.begin());
    for (auto i : n)
        cout << i;
    cout << endl;
    return 0;
}