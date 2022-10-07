#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> num(n);
        for (int i = 0; i < n; i++)
            cin >> num[i];
        int nmin = INT32_MAX;
        for (int i = 0; i < n; i++)
            nmin = min(nmin, num[i]);
        int part = nmin * 2 - 1;
        int cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += ceil(1.0 * num[i] / part) - 1;
        cout << cnt << endl;
    }
    return 0;
}