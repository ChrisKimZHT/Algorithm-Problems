#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(x + 10);
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        a[t]++;
    }
    for (int i = 1; i < x; i++)
    {
        if (a[i] % (i + 1))
        {
            cout << "No" << endl;
            return 0;
        }
        a[i + 1] += a[i] / (i + 1);
    }
    cout << "Yes" << endl;
    return 0;
}