#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int nn = n;
    set<int> s;
    int t;
    cin >> t;
    nn--;
    while (nn--)
    {
        int a;
        cin >> a;
        s.insert(abs(a - t));
        t = a;
    }
    s.erase(0);
    if (s.size() == n - 1 && *s.rbegin() == n - 1)
        cout << "Jolly" << endl;
    else
        cout << "Not jolly" << endl;
    return 0;
}