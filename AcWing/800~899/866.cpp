#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        bool flag = true;
        if (a == 1)
            flag = false;
        for (int i = 2; i <= a / i; i++)
            if (!(a % i))
            {
                flag = false;
                break;
            }
        cout << (flag ? "Yes" : "No") << endl;
    }
    return 0;
}