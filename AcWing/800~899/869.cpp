#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        vector<int> res1, res2;
        for (int i = 1; i <= x / i; i++)
        {
            if (x % i == 0)
            {
                res1.push_back(i);
                if (i != x / i)
                    res2.push_back(x / i);
            }
        }
        for (int i = 0; i < res1.size(); i++)
            cout << res1[i] << ' ';
        for (int i = res2.size() - 1; i >= 0; i--)
            cout << res2[i] << ' ';
        cout << endl;
    }
    return 0;
}