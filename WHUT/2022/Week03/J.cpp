#include <bits/stdc++.h>

using namespace std;

const int MAXN = 55;
int t, n;
int a[MAXN];
set<int> s;

int main()
{
    cin >> t;
    while (t--)
    {
        s.clear();
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            s.insert(a[i]);
        }
        if ((n - s.size()) % 2)
            cout << s.size() - 1 << endl;
        else
            cout << s.size() << endl;
    }
    return 0;
}