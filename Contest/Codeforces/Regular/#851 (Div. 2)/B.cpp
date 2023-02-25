#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n % 10 == 9)
    {
        vector<int> digit;
        while (n)
        {
            digit.push_back(n % 10);
            n /= 10;
        }
        int a = 0, b = 0;
        bool flag = false;
        for (int i = digit.size() - 1; i >= 0; i--)
        {
            int d = digit[i];
            a = a * 10 + d / 2;
            b = b * 10 + d / 2;
            if (d % 2)
            {
                if (flag)
                    a++;
                else
                    b++;
                flag = !flag;
            }
        }
        cout << a << ' ' << b << endl;
    }
    else if (n % 2)
        cout << n / 2 << ' ' << n / 2 + 1 << endl;
    else
        cout << n / 2 << ' ' << n / 2 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}