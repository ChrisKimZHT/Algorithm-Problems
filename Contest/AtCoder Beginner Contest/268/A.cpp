#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<int> s;
    for (int i = 0; i < 5; i++)
    {
        int t;
        cin >> t;
        s.insert(t);
    }
    cout << s.size() << endl;
    return 0;
}