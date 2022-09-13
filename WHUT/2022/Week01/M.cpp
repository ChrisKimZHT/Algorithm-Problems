#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b)
{
    return abs(a) > abs(b);
}

int main()
{
    int n;
    while (cin >> n, n)
    {
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int t;
            cin >> t;
            v.push_back(t);
        }
        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < v.size(); i++)
        {
            if (i)
                cout << ' ';
            cout << v[i];
        }
        cout << endl;
    }
    return 0;
}